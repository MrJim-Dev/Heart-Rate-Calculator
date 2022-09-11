#include <stdio.h>
#include "convert.h"
//#include "convert.c" // For Non-C Compilers


int main() {

    int command, exit = 0;
    float weight, height, bmi;

    char gender;
    int age, rhr; 
    int time, hr;

    while (exit == 0) {
        command = commandList();
        switch (command) {
        case 0:
            printf("Thank you for using the program!");
            exit = 1;
            break;
        case 1:
            printf("Enter weight (in kg): ");
            scanf("%f", &weight);
            printf("Enter height (in meters): ");
            scanf("%f", &height);

            findBMI(weight, height);

            break;
        case 2:
            printf("Enter BMI: ");
            scanf("%f", &bmi);
            printf("Age: ");
            scanf("%d", &age);
            printf("Gender (M or F): ");
            scanf(" %c", &gender);


            findBodyFat(bmi, age, gender);

            break;
        case 3:
            printf("Enter age: ");
            scanf("%d", &age);
            printf("\nMHR = %d", findMHR(age));
            break;
        case 4:
            printf("Enter Resting Heart Rate (RHR): ");
            scanf("%d", &rhr);
            printf("Enter age: ");
            scanf("%d", &age);

            findTHR(rhr, age);
        
            break;
        case 5:
            printf("Enter Resting Heart Rate (RHR): ");
            scanf("%d", &rhr);
            printf("Enter age: ");
            scanf("%d", &age);

            findTHRZone(rhr, age);
        
            break;

        case 6: 
    
            printf("Enter weight (in lbs): ");
            scanf("%f", &weight);
            printf("Enter age: ");
            scanf("%d", &age);
            printf("Gender (M or F): ");
            scanf(" %c", &gender);
            printf("Enter time of completion (in minutes): ");
            scanf("%d", &time);
            printf("Heart Rate After: ");
            scanf("%d", &hr);

            findVO2max(weight, age, gender, time, hr);
        
            break;
        default:
            printf("Invalid Command! Please try again.");
            break;
        }
    }

    return 0;
}