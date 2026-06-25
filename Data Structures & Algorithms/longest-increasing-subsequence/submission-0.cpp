class Solution {
public:
    int lower(int l, int r, vector<int> &temp, int ele){
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(temp[mid] >= ele){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;

        temp.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int x = temp.size();
                int ind = lower(0, x-1, temp, nums[i]);
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};