#include <stdio.h>
#include <string.h>

int main() {

    /* Sales table: 5 shops × 6 days */
    int A[5][6];

    /* Minimum sale per day */
    int MIN_AMOUNT_DAY[6];

    /* Average weekly sale for each shop */
    float AVERAGE[5];

    /* Names of the shop directors */
    char DIRECTOR_NAME[5][30];

    /* Names of the working days */
    char DAYS[6][10] = {
        "MONDAY",
        "TUESDAY",
        "WEDNESDAY",
        "THURSDAY",
        "FRIDAY",
        "SATURDAY"
    };

    float GOAL;      /* weekly target */
    float max;       /* maximum average */
    int amount;      /* bonus amount */

    int i,j,h;
    int min;

    /* -------------------------------------------------- */
    /* Read sales for 5 shops and 6 days                  */
    /* Negative sales are not accepted                    */
    /* -------------------------------------------------- */

    for(i=0;i<5;i++){
        for(j=0;j<6;j++){
            do{
                scanf("%d",&A[i][j]);
            }while(A[i][j] < 0);
        }
    }

    /* -------------------------------------------------- */
    /* Read the names of the shop directors               */
    /* -------------------------------------------------- */

    for(i=0;i<5;i++){
        scanf("%s",DIRECTOR_NAME[i]);
    }

    /* -------------------------------------------------- */
    /* Calculate the average weekly sales for each shop   */
    /* -------------------------------------------------- */

    for(i=0;i<5;i++){

        AVERAGE[i] = 0;

        for(j=0;j<6;j++){
            AVERAGE[i] += A[i][j];
        }

        /* divide by number of days */
        AVERAGE[i] = AVERAGE[i] / 6.0;
    }

    /* -------------------------------------------------- */
    /* Read the weekly sales goal                         */
    /* -------------------------------------------------- */

    scanf("%f",&GOAL);

    /* -------------------------------------------------- */
    /* Find the maximum average among all shops           */
    /* -------------------------------------------------- */

    max = AVERAGE[0];

    for(i=1;i<5;i++){
        if(AVERAGE[i] > max)
            max = AVERAGE[i];
    }

    /* -------------------------------------------------- */
    /* Bonus calculation                                  */
    /* If average > goal → bonus 300€                     */
    /* If shop also has the maximum average → double bonus*/
    /* -------------------------------------------------- */

    for(i=0;i<5;i++){

        amount = 0;

        if(AVERAGE[i] > GOAL)
            amount = 300;

        if(AVERAGE[i] == max)
            amount = amount * 2;

        if(amount > 0)
            printf("give %d to %s\n",amount,DIRECTOR_NAME[i]);
    }

    /* -------------------------------------------------- */
    /* Find the minimum sales value for each day          */
    /* -------------------------------------------------- */

    for(j=0;j<6;j++){

        MIN_AMOUNT_DAY[j] = A[0][j];

        for(i=1;i<5;i++){
            if(A[i][j] < MIN_AMOUNT_DAY[j])
                MIN_AMOUNT_DAY[j] = A[i][j];
        }
    }

    /* -------------------------------------------------- */
    /* Shops with the minimum sales need extra staff      */
    /* the next day                                       */
    /* -------------------------------------------------- */

    for(j=0;j<6;j++){
        for(i=0;i<5;i++){

            if(A[i][j] == MIN_AMOUNT_DAY[j]){

                /* determine next day */
                if(j==5)
                    h=0;
                else
                    h=j+1;

                printf("%s needs people for %s\n",
                       DIRECTOR_NAME[i],
                       DAYS[h]);
            }
        }
    }

    /* -------------------------------------------------- */
    /* Find the absolute minimum sale in the whole week   */
    /* -------------------------------------------------- */

    min = A[0][0];

    for(i=0;i<5;i++){
        for(j=0;j<6;j++){
            if(A[i][j] < min)
                min = A[i][j];
        }
    }

    /* -------------------------------------------------- */
    /* Administrative penalty                             */
    /* If the shop with the minimum sale has average      */
    /* below the goal → warning                           */
    /* -------------------------------------------------- */

    for(i=0;i<5;i++){

        int found = 0;

        for(j=0;j<6;j++){
            if(A[i][j] == min)
                found = 1;
        }

        if(found && AVERAGE[i] < GOAL)
            printf("warning to %s\n",DIRECTOR_NAME[i]);
    }

    return 0;
}