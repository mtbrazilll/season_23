#include<bits/stdc++.h>
#define MAXN 600

using namespace std;

int m = 8;
int n;
int matriz[8][8]; 
int pd[20][20]; 
int corte[100];
char x[100],y[100];



int funcao1(int i, int j) {
    
    //cout << i << " " << j << endl;
    if (i == -1 || j == -1) return 0;

    int &resp = pd[i][j];
    if (resp != -1) return resp;


    int I = i,J = j;

    while(x[i] == y[j] && (i != -1 && j != -1) ){
        i--;j--;   
    }
    
    //cout << i << j << endl;
    if (i != I){
        resp = max(funcao1(i,J),funcao1(I,j));
        return resp = max(resp,I-i);
    }
    else {
        resp = max(funcao1(i-1,j),funcao1(i,j-1));
        return resp = max(resp,1);
    }

}

void prefuncao() {
    m = n = 15;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            pd[i][j] = -1;
        }
    }
    strcpy(x,"12345abaca4te"); // funcao (6,4) e funao (4,6) e 2
    strcpy(y,"12abaca456tex");
    cout << funcao1(10,10) << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pd[i][j] == -1)
                cout << "a" << " ";
            else 
                cout << pd[i][j] << " " ;
        }
        cout << endl;
    }
        
}

int main() {
    //cin >> m >> n;//7
    prefuncao();
   
}