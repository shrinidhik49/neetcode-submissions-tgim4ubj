class Solution {
public:
    string minWindow(string s, string t) {

        if (s.size() == 0 || s.size() < t.size()) {
            return "";
        }

        unordered_map<char,int> need, window;
        int l = 0, r = 0;
        int n = s.size();
        int m = t.size();
        int minlength = INT_MAX;
        int count = 0;
        int startidx = -1;

        for (auto x : t) {
            need[x]++;
        }

        while(r < n) {
            window[s[r]]++;
            if (need.count(s[r]) && window[s[r]] <= need[s[r]]) {
                count++;
            }

            while(count == m) {
                if (r-l+1 < minlength) {
                    minlength = r-l+1;
                    startidx = l;
                }
                window[s[l]]--;
                if(need.count(s[l]) && window[s[l]] < need[s[l]]) {
                    count--;    
                }

                l++;
            }

            r++;

        }

        return startidx == -1 ? "" : s.substr(startidx,minlength);
    }
};
