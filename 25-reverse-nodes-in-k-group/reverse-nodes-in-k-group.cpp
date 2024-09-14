/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode *rev(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur){
            ListNode* nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        return prev;
    }
 ListNode* findkthnode(ListNode* head , int k ){
     ListNode* temp = head;
     k=k-1;
     while(temp && k>0){
         temp= temp->next ;
         k--;
     }
     return temp;
 }  
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
       ListNode* temp=head;
       ListNode* prevLast = NULL;
       while(temp){
           ListNode* kth = findkthnode(temp ,k);
           if(kth==NULL){
               if(prevLast)
                 prevLast->next = temp;
               break;
           }
           
           ListNode* nextHead = kth->next;
           kth->next = NULL;
           rev(temp);
           if(temp==head){ // first k group 
               head = kth;
           }
           else{
               prevLast->next = kth;
           }
           prevLast = temp;
           temp = nextHead;
           
        }
        
       return head;
    }
};