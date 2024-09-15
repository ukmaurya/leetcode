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
    ListNode* findKthNode(ListNode* head, int k){
        ListNode* temp = head;
        k=k-1;
        while(temp&&k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || k==0){
            return head;
        }
        int n = 0;
        ListNode *temp = head;
        while(temp){
            n++;
            temp=temp->next;
        }
        k = k%n;
        if(k==0){
            return head;
        }
        ListNode* kth = findKthNode(head,n-k);
        ListNode* nextNode = kth->next;
        kth->next = NULL;
        ListNode *last = nextNode;
       
        while(last->next){
            last=last->next;
            
        }
        last->next = head;
        head = nextNode;
        return head;
        
        
    }
};