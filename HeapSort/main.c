#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int troca=0;
int verifique=0;

void BuildHeap(int v[], int n, int i)
{
    int maior =i;
    int L=2*i+1, R=2*i+2;
    if(L<n && ++verifique && v[L]>v[maior])
        maior = L;
    if(R<n && ++verifique && v[R]>v[maior])
        maior = R;
    if(maior != i)
    {
        troca++;
        int aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        BuildHeap(v, n, maior);
    }
}

void HeapSort(int v[], int n)
{
    int i;
    
    for(i= n/2-1; i>=0; i--)
        BuildHeap(v, n, i);
    
    for(i=n-1; i>=0; i--)
    {
        troca++;
        int aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        BuildHeap(v, i, 0);
    }
}

void Imprime(int troca, int check, float tempo)
{
    printf("\n\nHeapSort: ");
    printf("\nComparacoes = %d  \nTrocas = %d", verifique, troca);
    printf( "\nExecucao foi de %f segundos\n", tempo);
}

int NumberRandon(int v[],int n){
    
    int porcento=0;
    porcento = (n*0.90);
    
    int num_iguais = 0;
    int i;
    
    srand( (unsigned)time(NULL) );
    
    num_iguais = rand() % n;
    for (i = 0; i < porcento; i++) {
        v[i] = num_iguais;
    }
    
    for (i = porcento; i < n; i++) {
        v[i] = rand() % n;
    }
    for (i = porcento; i < n; i++) {
        if(v[i] == v[i+1]){
            v[i] = rand() % n;
        }
    }
    //testando2e
    return v[i];
}



int main()
{
    int n, i;
    
    clock_t start, endd;
    //double tempo;
    
    printf("\n Informe o tamanho do vetor: ");
    scanf("%d",&n);
    
    int v[n];
    
    NumberRandon(v,n);
    
    for(i=0; i<n; i++)
        printf("%d ", v[i]);
    
    
    start = clock();
    HeapSort(v, n);
    endd = clock();
    double tempo = ((double) (endd - start))/CLOCKS_PER_SEC;
    
    printf("\n\n---------- Vetor Ordenado ----------\n\n");
    
    for(i=0; i<n; i++)
        printf("%d ", v[i]);
    
    Imprime(troca, verifique, tempo);
}
