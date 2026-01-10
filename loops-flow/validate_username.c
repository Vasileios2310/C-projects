#include <stdio.h>
#include <string.h>

 int main() {

    char username[20];

    while (1)
    {
        printf("Input a username at least 8 characters\n");
        scanf("%s" , username);

        if (strlen(username) >= 8 ){
            break;
        }
        else{
            printf("Error: Username must contains at least 8 characters\n");
        }

        //Clear the input buffer to handle any remaining characters
        while (getchar() != '\n');
    }

    printf("Valid username entered: %s\n" , username);

    return 0;
    
}