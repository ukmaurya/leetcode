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
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
         int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        ListNode* newHead = new ListNode(-1);
        newHead->next=head;
        ListNode *prev = newHead;
        ListNode *cur =  head;
        while(cur){
            if(mp.find(cur->val) != mp.end()){
                prev->next = cur->next;
                 ListNode*temp = cur;
                cur = cur->next;
                delete(temp);
            }
            else{
                prev = cur;
                cur = cur->next;
            }
        }
       return newHead->next;
    }
};