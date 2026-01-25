#include <stdio.h>

int main (void)
{
    char *ch, c;
    int *ip , i;
    double *dp , d;
    float *fp , f;

    ch = &c;
    ip = &i;
    dp = &d;
    fp = &f;

    /* print current values */
    printf("%p %p %p %p ", ch , ip , dp , fp);
 
    /* increace by 1 */
    ch++;   // 1 byte
    ip++;   // 4 bytes
    dp++;   // 8 bytes
    fp++;   // 4 bytes

    printf("\n");
    /* print new values */
    printf("%p %p %p %p ", ch , ip , dp , fp);


    printf("\nchar=%zu int=%zu float=%zu double=%zu\n",
       sizeof(char), sizeof(int), sizeof(float), sizeof(double));

}