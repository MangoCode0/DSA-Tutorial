// #include <stdio.h>
// int Binary_search(int arr[], int L, int H, int T) {
//     if (L <= H) {
//         int mid = L + (H - L) / 2;
//         if (arr[mid] == T) {
//             return mid;
//         }
//         if (arr[mid] < T) {
//             return Binary_search(arr, mid + 1, H, T);
//         }
//          return Binary_search(arr, L, mid - 1, T);
//     }
//     return -1;
// }
// int main() {
//     int arr[] = {3,4,5,6,10,16};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int target = 10;
//     int result = Binary_search(arr, 0, size - 1, target);

//     if (result == -1) {
//         printf("Element is not present in array\n");
//     } else {
//         printf("Element is present at index %d\n", result);
//     }

//     return 0;
// }


#include <stdio.h>

// Function to perform binary search using recursion
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;  // Base case: target is not found
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;  // Target found
    } else if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);  // Search in the left half
    } else {
        return binarySearch(arr, mid + 1, right, target);  // Search in the right half
    }
}

int main() {
    int size, target;
    
    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    // Declare the array and input elements
    int arr[size];
    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input the target value to search for
    printf("Enter the target value to search for: ");
    scanf("%d", &target);
    
    // Perform the binary search
    int result = binarySearch(arr, 0, size - 1, target);
    
    // Output the result
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    
    return 0;
}
