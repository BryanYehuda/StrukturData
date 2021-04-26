#include <bits/stdc++.h> 
using namespace std; 
  
class NODEBST 
{ 
public: 
    int data; 
    NODEBST *left, *right; 
}; 
  

NODEBST* newNode(int item) 
{ 
    NODEBST* temp = new NODEBST(); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  

void modifyBSTUtil(NODEBST* root, int* sum) 
{ 
    if (root == NULL) 
        return; 
    modifyBSTUtil(root->right, sum); 
    *sum = *sum + root->data; 
    root->data = *sum; 
    modifyBSTUtil(root->left, sum); 
} 
  
void modifyBST(NODEBST* root) 
{ 
    int sum = 0; 
    modifyBSTUtil(root, &sum); 
} 

void inorder(NODEBST* root) 
{ 
    if (root != NULL) 
	{ 
        inorder(root->left); 
        cout << root->data << " "; 
        inorder(root->right); 
    } 
} 
  

NODEBST* insert(NODEBST* node, int data) 
{ 
    
    if (node == NULL) 
        return newNode(data); 
    if (data < node->data) 
        node->left = insert(node->left, data); 
    else
        node->right = insert(node->right, data); 
    return node; 
} 
  

int main() 
{ 
    int a[100];
    NODEBST* root = NULL;
    int i=1, b;
    while(scanf("%d", &a[i]) != EOF)
	{
        b = a[i];
        root = insert(root, b);
    }
    modifyBST(root); 
    inorder(root); 
    return 0; 
}
