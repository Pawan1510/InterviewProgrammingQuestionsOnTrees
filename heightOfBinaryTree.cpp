// Height of Binary Tree with
// Time Complexity: O(n)
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
int heightOfTree( Node *root )
{
    if( root == NULL )  return 0;
    else
    {
        int lDepth = heightOfTree( root->left );
        int rDepth = heightOfTree( root->right );

        if( lDepth > rDepth )
            return( lDepth + 1 );
        else
            return( rDepth + 1 );
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout<<"Height of Tree: "<<heightOfTree(root);
}
