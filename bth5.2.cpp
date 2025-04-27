#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeHelper(const string& preorder, const string& inorder, int& preorderIndex, int inorderStart, int inorderEnd, unordered_map<char, int>& inorderMap) {
    if (inorderStart > inorderEnd) {
        return nullptr;
    }

    char rootVal = preorder[preorderIndex++];
    TreeNode* root = new TreeNode(rootVal);

    int inorderIndex = inorderMap[rootVal];

    root->left = buildTreeHelper(preorder, inorder, preorderIndex, inorderStart, inorderIndex - 1, inorderMap);
    root->right = buildTreeHelper(preorder, inorder, preorderIndex, inorderIndex + 1, inorderEnd, inorderMap);

    return root;
}

TreeNode* buildTree(const string& preorder, const string& inorder) {
    unordered_map<char, int> inorderMap;
    for (int i = 0; i < inorder.length(); ++i) {
        inorderMap[inorder[i]] = i;
    }
    int preorderIndex = 0;
    return buildTreeHelper(preorder, inorder, preorderIndex, 0, inorder.length() - 1, inorderMap);
}

void printPreorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}


void printInorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}


int main() {
    string preorder = "ABDCEF"; 
    string inorder = "DBAECF"; 
    TreeNode* root = buildTree(preorder, inorder);

    cout << "Duyet theo thu tu truoc: ";
    printPreorder(root);
    cout << endl;

    cout << "Duyet theo thu tu giua: ";
    printInorder(root);
    cout << endl;

    return 0;
}

