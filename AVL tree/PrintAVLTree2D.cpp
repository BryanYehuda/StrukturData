 #include<bits/stdc++.h> 
using namespace std; 
  
// Node Tree AVL  
class Node  
{  
    public: 
    int key;  
    Node *left;  
    Node *right;  
    int height;  
};  
  
//Fungsi mencari mana yang lebih besar 
int max(int a, int b);  
  
//Fungsi mencari height dari tree  
int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
    
//Fungsi mencari mana yang lebih besar
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
//Fungsi untuk menemukan sebuah Node
Node* newNode(int key)  
{  
    Node* node = new Node(); 
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; //Node yang baru ditaruh di Leave  
    return(node);  
}  
  
//Fungsi untuk melakukan Right Rotation  
Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
  	//Lakukan Rotation 
    x->right = y;  
    y->left = T2;  
  
    //Update Height  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
    //Kembalikan Root yang baru  
    return x;  
}  
  
//Fungsi untuk melakukan Left Rotation 
Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    //Lakukan Rotation  
    y->left = x;  
    x->right = T2;  
  
    //Update Height   
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    //Kembalikan Root yang baru  
    return y;  
}  
  
//Cek apakah Tree Balance  
int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
  
//Fungsi memasukkan Node ke dalam BST  
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
    
    // Left Left Case  
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && key > node->right->key)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->left->key)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->key)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    return node;  
}  
  
//Fungsi Print Preorder  
void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  
  
int main()  
{  
    Node *root = NULL;  
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  
      
    /*  AVL Tree : 
                30  
            / \  
            20 40  
            / \ \  
        10 25 50  
    */
    cout << "Preorder traversal dari "
            "constructed AVL tree adalah \n";  
    preOrder(root);  
      
    return 0;  
}  
