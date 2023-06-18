    #include <bits/stdc++.h>

    using namespace std;

    #define ll long long int
    #define ull unsigned long long int

 string soma(string a, string b) {

    int i_a = a.size() - 1;
    int i_b = b.size() - 1;
    int carry = 0;
    string soma;

    while (i_a >= 0 || i_b >= 0 || carry != 0) {
        int d1 = (i_a >= 0) ? (a[i_a] - '0') : 0;
        int d2 = (i_b >= 0) ? (b[i_b] - '0') : 0;

        int num = d1 + d2 + carry;
        carry = num / 10;
        num = num % 10;

        soma = to_string(num) + soma;

        i_a--;
        i_b--;
    }

    return soma;
}

string sub(string a, string b) { // a - b

    int size_a = a.size();
    int size_b = b.size();
    int carry = 0;
    std::string result;

    while (b.size() < size_a) {
        b = "0" + b;
    }

    for (int i = size_a - 1; i >= 0; i--) {
        int digit_a = a[i] - '0';
        int digit_b = b[i] - '0';

        int sub = digit_a - digit_b - carry;

        if (sub < 0) {
            sub += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }

        result = to_string(sub) + result;
    }
   
    result.erase(0, result.find_first_not_of('0'));
    
    if (result.empty()) {
        result = "0";
    }

    return result;
}


string karatsuba(string a, string b) {

    if (a.size() == 1 && b.size() == 1) {
        int d1 = a[0] - '0';
        int d2 = b[0] - '0';

        return to_string(d1 * d2);
    }

    int maxSize = a.size() > b.size() ? a.size() : b.size();
    if (maxSize % 2 == 1) maxSize = maxSize + 1;

    while (a.size() < maxSize) {
        a = "0" + a;
    }
    while (b.size() < maxSize) {
        b = "0" + b;
    }

    int halfSize = maxSize / 2;

    string a_l = a.substr(0, halfSize);
    string a_h = a.substr(halfSize);
    string b_l = b.substr(0, halfSize);
    string b_h = b.substr(halfSize);

    string z0 = karatsuba(a_l, b_l);
    string z1 = karatsuba(a_h, b_h);
    string z2 = karatsuba(soma(a_l, a_h), soma(b_l, b_h));
    string z3 = sub(sub(z2, z0), z1);

    
    z0 += string(maxSize, '0');
    z3 += string(halfSize, '0');

    z0 = soma(z0, z1);
    z0 = soma(z0, z3);

    return z0;
}



    int main() {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        string num1 = "3141592653589793238462643383279502884197169399375105820974944592";
        string num2 = "2718281828459045235360287471352662497757247093699959574966967627";

        string resultado = karatsuba(num1, num2);

        cout << "Resultado: " << resultado << std::endl;



        return 0;
    }