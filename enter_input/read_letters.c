#include <stdio.h>
#include <string.h>
#include <conio.h>
/**
 * 
 */
 int main(void) {

    char ch;
    char letters[11]; 
    int n = 10;
    char temp;

    for (int i = 0; i < 10; i++){
        printf("Enter a character :\n");               
        letters[i] = getche();
        printf("\n");                 
        }
    letters[n] = '\0';

    printf("You enterd: ");
    for(int i = 0; i < 10; i++){
        printf("%c " , letters[i]);
    }
    printf("\n ");
    //Outer loop = how many passes you make over the array
    //Inner loop = the actual walk through comparing neighbors and swapping them
     for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1 - i; j++) {
         if (letters[j] > letters[j + 1]) {
            temp = letters[j];
            letters[j] = letters[j + 1];
            letters[j + 1] = temp;
         }
      }
   }
   
    printf("String after sorting  - %s \n", letters);
    return 0;
}