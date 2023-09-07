/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        q.push(root);
        bool flag=true;
        while(!q.empty())
        {
            int n=q.size();
            vector<int> res(n,0);
            for(int i=0;i<n;i++)
            {
                TreeNode *front=q.front();
                q.pop();
                if(flag) res[i]=front->val;
                else res[n-i-1]=front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(res);
            flag=!flag;
        }
        return ans;
    }
};
