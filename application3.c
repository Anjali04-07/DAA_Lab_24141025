#include <stdio.h>
#include <stdlib.h>
void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }}}}
int optimalMerge(int files[], int n) {
    int totalCost = 0;
    for (int i = 0; i < n - 1; i++) {
        sort(files, n - i);
        int first = files[0];
        int second = files[1];
        int mergeCost = first + second;
        totalCost += mergeCost;

        printf("Merging %d and %d → Cost = %d\n", first, second, mergeCost);
        files[0] = mergeCost;
        for (int j = 1; j < n - i - 1; j++)
            files[j] = files[j + 1];
    }
    return totalCost;
}
int main() {
    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);
    int files[n];
    printf("Enter file sizes: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &files[i]);
    int cost = optimalMerge(files, n);
    printf("Total Minimum Cost = %d\n", cost);
    return 0;
}
