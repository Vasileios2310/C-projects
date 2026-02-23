#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Δομή κόμβου
typedef struct Node {
    int data;  // η πληροφορία
    struct Node* next;  // ο δείκτης
} Node;



// --------- Συνάρτηση εισαγωγής νέου κόμβου στο τέλος της λίστας  -------
void insert_end(Node** head , int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Σφάλμα στη δημιουργία νέου κόμβου.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
        return;
    }
    Node* current = *head;
    while (current-> next != NULL)
    {
        current = current->next;
    }
}


// ------------- Συνάρτηση δημιουργίας της λίστας --------------------
Node* create_list() {
    Node* head = NULL;
    int n;
    while (1)
    {
        printf("Δώστε ενα ακέραιο απο το 1 εως 100, διαφορετικά 0 για έξοδο: ");
        if(scanf("%d" , &n) != 1){
            printf("Ο αριθμός που δώσατε δεν είναι έγκυρος. Παρακαλώ εισάγετε έναν ακέραιο αριθμό.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF){ }
            continue;
        }
        if(n == 0){
            break;
        }
        if(n < 1 || n > 100){
            printf("Ο αριθμός πρέπει να είναι μεταξύ 1 και 100. Παρακαλώ δοκιμάστε ξανά.\n");
            continue;
        }
        insert_end(&head, n);
    }
    return head;    
}



// -------------------- Υπολογισμός τυπικής απόκλισης --------------------
int calculate_std_dev(Node* head, double* stdev) {
    if(head == NULL){
        printf("Η λίστα είναι κενή. Δεν μπορεί να υπολογιστεί η τυπική απόκλιση\n");
        return 0;
    }
    int n = 0;
    double sum = 0.0;
    Node* current = head;
    while(current != NULL){
        sum += current->data;
        n++;
        current = current->next;
    }

    double mean = sum / n;
    double variance_sum = 0.0;
    while(current != NULL){
        double diff = current->data - mean;
        variance_sum += diff * diff;
        current = current->next;
    }
    *stdev = sqrt(variance_sum / n);
    return 1;
}




// -------------------- Υπολογισμός ιστογράμματος --------------------
int build_histogram(Node* head , int histogram[100] , int* mode) {
    if(head == NULL){
        printf("Η λίστα είναι κενή. Δεν μπορεί να υπολογιστεί η τυπική απόκλιση\n");
        return 0;
    }
    for(int i = 0; i < 100; i++){
        histogram[i] = 0;
    }
    Node* current = head;
    while (current != NULL)
    {
        int val = current->data;
        histogram[val - 1]++;
        current = current->next;
    }

    int maxVal = histogram[0];
    int bestVal = 1;

    for(int i= 1; i < 100; i++){
        if(histogram[0] > maxVal){
            maxVal = histogram[i];
            bestVal = i + 1;
        }
    }
    *mode = bestVal;
    return 1;
}


// -------------------- Εκτύπωση ιστογράμματος --------------------
void print_histogram(int histogram[100]){
    for(int i = 0; i < 100; i++){
        if(histogram[i] > 0){
            printf("%d" , i + 1);
            for(int j = 0; j < histogram[i]; j++){
                printf("*");
            }
            printf("\n");
        }
    }
}


// -------------------- Εκτύπωση λίστας --------------------
void print_list( Node* head) {
    printf("Λιστα : [");

    Node* current = head;
    while (current != NULL)
    {
        printf("%d" , current->data);
        if (current -> next != NULL){
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}



// -------------------- Απελευθέρωση μνήμης --------------------
void free_list(Node* head) {
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

// -------------------- Main --------------------
int main() {
    Node* list = create_list();

    print_list(list);

    // Υπολογισμός τυπικής απόκλισης
    double stdev;
    if (calculate_std_dev(list, &stdev)) {
        printf("Τυπική απόκλιση: %.2f\n", stdev);
    }

    // Υπολογισμός ιστογράμματος και συχνότερη τιμής
    int histogram[100];
    int mode;
    if (build_histogram(list, histogram, &mode)) {
        printf("Συχνότερη τιμή: %d\n", mode);
        print_histogram(histogram);
    }

    // Απελευθέρωση μνήμης
    free_list(list);

    return 0;
}
