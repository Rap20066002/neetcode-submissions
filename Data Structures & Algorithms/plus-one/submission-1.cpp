class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        vector<int> ans;
        if(digits[n-1] != 9){
            digits[n-1] += carry;
            return digits;
        }
        else{    
            for(int i = n-1; i >= 0; i--){
                if(digits[i] == 9){
                    int sum = digits[i] + carry;
                    digits[i] = sum%10;
                    carry = sum/10;
                }
                else{
                    digits[i] += carry;
                    carry = 0;
                }
            }
            if(carry != 0){
                ans.push_back(carry);
                for(int i = 0; i <= n-1; i++){
                    ans.push_back(digits[i]);
                }
                return ans;
            }
            else{
                return digits;
            }
        }
    }
};
