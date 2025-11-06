#include <stdio.h>
#include <string.h>
// Structure to store product information
struct Product {
    char name[50];
    float price;
};
// Function to swap two products
void swap(struct Product *a, struct Product *b) {
    struct Product temp = *a;
    *a = *b;
    *b = temp;
}
// Partition function for Quick Sort
int partition(struct Product products[], int low, int high) {
    float pivot = products[high].price; // Pivot element
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (products[j].price <= pivot) { // Sorting in ascending order
            i++;
            swap(&products[i], &products[j]);
      }
    }
    swap(&products[i + 1], &products[high]);
    return i + 1;
}
// Quick Sort function
void quickSort(struct Product products[], int low, int high) {
    if (low < high) {
        int pi = partition(products, low, high);
        quickSort(products, low, pi - 1);   // Sort left sub-array
        quickSort(products, pi + 1, high);  // Sort right sub-array
    }}
// Function to display the list of products
void displayProducts(struct Product products[], int n) {
    printf("\nSorted Product List by Price:\n");
    printf("-----------------------------\n");
    printf("Name\t\tPrice\n");
    printf("-----------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-15s %.2f\n", products[i].name, products[i].price);
    }}
int main() {
    struct Product products[] = {
        {"Laptop", 45000},
        {"Smartphone", 22000},
        {"Headphones", 1500},
        {"Smartwatch", 5000},
        {"Camera", 28000}
    };
    int n = sizeof(products) / sizeof(products[0]):
    printf("E-Commerce Product Sorting System\n");
    // Sort products using Quick Sort
    quickSort(products, 0, n - 1);
    // Display sorted products
    displayProducts(products, n);
    return 0;
}
