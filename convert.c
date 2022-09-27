
#include <stdio.h>
#include <math.h>
#include <string.h>

int commandList(void) {
    printf("\n\n|- Command List -------------------------------------|");
    printf("\n| 0 - Exit the Program                               |");
    printf("\n| 1 - Find the BMI and Classification                |");
    printf("\n| 2 - Find the Fat Percentage and Classification     |");
    printf("\n| 3 - Find the Maximum Heart Rate (MHR)              |");
    printf("\n| 4 - Find the Target Heart Rate (THR)               |");
    printf("\n| 5 - Find the Target Heart Rate Zone (THR Zone)     |");
    printf("\n| 6 - Find the Maximum Volume Consumption (VO2max)   |");
    printf("\n| 7 - Display Levels of Heart Rate                   |");
    printf("\n|----------------------------------------------------|");
    printf("\n");

    int command;
    printf("\nEnter Command: ");
    scanf("%d", &command);

    return command;
}
void findBMI(float weight, float height) {

    float bmi;
    char class[50];
    int i;

    bmi = weight / pow(height, 2);

    if (bmi < 18.5) {
        strcpy(class, "Underweight");
    } else if (bmi >= 18.5 && bmi <= 22.9) {
        strcpy(class, "Normal");
    } else if (bmi >= 23.0 && bmi <= 24.9) {
        strcpy(class, "At-risk of Obesity");
    } else if (bmi >= 25.0 && bmi <= 29.9) {
        strcpy(class, "Obesity I");
    } else if (bmi >= 30) {
        strcpy(class, "Obesity II");
    }  else {
        strcpy(class, "Not Found");
    }
    
    printf("\nBMI = %.2f kg/m^2", bmi);
    printf("\nClassification = ");
    for (i = 0; i < strlen(class); i++) {
        printf("%c", class[i]);
    }
}; 

void findBodyFat(float bmi, int age, char gender) {
    float ans;
    int g = 0;
    char class[50];

    if (gender == 'M' || gender == 'm') {
        g = 1;
    }

    ans = (1.45 * bmi) + (0.12 * age) - (11.61 * g) - 10.02;

    if (g == 0) { // Female
        if (ans >= 10 && ans <= 12) {
            strcpy(class, "Essential Fat");
        } else if (ans >= 13 && ans <= 20) {
            strcpy(class, "Athletic");
        } else if (ans >= 21 && ans <= 24) {
            strcpy(class, "Fit");
        } else if (ans >= 25 && ans <= 31) {
            strcpy(class, "Acceptable");
        } else if (ans >= 30) {
            strcpy(class, "Obese");
        } else {
            strcpy(class, "Not Found");
        }
    } else { //Male
        if (ans >= 2 && ans <= 4) {
            strcpy(class, "Essential Fat");
        } else if (ans >= 5 && ans <= 13) {
            strcpy(class, "Athletic");
        } else if (ans >= 14 && ans <= 17) {
            strcpy(class, "Fit");
        } else if (ans >= 18 && ans <= 25) {
            strcpy(class, "Acceptable");
        } else if (ans >= 26) {
            strcpy(class, "Obese");
        } else {
            strcpy(class, "Not Found");
        }
    }

    printf("\n%% Fat = %0.2f%%", ans);
    printf("\nClassification = ");
    int i;
    for (i = 0; i < strlen(class); i++) {
        printf("%c", class[i]);
    }
};  

int findMHR(int age) {
    int mhr = 220-age;
    return mhr;
};

void findTHR(int rhr, int age) {
    int mhr = findMHR(age);

    int thr = mhr - rhr; 

    if (rhr < 60) {
        thr *= 0.8;
    } else if (rhr >= 60 && rhr <= 80) {
        thr *= 0.7;
    } else if (rhr > 80) {
        thr *= 0.60;
    }

    thr += rhr;

    printf("THR = %d", thr);
};

void findTHRZone(int rhr, int age) {
    int mhr = findMHR(age);

    int x = mhr - rhr; 

    int from, to;

    from = (x * 0.6) + rhr;
    to = (x * 0.8) + rhr;

    printf("THR Zone = %d to %d", from, to);
};

