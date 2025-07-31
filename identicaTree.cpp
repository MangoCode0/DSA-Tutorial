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
bool isidentical(Node* p, Node* q){
    if(p==NULL && q==NULL) return true;
    if(p==NULL || q==NULL) return false;

    int isleftsame = isidentical(p->left,q->left);
    int isrightsame = isidentical(p->right, q->right);

    return isleftsame && isrightsame && p->data == q->data;

}


int main(){
    vector<int> p= {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    vector<int> q ={3,4,-1,-1,5,-1,-1} ;
    Node* root1 = buildTree(p);
    Node* root2 = buildTree(q);
    cout << (isidentical(root1, root2) ? "Identical" : "Not Identical") << endl;
    return 0;

}