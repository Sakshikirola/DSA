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
class Info {
public:
    int min;
    int max;
    int sum;
    bool isBST;

    Info(int min, int max, int sum, bool isBST)
        : min(min), max(max), sum(sum), isBST(isBST) {}
};

class Solution {
public:
    int maxsum = 0;

    Info helper(TreeNode* root){
       if(root == NULL){
        return Info(INT_MAX, INT_MIN, 0, true) ;
       }

       Info left = helper(root->left);
       Info right = helper(root->right);

       if(left.isBST && right.isBST && root->val > left.max && root->val < right.min){
        int currsum = left.sum + right.sum + root->val;
        maxsum = max(maxsum , currsum);

        int currmin = min(root->val, left.min);
        int currmax = max(root->val, right.max);

        return Info(currmin, currmax, currsum, true);
       }

       return Info(INT_MIN, INT_MAX, 0, false); 
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxsum;
    }
};