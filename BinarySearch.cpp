#include <iostream>
using namespace std;

int binarySearch(int arr[], int &n, int &t){
    int st =0 , end = n-1;

    while(st<end){
        int mid = st + (end-st)/2;
        if(arr[mid] == t){
            return mid;
        }
        else if(arr[mid] < t){
            st = mid +1;
        }else{
            end = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[]= {1,2,3,4,5,6,7,8,9};
    int n = 9;
    int t = 8;
    int result = binarySearch(arr,n,t);
    cout<<"value found at index: "<<result;
}
