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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL)
         return head;
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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
         
         ListNode* temp = head;
         ListNode* prev = new ListNode(-1);
         ListNode* finalHead = prev;
         while(temp){
           int count=1;
           ListNode* tstart = temp;
           ListNode* tend = temp;
           while(tend && count<k){
               tend = tend->next;
               count++;
           }
           if(tend){
             temp = tend->next;
             tend->next = NULL;
             ListNode *tempHead = reverse(tstart);
             prev->next = tempHead;
             prev = tstart;
           }
           else{ // last group 
             prev->next = tstart;
             temp=NULL; 
           }
          
         }

         return finalHead->next;    


    }
};