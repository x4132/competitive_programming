#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /*
    class Node {
        public:
            int data;
            Node *left;
            Node *right;
            Node(int d) {
                data = d;
                left = NULL;
                right = NULL;
            }
    };

    */

    void topView(Node *root)
    {
        queue<Node *> toSearch;
        queue<int> searchPos;

        deque<tuple<int, int>> output;

        toSearch.push(root);
        searchPos.push(0);
        output.push_back({0, root->data});

        while (!toSearch.empty())
        {
            Node *cur = toSearch.front();
            toSearch.pop();
            int curPos = searchPos.front();
            searchPos.pop();

            if (get<0>(output.front()) - 1 == curPos)
            {
                output.push_front({curPos, cur->data});
            }
            else if (get<0>(output.back()) + 1 == curPos)
            {
                output.push_back({curPos, cur->data});
            }

            if (cur->left)
            {
                toSearch.push(cur->left);
                searchPos.push(curPos - 1);
            }

            if (cur->right)
            {
                toSearch.push(cur->right);
                searchPos.push(curPos + 1);
            }
        }

        while (!output.empty()) {
            cout << get<1>(output.front()) << " ";
            output.pop_front();
        }
    }

}; // End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.topView(root);

    return 0;
}
