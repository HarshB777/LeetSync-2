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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> curr;
        queue<TreeNode*> curr_dup;


        queue<TreeNode*> prev_dup;

        curr.push(root);
        curr.push(NULL);

        TreeNode* first = new TreeNode(root->val);
        TreeNode* ans = new TreeNode(0);
        ans->left = first;
        curr_dup.push(first);
        curr_dup.push(NULL);

        int row = 0;
        stack<int> stack;

        while (!curr.empty())
        {
            TreeNode* node = curr.front();
            curr.pop();
            TreeNode* node_dup = curr_dup.front();
            if (row % 2 == 0 && node_dup != NULL)
            {
                prev_dup.push(node_dup);
            }
            curr_dup.pop();

            if (node == NULL)
            {
                if (row % 2 == 0 && !curr.empty())
                {
                    while (!prev_dup.empty())
                    {
                        TreeNode* cnode = prev_dup.front();
                        prev_dup.pop();

                        for (int z = 0; z < 2; z++)
                        {
                            int val = stack.top();
                            TreeNode* tmp = new TreeNode(val);
                            stack.pop();

                            if (z == 0)
                            {
                                cnode->left = tmp;
                                curr_dup.push(tmp);
                            }
                            else
                            {
                                cnode->right = tmp;
                                curr_dup.push(tmp);
                            }
                        }
                    }
                }

                if (!curr.empty())
                {
                    curr.push(NULL);
                    curr_dup.push(NULL);
                }

                row++;
                continue;
            }
            
            if (node->left)
            {
                curr.push(node->left);
                if (row % 2 == 1)
                {
                    TreeNode* tmp = new TreeNode(node->left->val);
                    node_dup->left = tmp;
                    curr_dup.push(tmp);
                }
                else
                {
                    stack.push(node->left->val);
                }
            }
            
            if (node->right)
            {
                curr.push(node->right);
                if (row % 2 == 1)
                {
                    TreeNode* tmp = new TreeNode(node->right->val);
                    node_dup->right = tmp;
                    curr_dup.push(tmp);
                }
                else
                {
                    stack.push(node->right->val);
                }
            }

        }










        return ans->left;
    }
};