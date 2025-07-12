/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(TreeNode* root, string &s){
        if(root == NULL){
            s += "NULL,";
            return;
        } 
        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
       preorder(root , s);
       return s;
    }

    TreeNode* buildtree(vector<string>&nodes, int &index){
        if(index >= nodes.size() || nodes[index] == "NULL"){
            index++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(nodes[index++]));
        node->left = buildtree(nodes,index);
        node->right = buildtree(nodes,index);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>nodes;
        string temp;
        for(char c:data){
            if( c == ','){
                nodes.push_back(temp);
                temp.clear();
            }else{
                temp += c;
            }
        }
        int index = 0;
        return buildtree(nodes,index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));