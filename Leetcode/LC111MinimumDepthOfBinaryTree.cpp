#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        deque<TreeNode *> queue;
        deque<int> queueDist;
        int minDepth = 100001;

        queue.push_back(root);
        queueDist.push_back(1);
        while (!queue.empty()) {
            TreeNode* cur = queue.back();
            int curDist = queueDist.back();
            queue.pop_back();
            queueDist.pop_back();

            if (cur->left == NULL && cur->right == NULL) {
                minDepth = min(minDepth, curDist);
            }

            if (cur->left != NULL) {
                queue.push_back(cur->left);
                queueDist.push_back(curDist + 1);
            }

            if (cur->right != NULL) {
                queue.push_back(cur->right);
                queueDist.push_back(curDist + 1);
            }
        }

        return minDepth;
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