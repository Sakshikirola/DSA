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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        vector<long long>levelsums;

        while(q.size()>0){
            int size = q.size();
            long long sum = 0;

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
           levelsums.push_back(sum);
        }

        if(k > levelsums.size()) return -1;
        sort(levelsums.begin() , levelsums.end() , greater<long long>());
        return levelsums[k-1];
    }
};