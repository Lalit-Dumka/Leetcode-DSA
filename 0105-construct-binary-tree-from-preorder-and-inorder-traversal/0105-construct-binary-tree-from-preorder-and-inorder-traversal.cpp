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
    TreeNode * build(vector<int> &preorder, int pstart, int pend, vector<int> &inorder, int instart, int inend, unordered_map<int,int> &inMap){
        
        if(pstart>pend || instart>inend) return NULL;
        
        TreeNode * root = new TreeNode(preorder[pstart]);
        int inmid = inMap[preorder[pstart]];
        int nums_left = inmid-instart;
        
        root->left = build(preorder, pstart+1, pstart+nums_left, inorder, instart, inmid-1, inMap);
        root->right = build(preorder, pstart+nums_left+1, pend, inorder, inmid+1, inend, inMap);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        int n = preorder.size();
        for(int i = 0; i<n; i++){
            inMap[inorder[i]]=i;
        }
        TreeNode * root = build(preorder, 0, n-1, inorder, 0, n-1, inMap);
        
        return root;
    }
};