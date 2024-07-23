struct node{
      
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
struct  List{
     node* head;
     node* tail;
    
    List(){
         head = new node(-1,-1);
         tail = new node(-1,-1);
        head->next = tail;
        tail->prev = head;
       
    }
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
   

};
class LRUCache {
    public:
      int size; // size of list 
      List* lst ;
      unordered_map<int , node*>mp; // key  , node address
    LRUCache(int capacity) { // initialization
         size = capacity; 
        lst = new List();
    }
    int get(int key) {
        if(mp.find(key) != mp.end()){
            int ans = mp[key]->val;
            lst->deletenode(mp[key]);
            mp.erase(key);
            mp[key]=lst->addnode(key,ans);
            return ans;
          }
        else{
           return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
             lst->deletenode(mp[key]);
             mp.erase(key);
             mp[key]=lst->addnode(key,value);
          }
        else{
            if(mp.size()<size){
                mp[key]=lst->addnode(key,value);
                
            }
            else{
                mp.erase(lst->tail->prev->key);
                lst->deletenode(lst->tail->prev);
                mp[key]=lst->addnode(key , value);
               
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