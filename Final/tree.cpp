#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
};

Node *createNode(int x);

void insert(Node *&root, int x);

void preOrder(Node *root);

void inOrder(Node *root);

void postOrder(Node *root);

Node *search(Node *root, int x);

Node *min(Node *root);

Node *max(Node *root);

int main()
{
    Node *root = nullptr;

    insert(root, 8);
    insert(root, 7);
    insert(root, 9);
    insert(root, 6);
    insert(root, 10);
    insert(root, 5);
    insert(root, 11);

    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    cout << search(root, 7)->val << endl;
    cout << min(root)->val << endl;
    cout << max(root)->val << endl;
}

Node *createNode(int x)
{
    Node *node = new Node();
    node->val = x;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void insert(Node *&root, int x)
{
    if (!root)
        root = createNode(x);
    else if (x > root->val)
        insert(root->right, x);
    else
        insert(root->left, x);
}

void preOrder(Node *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

Node *search(Node *root, int x)
{
    Node *curr = root;

    while (curr)
    {
        if (curr->val == x)
            return curr;
        else if (curr->val < x)
            curr = curr->right;
        else
            curr = curr->left;
    }

    return nullptr;
}

Node *min(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node *max(Node *root)
{
    while (root && root->right)
        root = root->right;
    return root;
}
