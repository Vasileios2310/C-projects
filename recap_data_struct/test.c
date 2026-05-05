#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Eating RAM fast...\n");

    while(1)
    {
        size_t size = 900 * 1024 * 1024; // 🔥 200MB κάθε loop

        char *ptr = malloc(size);

        if(ptr == NULL)
        {
            printf("Memory allocation failed!\n");
            break;
        }

        memset(ptr, 1, size); // force πραγματική χρήση RAM

        printf("Allocated 200MB more...\n");
    }

    return 0;
}