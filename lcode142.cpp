/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> mhead;
        int idx=0;
        ListNode *phead=head;
        while(phead){
            if(mhead.count(phead))return phead;
            mhead[phead]=idx;
            idx++;
            phead=phead->next;
        }
        return nullptr;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                while(head!=slow){
                    head=head->next;
                    slow=slow->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};