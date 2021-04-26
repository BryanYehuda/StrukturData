#include<bits/stdc++.h> 
#include <list> 
#include <iterator> 
using namespace std; 
typedef long long LL;
  
struct Node 
{ 
    LL data; 
    Node *left, *right; 
}; 
  
Node *newNode(LL item) 
{ 
    Node *temp = new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
Node* insert(Node* node, LL data) 
{ 
    if (node == NULL) return newNode(data); 
  
    if (data < node->data) 
        node->left  = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data); 
  
    return node; 
} 

void find(Node *root, LL level, LL &maxLevel, LL &res) 
{ 
    if (root != NULL) 
    { 
        find(root->left, ++level, maxLevel, res); 
        if (level > maxLevel) 
        { 
            res = root->data; 
            maxLevel = level; 
        } 
  
        find(root->right, level, maxLevel, res); 
    } 
} 

LL findDistance(Node* root, LL key) 
{ 
    if (root == NULL) 
	{ 
        return -1; 
    } 
  
    if (root->data == key) 
        return 0; 
  
    queue<Node*> q;  
    q.push(root);  
    q.push(NULL);  
    LL levelCount = 0; 
  
    while (!q.empty()) 
	{ 
  
        Node* temp = q.front(); 
        q.pop(); 
   
        if (temp == NULL && !q.empty()) 
		{ 
            q.push(NULL); 
            levelCount++; 
        } 
        else if (temp != NULL) 
		{ 
            if (temp->data == key) 
                return levelCount; 
  
            if (temp->left) 
                q.push(temp->left); 
  
            if (temp->right) 
                q.push(temp->right); 
        } 
    } 
    return -1; 
} 

bool isLeaf(Node* root, LL key) 
{
    if (root == NULL)       
        return false;
    if (root->left == NULL && root->right == NULL)      
        return true;       
} 
  
int main() 
{ 
	LL tc;
	LL awal=0;
	LL angka=0;
	LL answer=0;
	LL distance;
	list <LL> leaf;
    Node *root = NULL; 
    leaf.push_front(0);
    leaf.push_front(0);
    list<LL>::iterator it1 = leaf.begin(); 
    list<LL>::iterator it2 = leaf.begin();
    advance(it2, 1);
    
    cin >> tc;
    cin >> awal;
    root = insert(root, awal); 
    distance = findDistance(root, awal);
    leaf.push_front(distance);
    leaf.reverse();
    answer = *it1 + *it2;
    cout << answer << endl; 
    
    for(LL i=1; i<tc; i++)
    {
    	cin >> angka;
    	insert(root, angka); 
    	distance = findDistance(root, angka);
    	leaf.emplace_front(distance);
    	leaf.reverse();
    	answer = *it1 + *it2;
    	cout << answer << endl; 
	}
    return 0;
}
