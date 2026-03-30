class Solution {
public:
    bool isValid(string s) {
        unordered_map <char,char> close_to_open = {
        {')' , '('},
        {']' , '['},
        {'}' , '{'}
    };
        stack<char> st;
        for (char x : s) {
            if (close_to_open.count(x)) {
                if (!st.empty() && st.top() == close_to_open[x]){
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                st.push(x);
            }
        }

        return st.empty();

    }
};
