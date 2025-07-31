#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
static int idx =-1;
Node* buildTree(vector<int>preorder){
    idx++;
    if(preorder[idx]==-1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right =buildTree(preorder);

    return root;
}
int height(Node* root){// Function to calculate the height of the binary tree
    if (root==NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int main(){
    vector<int> preorder= {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    
    Node* root = buildTree(preorder);
    cout << height(root) << endl;

    return 0;

}