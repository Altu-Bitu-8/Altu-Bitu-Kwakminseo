#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(0), right(0) {}
};

void insert(Node*& root, int val) {
    if (!root) {
        root = new Node(val);
        return;
    }
    if (val < root->val) insert(root->left, val);
    else insert(root->right, val);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int val;
    Node* root = 0;
    while (cin >> val) insert(root, val);
    postorder(root);
    return 0;
}