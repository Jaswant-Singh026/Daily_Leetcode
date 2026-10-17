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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        long long maxWidth = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            long long size = q.size();
            long long l = q.front().second;
            long long r = q.back().second;
            maxWidth = max(maxWidth, r - l + 1);

            for(int i = 0; i < size; i++){
                auto p = q.front();
                q.pop();
                
                long long idx = p.second - l;
                if(p.first -> left != NULL) q.push({p.first -> left, (long long)2 * idx + 1});
                if(p.first -> right != NULL) q.push({p.first -> right, (long long)2 * idx + 2});
            }
        }
        return maxWidth;
    }
};