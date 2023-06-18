#include <iostream>
#include <string>
#include <iterator>

using std::cout; using std::cin;
using std::endl; using std::string;

using namespace std;


#define STRING(num) #num

//0.....16
//0 8 9..16
//0-4 5

long int exp(long int base, long int expoente){

    if(expoente == 0){
        return 1;
    }
    long int metade = exp(base,expoente/2);
    long int resposta = metade*metade;
    if(expoente%2 == 1) resposta = resposta * base ;
    return resposta;
    
}

int main() {
    int a = exp(5,6);
    printf("Ou");
    printf("%d", a);
    return 0;
}