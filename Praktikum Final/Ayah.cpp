#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>
using namespace std;

struct NodeBST
{
 	int data;
 	NodeBST* left;
 	NodeBST* right;
};

NodeBST *getNode(int item) 
{
   	NodeBST *temp = new NodeBST;
   	temp->data = item;
   	temp->left = temp->right = NULL;
   	return temp;
}

NodeBST* insert(struct NodeBST* node, int data) 
{
   	if (node == NULL) return getNode(data);
   	if (data < node->data) 
   	{
      	node->left = insert(node->left, data);
   	}
   	else if (data > node->data) 
   	{ 
      	node->right = insert(node->right, data);
   	}
   	return node;
}

void Parent (NodeBST* node, int value, int parent)
{
 	if (node==NULL) return;
 	if (node->data==value) 
  	cout << parent <<endl;
 	else 
 	{	
  		Parent(node->left, value, node->data);
  		Parent(node->right, value, node->data);
 	}
}

void print (NodeBST *node)
{
 	if(node==NULL) cout << "NULL ";
 	else printf("%d ", node->data);
}

void Child (NodeBST* node, int value)
{ 
 	if (node==NULL) return;
 	if (node->data==value)
 	{
  		print(node->left);
  		print(node->right);
  		cout << endl;
 	}
 	else
 	{
  		Child(node->left, value);
  		Child(node->right, value);
 	}
}

int main()
{
    NodeBST* root;
 	root=NULL;
    int tc;
    string n;
    cin >> tc;
    while (tc--)
	{
    	int tq;
    	cin >> tq;
    	switch (tq)
    	{
    		case 1:
  			{   
            	int k;
            	cin >> k;
            	root=insert(root, k);
            	break;
        	}
        	case 2:
  			{  
     			cin >> n;
            	if (n=="child")
				{
    			int x; 
             	cin >> x;
             	Child(root, x);
            	}
            	else if (n=="parent" )
				{
            	int x;
    			cin >> x;
             	Parent(root, x, -1);
            	}
   			break;        
        	}
     	}
    }
    return 0;
}
