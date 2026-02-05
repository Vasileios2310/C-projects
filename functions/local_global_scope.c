/*
A variable created inside a function belongs to the local scope of that function, and can only be used inside that function
A local variable cannot be used outside the function it belongs to
*/

// global_varaible
#include <stdio.h>

int z = 555;

void myFunction(int x){
    x = 5;
    printf("%d", ++x);
}

int main(){
    int y = 8;

    myFunction(y);
    printf("\n");
    printf("Global variable : %d\n", z);

    return 0;
}
