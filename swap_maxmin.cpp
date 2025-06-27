#include<iostream>
using namespace std;
void swapMaxMin(int arr[], int n) {
    if (n < 2) return; // No need to swap if less than 2 elements

    int maxIndex = 0, minIndex = 0;

    // Find indices of max and min elements
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap the max and min elements
    swap(arr[maxIndex], arr[minIndex]);
}
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    swapMaxMin(arr, n);

    cout << "Array after swapping max and min elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}