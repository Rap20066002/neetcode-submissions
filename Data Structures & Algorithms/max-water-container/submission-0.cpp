class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int ans = 0;

        while(i < j){
            int vol = (j-i) * min(heights[i], heights[j]);
            ans = max(ans, vol);

            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return ans;
    }
};
