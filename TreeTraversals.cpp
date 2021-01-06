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
void inOrder( Node *root )
{
    if( root == NULL ) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void preOrder( Node *root )
{
    if( root == NULL ) return;
    cout<<root->data<<" ";
    preOrder( root->left );
    preOrder( root->right );
}
void postOrder( Node *root )
{
    if( root == NULL )  return;
    postOrder( root->left );
    postOrder( root->right );
    cout<<root->data<<" ";
}
void levelOrder( Node *root )
{
    if( root == NULL ) return;

    queue<Node*> q;
    q.push(root);

    while( q.empty() == false ) {

        Node *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if( temp->left != NULL )
            q.push( temp->left );

        if( temp->right != NULL )
            q.push( temp->right );

    }
}
void getVerticalOrder( Node *root, int hd, map< int, vector<int> > &m )
{
    if( root == NULL )  return;
    m[hd].push_back( root->data );

    getVerticalOrder( root->left, hd - 1, m );

    getVerticalOrder( root->right, hd + 1, m );
}
void printVerticalOrder(  Node *root )
{
    map< int, vector<int> > m;
    int hd = 0;
    getVerticalOrder( root, hd, m );
    for( auto it = m.begin(); it != m.end(); it++ ) {
        for( int i=0; i<it->second.size(); i++ ) {
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->right = new Node(8);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);
    /*
                 1
               /    \
              2      3
             / \    /  \
            4   5  6    7
                    \    \
                     8    9
    */
    cout<<"Inorder Traversal: ";        inOrder(root);              cout<<endl;
    cout<<"Preorder Traversal: ";       preOrder(root);             cout<<endl;
    cout<<"PostOrder Traversal: ";      postOrder(root);            cout<<endl;
    cout<<"LevelOrder Traversal: ";     levelOrder(root);           cout<<endl;
    cout<<"VerticalOrder Traversal: ";  cout<<endl; printVerticalOrder(root);   cout<<endl;
    return 0;
}
