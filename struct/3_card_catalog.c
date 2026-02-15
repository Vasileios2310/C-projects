/* Electronic catalog card */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
void read_line(char *buf , size_t size);
int str_casecmp(const char *a , const char *b);
void load(void);
int menu(void);
void enter(void);
void display(int i);
void author_search(void);
void title_search(void);
void save(void);


struct catalog{
    char name[80];
    char title[80];
    char publisher[80];
    unsigned date;
    unsigned char edition;
} catalog[MAX];

/* last used position */
int top = 0;

int main(void){

    int choice;
    load();

    do{
        choice = menu();
        switch (choice)
        {
        case 1 : enter() ;
            break;
        case 2 : author_search() ;
            break;
        case 3 : title_search() ;
            break;
        case 4 : save() ;
            break;
        default:
            break;
        }
    }while (choice !=5);
    {
        return 0;
    }
}

int str_casecmp(const char *a , const char *b)
{
    unsigned char ca , cb;

    while (*a && *b)
    {
        ca = (unsigned char)tolower((unsigned char)*a);
        cb = (unsigned char)tolower((unsigned char)*b);

        if (ca != cb) return (int)ca - (int)cb;
        a++;
        b++;
    }
    ca = (unsigned char)tolower((unsigned char)*a);
    cb = (unsigned char)tolower((unsigned char)*b);
}

void read_line(char *buf , size_t size)
{
    if(fgets(buf , size , stdin ) == NULL){
        buf[0] = '\0';  // treat EOF/error as empty input
        return;
    }
    buf[strcspn(buf , "\n") ] = '\0';   // remove trailing newline if present
}

/* load catalogue data*/
void load(void)
{
    FILE *fp = fopen("catalog", "rb");
    if (fp == NULL) {
        top = 0;          // no file yet, empty catalog
        return;
    }

    if (fread(&top, sizeof top, 1, fp) != 1) {
        printf("Error in reading count\n");
        fclose(fp);
        exit(1);
    }

    if (top > MAX) {
        printf("Catalog file corrupt\n");
        fclose(fp);
        exit(1);
    }

    if (fread(catalog, sizeof *catalog, top, fp) != (size_t)top) {
        printf("Error in reading catalog data\n");
        fclose(fp);
        exit(1);
    }
    fclose(fp);
}

/* returns a choice from menu*/
int menu(void){
    int i = 1;
    char str[80];

    printf("Card catalog:\n");
    printf(" 1. Enter\n");
    printf(" 2. Search by author\n");
    printf(" 3. Search by title\n");
    printf(" 4. Save catalog\n");
    printf(" 5. Quit\n");

    do{
        printf("Choose rour selection : ");
        read_line(str , sizeof str);
        i = atoi(str);  // atoi converts a string into an integer numerical presentation
        printf("\n");
    }while (i < 1 || i >5);    
    return i;
}

/* Insert books in database */
void enter(void){
    int i ;
    char temp[80];  // local buffer - is used as a “temporary string holder”

    for (i = top; i < MAX; i++)
    {
        printf("Enter author name: (ENTER to quit)");
        read_line(catalog[i].name , sizeof catalog[i].name);
        if(!*catalog[i].name) break;

        printf("Enter title: ");
        read_line(catalog[i].title , sizeof catalog[i].title);
        if(!*catalog[i].title) break;

        printf("Enter publisher: ");
        read_line(catalog[i].publisher , sizeof catalog[i].publisher);
        if(!*catalog[i].publisher) break;

        printf("Enter copyright date: ");
        read_line(temp , sizeof temp); //reads the next line the user types (until newline) and stores it as a C-string in temp.
        catalog[i].date = (unsigned) atoi(temp); // converts that string to an int
        
        printf("Enter edition: ");
        read_line(temp , sizeof temp);
        catalog[i].edition = (unsigned char) atoi(temp);
    }
    top = i;
}

/* display the content of catalogue*/
void display(int i)
{
    printf("%s\n" , catalog[i].title);
    printf("by %s\n" , catalog[i].name);
    printf("Published by %s\n" , catalog[i].publisher);
    printf("Copyright: %u , %u edition\n" , catalog[i].date , catalog[i].edition);
}

/* search by author*/
void author_search(void)
{
    char name[80];
    int i , found;

    printf("Name : ");
    read_line(name , sizeof name);

    found = 0; // not match yet

    for (i = 0; i < top; i++)
        if(str_casecmp(name , catalog[i].name) == 0){ // used to compare two strings , returns 0 if the strings are exactly equal
            display(i);
            found = 1;
            printf("\n");
        }
    if(!found) printf("Not found\n");
}

/* search by title*/
void title_search(void)
{
    char title[80];
    int i , found;

    printf("Title :");
    read_line(title , sizeof title);

    found = 0;

    for (i = 0; i < top; i++)   // top is  “how many records are actually filled” marker
        if(strcmp(title , catalog[i].title) == 0){
            display(i);
            found = 1;
            printf("\n");
        }
    if(!found) printf("Not found");
}

/* save the file of catalogue
example -->     
            read top → gets 2
            read 2 structs into catalog[0] and catalog[1]
*/
void save (void)
{
    FILE *fp;
    if((fp = fopen("catalog" , "wb")) == NULL){
        printf("Can not open catalog file\n");
        exit(1);
    }
    // write how many records you have (top)
    if(fwrite(&top , sizeof top , 1 , fp) != 1){
        printf("Error writing count\n");
        exit(1);
    }
    // write the array of structs
if (fwrite(catalog, sizeof *catalog, top, fp) != (size_t)top) {
    printf("Error writing catalog data\n");
    fclose(fp);
    exit(1);
}
    fclose(fp);
}