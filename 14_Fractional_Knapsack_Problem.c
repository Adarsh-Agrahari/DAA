// C program to perform fractional Knapsack using greedy approach. 
#include <stdio.h>
#include <stdlib.h>

// Define a structure for items
struct Item {
    int value;
    int weight;
    float ratio;
};

// Function to compare items based on ratio
int compare(const void* a, const void* b) {
    struct Item* itemA = (struct Item*)a;
    struct Item* itemB = (struct Item*)b;
    return (int)(itemB->ratio - itemA->ratio);
}

// Function to perform fractional Knapsack
float fractionalKnapsack(int W, struct Item items[], int n) {
    // Calculate ratio of each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / (float)items[i].weight;
    }
    
    // Sort items based on ratio in descending order
    qsort(items, n, sizeof(struct Item), compare);
    
    float result = 0.0;
    int remainingWeight = W;
    
    // Iterate through items and add to knapsack
    for (int i = 0; i < n; i++) {
        if (remainingWeight >= items[i].weight) {
            result += items[i].value;
            remainingWeight -= items[i].weight;
        } else {
            result += items[i].ratio * (float)remainingWeight;
            break;
        }
    }
    
    return result;
}

// Main function to test fractional Knapsack
int main() {
    int W = 50;  // Knapsack capacity
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};  // Items with values and weights
    int n = sizeof(items) / sizeof(items[0]);  // Number of items
    
    // Calculate maximum value using fractional Knapsack
    float maxValue = fractionalKnapsack(W, items, n);
    
    printf("Maximum value that can be obtained = %f", maxValue);
    
    return 0;
}


// Input:
// Knapsack capacity: 50
// Number of items: 3
// Item 1 value and weight: 60 10
// Item 2 value and weight: 100 20
// Item 3 value and weight: 120 30

// Output:
// Maximum value that can be obtained = 240.000000
