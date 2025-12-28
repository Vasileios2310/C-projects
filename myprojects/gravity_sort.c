#include <stdio.h>

int main(void){

    const int M = 100;  // columns
    const int N = 10;   // raws
    int table_A[N];
    int table_B[N];
    int choice;
    int sum = 0 ;
    int size_table_A = sizeof(table_A)/sizeof(table_A[0]);
    int size_table_B = sizeof(table_B)/sizeof(table_B[0]);
    int table_counts[M+1];
    for (int i = 0; i <= M; i++) table_counts[i] = 0;
    

        // read table_A
        for (int i = 0; i < N; i++){ 
        while (1)
        {
            printf("Insert the element %d (valid numbers from 0 to 100)\n" , i+1 );
            if(scanf("%d" , &table_A[i]) != 1){
                printf("The value must be 0 to 100. Please Try again\n");
                while ((choice = getchar()) != '\n' && choice != EOF) {}
                continue;
            }

            if(table_A[i] < 0 || table_A[i] > M){
                printf("The value must be 0 to 100. Please Try again\n");
                continue;
            }
            break;
        }
    }
    // count table_counts

    for (int i = 0; i < size_table_A; i++){
        //printf("%d\n" , table_A[i]);
        for(int j = 0; j < table_A[i]; j++){
            table_counts[j]++;
            //printf("%d\n" , table_counts[j]);
        }
    }

    // create table_B
    for( int k = 1; k <= N; k++){
        for(int j = 0; j <=M; j++){
            if(table_counts[j] >= N - k + 1) 
            sum++;
        }
        table_B[k - 1] = sum; 
        sum = 0;
        
    }

     //print table_B elements
     for(int i = 0; i < size_table_B; i++){
        printf("the element %d is equal to %d\n", i+1, table_B[i] );
     }
}   