class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size()-1;
        unordered_map<char,int> hashmap;
        int i = 0;
        int max_len = 0;
        int maxf =0;

        for (int j=0; j<=n ; j++) {
            hashmap[s[j]]++;
            maxf = max(maxf,hashmap[s[j]]);

            while((j-i+1) - maxf > k) {
                hashmap[s[i]]--;
                i++;
            }
            max_len = max(max_len,j-i+1);
        }
    return max_len;
    }
};
