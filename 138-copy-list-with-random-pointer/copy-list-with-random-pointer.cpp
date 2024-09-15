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
        unordered_map<Node* , Node*> mp;
        Node* temp =head;
        while(temp!=NULL){ // sotring the clone node in the map  
            Node *clone = new Node(temp->val);
            mp[temp] = clone;
            temp=temp->next;
        }

        // now do one more iteration for linking purpose 

        Node *ptr = head;
        while(ptr){
            mp[ptr]->next = mp[ptr->next];  // why wrong?
            mp[ptr]->random = mp[ptr->random];
            ptr = ptr->next; 

         /*   Node *node = mp[ptr];
            node->next = NULL;
            if(ptr->next != NULL)
              node->next = mp[ptr->next];
            
            node->random=NULL;
            if(ptr->random != NULL)
              node->random = mp[ptr->random];

            ptr = ptr->next;     */
        }
        return mp[head];
    }
};