struct node{
    int key;
    int val;
    int cnt;
    node* prev;
    node* next;
    node(int k, int v){
        key = k;
        val = v;
        cnt = 1;
    }
};
struct List{
    node* head;
    node* tail;
    int dllSize ;
    List(){
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head->next = tail;
        tail->prev = head;
        dllSize=0;
    }
    void addnode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
        dllSize++;
    }
    void removenode(node* delNode){
         node* delNext = delNode->next;
         node* delPrev = delNode->prev;
         delNext->prev = delPrev;
         delPrev->next = delNext;
         dllSize--;
    }
};

class LFUCache {
    unordered_map<int,node*> mp;  // key , address of the node to give val in constant time 
    map<int,List* > freq;      // freq , doubly linked list 
    int size ;
    int minFreq ;
  
public:
    void updateFreq(node* temp){
         
        // mp.erase(temp->key);
         freq[temp->cnt]->removenode(temp);
         if(freq[temp->cnt]->dllSize==0 && temp->cnt==minFreq){
            minFreq++;
         }
         if(freq.find(temp->cnt+1) != freq.end()){ // add in front if present 
              temp->cnt +=1;
              freq[temp->cnt]->addnode(temp);
         }
         else{
            temp->cnt +=1;
            freq[temp->cnt] = new List();
            freq[temp->cnt]->addnode(temp);// adding same node ie chainging only linkes 
         }
         // mp[temp->key]=temp;

    }
    LFUCache(int capacity) {
        size = capacity ;
        minFreq = 0;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
             // change frequency , no need to delete the node just change the the links , address will remain the same 
            int val = mp[key]->val;
            updateFreq(mp[key]);
            return val;
        }
        else 
         return -1;
    }
    
    void put(int key, int value) {
        if(size==0){
            return;
        }
        if(mp.find(key)!= mp.end()){
            node* temp = mp[key];
            temp->val= value;// may be case where new value is assigned to same key 
            updateFreq(temp);
        }
        else{
            if(mp.size()== size){
                //remove the lru of min freq 
                node* lru = freq[minFreq]->tail->prev;
                mp.erase(lru->key);
                freq[minFreq]->removenode(lru);

            }
            minFreq = 1;
            node* tmp = new node(key,value);
            if(freq.find(minFreq) != freq.end()){
                freq[minFreq]->addnode(tmp);
            }
            else{
               List* lst = new List();
               freq[minFreq] = lst;
               freq[minFreq]->addnode(tmp);

            }
            mp[key]=tmp;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */