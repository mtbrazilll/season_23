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
    else{
        if(expoente % 2 == 0){
            return exp(base,expoente/2)*exp(base,expoente/2);
        }
        else{
            return exp(base,expoente-1)*base;
        }
    }
}


long int log(long y){

    long cont = -1;
    while(y != 0){
        y = y/2;
        cont++;
    }
    return cont;
}       




void printa(int inicio, int final){

    
    if(final - inicio + 1 == 2){
        return;
    }
    int meio = (inicio+final)/2;

    //printf("%d %d\n",inicio,final);
    printa(inicio,meio);
    printf(". ");
    for(int i=0; i<log(final - inicio);i++){
        printf("-");
    }
    printf("\n");

    printa(meio,final);
    return;
}


int main() {
    int c = 0;
    int n = 5;
    for(int l = 1; l <= n; l++){
        for(int i=1; i<= n-l; i++){
            for(int k=1; k<= i+l; k++){
                c = c + 1;
            }
        }
    }
    
    printf("%d",c);
    return 0;
}