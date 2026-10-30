#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int v) {
        val = v;
        left = right = nullptr;
    }
};
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

        int leftVal, rightVal;

        cout << "Enter left child of " << curr->val << " (-1 if none): ";
        cin >> leftVal;

        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->val << " (-1 if none): ";
        cin >> rightVal;

        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}

void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void postorder(Node* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void levelOrder(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();

            cout << curr->val << " ";

            if (curr->left != nullptr)
                q.push(curr->left);

            if (curr->right != nullptr)
                q.push(curr->right);
        }

        cout << "| ";
    }
}

int main() {

    Node* root = buildTree();

    cout << "\nPreorder:   ";
    preorder(root);
    cout << "\nInorder:    ";
    inorder(root);
    cout << "\nPostorder:  ";
    postorder(root);
    cout << "\nLevelOrder: ";
    levelOrder(root);
    cout << endl;
    return 0;
}