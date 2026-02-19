#include <stdio.h>
#include <stdlib.h>
/**
 * Το πρόγραμμα διαβάζει αριθμό πυρκαγιών για 8 χώρες για τα έτη 2023/2024
 *  και υπολογίζει min/max για το 2023, πόσες χώρες είχαν αύξηση το 2024 και ποια είχε τη μεγαλύτερη αύξηση.
 */
int main(void)
{

    system("chcp 65001>nul"); // εκτύπωση ελληνικών
    const int N = 8;

    int N = 8;
    
    int choice_2023;
    int choice_2024;
    const int MIN_FIRES = 100;
    const long MAX_FIRES = 50000;    
    int fires_2023[N];
    int fires_2024[N];

    for (int i = 0; i < N; i++){
        // data for 2023
        while (1)
        {
            printf("Χώρα %d : Δώσε αριθμό πυρκαγιών για το 2023 (%d έως %ld): " , i+1 , MIN_FIRES , MAX_FIRES);
            if(scanf("%d" , &fires_2023[i]) != 1){
                printf("Μη έγκυρη τιμή. Ξαναπροσπάθησε\n");
                while ((choice_2023 = getchar()) != '\n' && choice_2023 != EOF) {}
                continue;
            }

            if(fires_2023[i] < MIN_FIRES || fires_2023[i] > MAX_FIRES){
                printf("Μη έγκυρη τιμή. Ξαναπροσπάθησε\n");
                continue;
            }
            break;
        }
        // data for 2024
        while (1)
        {
            printf("Χώρα %d : Δώσε αριθμό πυρκαγιών για το 2024 (%d έως %ld):  " , i+1 , MIN_FIRES , MAX_FIRES);
            if(scanf("%d" , &fires_2024[i]) != 1){
                printf("Μη έγκυρη τιμή. Ξαναπροσπάθησε\n");
                while ((choice_2024 = getchar()) != '\n' && choice_2024 != EOF){}
                continue;
            }
            if(fires_2024[i] < MIN_FIRES || fires_2024[i] > MAX_FIRES){
                printf("Μη έγκυρη τιμή. Ξαναπροσπάθησε\n");
                continue;
            }
        break;
        }
    }

    //Επιλέγουμε τυχαία το min και max απο τον πινακα για το 2023
    int min2023 = fires_2023[0];
    int max2023 = fires_2023[0];

    //Με σύγκριση βρίσκουμε το min και max
    for (int i = 1; i < N; i++){
        if(fires_2023[i] < min2023) {
            min2023 = fires_2023[i];
        }
        if(fires_2023[i] > max2023){
            max2023 = fires_2023[i];
        }
    }

    //Αρχικοποίση μεταβλητών
    int countIncrease = 0;
    int bestCountry = -1;
    int maxIncrease = 0;

    // Υπολογίζει πόσες χώρες είχαν αύξηση το 2024
    for (int i = 0; i < N; i++){
        int diff = fires_2024[i] - fires_2023[i];

        // αν η διαφορά ειναι θετική , μετράει τη χώρα
        if (diff > 0){
            countIncrease++;

            // Κρατάει τη χώρα με τη μεγαλύτερη αύξηση
            if(bestCountry == -1 || diff > maxIncrease){
                maxIncrease = diff;
                bestCountry = i;
            }
        }
    }

    printf("-----Αποτέλεσμα στατικής ανάλυσης-----\n");
    printf("Μικρότερος αριθμός πυρκαγιών για το 2023: %d\n",min2023);
    printf("Μεγαλύτερος αριθμός πυρκαγιών για το 2023: %d\n",max2023);
    printf("Αριθμός χωρών με αύξηση πυρκαγιών το 2024: %d\n", countIncrease);
    
    if (bestCountry == -1){
        printf("Καμία χώρα δεν είχε αύξηση το 2024\n");
    }
    else{
        printf("Η χώρα %d είχε τη μεγαλύτερη αύξηση πυρκαγιών : %d " , bestCountry + 1 , maxIncrease);
    }
}