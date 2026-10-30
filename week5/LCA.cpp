#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Build binary tree
Node* buildTree() {
    int rootVal;

    cout << "Enter root value: ";
    cin >> rootVal;

    if (rootVal == -1)
        return nullptr;

    Node* root = new Node(rootVal);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int l, r;

        cout << "Left child of " << curr->val << " (-1 if none): ";
        cin >> l;

        if (l != -1) {
            curr->left = new Node(l);
            q.push(curr->left);
        }

        cout << "Right child of " << curr->val << " (-1 if none): ";
        cin >> r;

        if (r != -1) {
            curr->right = new Node(r);
            q.push(curr->right);
        }
    }

    return root;
}

// Find a node in the tree
Node* findNode(Node* root, int val) {
    if (!root)
        return nullptr;

    if (root->val == val)
        return root;

    Node* left = findNode(root->left, val);

    if (left)
        return left;

    return findNode(root->right, val);
}

// Find Lowest Common Ancestor
Node* LCA(Node* root, Node* p, Node* q) {

    if (!root || root == p || root == q)
        return root;

    Node* left = LCA(root->left, p, q);
    Node* right = LCA(root->right, p, q);

    if (left && right)
        return root;

    return left ? left : right;
}

int main() {

    Node* root = buildTree();

    int pv, qv;

    cout << "Enter value of node p: ";
    cin >> pv;

    cout << "Enter value of node q: ";
    cin >> qv;

    Node* p = findNode(root, pv);
    Node* q = findNode(root, qv);

    if (!p || !q) {
        cout << "One or both nodes not found in the tree." << endl;
        return 0;
    }

    Node* ancestor = LCA(root, p, q);

    cout << "LCA of " << pv << " and " << qv
         << " is: " << ancestor->val << endl;

    return 0;
}