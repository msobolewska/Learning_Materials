#include <stdio.h>
#include <stdlib.h>

long int Find_Ways(int *coins, int m, int n, int j, int poziom, long int **MemCoins);
int main(){
    FILE* input;
    input = fopen("Equal.txt", "r");

    if(!input){
        return 0;
    }

    int t;

    fscanf(input, "%d", &t);

    if(t==0){
        printf("0\n");
        return 0;
    }

    for(int i= 0; i<t; i++){
        fscanf(input, "%d", &n);
        int *chocolate = (int*)malloc(n*sizeof(int));
        int **MemChocolate = (int**)malloc(n*sizeof(long int*));
        for(int i = 0; i < n; i++)
        {
            MemCoins[i] = (long int*)malloc(m*sizeof(long int));
            for(int j=0;j<m;j++){
            MemCoins[i][j] = -1;
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        fscanf(input, "%d", &coins[i]);
        if(coins[i] == 0){
            i--;
            m--;
        }
    }

    printf("%ld\n", Find_Ways(coins, m, n, 0,0, MemCoins));

    for(int i = 0; i < n+1; i++)
        {
            for(int j=0;j<m;j++){
            //printf("%ld ", MemCoins[i][j]);
            }
            //printf("\n");
    }

    free(coins);
    for(int i = 0; i < n+1; i++)
    {
        free(MemCoins[i]);
    }
    free(MemCoins);

    return 0;
}

long int Find_Ways(int *coins, int m, int n, int j, int poziom, long int **MemCoins){
    if(poziom == n){
        return 1;
    }
    else if(j>m-1 || poziom>n){
        return 0;
    }
    else if(MemCoins[poziom][j] > -1){
        return MemCoins[poziom][j];
    }
    else{
        MemCoins[poziom][j]=Find_Ways(coins, m, n, j+1, poziom, MemCoins)+Find_Ways(coins, m, n, j, poziom+coins[j], MemCoins);
        return MemCoins[poziom][j];
    }
}
