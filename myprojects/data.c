#include <stdio.h>

int main(void)
{

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
            printf("Country %d : Give the number of fires for 2023 (%d to %ld): " , i+1 , MIN_FIRES , MAX_FIRES);
            if(scanf("%d" , &fires_2023[i]) != 1){
                printf("Invalid number. Try again\n");
                while ((choice_2023 = getchar()) != '\n' && choice_2023 != EOF) {}
                continue;
            }

            if(fires_2023[i] < MIN_FIRES || fires_2023[i] > MAX_FIRES){
                printf("Invalid number. Try again\n");
                continue;
            }
            break;
        }
        // data for 2024
        while (1)
        {
            printf("Country %d : Give the number of fires for 2024 (%d to %ld): " , i+1 , MIN_FIRES , MAX_FIRES);
            if(scanf("%d" , &fires_2024[i]) != 1){
                printf("Invalid number. Try again\n");
                while ((choice_2024 = getchar()) != '\n' && choice_2024 != EOF){}
                continue;
            }
            if(fires_2023[i] < MIN_FIRES || fires_2023[i] > MAX_FIRES){
                printf("Invalid number. Try again\n");
                continue;
            }
        break;
        }
    }

    int min2023 = fires_2023[0];
    int max2023 = fires_2023[0];

    for (int i = 1; i < N; i++){
        if(fires_2023[i] < min2023) {
            min2023 = fires_2023[i];
        }
        if(fires_2023[i] > max2023){
            max2023 = fires_2023[i];
        }
    }

    int countIncrease = 0;
    int bestCountry = -1;
    int maxIncrease = 0;

    for (int i = 0; i < N; i++){
        int diff = fires_2024[i] - fires_2023[i];

        if (diff > 0){
            countIncrease++;

            if(bestCountry == -1 || diff > maxIncrease){
                maxIncrease = diff;
                bestCountry = i;
            }
        }
    }

    printf("-----Results from static analysis-----\n");
    printf("Minimun amount for fires in 2023: %d\n",min2023);
    printf("Maximun amount for fires in 2023: %d\n",max2023);
    printf("Amount of countries with increasement in 2024: %d\n", countIncrease);
    
    if (bestCountry == -1){
        printf("No country haw increasment in 2024\n");
    }
    else{
        printf("The country %d with the maximun increasment in 2024 : %d " , bestCountry + 1 , maxIncrease);
    }
}