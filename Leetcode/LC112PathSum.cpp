#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
        {
            return false;
        }

        deque<TreeNode *> stk;
        deque<int> sums;
        stk.push_back(root);
        sums.push_back(0);

        while (!stk.empty())
        {
            TreeNode *cur = stk.front();
            int curSum = sums.front();
            stk.pop_front();
            sums.pop_front();

            curSum += cur->val;
            if (curSum == targetSum && cur->left == NULL && cur->right == NULL)
            {
                return true;
            }

            if (cur->left != NULL)
            {
                stk.push_back(cur->left);
                sums.push_back(curSum);
            }

            if (cur->right != NULL)
            {
                stk.push_back(cur->right);
                sums.push_back(curSum);
            }
        }

        return false;
    }
};
