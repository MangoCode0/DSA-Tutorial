#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxWater(vector<int>& height) {
        int ans = 0
        

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                ans += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                ans += rightMax - height[right];
                right--;
            }
        }

        return ans;
    }
};
