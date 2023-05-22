// C program to perform Bin Packing using greedy approach (first fit packing).
#include <stdio.h>

// Function to perform First Fit Packing
void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n]; // Array to store the block allocated to each process
    
    // Initialize all blocks as free
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
    
    // Traverse through all processes
    for (int i = 0; i < n; i++) {
        // Find the first block that can accommodate current process
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                // Allocate block j to process i
                allocation[i] = j;
                
                // Reduce available size of block j
                blockSize[j] -= processSize[i];
                
                // Process i has been allocated, break the inner loop
                break;
            }
        }
    }
    
    // Print the allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("   %d\t\t   %d\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("   %d\n", allocation[i]+1);
        else
            printf("   Not Allocated\n");
    }
}

// Main function
int main()
{
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);
    
    printf("Bin Packing using First Fit Packing algorithm:\n");
    firstFit(blockSize, m, processSize, n);
    
    return 0;
}

// Output
// Bin Packing using First Fit Packing algorithm:

// Process No.     Process Size    Block No.
//    1               212             2
//    2               417             5
//    3               112             2
//    4               426             Not Allocated