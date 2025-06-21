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

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1; 
    
}

int main() {
    int size, target;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the target value to search for: ");
    scanf("%d", &target);
    
    int result = linearSearch(arr, size, target);
    
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    
    return 0;
}
