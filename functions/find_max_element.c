#include <stdio.h>

#define MAX 100

int findMaxElement(int []);
int n;

int main()
{
    int arr1[MAX];
    int i;
    int maxElement;

    printf("\n\n Function : get largest element of an array :\n");
	printf("-------------------------------------------------\n"); 

    printf(" Input the number of elements to be stored in the array :");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid n. Must be between 1 and %d.\n", MAX);
        return 1;
    }
   
    printf(" Input %d elements in the array :\n", n);

    for (i = 0; i<n; i++)
    {
        printf(" element - %d" , i);
        scanf("%d", &arr1[i]);
    }
    maxElement = findMaxElement(arr1);
    printf("The largest element in the array is : %d\n\n" , maxElement);
    return 0;
}

int findMaxElement(int arr1[])
{
    int maxElem;
    int i = 1;
    maxElem = arr1[0];

    while (i < n)
    {
        if (maxElem < arr1[i])
        
            maxElem = arr1[i];
        i++;
    }
    return maxElem;
}