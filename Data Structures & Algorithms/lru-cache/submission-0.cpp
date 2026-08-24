class LRUCache {
  public:
    class Node{
        public:
            int key , val;
            Node* prev;
            Node* next;
            
            Node(int k , int v){
                key = k;
                val =v;
                prev = next = NULL;
            }
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    unordered_map<int,Node*> m;
    int limit;
    
    // addNode
     
    void addNode(Node* newNode){
        Node* oldNext = head->next;
        
        head->next = newNode;
        newNode->next = oldNext;
        oldNext->prev = newNode;
        newNode->prev = head;
        
    }

  void delNode(Node* oldNode){
        Node* oldPrev = oldNode->prev;
         Node* oldNext = oldNode->next;
        
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
        
    }

    LRUCache(int cap) {
        // code here
        limit = cap;
        head->next = tail;
        tail->prev = head;
        
    }

    int get(int key) {
        // code here
        if(m.find(key) == m.end()){
            //not found
            return -1;
        }
        Node* ansNode = m[key];
        int ans = ansNode->val;
        
        // now make it most recent use data
        m.erase(key);
        delNode(ansNode);
        
        addNode(ansNode);
        m[key] = ansNode;
        return ans;
    }

        
    void put(int key, int val) {
        // code here
        
        // before adding check is key is alredy in map or not
        if(m.find(key) != m.end()){
            // already exist
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }
        
        // if capacity reached
        if(m.size() == limit){
            //delete LRU data
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        
        Node* newNode = new Node(key , val);
        addNode(newNode);
        m[key] = newNode;
        
    }
};