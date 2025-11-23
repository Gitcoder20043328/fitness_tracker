#include <stdio.h>
#include <string.h>

struct Fitness {
    char name[30];
    int steps;
    float calories;
    float sleep;
};

int main() {
    struct Fitness user[50];
    int n, i, choice;
    float totalSteps = 0, totalCalories = 0, totalSleep = 0;

    printf("=== PERSONAL FITNESS TRACKER ===\n");
    printf("Enter number of records you want to store: ");
    scanf("%d", &n);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Add Records\n");
        printf("2. Display Records\n");
        printf("3. Show Average Stats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                for(i=0; i<n; i++) {
                    printf("\nEnter Name: ");
                    scanf("%s", user[i].name);
                    printf("Enter Steps Walked: ");
                    scanf("%d", &user[i].steps);
                    printf("Enter Calories Burned: ");
                    scanf("%f", &user[i].calories);
                    printf("Enter Sleep Hours: ");
                    scanf("%f", &user[i].sleep);
                }
                break;

            case 2:
                printf("\n--- Fitness Records ---\n");
                printf("Name\tSteps\tCalories\tSleep\n");
                for(i=0; i<n; i++) {
                    printf("%s\t%d\t%.2f\t\t%.1f\n", user[i].name, user[i].steps, user[i].calories, user[i].sleep);
                }
                break;

            case 3:
                for(i=0; i<n; i++) {
                    totalSteps += user[i].steps;
                    totalCalories += user[i].calories;
                    totalSleep += user[i].sleep;
                }
                printf("\n--- Average Stats ---\n");
                printf("Average Steps: %.0f\n", totalSteps/n);
                printf("Average Calories: %.2f\n", totalCalories/n);
                printf("Average Sleep Hours: %.2f\n", totalSleep/n);
                break;

            case 4:
                printf("\nExiting Program... Stay Fit!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 4);

    return 0;
}