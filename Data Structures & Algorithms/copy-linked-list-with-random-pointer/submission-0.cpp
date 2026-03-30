/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }
        unordered_map<Node*,Node*> hashmap;
        Node* temp = head;

        while (temp != NULL) {
            Node* newnode = new Node(temp->val);
            hashmap[temp] = newnode;
            temp = temp->next;
        }

        temp = head;
        while(temp != NULL) {
            Node* copynode = hashmap[temp];
            copynode->next = hashmap[temp->next];
            copynode->random = hashmap[temp->random];
            temp=temp->next;
        }

        return hashmap[head];

    }
};
