class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int nu : nums) {
            if (hashset.count(nu)){
                return true;
            }
            hashset.insert(nu);
        }
        return false;
    }
};