#include <stdio.h>
#include <stdlib.h>
/*
ο πρόγραμμα διαβάζει 10 αριθμούς απο το 0 έως 100 και παράγει έναν νέο πίνακα, που είναι ο αρχικός πίνακας
 ταξινομημένος σε φθίνουσα σειρά, (δηλαδή βρίσκει 1ο μεγαλύτερο, 2ο μεγαλύτερο, ..., 10ο μεγαλύτερο).
 Πρόκειται  για τον αλγόριθμο Bead Sort.
*/
int main(void){
    system("chcp 65001>nul"); // εκτύπωση ελληνικών
    const int M = 100; 
    const int N = 10;   
    int table_A[N];
    int table_B[N];
    int choice;
    int sum = 0 ;
    int size_table_A = sizeof(table_A)/sizeof(table_A[0]);
    int size_table_B = sizeof(table_B)/sizeof(table_B[0]);
    int table_counts[M+1];
    for (int i = 0; i <= M; i++) table_counts[i] = 0;

        // Δίαβάζει τον table_Α ( ύψος της στήλης για κάθε στοιχείο)
        for (int i = 0; i < N; i++){ 
        while (1)
        {
            printf("Εισάγετε το στοιχείο %d (επιτρεπόμενες τιμές απο 0 έως 100)\n" , i+1 );
            if(scanf("%d" , &table_A[i]) != 1){
                printf("Η τιμή πρέπει να είναι απο 0 έως 100. Ξαναπροσπάθησε\n");
                while ((choice = getchar()) != '\n' && choice != EOF) {}
                continue;
            }

            if(table_A[i] < 0 || table_A[i] > M){
                printf("Η τιμή πρέπει να είναι απο 0 έως 100. Ξαναπροσπάθησε\n");
                continue;
            }
            break;
        }
    }
    // Δημιουργία ενδιάμεσου πίνακα table_counts (αριθμός χάντρων σε κάθε επίπεδο)
    for (int i = 0; i < size_table_A; i++){
        for(int j = 0; j < table_A[i]; j++){
            table_counts[j]++;
        }
    }

    // Δημιουργία table_B (εδω οι χάντρες πέφτουν)
    for( int k = 1; k <= N; k++){
        for(int j = 0; j <=M; j++){
            if(table_counts[j] >= N - k + 1) 
            sum++;
        }
        table_B[k - 1] = sum; 
        sum = 0;   
    }
     //Εκτύπωση στοιχείων table_B
     for(int i = 0; i < size_table_B; i++){
        printf("Το στοιχείο %d είναι ίσο %d\n", i+1, table_B[i] );
     }
}   