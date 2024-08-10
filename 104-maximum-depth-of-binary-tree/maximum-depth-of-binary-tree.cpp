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
    int maxDepth(TreeNode* root) {
        TreeNode* it = root;

        if (root == NULL)
        {
            return 0;
        }
        queue<TreeNode*> q; 
        q.push(root);
        int curr = 0;


        q.push(NULL);
        while (!q.empty())
        {
            TreeNode* here = q.front();
            q.pop();

            if (here == NULL)
            {
                curr++;
                if (!q.empty())
                    q.push(NULL);
                continue;
            }
            else
            {
                if (here->left)
                {
                    q.push(here->left);
                }

                if (here->right)
                {
                    q.push(here->right);
                }
            }
        }






        return curr;
    }
};