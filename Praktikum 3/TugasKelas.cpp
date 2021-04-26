#include<bits/stdc++.h> 
#include<iostream>
#include<map>
#include<string.h>
using namespace std; 
  
class Node  
{  
    public: 
    int key;  
    Node *left;  
    Node *right;  
    int height;  
};  
  
int max(int a, int b);  
    
int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
    
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
Node* newNode(int key)  
{  
    Node* node = new Node(); 
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;   
    return(node);  
}  
  
Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    x->right = y;  
    y->left = T2;  
    
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
    
    return x;  
}  
  
Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
   
    y->left = x;  
    x->right = T2;  
    
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
   
    return y;  
}  
   
int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
    
Node* insert(Node* node, int key)  
{  
    if (node == NULL)  
        return(newNode(key));  
  
    if (key < node->key)  
        node->left = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
    else  
        return node;  
  
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    int balance = getBalance(node);  
      
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node);  
   
    if (balance < -1 && key > node->right->key)  
        return leftRotate(node);  
  
    if (balance > 1 && key > node->left->key)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
   
    if (balance < -1 && key < node->right->key)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    return node;  
}  
   
void verticalSum(Node *root, int dist, auto &map)
{
    if (root == nullptr)
        return;
 
    map[dist] += root->key;
 
    verticalSum(root->left, dist - 1, map);
 
    verticalSum(root->right, dist + 1, map);
}
 
void verticalSum(Node *root)
{
    map<int, int> map;
 
    verticalSum(root, 0, map);
 
    for (auto it: map)
        cout << it.second << " ";
}
  
int main()  
{  
    struct Node *root = NULL;
    char query[10];
    int N, value;
    scanf("%d", &N);

    while (N)
    {
        scanf("%s", query);
        if (strcmp(query, "insert") == 0)
        {
            //printf("halo");
            scanf("%d", &value);
            root = insert(root, value);
        }
        else if (strcmp(query, "print") == 0)
        {
            verticalSum(root);
            printf("\n");
        }

        N--;
    }

  return 0;
}
