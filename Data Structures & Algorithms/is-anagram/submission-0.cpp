class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpp;

        for(int i = 0; i < 26; i++){
            mpp[i + 'a'] = 0;
        }

        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
        }

        for(int i = 0; i < t.size(); i++){
            mpp[t[i]]--;
        }

        for(int i = 0; i < 26; i++){
            if(mpp[i + 'a'] != 0) return false;
        }
        return true;
    }
};
