class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size() -1;
        if(n == 0) return 1;
        
        int i=0;
        int max_len = 0;
        unordered_set<char> hashset;
        for (int j = 0; j <= n ; j++) {
            while (hashset.find(s[j]) != hashset.end()) {
                    hashset.erase(s[i]);
                    i++;
            }
            hashset.insert(s[j]);
            max_len = max(max_len, j - i +1);

        }

        return max_len;
    }
};
