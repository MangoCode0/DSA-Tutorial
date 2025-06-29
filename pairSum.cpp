#include<iostream>
using namespace std;

int findPairWithSum(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")" << endl;
            }
        }
    }

    return 0;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int target = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    findPairWithSum(arr, n, target);
    return 0;
}






// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans;
//         int n= nums.size();
//         int i=0 , j= n-1;

//         while(i<j){
//             int twoSum = nums[i] + nums[j];
//             if (twoSum > target){
//                 j--;
//             }else if(twoSum < target){
//                 i++;
//             }else{
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 return ans;
//             }
//         }
//         return ans;
//     }
// };