void findVO2max(float weight, int age, char gender, int time, int hr) {
    float ans;
    int g = 0;
    char rating[50];

    if (gender == 'M' || gender == 'm') {
        g = 1;
    }

    ans = 132.853 - 0.0769 * weight;
    ans -= 0.3877 * age;
    ans += 6.315 * g;
    ans -= 3.2649 * time;
    ans -=  0.1565 * hr;

    if (age >= 13 && age <= 19) {
        if (ans < 35.0) {
            strcpy(rating, "Very Poor");
        } else if (ans >= 35.0 && ans <= 38.3) {
            strcpy(rating, "Poor");
        } else if (ans >= 38.4 && ans <= 45.1) {
            strcpy(rating, "Fair");
        } else if (ans >= 45.2 && ans <= 50.9) {
            strcpy(rating, "Good");
        } else if (ans >= 51.0 && ans <= 55.9) {
            strcpy(rating, "Excellent");
        } else if (ans > 55.9) {
            strcpy(rating, "Superior");
        } 
    } else if (age >= 20 && age <= 29) {
        if (ans < 33.0) {
            strcpy(rating, "Very Poor");
        } else if (ans >= 33.0 && ans <= 36.4) {
            strcpy(rating, "Poor");
        } else if (ans >= 36.5 && ans <= 42.4) {
            strcpy(rating, "Fair");
        } else if (ans >= 42.5 && ans <= 46.4) {
            strcpy(rating, "Good");
        } else if (ans >= 46.5 && ans <= 52.4) {
            strcpy(rating, "Excellent");
        } else if (ans > 52.4) {
            strcpy(rating, "Superior");
        } 
    } else if (age >= 30 && age <= 39) {
        if (ans < 31.5) {
            strcpy(rating, "Very Poor");
        } else if (ans >= 31.5 && ans <= 35.4) {
            strcpy(rating, "Poor");
        } else if (ans >= 35.5 && ans <= 40.9) {
            strcpy(rating, "Fair");
        } else if (ans >= 41.0 && ans <= 44.9) {
            strcpy(rating, "Good");
        } else if (ans >= 45.0 && ans <= 49.4) {
            strcpy(rating, "Excellent");
        } else if (ans > 49.4) {
            strcpy(rating, "Superior");
        } 
    } else if (age >= 40 && age <= 49) {
        if (ans < 30.2) {
            strcpy(rating, "Very Poor");
        } else if (ans >= 30.2 && ans <= 33.5) {
            strcpy(rating, "Poor");
        } else if (ans >= 33.6 && ans <= 38.9) {
            strcpy(rating, "Fair");
        } else if (ans >= 39.0 && ans <= 43.7) {
            strcpy(rating, "Good");
        } else if (ans >= 43.8 && ans <= 48.0) {
            strcpy(rating, "Excellent");
        } else if (ans > 48.0) {
            strcpy(rating, "Superior");
        } 
    } else if (age >= 50 && age <= 59) {
        if (ans < 26.1) {
            strcpy(rating, "Very Poor");
        } else if (ans >= 26.1 && ans <= 30.9) {
            strcpy(rating, "Poor");
        } else if (ans >= 31.0 && ans <= 35.7) {
            strcpy(rating, "Fair");
        } else if (ans >= 35.8 && ans <= 40.9) {
            strcpy(rating, "Good");
        } else if (ans >= 41.0 && ans <= 45.3) {
            strcpy(rating, "Excellent");
        } else if (ans > 45.3) {
            strcpy(rating, "Superior");
        } 
    } else if (age >= 60) {
        if (ans < 20.5) {
            strcpy(rating, "Very Poor");
        } else if (ans >= 20.5 && ans <= 26.0) {
            strcpy(rating, "Poor");
        } else if (ans >= 26.1 && ans <= 32.2) {
            strcpy(rating, "Fair");
        } else if (ans >= 32.3 && ans <= 36.4) {
            strcpy(rating, "Good");
        } else if (ans >= 36.5 && ans <= 44.2) {
            strcpy(rating, "Excellent");
        } else if (ans > 44.2) {
            strcpy(rating, "Superior");
        } 
    }

    printf("\nVO2max = %.2f", ans);
    int i;
    printf("\nRating = ");
    for (i = 0; i < strlen(rating); i++) {
        printf("%c", rating[i]);
    }
}

void levelsOfHeartRate(int rhr, int age) {
    int mhr = findMHR(age);

    int x = mhr - rhr; 

    int ans, i = 50;

    while (i <= 85) {
        if (i == 50 ) {
            printf("\nLEVEL 1 AND 2");
        } else if (i == 65){
            printf("\n\nLEVEL 3");
        } else if (i == 75) {
            printf("\n\nLEVEL 4 AND 5");
        }
        ans = (x *(i *.01)) + rhr;
        printf("\n%d%% - %d bpm", i, ans);
        i += 5;
    }

};