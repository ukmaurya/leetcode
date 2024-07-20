class LRUCache {
    private:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        public:
        node(int key,int val){
            this->key = key;
            this->val = val;
        }
        
    };
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int size;
    unordered_map<int , node*>mp; // key  , node address
public:
    node* addnode(int key , int val){
        node* temp = new node(key,val);
        temp->next = head->next;
        temp->prev = head;
        head->next = temp;
        temp->next->prev = temp;
        return temp;
    }
    void deletenode(node* temp){
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete(temp);
    }
    
  LRUCache(int capacity) { // initialization
         size = capacity; 
         head->next = tail;
         tail->prev = head;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()){
            int ans = mp[key]->val;
            deletenode(mp[key]);
            mp.erase(key);
            mp[key]=addnode(key,ans);
            return ans;
          }
        else{
           return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
             deletenode(mp[key]);
             mp.erase(key);
             mp[key]=addnode(key,value);
          }
        else{
            if(mp.size()<size){
                mp[key]=addnode(key,value);
                
            }
            else{
                mp.erase(tail->prev->key);
                deletenode(tail->prev);
                mp[key]=addnode(key , value);
               
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */