class LRUCache {
public:
    class Node{
        public:
        int key, val;
        Node *prev, *next;
        
        Node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    
    Node * head = new Node(-1,-1);
    Node * tail = new Node(-1,-1);
    
    int cap;
    
    unordered_map<int,Node*> mp;
    
    void deleteNode(Node * n){
        Node * prev = n->prev;
        n->next->prev = prev;
        prev->next = n->next;
    }
    
    void insertNode(Node *n){
        Node * temp = head->next;
        head->next = n;
        n->next = temp;
        n->prev = head;
        temp->prev = n;
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node * temp = mp[key];
            deleteNode(mp[key]);
            insertNode(temp);
            mp[key] = head->next;
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node * temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size()==cap){
            Node * temp = tail->prev;
            mp.erase(temp->key);
            deleteNode(temp);
        }
        insertNode(new Node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */