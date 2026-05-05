#include <stdio.h>
#include <stdlib.h>

#define N 3          // number of months
#define CATEGORY 5   // number of expense categories

/*
 * Inserts expense values into the array.
 * Checks that the user does not enter negative values.
 * The values are stored by expense category and by month.
 */
void insertExpenses(int expenses[CATEGORY][N])
{
    char *categories[CATEGORY] = {
        "Shared electricity",
        "Shared water",
        "Elevator maintenance",
        "Cleaning services",
        "Heating expenses"
    };

    int i, j, data;

    for (i = 0; i < CATEGORY; i++) {
        for (j = 0; j < N; j++) {
            do {
                printf("Enter a positive expense amount for category '%s' and month %d: ",
                       categories[i], j + 1);

                scanf("%d", &data);

                if (data < 0) {
                    printf("Negative expense values are not allowed!\n");
                }

            } while (data < 0);

            expenses[i][j] = data;
        }
    }
}

/*
 * Traverses the expenses array and prints the expense table.
 * For each category, it prints the category name and the amount for each month.
 */
void printExpenses(int expenses[CATEGORY][N])
{
    int i, j;

    char *categories[CATEGORY] = {
        "Shared electricity",
        "Shared water",
        "Elevator maintenance",
        "Cleaning services",
        "Heating expenses"
    };

    printf("\n---------- EXPENSE TABLE ----------\n\n");

    printf("%-25s %10s %10s %10s\n", "", "Month 1", "Month 2", "Month 3");

    for (i = 0; i < CATEGORY; i++) {
        printf("%-25s", categories[i]);

        for (j = 0; j < N; j++) {
            printf("%10d", expenses[i][j]);
        }

        printf("\n");
    }
}

/*
 * Calculates and prints:
 * - the total amount per expense category
 * - the total amount per month
 * - the overall total amount for all expenses
 */
void calcTotal(int expenses[CATEGORY][N])
{
    int i, j;

    int categorySum[CATEGORY] = {0};   // total per category
    int monthSum[N] = {0};             // total per month
    int totalSum = 0;                  // overall total for the three-month period

    char *categories[CATEGORY] = {
        "Shared electricity",
        "Shared water",
        "Elevator maintenance",
        "Cleaning services",
        "Heating expenses"
    };

    for (i = 0; i < CATEGORY; i++) {
        for (j = 0; j < N; j++) {
            categorySum[i] += expenses[i][j];
            monthSum[j] += expenses[i][j];
            totalSum += expenses[i][j];
        }
    }

    printf("\nTotal expense amount per category for 3 months:\n");

    for (i = 0; i < CATEGORY; i++) {
        printf("%s: %d\n", categories[i], categorySum[i]);
    }

    printf("\nTotal expense amount per month:\n");

    for (j = 0; j < N; j++) {
        printf("Month %d: %d\n", j + 1, monthSum[j]);
    }

    printf("\nOverall total amount of all expenses: %d\n", totalSum);
}

/*
 * Calculates and prints:
 * - the average expense per category
 * - the average expense per month
 */
void calculateAverages(int expenses[CATEGORY][N])
{
    int i, j;

    char *categories[CATEGORY] = {
        "Shared electricity",
        "Shared water",
        "Elevator maintenance",
        "Cleaning services",
        "Heating expenses"
    };

    float categoryAverage[CATEGORY] = {0};
    float monthAverage[N] = {0};

    int categorySum[CATEGORY] = {0};
    int monthSum[N] = {0};

    // First, calculate the total amount per category and per month
    for (i = 0; i < CATEGORY; i++) {
        for (j = 0; j < N; j++) {
            categorySum[i] += expenses[i][j];
            monthSum[j] += expenses[i][j];
        }
    }

    // Calculate the average expense per category
    for (i = 0; i < CATEGORY; i++) {
        categoryAverage[i] = (float)categorySum[i] / N;
    }

    // Calculate the average expense per month
    for (j = 0; j < N; j++) {
        monthAverage[j] = (float)monthSum[j] / CATEGORY;
    }

    printf("\nAverage expense per category:\n");

    for (i = 0; i < CATEGORY; i++) {
        printf("%s: %.2f\n", categories[i], categoryAverage[i]);
    }

    printf("\nAverage expense per month:\n");

    for (j = 0; j < N; j++) {
        printf("Month %d: %.2f\n", j + 1, monthAverage[j]);
    }
}

/*
 * Finds and prints the maximum expense value.
 * Also prints the month and category where this maximum value appears.
 */
void findMaxExpense(int expenses[CATEGORY][N])
{
    int max = expenses[0][0];
    int maxMonth = 0;
    int maxCategory = 0;

    for (int i = 0; i < CATEGORY; i++) {
        for (int j = 0; j < N; j++) {
            if (expenses[i][j] > max) {
                max = expenses[i][j];
                maxMonth = j;
                maxCategory = i;
            }
        }
    }

    printf("\n--- Maximum Expense ---\n");
    printf("Amount: %d\n", max);
    printf("Month: %d\n", maxMonth + 1);
    printf("Category: %d\n", maxCategory + 1);
}

/*
 * Calculates and prints the amount each tenant has to pay.
 * The expenses are distributed according to predefined percentages.
 */
void calculatePerPerson(int expenses[CATEGORY][N])
{
    char *categories[CATEGORY] = {
        "Shared electricity",
        "Shared water",
        "Elevator maintenance",
        "Cleaning services",
        "Heating expenses"
    };

    int i, j, k;

    float percentages[4] = {0.10, 0.25, 0.28, 0.37};

    int categorySum[CATEGORY] = {0};
    float totalSumPerPerson[4] = {0};

    // Calculate the total amount per expense category
    for (i = 0; i < CATEGORY; i++) {
        for (j = 0; j < N; j++) {
            categorySum[i] += expenses[i][j];
        }
    }

    // Calculate each tenant's share
    for (k = 0; k < 4; k++) {
        printf("\nTenant %d\n", k + 1);

        for (i = 0; i < CATEGORY; i++) {
            float amount = categorySum[i] * percentages[k];

            printf("%-25s: %.2f\n", categories[i], amount);

            totalSumPerPerson[k] += amount;
        }

        printf("Total: %.2f\n", totalSumPerPerson[k]);
    }
}

int main()
{
    system("chcp 65001>nul"); // enables UTF-8 output on Windows console

    int expenses[CATEGORY][N];

    insertExpenses(expenses);

    printExpenses(expenses);

    calcTotal(expenses);

    calculateAverages(expenses);

    findMaxExpense(expenses);

    calculatePerPerson(expenses);

    return 0;
}