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
    ListNode* removeZeroSumSublists(ListNode* head) {   
        while(head&&head->val==0)
            head=head->next;
         if(head==nullptr)return nullptr;
        ListNode *prehead=new ListNode(1),*pres=prehead;
        prehead->next=head;
        ListNode *phead=head,*pre=prehead;
        while(phead)
        {
            int sum=phead->val;
            ListNode *sele=phead->next;
            while(sum!=0&&sele)
            {
                sum+=sele->val;
                sele=sele->next;
            }
            if(sum==0)
            {
                prehead->next=sele;
                phead=sele;
            }
            else
            {
                prehead=phead;
                phead=phead->next;
            }
        }
        return pres->next;
    }
};