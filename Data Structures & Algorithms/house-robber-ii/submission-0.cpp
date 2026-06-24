class Solution {
public:
    int solve(vector<int>& nums, int l, int r){
        int s = r-l+1;
        if(s == 0) return 0;
        if(s == 1) return nums[l];

        int prev = nums[l];
        int prev2 = 0;

        for(int i = l+1; i <= r; i++){
            int include = nums[i] + prev2;
            int exclude = prev;

            int curr = max(include, exclude);

            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int ans1 = solve(nums, 0, n-2);
        int ans2 = solve(nums, 1, n-1);

        return max(ans1, ans2);
    }
};