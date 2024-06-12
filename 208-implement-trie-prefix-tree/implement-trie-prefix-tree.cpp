struct Node{
     Node* links[26];
     bool flag = false;
     
     // some functions
     bool containsKey(char ch){
        if(links[ch-'a'] != NULL)
         return true;
        else return false; 
     }

     void put(char ch , Node *node){
            links[ch-'a'] = node; // creats empty reference node 

     }
     Node* get(char ch){
        return links[ch-'a'];
     }
     void setEnd(){
        flag=true;
     }
     bool isEnd(){
        if(flag==true)
         return true;
        else
         return false; 
     }

};

class Trie {
    private:
      Node *root;
public:
    Trie() {
         root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!(node->containsKey(word[i]))){
                   node->put(word[i] , new Node());
             }
             node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
           Node* node = root;
           for(int i=0;i<word.size();i++){
             if(!node->containsKey(word[i])){
                return false;
             }
             node = node->get(word[i]);
           }
           // all char match ,but we need to check the refence node flag must be true as it tells that ending of the word
          return node->isEnd(); // if true then return true
    }
    
    bool startsWith(string prefix) {
         Node *node = root;
         for(int i=0;i<prefix.size();i++){
              if(!(node->containsKey(prefix[i])))
                return false;

              node = node->get(prefix[i]);  
         }
         return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */