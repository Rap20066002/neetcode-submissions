class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < numbers.size(); i++){
            if(mpp.find(target - numbers[i]) != mpp.end()){
                return {mpp[target - numbers[i]], i + 1};
            }
            mpp[numbers[i]] = i + 1;
        }
        return {};
    }
};
