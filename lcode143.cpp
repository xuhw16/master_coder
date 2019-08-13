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
    ListNode *revers_L(ListNode *head){
        if(!head)return nullptr;
        ListNode *pre=head,*now=head->next,*next;
        pre->next=nullptr;
        while(now){
            next=now->next;
            now->next=pre;
            pre=now;
            now=next;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        if(!head||!head->next||!head->next->next)return;
        int k=0;
        ListNode *t_head=head;
        while(t_head){
            k++;
            t_head=t_head->next;
        }
        int mid =(k-1)/2;
        t_head=head;
        while(mid--){
            t_head=t_head->next;
        }
        ListNode* next=t_head->next;
        t_head->next=nullptr;
        next=revers_L(next);
        t_head=head;
        while(t_head&&next){
            ListNode *tmp_n=next->next;
            next->next=t_head->next;
            t_head->next=next;
            t_head=t_head->next->next;
            next=tmp_n;
        }
        return;
    }
};