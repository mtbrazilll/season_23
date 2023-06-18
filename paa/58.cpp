#include<bits/stdc++.h>
#define MAXN 600

using namespace std;

int m = 100;
int n = 100;
int lista[100] = {2,4,6};
int pd[100][100]; 

int funcao(int i, int v) {

    int &resp = pd[i][v];
    if (resp != -1) return resp;

    if (v == 0) return resp = 1;

    if (i==-1) {
        if(lista[i]==v) return resp = 0;
    }
    
    if(lista[i]>v){
        return resp = funcao(i-1,v);
    }

    if (funcao(i-1,v) == 1 || funcao(i-1,v-lista[i])) return resp = 1;
    else return resp = 0;
    
}

void prefuncao() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            pd[i][j] = -1;
        }
    }

    
    cout << "resultado: "<< funcao(7, 10) << endl;

    
}

int main() {
    //cin >> m >> n;
    //printf("oi");
    //prefuncao();

    int a=4;
    int b=6;

    for (int i = 0; i<b; i++)
        pd[0][i] = 0;
    for (int i = 0; i<a; i++)
        pd[i][0] = 1;

    for (int i = 1; i<a; i++){
        for (int j = 1; j<b; j++){
            
            if (lista[i-1]>j){
                pd[i][j] = pd[i-1][j];
            }
            else if (pd[i-1][j] == 1 || pd[i-1][j-lista[i-1]] == 1)
                pd[i][j] = 1;
            else
                pd[i][j] = 0;
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d  ",pd[i][j]);
        }
        printf("\n");
    }
}