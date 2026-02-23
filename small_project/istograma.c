#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Δομή κόμβου
/**
 * 
 * Κάθε κόμβος αποθηκεύει μία ακέραια τιμή (1..100) και δείκτη προς τον επόμενο κόμβο της λίστας
 */
typedef struct Node {
    int data;  // η πληροφορία
    struct Node* next;  // ο δείκτης
} Node;

// --------- Συνάρτηση εισαγωγής νέου κόμβου στο τέλος της λίστας  -------
/**
 * Δεσμεύει δυναμικά μνήμη για έναν νέο κόμβο και τον τοποθετεί στο τέλος της λίστας.
 * Αν η λίστα είναι κενή, ο νέος κόμβος γίνεται η κεφαλή (head).
 */
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
    current -> next = new_node;
}

/**
 * Ο χρήστης εισάγει ακέραιες τιμές στο διάστημα [1,100].
 * Η εισαγωγή τερματίζεται όταν δοθεί 0.
 * Περιλαμβάνει έλεγχο εγκυρότητας.
 */
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


/**
 * Χρησιμοποιείται ο τύπος της τυπικής απόκλισης πληθυσμού (διαίρεση με n).
 */
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
    current = head;
    while(current != NULL){
        double diff = current->data - mean;
        variance_sum += diff * diff;
        current = current->next;
    }
    *stdev = sqrt(variance_sum / n);
    return 1;
}

/**
 * Η συνάρτηση επιστρέφει μέσω δείκτη τη συχνότερη τιμή.
 * Σε περίπτωση ισοπαλίας, επιστρέφεται η πρώτη τιμή με τη μέγιστη συχνότητα.
 */
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
        if(histogram[i] > maxVal){
            maxVal = histogram[i];
            bestVal = i + 1;
        }
    }
    *mode = bestVal;
    return 1;
}


/**
 * Για κάθε τιμή που εμφανίζεται τουλάχιστον μία φορά, εκτυπώνει τιμή με ***
 */
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

/**
 * Εκτυπώνει όλα τα στοιχεία της λίστας.
 */
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

/**
* Διατρέχει τη λίστα κόμβο-κόμβο και καλεί free() για κάθε κόμβο
*/
// -------------------- Main --------------------
int main() {

    system("chcp 65001>nul"); // εκτύπωση ελληνικών
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
