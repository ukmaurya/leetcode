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
    private:
    ListNode* merge( ListNode* head1 ,  ListNode* head2){
        if(head1==NULL && head2!=NULL){
            return head2;
        }
         if(head1!=NULL && head2==NULL){
            return head1;
        }
        if(!head1 && !head2){
            return NULL;
        }
        
        ListNode* head = new ListNode(-1);
    
    ListNode *temp=head;
    while(head1!=NULL && head2!=NULL){
        if(head1->val <= head2->val){
            temp->next = head1;
            temp=temp->next;
            head1=head1->next;
            
        }
        else if(head2->val<head1->val){
            temp->next=head2;
            temp=temp->next;
            head2=head2->next;
        }
    }
    if(head1!=NULL)
      temp->next =head1;
    else if(head2!=NULL)
      temp->next=head2;
    return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         int n = lists.size();
        if(n==0){
            return NULL;
        }
       
        for(int i=0;i<n-1;i++){
            ListNode* temp = merge(lists[i],lists[i+1]);
            lists[i+1]=temp;
            
        }
        return lists[n-1];
    }
};