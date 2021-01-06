// CHECK IF A GIVEN BNARY TREE IS BST OR NOT
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node( int data )
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int isBstUtil( Node *root, int min, int max )
{
    if( root == NULL )
        return 1;

    if( root->data < min || root->data > max )
        return 0;

    return isBstUtil( root->left, min, root->data-1 ) && isBstUtil( root->right, root->data+1, max );
}
int isBst( Node *root )
{
    return( isBstUtil( root, INT_MIN, INT_MAX ) );
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    isBst(root)? cout<<"Is BST\n" : cout<<"Not a BST";
}
