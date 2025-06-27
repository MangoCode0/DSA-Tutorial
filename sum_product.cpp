#include <iostream>
using namespace std;

int sumAndProduct(int arr[], int n){
    int sum = 0;
    int product = 1;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        product *= arr[i];
    }
    return sum + product;
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = sumAndProduct(arr, n);
    cout << "The sum and product of the array elements is: " << result << endl;
    return 0;   
}
