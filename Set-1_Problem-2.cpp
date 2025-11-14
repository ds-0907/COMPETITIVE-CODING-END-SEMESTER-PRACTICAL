LC: 213 (House Robber II)
Submitted by: Devansh Sharma

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        auto robLinear = [&] (int start, int end) {
            int prev1 = 0, prev2 = 0;
            for (int i = start; i <= end; i++) {
                int temp = max(prev1, prev2 + nums[i]);
                prev2 = prev1;
                prev1 = temp;
            }
            return prev1;
        };
        return max(robLinear(0, nums.size() - 2), robLinear(1, nums.size() - 1));
    }
};
