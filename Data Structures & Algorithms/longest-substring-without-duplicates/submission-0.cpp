class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charset;
        int l=0;
        int res = 0;
        int n= s.size();

        for (int r=0;r<n;r++){
            while (charset.find(s[r]) != charset.end()){
                charset.erase(s[l]);
                l++;
            }
            charset.insert(s[r]);
            res = max(res,r-l+1);
        }
        return res;
    }
};
