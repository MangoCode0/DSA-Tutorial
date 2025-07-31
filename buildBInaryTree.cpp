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
void preOrder(Node* root){// preorder traversal.
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){//inorder traversal.
    if (root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}
void postOrder(Node* root){//postorder traversal.
    if (root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void levelOrder(Node* root){// level order traversal;
    queue<Node*>q;
    q.push(root);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
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
    // cout<<root->data<<endl;
    // cout<<root->right->data<<endl;
    // cout<<root->left->data<<endl;

    // preOrder(root);
    // inOrder(root);
    // postOrder(root);
    // levelOrder(root);
    cout << height(root) << endl;
    return 0;

}