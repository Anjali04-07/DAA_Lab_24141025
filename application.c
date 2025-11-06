 #include <stdio.h>
// Structure to store food item information
struct Food {
    char name[50];
    float calories; // Weight equivalent (calorie content)
    float nutrition; // Value (nutrition score)
};// Function to swap two food items
void swap(struct Food *a, struct Food *b) {
    struct Food temp = *a;
    *a = *b;
    *b = temp;
}// Function to sort food items based on nutrition per calorie ratio (descending)
void sortByRatio(struct Food foods[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            float ratio_i = foods[i].nutrition / foods[i].calories;
            float ratio_j = foods[j].nutrition / foods[j].calories;
            if (ratio_i < ratio_j) {
                swap(&foods[i], &foods[j]);
            }
        }
    }
}
// Function to implement Fractional Knapsack
void fractionalKnapsack(struct Food foods[], int n, float calorieLimit) {
    float totalNutrition = 0;
    printf("\nSelected Foods for Optimal Nutrition:\n");
    printf("------------------------------------\n");
    printf("Food\t\tCalories\tNutrition\tFraction\n");
    for (int i = 0; i < n; i++) {
        if (calorieLimit == 0)
            break;
        if (foods[i].calories <= calorieLimit) {
            // Take the whole food item
            calorieLimit -= foods[i].calories;
            totalNutrition += foods[i].nutrition;
            printf("%-15s %.2f\t%.2f\t%.2f\n", foods[i].name, foods[i].calories, foods[i].nutrition, 1.0);
        } else {
            // Take a fraction of the food item
            float fraction = calorieLimit / foods[i].calories;
            totalNutrition += foods[i].nutrition * fraction;
            printf("%-15s %.2f\t%.2f\t%.2f\n", foods[i].name, foods[i].calories, foods[i].nutrition, fraction);
            calorieLimit = 0; // Knapsack is full
        }
    }

    printf("\nTotal Nutrition Value Achieved: %.2f\n", totalNutrition);
}
int main() {
    struct Food foods[] = {
        {"Apple", 95, 50},
        {"Banana", 105, 60},
        {"Chicken", 250, 200},
        {"Egg", 70, 65},
        {"Almonds", 160, 150}
    };
    int n = sizeof(foods) / sizeof(foods[0]);
    float calorieLimit;
    printf("Diet Optimization / Nutrition Planning\n");
    printf("--------------------------------------\n");
    printf("Enter your daily calorie limit: ");
    scanf("%f", &calorieLimit);
    // Sort foods based on nutrition per calorie ratio
    sortByRatio(foods, n);
    // Apply Fractional Knapsack
    fractionalKnapsack(foods, n, calorieLimit);
return 0;
}
