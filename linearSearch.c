// #include<stdio.h>
// int linearSearch(int arr[], int size, int target) {
//     for (int i = 0; i < size; i++) {
//         if (arr[i] == target) {
//             return i; 
//         }
//     }
//     return -1; 
// }

// int main() {
//     int arr[] = {3,4,5,6, 19, 49};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int target = 10;
//     int result = linearSearch(arr, size, target);

//     if (result == -1) {
//         printf("Element is not present in array\n");
//     } else {
//         printf("Element is present at index %d\n", result);
//     }

//     return 0;
// }

#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index where the target is found
        }
    }
    return -1;  // Return -1 if the target is not found
}

int main() {
    int size, target;
    
    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    // Declare the array and input elements
    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input the target value to search for
    printf("Enter the target value to search for: ");
    scanf("%d", &target);
    
    // Perform the linear search
    int result = linearSearch(arr, size, target);
    
    // Output the result
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    
    return 0;
}
