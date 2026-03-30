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
    void reorderList(ListNode* head) {
        if (!head || head->next == NULL || head->next->next == NULL) {
            return;
        }
        //finding midpoint
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p2->next != NULL && p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        //reversing the second half
        ListNode* premid = p1;
        ListNode* precurr = premid->next;
        while (precurr->next != NULL){
            ListNode* curr = precurr->next;
            precurr->next = curr->next;
            curr->next = premid->next;
            premid->next = curr;
        }

        //re-ordering
        p1 = head;
        p2 = premid->next;
        while(p1 != premid) {
            premid->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = premid->next;
        
        }
    }
};