#include <stdio.h>

int main(void)
{
    int N;
    int i;
    long long Sum1 = 0;
    long long Sum2 = 0;
    long long SumTemp = 0;

    do{
        printf("Give a number N (100 to 300)\n");
        scanf("%d" , &N);
    } while (N < 100 || N > 300);
    
    for (i = 1; i <=N; i++){
        Sum1 += (long long)i*i*i;
        SumTemp += i; 
    }

    Sum2 = SumTemp*SumTemp;

    printf("The sum for SUM1 is %lld\n", Sum1);
    printf("The sum for SUM2 is %lld\n", Sum2);

    if (Sum1 == Sum2)
        printf("The theory is valid\n");
    else
        printf("The theory is not valid\n");

    return 0;
}