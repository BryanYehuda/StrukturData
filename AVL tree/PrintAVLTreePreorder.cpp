#include<bits/stdc++.h> 
using namespace std; 
#define COUNT 10

//Node Tree AVL
class Node 
{ 
 public: 
 int key; 
 Node *left; 
 Node *right; 
 int height; 
}; 

//Fungsi Mencari Maksimum dari 2 Variabel
int max(int a, int b); 

//Fungsi Mencari Height dari Tree
int height(Node *N) 
{ 
 if (N == NULL) 
  return 0; 
 return N->height; 
} 

//Fungsi Mencari Maksimum dari 2 Variabel 
int max(int a, int b) 
{ 
 return (a > b)? a : b; 
} 

//Fungsi yang memasukkan sebuah Node ke dalam Tree
Node* newNode(int key) 
{ 
 Node* node = new Node(); 
 node->key = key; 
 node->left = NULL; 
 node->right = NULL; 
 node->height = 1; //Node yang baru awalnya dimasukkan ke dalam leave
 return(node); 
} 

//Fungsi Melakukan Right Rotation 
Node *rightRotate(Node *y) 
{ 
 Node *x = y->left; 
 Node *T2 = x->right; 

 //Lakukan Rotasi 
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

void print2DUtil(Node *root, int space)  
{  
    //Base case  
    if (root == NULL)  
        return;  
  
    //Tambahkan jarak antara tingkatan 
    space += COUNT;  
  
    //Proses anak kanan dahulu 
    print2DUtil(root->right, space);  
  
    //Print Node saat ini setelah spasi 
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->key<<"\n";  
  
    //Proses anak kiri 
    print2DUtil(root->left, space);  
}  
 
void print2D(Node *root)  
{  
    //Initial space count 0 
    print2DUtil(root, 0);  
}  

//Fungsi Left Rotation 
Node *leftRotate(Node *x) 
{ 
 Node *y = x->right; 
 Node *T2 = y->left; 

 //Lakukan Rotasi
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

//Dapatkan Balance factor dari node N 
int getBalance(Node *N) 
{ 
 if (N == NULL) 
  return 0; 
 return height(N->left) - height(N->right); 
} 

//Pembuatan BST biasa 
Node* insert(Node* node, int key) 
{ 
 /* 1.Masukkan Node ke dalam BST seperti biasa */
 if (node == NULL) 
  return(newNode(key)); 

 if (key < node->key) 
  node->left = insert(node->left, key); 
 else if (key > node->key) 
  node->right = insert(node->right, key); 
 else //Key tidak boleh sama di dalam BST 
  return node; 

 /* 2. Update height */
 node->height = 1 + max(height(node->left), 
      height(node->right)); 

 /* 3. Dapatkan balance factor untuk melihat unbalanced node */
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

//Fungsi print preorder
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
 
 root = insert(root, 12); 
 root = insert(root, 8); 
 root = insert(root, 7); 
 root = insert(root, 14); 
 root = insert(root, 18); 
 root = insert(root, 10); 
 root = insert(root, 20);
 root = insert(root, 9);

 print2D(root); 
 return 0; 
}
