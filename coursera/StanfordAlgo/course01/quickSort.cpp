    #include <bits/stdc++.h>

    using namespace std;

    #define ll long long int
    #define ull unsigned long long int

    int conta = 0;

    int split_01(int *v, int inicio, int final)
    {
        conta = final - inicio + conta;
        int pivo, i, j;
        pivo = v[final];

        i = inicio;
        for (int j = i; j < final; j++)
        {
            if (v[j] < pivo)
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
            }
        }
        int aux = pivo;
        v[inicio] = v[i];
        v[i] = aux;

        return i;
    }

    int split(int *v, int inicio, int final){
        conta = final - inicio + conta;
        int pivo, i, j;
        pivo = v[inicio];

        i = inicio+1;
        for (int j = i; j < final+1; j++)
        {
            if (v[j] < pivo){
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
            }
        }
        int aux = pivo;
        v[inicio] = v[i-1];
        v[i-1] = aux;
        
        return i-1;

    }

    void quickSort(int *v, int inicio, int final){
        cout <<"inicio: "<< inicio <<" final: "<< final<< endl;;
        int p;
        
        if (final - inicio > 0){

            p  = split(v, inicio, final);
            
            quickSort(v,inicio,p-1);
            quickSort(v,p+1,final);
        }
    }
    

  /*   int main() {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int v[] = {1,2,1,4};
        
        quickSort(v, 0, 3);

        for (int i = 0; i < 4; i++)
        {
            cout << v[i] << " ";
        }
        
        

  


        return 0;
    } */
    void quickSort_median(int *v, int inicio, int final){
        cout <<"inicio: "<< inicio <<" final: "<< final<< endl;;
        int p;
        
        if (final - inicio > 0){
            int p_aux = inicio;
            int menor = v[inicio];
            if (menor <= v[final]){
                if ( menor <= v[(final+inicio)/2]){
                    if (v[final] <= v[(final+inicio)/2]){
                        p_aux = final;
                    }
                    else{
                        p_aux = (final+inicio)/2;
                    }
                }
                else{
                    
                }
            }
            else{
                if (v[final] <= v[(final + inicio) / 2])
                {
                    if (v[inicio] <= v[(final + inicio) / 2])
                    {
                        p_aux = inicio;
                    }
                    else
                    {
                        p_aux = (final + inicio) / 2;
                    }
                }
                else
                {
                    p_aux = final;
                }
            }

            int aux = v[inicio];
            v[inicio] = v[p_aux];
            v[p_aux] = aux;
            p = split(v, inicio, final);

            quickSort(v,inicio,p-1);
            quickSort(v,p+1,final);
        }
    }
    
        
     int main() {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int *v = new int[100000];  

        ifstream arquivo("quick.txt");  
        if (arquivo.is_open()) {
            for (int i = 0; i < 10000; i++) {
                arquivo >> v[i];  
            }
            arquivo.close();
            cout << "Valores lidos com sucesso!" << endl;
        } else {
            cout << "Não foi possível abrir o arquivo." << endl;
        }

        quickSort(v, 0, 999);

        cout << conta << endl;
        delete[] v;  // Libera a memória alocada para o vetor
  


        return 0;

     }