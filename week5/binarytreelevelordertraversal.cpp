#include <iostream>
#include<queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
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
void levelOrder(Node* root) {

    if (!root) {
        cout << "Empty tree.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    int level = 1;

    while (!q.empty()) {

        int levelSize = q.size();

        cout << "Level " << level << ": ";

        for (int i = 0; i < levelSize; i++) {

            Node* curr = q.front();
            q.pop();

            cout << curr->val << " ";

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        cout << "\n";
        level++;
    }
}

int main() {

    Node* root = buildTree();

    cout << "\nLevel Order Traversal:\n";

    levelOrder(root);

    return 0;
}