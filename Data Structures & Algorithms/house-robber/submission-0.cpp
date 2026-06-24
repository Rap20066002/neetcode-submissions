class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;

        int prev2 = 0;
        int prev = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int include = nums[i] + prev2;

            int exclude = prev;

            int curr = max(include, exclude);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};