class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int temp = 1;
            for(int j = 0; j < nums.size(); j++){
                if(i==j) continue;
                temp = temp*nums[j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
