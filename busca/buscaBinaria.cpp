#include <iostream>
#include <string>
#include <iterator>

using std::cout; using std::cin;
using std::endl; using std::string;

using namespace std;


#define STRING(num) #num

string printVetor(int v[],int e, int d){
    string vetor = "{" ;
    vetor = vetor + to_string(v[e]);
    e++;
    while(e != d + 1){
        vetor = vetor + ", " + to_string(v[e]);
        e++;
    }
    vetor = vetor + "}";
    return vetor;
}

int buscaBinaria(int v[],int esq,int dir,int procura){
    
    if(esq>dir) return -1;
    int meio = (esq+dir)/2;

    if(v[meio]>procura){
        return buscaBinaria(v,esq,meio-1,procura);
    }
    else if (v[meio]<procura){
        return buscaBinaria(v,meio+1,dir,procura);
    }
    return meio;

}

int buscaBinaria2(int v[],int esq,int dir,int procura){
   
    while(esq<=dir){
         int meio = (esq+dir)/2;
         if(v[meio]>procura){
             dir = meio - 1;
         }
         else if(v[meio]<procura){
             esq = meio + 1;
         }
         else{
             return meio;
         }
    }
    return -1;

}

int chamaBuscaBinaria(int v[],int tamanho,int procura){
    if(tamanho <= 0) return -2;
    return buscaBinaria(v,0,tamanho-1,procura);

}


int main() {

    int n = 5;
    int v[n] = {1, 2, 3, 4, 5};
    int cont = 0;
    int index = 0;
    int i;

    printf("\n%d\n",chamaBuscaBinaria(v,n,5));

    //printf("%s",printVetor(v,0,4).c_str());

    return 0;
}