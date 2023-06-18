#include<bits/stdc++.h>
#define MAXN 600

using namespace std;









int main() {
    //cin >> m >> n;//7
    
    int triangulo[4][4] = {0,0,0,2,0,0,5,4,0,3,4,7,1,6,9,6};

    
    int pd[4][4] = {};

    int n = 3;


    for(int i=3; i>=0; i--){
       
        for(int j = n-i; j<=n; j++){
            
            if (i==n){
                
                pd[i][j] = triangulo[i][j];
            }
            else if (pd[i+1][j-1]>pd[i+1][j]){
                pd[i][j] = pd[i+1][j-1] + triangulo[i][j];
            }
            else {
                pd[i][j] = pd[i+1][j] + triangulo[i][j];
            }
        }
    }
    
    




    cout << "triângulo:\n";
    for(int a=0; a<4;a++){
        for(int b =0; b<4;b++){
            cout << triangulo[a][b] << " ";
        }
        cout << endl;
    }
    cout << "Matriz:\n";
    for(int a=0; a<4;a++){
        for(int b =0; b<4;b++){
            cout << pd[a][b] << " ";
        }
        cout << endl;
    }
    cout << pd[0][n] << endl;

    cout<<"triângulo\n";
    int pos = n;
    int i = 1;
    cout << triangulo[0][n] << endl;
    while(true){
        if(pd[i][pos-1]>pd[i][pos]){
            cout << triangulo[i][pos-1] << endl;
            i++;
            pos--;
        }
        else {
            cout << triangulo[i][pos] << endl;
            i++;
        }

        if (i==n+1) break;
    }
    
}