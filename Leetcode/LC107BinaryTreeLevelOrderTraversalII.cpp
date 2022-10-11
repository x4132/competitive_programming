#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        deque<vector<int>> traversal;

        if (root == NULL) {
            return {traversal.begin(), traversal.end()};
        }

        vector<TreeNode *> current;
        int nulls = 0;
        current.push_back(root);
        while (current.size() != 0) {
            deque<int> curVals;
            vector<TreeNode *> next;

            for (int i = 0; i < current.size(); i++) {
                curVals.push_front(current[i]->val);
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

            traversal.push_front({curVals.begin(), curVals.end()});
            current = next;
        }

        return {traversal.begin(), traversal.end()};
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