#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 0, end = arr.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Check if mid is the peak
            if (arr[mid - 1] <= arr[mid] && arr[mid + 1] < arr[mid]) {
                return mid;
            }

            // If we are in the increasing part of the mountain
            if (arr[mid - 1] < arr[mid]) {
                st = mid + 1;
            } 
            // If we are in the decreasing part of the mountain
            else {
                end = mid - 1;
            }
        }

        // Should never reach here if input is a valid mountain array
        return -1;
    }
};
// Example usage:
int main() {
    Solution sol;
    vector<int> mountainArray = {0, 2, 1, 0};
    int peakIndex = sol.peakIndexInMountainArray(mountainArray);
    return 0;
}