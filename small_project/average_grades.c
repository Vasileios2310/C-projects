#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_ARTISTS 7
#define NUM_OF_JUDGES 5

/* Ορισμός πινάκων */
int KodikosKallitexni[NUM_OF_ARTISTS];            /* Κωδικός Καλλιτέχνη (ΚΚ) */
int Vathmoi[NUM_OF_ARTISTS][NUM_OF_JUDGES];       /* Βαθμοί από Κριτές */
float TelikosMesosOros[NUM_OF_ARTISTS];           /* Τελικός Μέσος Όρος */

/* Ορισμός συναρτήσεων */
void input_data();       /* Είσοδος ΚΚ και βαθμών */
void compute_average();  /* Υπολογισμός Τελικού Μέσου Όρου */
void print_results();    /* Εμφάνιση Αποτελεσμάτων */
void show_winners();     /* Εμφάνιση Νικητών */

int main()
{
    system("chcp 65001>nul"); // εκτύπωση ελληνικών

    input_data();
    compute_average();
    print_results();
    show_winners();

    return 0;
}

/* Είσοδος ΚΚ και βαθμών */
void input_data()
{
    int i = 1;
    int j = 1;
    int choice_code = 0;
    int choice_grade = 0;
    while (i <= NUM_OF_ARTISTS)
    {
        int j = 1;
        printf("Κωδικός %dου Καλλιτέχνη (10-99): " , i);
            if(scanf("%d" , &choice_code) != 1 ){
            while ((choice_code = getchar()) != '\n' && choice_code != EOF) {}
            continue; 
            }

        if(choice_code < 10 || choice_code > 99 ){
            printf("Λάθος τιμή\n");
            continue;
        }

        KodikosKallitexni[i-1] = choice_code;

            while (j <= NUM_OF_JUDGES)
            {
                printf("Βαθμός Κριτή %d : " , j);
                if(scanf("%d" , &choice_grade) != 1 ){
                while ((choice_grade = getchar()) != '\n' && choice_grade != EOF) {}
                continue; 
                }

                if(choice_grade > 10 || choice_grade < 0 ){
                printf("Λάθος τιμή\n");
                continue;
                }
                Vathmoi[i-1][j-1] = choice_grade;
                 j++;
            }
        i++;
    }
}


/* Υπολογισμός Τελικού Μέσου Όρου (αγνοώντας μέγιστο και ελάχιστο) */
void compute_average()
{
    for (int i = 0; i < NUM_OF_ARTISTS; i++)
    {
        int sum = 0;
        int min = Vathmoi[i][0];
        int max = Vathmoi[i][0];

        for (int j = 0; j < NUM_OF_JUDGES; j++)
        {
            int g = Vathmoi[i][j];
            sum += g;
            if (g < min) min = g;
            if (g > max) max = g;
        }
        TelikosMesosOros[i] = (sum - min - max) / (float)(NUM_OF_JUDGES - 2);
    }
}

/* Εμφάνιση Αποτελεσμάτων */
void print_results(void)
{
    printf("--- ΑΠΟΤΕΛΕΣΜΑΤΑ ΔΙΑΓΩΝΙΣΜΟΥ ΤΡΑΓΟΥΔΙΟΥ ---\n");

    printf(" KK |");
    for (int j = 0; j < NUM_OF_JUDGES; j++){
        printf(" K%d |", j + 1);
    }
    printf(" M.O.\n");

    printf("----|");
    for(int j = 0; j < NUM_OF_JUDGES; j++){
        printf("----|");
    }
    printf("------|\n");

    for(int i = 0; i < NUM_OF_ARTISTS; i++){
        printf("%3d |" , KodikosKallitexni[i]);

        int sum = 0;
        int min = Vathmoi[i][0];
        int max = Vathmoi[i][0];

        for ( int j = 0; j < NUM_OF_JUDGES; j++)
        {
            int g = Vathmoi[i][j];
            printf(" %2d | " , g);

            sum += g;
            if (g < min) min = g;
            if (g > max) max = g;
        }

        float avg = (sum - min - max ) / (float)(NUM_OF_JUDGES - 2);
        printf("%5.2f\n" , avg);
    }
}

/* Εμφάνιση Νικητών */
void show_winners()
{
    float max_avg = -1.0f;
    for(int i = 0; i < NUM_OF_ARTISTS; i++){
        int sum = 0;
        int min = Vathmoi[i][0];
        int max = Vathmoi[i][0];

        

        for ( int j = 0; j < NUM_OF_JUDGES; j++){
            int g = Vathmoi[i][j];

            sum += g;
            if (g < min) min = g;
            if (g > max) max = g;
        }

        float avg = (sum - min - max ) / (float)(NUM_OF_JUDGES - 2);
        if (avg > max_avg) max_avg = avg;
    }
        /*same average*/
        for(int i = 0; i < NUM_OF_ARTISTS; i++){
        int sum = 0;
        int min = Vathmoi[i][0];
        int max = Vathmoi[i][0];
        for ( int j = 0; j < NUM_OF_JUDGES; j++)
        {
            int g = Vathmoi[i][j];

            sum += g;
            if (g < min) min = g;
            if (g > max) max = g;
        }
        float avg = (sum - min - max ) / (float)(NUM_OF_JUDGES - 2);
        if(avg >= max_avg - 0.0001f && avg <= max_avg + 0.0001f){
             printf("ΝΙΚΗΤΗΣ : Καλλιτέχνης με ΚΚ %d =  (M.O. = %.2f\n)" , KodikosKallitexni[i] ,  max_avg);
        }
    }
}