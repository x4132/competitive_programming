#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> lQueue, rQueue;
        lQueue.push(root->left);
        rQueue.push(root->right);
        while (!lQueue.empty() && !rQueue.empty())
        {
            TreeNode *left, *right;
            left = lQueue.front();
            right = rQueue.front();
            lQueue.pop();
            rQueue.pop();
            if (left == NULL && right == NULL) {
                continue;
            } else if (left == NULL || right == NULL) {
                return false;
            } else if (left->val != right->val) {
                return false;
            }

            lQueue.push(left->left);
            lQueue.push(left->right);
            rQueue.push(right->right);
            rQueue.push(right->left);
        }

        return true;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};