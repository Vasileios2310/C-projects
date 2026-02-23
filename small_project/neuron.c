#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Υπολογίζει το άθροισμα 
*/
float neuron(float x1 , float x2 , float w1 , float w2)
{
    float sum;
    sum = w1 * x1 + w2 * x2;
    return sum;
}

/*
    Παίρνει το sum και αφαιρεί το θ (theta) και μετα εφραμόζει την εξίσωση f(𝜉)
*/
float activation(float sum , float theta , float alpha)
{
    float net;
    float y;

    net = sum - theta;
    y = (1.0f - expf(-alpha * net)) / (1.0f + expf(-alpha * net));

    return y;
}

int main(void)
{

    system("chcp 65001>nul"); // εκτύπωση ελληνικών
    float neuron_parameters[7][2];

    int number_of_neurons[2];

    float x1 , x2 , y1 , y2 , y3;

    float sum1 , sum2 , sum3;

    number_of_neurons[0] = 2;
    number_of_neurons[1] = 1;

    for (int row = 0; row < 7; row++){
        for(int column = 0; column < 2; column++){
            neuron_parameters[row][column] = 0.0f;
        }
    }

    printf("");

    printf("Εισαγωγή παραμέτρων 1ου επιπέδου (νευρώνες 1 και 2)\n");

    printf("Δώσε w11: ");
    scanf("%f" , &neuron_parameters[0][0]);

    printf("Δώσε w12: ");
    scanf("%f" , &neuron_parameters[1][0]);

    printf("Δώσε θ1: ");
    scanf("%f" , &neuron_parameters[2][0]);

    printf("Δώσε w21: ");
    scanf("%f" , &neuron_parameters[3][0]);

    printf("Δώσε w22: ");
    scanf("%f" , &neuron_parameters[4][0]);

    printf("Δώσε θ2: ");
    scanf("%f" , &neuron_parameters[5][0]);

    printf("Δώσε α1 (alpha για το 1ο επίπεδο): ");
    scanf("%f" , &neuron_parameters[6][0]);

    printf("Εισαγωγή παραμέτρων 2ου επιπέδου (νευρώνας 3)\n");

    printf("Δώσε w31: ");
    scanf("%f" , &neuron_parameters[0][1]);

    printf("Δώσε w32: ");
    scanf("%f" , &neuron_parameters[1][1]);

    printf("Δώσε θ3: ");
    scanf("%f" , &neuron_parameters[2][1]);

    printf("Δώσε α2 (alpha για το 2ο επίπεδο): ");
    scanf("%f" , &neuron_parameters[6][1]);

    printf("Δώσε τιμή του x1: ");
    scanf("%f" , &x1);

    printf("Δώσε τιμή του x2: ");
    scanf("%f" , &x2);

    sum1 = neuron(x1 , x2 , neuron_parameters[0][0] , neuron_parameters[1][0]);
    
    y1 = activation(sum1 , neuron_parameters[2][0] , neuron_parameters[6][0]);


    sum2 = neuron(x1 , x2 , neuron_parameters[3][0] , neuron_parameters[4][0]);
    
    y2 = activation(sum2 , neuron_parameters[5][0] , neuron_parameters[6][0]);

    sum3 = neuron(y1 , y2 , neuron_parameters[0][1] , neuron_parameters[1][1]);
    
    y3 = activation(sum3 , neuron_parameters[2][1] , neuron_parameters[6][1]);

    printf("\nΥπολογισμος εξοδου του δικτυου...\n");
    printf("Εξοδος 1ου νευρωνα (y1): %f\n", y1);
    printf("Εξοδος 2ου νευρωνα (y2): %f\n", y2);
    printf("Τελικη εξοδος δικτυου (y3): %f\n", y3);

    return 0; 
}