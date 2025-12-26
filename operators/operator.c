 #include <stdio.h>

 int main(){

    int x = 10;
    int y = 2;
    int z = 0;

    //z = x / 2;
    //z = x % 2;

    //x += 2; //12
    //x -= 2; //10
    //x *= 2; //20
    //x /= 2;

    x = y++;

    printf("x = %d  \n" , x);
    printf("y = %d  \n" , y);

    x = ++y;

    printf("x = %d  \n" , x);
    printf("y = %d  \n" , y);
 }