#include <stdio.h>
#include <stdlib.h>
/**
    Το πρόγραμμα διαχειρίζεται έναν πίνακα αποστάσεων N×N για N=5 πόλεις.
    Ζητά από τον χρήστη τις αποστάσεις μόνο για τα ζευγάρια i<j (πάνω δεξιά τμήμα), με έλεγχο ώστε οι τιμές να είναι θετικοί αριθμοί.
    Συμπληρώνει συμμετρικά τον πίνακα (CT[j][i]=CT[i][j]) και θέτει μηδενική την κύρια διαγώνιο.
    Εμφανίζει τον πίνακα αποστάσεων και υπολογίζει τη μικρότερη και τη μεγαλύτερη απόσταση μεταξύ δύο πόλεων.
    Διαβάζει πόλη-αφετηρία (1..N) και υπολογίζει τη συνολική απόσταση ταξιδιού προς όλες τις πόλεις με επιστροφή.
 */
int main(void)
{
    system("chcp 65001>nul"); // εκτύπωση ελληνικών
    int N = 5;
    int choice; 
    double city[N][N];
    double distance;
    int start;

    //Αρχικοποίηση του πίνακα με 0
    for (int i = 0; i<N; i++){
        for (int j = 0; j < N; j++){
            city[i][j] = 0.0;
        }
    }
    //Εμφάνιση αποστάσεων μόνο για το πάνω δεξιά τρίγωνο
    printf("Είσοδο δεδομένων στον πίνακα\n");
    for (int i = 0; i < N; i++){
        for(int j = i +1; j < N; j++){
            while (1)
            {
                printf("Δώσε την απόσταση μεταξύ %dης and %dης πόλης: ", i+1 , j+1);
                if(scanf("%lf" , &distance) != 1){
                    printf("Η απόσταση πρέπει να είναι θετικός αριθμός\n");
                    while ((choice = getchar()) != '\n' && choice != EOF) {}
                    continue;
                }
                //Έλεγχος να είναι η απόσταση αριθμός μεγαλύτερος του 0
                if(distance <= 0.0){
                    printf("Η απόσταση πρέπει να είναι θετικός αριθμός\n");
                    continue;
                }
                //Συμπλήρωση συμμετρικών στοιχείων
                city[i][j] = distance;
                city[j][i] = distance;
                break;
            }
        }
    }
    // Εκτύπωση πίνακα
    printf("\n Εκτύπωση πίνακα\n");
    for(int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            printf("%7.2f" , city[i][j]);
        }
        printf("\n");
    }
    //Εύρεση του min/max απόστασης στο πάνω δεξιά τρίγωνο
    double minDistance = city[0][1];
    double maxDistance = city[0][1];
    // μεταβλητές που θα αποθηκευτουν τα i,j , τα οποία έχουν τις min/max τιμές 
    int minA = 0, minB = 1;
    int maxA = 0, maxB = 1;

    // αποθηκεύουμε τα στοιχεία του πίνακα που έχουν τα min και max 
    for (int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){    
            if(city[i][j] < minDistance) {
                minDistance = city[i][j];
                minA = i;
                minB = j;
            }
            if(city[i][j] > maxDistance){
                maxDistance = city[i][j];
                maxA = i;
                maxB = j;
            }
        }
    }
    // βάζουμε +1 αφου ο πίνακας ξεκινάει απο το 0
    printf("Ελάχιστη απόσταση είναι : %.2f μεταξύ %dης και %dης πόλης\n" , minDistance , minA + 1 , minB + 1);
    printf("Μέγιστη απόσταση είναι : %.2f μεταξύ %dης και %dης πόλης\n" , maxDistance , maxA + 1 , maxB + 1);

    // Επιλογή αφετηρίας με αμυντικό προγραμματισμό
    printf("\n Υπολογισμός ταξιδιού προς ολες τις πόλεις: %d\n", N);

    while(1){
        printf("Δώσε την πόλη - αφετηρία");
        if(scanf("%d" , &start) != 1){
            printf("Η επιλογή σου πρέπει να είναι από 1 έως %d\n", N);
            while ((choice = getchar()) != '\n' && choice != EOF){}
            continue;
        }
        // έλεγχος της τιμής που εισάγει ο χρήστης
        if (start < 1 || start > N) {
            printf("Η επιλογή σου πρέπει να είναι από 1 έως %d\n", N);
            continue;
        }
        break;
    }

    // Υπολογισμός συνολικού ταξιδιού από την αφετηρία προς όλες τις άλλες
    int s = start - 1;
    double sum = 0.0;
    for(int j = 0;  j < N; j++){
        if(j !=s )
        sum += city[s][j]; 
    }
    double trip = 2.0 * sum;

    printf("Το ταξίδι απο την αφετηρία προς ολες τις αλλες πόλεις είναι %.2f km \n" , trip);
}