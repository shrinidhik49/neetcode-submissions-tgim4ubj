
class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v),
    prev(nullptr), next(nullptr) {}
};
class LRUCache {
    int cap;
    unordered_map<int, Node *> mapp;
    Node* head;
    Node* tail;
    
    void remove (Node* node) {
        Node* left = node->prev;
        Node* right = node->next;
        left->next = right;
        right->prev = left;
    }

    void insertathead(Node* node) {
        Node* first = head->next;
        head->next = node;
        node->next = first;
        first->prev = node;
        node->prev = head;
    }
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        mapp.clear();
        head = new Node(1,-1);
        tail = new Node(1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mapp.find(key) != mapp.end()) {
            Node* node = mapp[key];
            remove(node);
            insertathead(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mapp.find(key) != mapp.end()) {
            Node* node = mapp[key];
            node->val = value;
            remove(node);
            insertathead(node);
        }
        else {
            if (mapp.size() == cap) {
                Node* lastnode = tail->prev;
                mapp.erase(lastnode->key);
                remove(lastnode);
                delete lastnode;
            }
            Node* newnode = new Node(key,value);
            mapp[key] = newnode;
            insertathead(newnode);
            
        }
    }
};
