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

ListNode* reverselist (ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* temp = curr;

    while(curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    head = prev;
    return head;
}


ListNode* findkthnode(ListNode* head, int k) {
    ListNode* temp = head;
    k -= 1;
    while (temp != NULL && k > 0) {
        temp = temp->next;
        k--;
    }

    return temp;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextnode = NULL;
        ListNode* prevnode = NULL;
        
        while (temp != NULL) {
            ListNode* kthnode = findkthnode(temp,k);

            if (kthnode == NULL) {
                if(prevnode) prevnode->next = temp;
                break;
            }

            nextnode = kthnode->next;
            kthnode->next = NULL;
            reverselist(temp);

            if(temp == head) {
                head = kthnode;
            }
            else {
                prevnode->next = kthnode;
            }
            
            prevnode = temp;
            temp = nextnode;
            
        }

        return head;
    }
};
