# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int waterTrapped = 0;
        for (int i = 1; i < n - 1; i++) {
            int leftMax = height[i];
            for (int j = 0; j < i; j++) {
                leftMax = max(leftMax, height[j]);
            }
            int rightMax = height[i];
            for (int j = i + 1; j < n; j++) {
                rightMax = max(rightMax, height[j]);
            }
            waterTrapped += min(leftMax, rightMax) - height[i];
        }

        return waterTrapped;
    }
};
