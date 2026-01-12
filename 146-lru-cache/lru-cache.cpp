class LRUCache {
public:
    struct Node {
        int data;
        int key;
        Node* next;
        Node* prev;
        Node(int k,int val){
            data = val;
            key = k;
            next = nullptr;
            prev = nullptr;
        }
    };
    unordered_map<int, Node*> mp;
    int cap;
    Node *head;
    Node *tail;
    int size;
    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void remove(Node* node){
        if(node == NULL || node == head || node == tail) return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertHead(Node* node){
        if(node == NULL) return;
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        int val = node->data;
        remove(node);
        insertHead(node);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(mp.size() == cap){
                Node *node = tail->prev;
                remove(node);
                mp.erase(node->key);
                Node *newN = new Node(key, value);
                mp[key] = newN;
                insertHead(newN);

            }else{
                Node *node = new Node(key, value);
                mp[key] = node;
                insertHead(node);
            }
        }else {
            Node *node = mp[key];
            node->data = value;
            remove(node);
            insertHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */