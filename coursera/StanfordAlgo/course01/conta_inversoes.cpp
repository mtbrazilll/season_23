    #include <bits/stdc++.h>

    using namespace std;

    #define ll long long int
    #define ull unsigned long long int

    ull conta_split(int *v, int inicio, int meio, int fim){
        int i,j,k;
        ull conta = 0;
        k = 0; i = inicio; j = meio;
        while (i < meio && j < fim){
            if(v[i] <= v[j]) i++;
            else {
                conta += meio - i;
                j++;
            }
        }
        return conta;
    }

    ull conta_inversoes(int *v, int i, int f){
        int m;
        ull conta = 0;

        if (f - i == 1) return conta;
        
        m = (i + f)/2;
        conta += conta_inversoes(v,i,m);
        conta += conta_inversoes(v,m,f);
        conta += conta_split(v,i,m,f);

        return conta;
    }

    // Função para mesclar e contar as inversões
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    long long invCount = 0;

    i = left; // Índice para percorrer a subarray esquerda
    j = mid; // Índice para percorrer a subarray direita
    k = left; // Índice para percorrer a array original

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            invCount += (mid - i); // Incrementa o contador de inversões
        }
    }

    // Copia os elementos restantes da subarray esquerda, se houver
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    // Copia os elementos restantes da subarray direita, se houver
    while (j <= right)
        temp[k++] = arr[j++];

    // Copia os elementos ordenados de volta para a array original
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return invCount;
}

// Função auxiliar recursiva para dividir a array e contar as inversões
long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long invCount = 0;

    if (right > left) {
        int mid = (left + right) / 2;

        // Conta as inversões na subarray esquerda e na subarray direita
        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);

        // Conta as inversões entre as subarrays e mescla as subarrays
        invCount += mergeAndCount(arr, temp, left, mid + 1, right);
    }

    return invCount;
}

// Função principal para contar as inversões em uma array
long long countInversions(int arr[], int n) {
    int* temp = new int[n];
    return mergeSortAndCount(arr, temp, 0, n - 1);
}


    

   int main() {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int v[] = {4, 1, 2, 3};
        long long inversionCount = countInversions(v, 4);
        //cout << conta_inversoes(v,0,4) << endl;
        cout << inversionCount << endl;
  


        return 0;
    }
/* 
    
     int main() {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int *v = new int[100000];  

        ifstream arquivo("array_int.txt");  
        if (arquivo.is_open()) {
            for (int i = 0; i < 100000; i++) {
                arquivo >> v[i];  
            }
            arquivo.close();
            cout << "Valores lidos com sucesso!" << endl;
        } else {
            cout << "Não foi possível abrir o arquivo." << endl;
        }

        long long inversionCount = countInversions(v, 100000);

        cout << inversionCount << endl;
        delete[] v;  // Libera a memória alocada para o vetor
  


        return 0;
    }  */