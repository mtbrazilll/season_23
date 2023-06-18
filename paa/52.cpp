#include<bits/stdc++.h>
#define MAXN 600

using namespace std;

int m = 8;
int n = 8;
int matriz[8][8]; 
int pd[8][8]; 

int funcao(int x, int y) {
    
    int &resp = pd[x][y];
    if (resp != -1) return resp;

    int a = funcao(x+1, y);
    int b = funcao(x, y+1);
    a = a > b ? a : b;
    resp = matriz[x][y] + a;

    return resp;
}

void prefuncao() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            pd[i][j] = -1;
        }
    }

    int a = 0;
    for (int i = m-1; i > 0; i--) {
        a += matriz[i][n-1];
        pd[i][n-1] = a; 
    }
    a = 0;
    for (int j = n-1; j > 0; j--) {
        a += matriz[m-1][j];
        pd[m-1][j] = a; 
    }
    
    cout << "O valor arrecadado foi de: "<< funcao(0, 0) << endl;
    
    cout << "O caminho percorrido foi: "<< endl;
    int i, j, q, w, tam;
    i = j = 0;
    tam = m + n - 1;

    while (tam != 0) {
        q = w = -2;

        if (i < m - 1) q = pd[i+1][j];
        if (j < n - 1) w = pd[i][j+1];

        if (q > w) {
            cout << i << "," << j << "     ";
            i++;
        } else {
            cout << i << "," << j << "     ";
            j++;        
        }
        tam--;
    }
}

int main() {
    //cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = (i+j)%2 + j;
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    prefuncao();
    cout << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << pd[i][j] << " ";
        }
        cout << endl;
    }
}