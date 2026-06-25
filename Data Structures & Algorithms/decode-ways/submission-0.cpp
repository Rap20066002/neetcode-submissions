class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int prev2 = 1;
        int prev1 = (s[0] != '0');
        
        for (int i = 2; i <= n; i++) {
            int curr = 0;

            if (s[i - 1] != '0')
                curr += prev1;

            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

            if (num >= 10 && num <= 26)
                curr += prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};