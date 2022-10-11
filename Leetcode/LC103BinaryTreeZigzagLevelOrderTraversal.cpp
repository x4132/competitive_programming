#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> traversal;
        if (root == NULL)
        {
            return traversal;
        }
        vector<TreeNode *> current;
        int nulls = 0;
        current.insert(current.begin(), root);
        while (current.size() != 0)
        {
            deque<int> curVals;
            vector<TreeNode *> next;
            for (int i = 0; i < current.size(); i++)
            {
                if (traversal.size() % 2 == 0)
                {
                    curVals.push_front(current[i]->val);
                } else {
                    curVals.push_back(current[i]->val);
                }
                if (current[i]->right == NULL)
                {
                    nulls++;
                }
                else
                {
                    next.push_back(current[i]->right);
                }
                if (current[i]->left == NULL)
                {
                    nulls++;
                }
                else
                {
                    next.push_back(current[i]->left);
                }
            }

            traversal.push_back({curVals.begin(), curVals.end()});
            current = next;
        }

        return traversal;
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