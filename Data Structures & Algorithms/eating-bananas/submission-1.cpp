class Solution {
public:
    int ispossible(vector<int>& piles, int k){
        int hours = 0;
        for(auto it : piles){
            if(it <= k){
                hours += 1;
            }
            else{
                if(it % k == 0){
                    hours += (it / k);
                }
                else{
                    hours += (it / k) + 1;
                }
            }
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(ispossible(piles, mid) <=  h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
