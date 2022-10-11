#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  Node *connect(Node *root)
  {
    if (root == NULL) {
      return root;
    }

    deque<Node *> nodeQueue;
    nodeQueue.push_back(root);

    
    while (!nodeQueue.empty())
    {
      deque<Node *> next;
      Node *prev = NULL;

      while (!nodeQueue.empty())
      {
        Node *cur = nodeQueue.front();
        nodeQueue.pop_front();

        if (prev != NULL) {
          prev->next = cur;
        }

        if (cur->left != NULL) {
          next.push_back(cur->left);
        }

        if (cur->right != NULL) {
          next.push_back(cur->right);
        }

        prev = cur;
      }

      nodeQueue = next;
    }

    return root;
  }
};

struct Node
{
  int val;
  Node *left;
  Node *right;
  Node *next;
};