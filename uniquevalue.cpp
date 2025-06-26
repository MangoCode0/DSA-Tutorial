#include<iostream>
using namespace std;
void uniqueValue(int arr[],int n){
    int unique= 0;
    for (int i=0; i<n; i++){
        unique ^= arr[i];
    }
    cout << "The unique element is: " << unique << endl;
}
int main(){
    int arr[] = {1, 2, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    uniqueValue(arr, n);
    return 0;
}