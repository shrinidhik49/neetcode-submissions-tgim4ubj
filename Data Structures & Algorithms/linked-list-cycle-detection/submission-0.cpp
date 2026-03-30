/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set <ListNode*> hashset;
        ListNode* ptr = head;

        while (ptr != NULL){
            if (hashset.find(ptr) != hashset.end()) {
                return true;
            }
            hashset.insert(ptr);
            ptr = ptr->next;
        }

        return false;
    }
};
