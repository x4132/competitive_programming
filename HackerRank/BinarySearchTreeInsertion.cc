#include <iostream>
#include <cstddef>

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
    void preOrder(Node *root)
    {

        if (root == NULL)
            return;

        std::cout << root->data << " ";

        preOrder(root->left);
        preOrder(root->right);
    }

    /* you only have to complete the function given below.
    Node is defined as

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

    Node *insert(Node *root, int data)
    {
        Node *cur = root;
        Node *toAdd = new Node(data);

        if (root == NULL) {
            return toAdd;
        }

        while (true)
        {
            if (cur->data > data)
            {
                if (cur->right) {
                    cur = cur->right;
                } else {
                    cur->right = toAdd;
                    break;
                }
            }
            else
            {
                if (cur->left) {
                    cur = cur->left;
                } else {
                    cur->left = toAdd;
                    break;
                }
            }
        }

        return root;
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
    myTree.preOrder(root);
    return 0;
}
