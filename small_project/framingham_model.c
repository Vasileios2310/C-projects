#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Δείκτες για τον πίνακα των συντελεστών */
#define INDEX_AGE 0
#define INDEX_TC 1
#define INDEX_HDL 2
#define INDEX_SBP_NO_TREATMENT 3
#define INDEX_SBP_TREATMENT 4
#define INDEX_SMOKING 5
#define INDEX_DIABETES 6

//Structure Patient
typedef struct Patient
{
    int sex;
    double age;
    double tc;
    double hdl;
    double sbp;
    int treated;
    int smoking;
    int diabetes;
} Patient;

double framingham_risk_10y(Patient patient);
void risk_category(double risk);

/* Σε όλους τους πίνακες η τιμή δείκτη 0 αφορά τους ΑΝΔΡΕΣ ενώ 1 τις ΓΥΝΑΙΚΕΣ. 
 Πίνακας με τα μηνύματα προς τον χρήστη */

/*Ο μέσος όρος του αθροίσματος των βαρών (βX) για τον μέσο πληθυσμό της μελέτης. */ 
double SUM_BETA_REFERENCES[2] = {23.982 , 26.1931};
/*  Συντελεστές παραγόντων κινδύνου  */
double COEFFICIENTS[2][7] = {
    {3.06117 , 1.12370 , -0.93263 , 1.93303 , 1.99881 , 0.65451 , 0.57367 },
    {2.3288 , 1.20904 , -0.70833 , 2.76157 , 2.82263 , 0.52873 , 0.69154 }
};
/* βασικές τιμές (baseline survival) επιβίωσης στα 10 χρόνια για τον πληθυσμό αναφοράς για κάθε φύλο.*/
double S0[2] = {0.88936 , 0.95012};
/* επιτρεπτά όρια για κάθε παράγοντα κινδύνου*/
double RANGES[8][2] = {
    {0,   1},    // sex
    {18, 110},   // age
    {100, 400},  // tc
    {20, 110},   // hdl
    {60, 220},   // sbp
    {0,   1},    // treated
    {0,   1},    // smoking
    {0,   1}     // diabetes
};

char *PROMPTS[] = {
    "Φύλο (0=Άνδρας, 1=Γυναίκα):",
    "Ηλικία 18-110:",
    "Ολική χοληστερόλη (mg/dL) 100-400:",
    "HDL χοληστερόλη (mg/dL) 20-110:",
    "Συστολική πίεση (mmHg) 60-220:",
    "Υπό αγωγή για υπέρταση; (0=Όχι, 1=Ναι):",
    "Καπνιστής; (0=Όχι, 1=Ναι):",
    "Σακχαρώδης διαβήτης; (0=Όχι, 1=Ναι):"};


/* Δήλωση συναρτήσεων */
int main()
{
    system("chcp 65001>nul"); // εκτύπωση ελληνικών
    float values[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
    Patient p;

    // αμυντικός μηχανισμός για εισαγωγή τιμών και ανάθεση τιμών στο p
    for (int i = 0; i < 8; i++){
        while (1) {
            printf("%s " , PROMPTS[i]);

            if (scanf("%f" , &values[i]) != 1){
                int c;
                while ((c = getchar()) != '\n' && c != EOF){}
                printf("Μη έγκυρη τιμή . Έγκυρες τιμές %.0f - %.0f\n" , RANGES[i][0] , RANGES[i][1]);
                continue;
            }
                if (values[i] < RANGES[i][0] || values[i] > RANGES[i][1]) {
                printf("Μη έγκυρη τιμή. Έγκυρες τιμές %.0f - %.0f\n", RANGES[i][0], RANGES[i][1]);
                continue;
                }
                switch (i)
                {
                case 0 : p.sex = (int)values[i];
                    break;
                case 1 : p.age = values[i];
                    break;
                case 2 : p.tc = values[i];
                    break;
                case 3 : p.hdl = values[i];
                    break;
                case 4 : p.sbp = values[i];
                    break;
                case 5 : p.treated = (int)values[i];
                    break;
                case 6 : p.smoking = (int)values[i];
                    break;
                case 7 : p.diabetes = (int)values[i];
                    break;
                }
                break;
        }
    }
        

    double risk = framingham_risk_10y(p);
    printf("\n\t*****\tΑποτελέσματα\t*****\n");
    printf("Εκτιμώμενος 10ετής καρδιαγγειακός κίνδυνος : %.1lf%%\n", risk);
    risk_category(risk);
    
    return 0;
}

/* Η συνάρτηση που υπολογίζει το ρίσκο και το επιστρέφει*/
double framingham_risk_10y(Patient patient){
    int sex = patient.sex;
    double ln_age = log(patient.age);
    double ln_tc = log(patient.tc);
    double ln_hdl = log(patient.hdl);
    double ln_sbp = log(patient.sbp);

    int sbp_treatment_or_no = (patient.treated == 1) ? INDEX_SBP_TREATMENT : INDEX_SBP_NO_TREATMENT;

    double sum = 0.0;

    sum += COEFFICIENTS[sex][INDEX_AGE] * ln_age;
    sum += COEFFICIENTS[sex][INDEX_TC] * ln_tc;
    sum += COEFFICIENTS[sex][INDEX_HDL] * ln_hdl;
    sum += COEFFICIENTS[sex][sbp_treatment_or_no] * ln_sbp;
    sum += COEFFICIENTS[sex][INDEX_SMOKING] * (double)patient.smoking;
    sum += COEFFICIENTS[sex][INDEX_DIABETES] * (double)patient.diabetes;

       printf("DEBUG: sex=%d age=%.1f tc=%.1f hdl=%.1f sbp=%.1f treated=%d smoking=%d diabetes=%d\n",
       patient.sex, patient.age, patient.tc, patient.hdl, patient.sbp, patient.treated, patient.smoking, patient.diabetes);


    double exp_part = exp(sum - SUM_BETA_REFERENCES[sex]);

    double risk = 1.0 - pow(S0[sex] , exp_part);

    if (risk < 0.0) risk = 0.0;
    if (risk > 1.0) risk = 1.0;

    return risk * 100.0;
}

/* Μετατρέπει την δεκαδική τιμή του ρίσκου σε κατηγορία κινδύνου και την εκτυπώνει */
void risk_category(double risk){
    printf("Κατηγορία κινδύνου : ");

    if (risk < 5.0){
        printf("Χαμηλός κίνδυνος");
    }else if (risk < 10.0)
    {
        printf("Μέτριος κίνδυνος");
    }
    else if (risk < 20.0)
    {
        printf("Υψηλός κίνδυνος");
    }
    else if (risk >= 20.0)
    {
        printf("Πολύ υψηλός κίνδυνος");
    }
}
