class Solution {
public:
    bool isPalindrome(string s) {
        int r = s.size()-1;
        int l = 0;

        while (l < r){
            if (!alphaNum(s[l])){
                l++;
            }
            else if (!alphaNum(s[r])){
                r--;
            }
            else {
            if (tolower(s[l]) == tolower(s[r])){
                r--;
                l++;
            }
            else {
                return false;
            }
            }
        }
        return true;
    }

    bool alphaNum(char c){
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9'); 
    }
};
