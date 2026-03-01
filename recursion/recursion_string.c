#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

char *RevStr(int count , char *str)
{
    char Value;

    if(count)
    {
        Value = str[count - 1];// the last character
        RevStr(count - 1 , str);
        str[strlen(str) - count] = Value; // symmetric from start position , char N takes value ) and goes first in str
    }
    return (str);
}

int main()
{
   
    char Test[10] = "SIBERIAN";
    char Out[10];
    printf("Value of test : %s\n" , Test);
    strcpy(Out , RevStr(strlen(Test) , Test));
    printf("Value of Out: %s\n" , Out);
    system("PAUSE");
    return 0;
}