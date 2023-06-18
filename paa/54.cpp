#include<bits/stdc++.h>
#define MAXN 600

using namespace std;

int m;
int p[100];
int lista[1000] = {5, 10, -30, 10, -5, 40, 10};
//5,15,-15,10,5,45,55

// F(i, j) = min{F(i, k)}{F(k, j)}, k = 0 a m

int funcao(int i) {
    vector<int> lucas;
    int &resp = p[i];
    if (i==0) return resp = lista[i];
    
    if (resp != -1) return resp;
    return resp = max(lista[i]+funcao(i-1),lista[i]);

}

int  funcao2(int i) {
    vector<int> lucas;
    int &resp = p[i];
    if (i==0) return resp = lista[i];
    
    if (resp != -1) return resp;

    return resp = max(lista[i]+funcao(i-1),lista[i]);

}

void prefuncao() {
    m =  7;
    for (int i = 0; i < m; i++) {
        p[i] = -1;
        printf("%d ",lista[i]);
    }
    printf("\n");
    
    cout << funcao(m-1) << endl;
        
}

int main() {
    //cin >> m >> n;//7
    //
    //prefuncao();

    int aux[100]= {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int melhor = lista[0];
    int a;
    m = 7;
    a = 0;


    aux[0] = lista[0];
    for(int i = 1; i<m;i++){
        if(aux[i-1]+lista[i]>lista[i]){
            aux[i] = aux[i-1]+lista[i];
            if(aux[i]>melhor) {
                melhor = aux[i];
                a = i;
            }
        }
        else{
            if(aux[i]>melhor){
                melhor = aux[i];
                a = i;
            }
            aux[i] = lista[i];
        }
    }
    for (int i = a; i>-1;i--){
        cout << lista[i] << " ";
        if (lista[i] == aux [i])
            break;
    }
    cout << endl << melhor;
    
}