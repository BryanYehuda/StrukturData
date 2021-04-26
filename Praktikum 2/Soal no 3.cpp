#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std; 

class BST {
public:
    int data;
    BST* parent;
    BST* left;
    BST* right;
};
  
void reverseLevelOrder(BST* root) 
{ 
    stack <BST *> S; 
    queue <BST *> Q; 
    Q.push(root); 
  
    while (Q.empty() == false) 
    { 
        root = Q.front(); 
        Q.pop(); 
        S.push(root); 
  
        if (root->right) 
            Q.push(root->right);
  
        if (root->left) 
            Q.push(root->left); 
    } 
  
    while (S.empty() == false) 
    { 
        root = S.top(); 
        cout << root->data << " "; 
        S.pop(); 
    } 
} 
 
BST* createBSTNode(int data)
{
    BST* newNode = new BST();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}
 
void bst_insert(BST*& tree, BST* node)
{
    BST* prev = NULL;
    BST* iter=tree;
    while(iter != NULL)
    {
        prev = iter;
        if(node->data < iter->data)
            iter = iter->left;
        else
            iter = iter->right;
    }
    node->parent = prev;
 
    if(prev == NULL)
        tree = node;
    else {
    
        if(node->data < prev->data)
            prev->left = node;
        else
            prev->right = node;
    }
 
}
 
BST* convert_arr_bst(int* arr, int size)
{
    BST* tree=NULL;
    for(int i=0;i<size;i++) {
        bst_insert(tree, createBSTNode(arr[i]));
    }
    return tree;
}
  
int main() 
{ 
    int sizeofarray;
	cin>>sizeofarray;
	int A[sizeofarray];
	for(int i=0; i<sizeofarray; i++)
	{
		cin>>A[i];
	}
    BST* root = convert_arr_bst(A, sizeof(A)/sizeof(int));
    reverseLevelOrder(root); 
    cout<<"\n"; 
  
    return 0; 
} 
