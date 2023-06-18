#include <iostream>
#include <string>
#include <iterator>


void mergeSort(int *v,int esq,int meio,int dir){

    int i1 = esq;
    int i2 = meio + 1;
    int vetor[dir-esq+1];

    int i = 0;
    while(i1 != meio + 1 && i2 != dir + 1){
        
        if(v[i1] < v[i2]){
            vetor[i] = v[i1];
            i1++;
        }
        else{
            vetor[i] = v[i2];
            i2++;

        }
        i++;

    }

    if(i1 == meio + 1){
        while(i2 != dir + 1){
            vetor[i] = v[i2];
            i++;
            i2++;
        }
    }
    if(i2 == dir + 1){
        while(i1 != meio + 1){
            vetor[i] = v[i1];
            i++;
            i1++;
        }
    }

    for(int j = 0; j< dir-esq+1;j++){
        v[esq+j] = vetor[j];
    }

}


void merge(int v[], int esq, int dir){


    if(esq <= dir) return;

    int meio = (esq+dir)/2;
    
    merge(v,esq,meio);
    merge(v,meio+1,dir);

    mergeSort(v,esq,meio,dir);
    
}