

#include<stdio.h>
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;  
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid; 
    } else if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);  
    } else {
        return binarySearch(arr, mid + 1, right, target); 
        
    }
}

int main() {
    int size, target;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the target value to search for: ");
    scanf("%d", &target);
    
    int result = binarySearch(arr, 0, size - 1, target);
    
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    
    return 0;
}
