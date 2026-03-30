class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need,window;
        int totalchars = 0;
        for (auto x: s1) {
            need[x] += 1;
        }

        int k = s1.size();
        
        for (int i=0; i<s2.size() ;i++) {
            window[s2[i]]++;

            if (i >= k) {
                char leftchar = s2[i - k];
                window[leftchar]--;
                if (window[leftchar] == 0) {
                    window.erase(leftchar);
                }
            }

            if(window == need) {
                return true;
            }
        }

        return false;

    }
};
