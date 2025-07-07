
#include <vector>
using namespace std;
// This code finds the single element in a sorted array where every other element appears twice.

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& A) {
//         int st = 0, end = A.size() - 1;

//         while (st < end) {
//             int mid = st + (end - st) / 2;

//             // Ensure mid is even for proper comparison
//             if (mid % 2 == 1) {
//                 mid--;
//             }

//             // If the pair is valid, move to the right half
//             if (A[mid] == A[mid + 1]) {
//                 st = mid + 2;
//             } else {
//                 // If not, move to the left half
//                 end = mid;
//             }
//         }

//         // When st == end, that's the single element
//         return A[st];
//     }
// };
// int main() {
//     Solution sol;
//     vector<int> A = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6};
//     int result = sol.singleNonDuplicate(A);
//     return 0;
// }   


















class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int st = 0, end = A.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            // Ensure mid is even for proper comparison
            if (mid % 2 == 1) {
                mid--;
            }

            // If the pair is valid, move to the right half
            if (A[mid] == A[mid + 1]) {
                st = mid + 2;
            } else {
                // If not, move to the left half
                end = mid;
            }
        }

        // When st == end, that's the single element
        return A[st];
    }
};
int main() {
    Solution sol;
    vector<int> A = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6};
    int result = sol.singleNonDuplicate(A);
    return 0;
}