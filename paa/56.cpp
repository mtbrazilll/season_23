#include<bits/stdc++.h>
using namespace std;
int corte[] = {0, 3, 6, 10, 17, 20};
int pd[6][6] = {};
/*
int corte[4] = {0, 3, 10, 20};
int pd[4][4] = {};
*/
int funcao(int i, int j) {

    if (j == i + 1) return 0;

    int &ans = pd[i][j];
    if (ans != 0) return ans;

    int custo, aux = 999999;
    for (int k = i + 1; k < j; k++) {
        custo = funcao(i, k) + funcao(k, j);
        if (custo < aux) aux = custo;
    }

    ans = corte[j] - corte[i] + aux;  
    return ans;
}

int main () {

    cout << "\n" << funcao(0, 5) << endl;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (pd[i][j] < 10) cout << " ";
            cout << pd[i][j] << " ";
        }
        cout << endl;
    }
}
