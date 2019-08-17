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
    ListNode* insertionSortList(ListNode* head) {
        if(!head)return nullptr;
        ListNode *now=head;
        while(now&&now->next){
            ListNode *t_now=now->next,*temp=head,*pre=nullptr;
            bool flag=false;
            while(temp){
                if(temp->val==t_now->val&&temp==t_now)
                    break;
                else if(temp->val<t_now->val)
                {
                    pre=temp;
                    temp=temp->next;
                }
                else{
                    flag=true;
                    now->next=now->next->next;
                    if(pre)
                        pre->next=t_now;
                    t_now->next=temp;
                    if(pre==nullptr)
                        head=t_now;
                    break;
                }
            }
            if(flag)
                continue;
            now=now->next;
        }
        return head;
    }
};