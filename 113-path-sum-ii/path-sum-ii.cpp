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
    vector<vector<int>> ans;
    void help(vector<int> &curr, int curr_sum, TreeNode* root, int &targetSum)
    {


        // cout<<"pushing "<<root->val<<" to the vector"<<endl;

        if (root == NULL)
        {
            return;
        }

        curr.push_back(root->val);
        curr_sum += root->val;
        // cout<<"adding "<<root->val<<" to curr sum making = "<<curr_sum<<endl;

        if (!root->left && !root->right)
        {
            if (targetSum == curr_sum)
            {
                // cout<<"ts = cs pushing vec"<<endl;
                ans.push_back(curr);
            }
            // return;
        }
        if (root->left)
        {
            // cout<<"calling for left node :: "<<root->left->val<<endl;
            help(curr,curr_sum,root->left,targetSum);
        }
        if (root->right)
        {
            // cout<<"calling for right node :: "<<root->right->val<<endl;
            help(curr,curr_sum,root->right,targetSum);
        }

        // cout<<"removing the element from vector :; "<<curr.back()<<endl;
        curr.pop_back();
        curr_sum -= root->val;
        // cout<<"sub "<<root->val<<" to make curr sum = "<<curr_sum<<endl;

        // cout << "%%%%%%%%%%%%%%%%%%%%%%"<<endl<<endl;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int curr_sum = 0;
        // vector<vector<int>> ans;

        vector<int> curr;

        help(curr,curr_sum,root,targetSum);

        return ans;
    }
};