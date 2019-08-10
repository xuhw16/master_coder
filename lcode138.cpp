/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* next_p(Node *head,unordered_map<Node *,Node*> &mp){
        if(!head) return nullptr;
        Node* temp =new Node ();
        temp->val=head->val;
        temp->random=head->random;
        mp[head]=temp;
        temp->next=next_p(head->next,mp);
        return temp;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        if(!head)return nullptr;
        Node* pnew=new Node();
        Node *hold=head;
        pnew->val=hold->val;
        pnew->random=hold->random;
        mp[hold]=pnew;
        pnew->next=next_p(hold->next,mp);
        Node *t_pnew=pnew;
        while(t_pnew){
            t_pnew->random=mp[t_pnew->random];
            t_pnew=t_pnew->next;
        }
        return pnew;
    }
};



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
       Node * curr=head;
        while(curr){
            Node *temp=new Node(curr->val,curr->next,NULL);
            curr->next=temp;
            curr=temp->next;
        }
        curr=head;
        while(curr){
            Node *temp=curr->next;
            temp->random=curr->random==NULL?NULL:curr->random->next;
            curr=temp->next;
        }
        curr=head;
        Node *res=curr->next,*phead=res;;
        while(curr){
            curr->next=res->next;
            res->next=res->next==NULL?NULL:res->next->next;
            curr=curr->next;
            res=res->next;
        }
        return phead;
    }
};
