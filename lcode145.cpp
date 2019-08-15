/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode *> st;
        TreeNode *head=root;
        while(head){
            st.push(head);
            head=head->left;
        }
        while(!st.empty()){
            head=st.top();
            TreeNode *tmp=head->right;
            head->right=nullptr;
            if(!tmp){
                res.push_back(head->val);
                st.pop();
            }
            while(tmp){
                    st.push(tmp);
                    tmp=tmp->left;
            }    
        }
        return res;
    }
};