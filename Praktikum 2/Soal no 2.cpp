#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct bstnode_t 
{
    int key;
    struct bstnode_t \
        *left, *right;
} NODEBST;

typedef struct bst_t 
{
    NODEBST *_root;
    unsigned int _size;
} BST;

NODEBST* __bst__createNode(int value) 
{
    NODEBST *newNode = (NODEBST*) malloc(sizeof(NODEBST));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

NODEBST* __bst__insert(NODEBST *root, int value) 
{
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);

    return root;
}

NODEBST* __bst__search(NODEBST *root, int value) 
{
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

NODEBST* __bst__findMinNode(NODEBST *node) 
{
    NODEBST *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

NODEBST* __bst__remove(NODEBST *root, int value) 
{
    if (root == NULL) return NULL;

    if (value > root->key)
        root->right = __bst__remove(root->right, value);
    else if (value < root->key)
        root->left = __bst__remove(root->left, value);
    else {

        if (root->left == NULL) 
		{
            NODEBST *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) 
		{
            NODEBST *leftChild = root->left;
            free(root);
            return leftChild;
        }

        NODEBST *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(NODEBST *root) 
{
    if (root) 
	{
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(NODEBST *root) 
{
    if (root) 
	{
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(NODEBST *root) 
{
    if (root) 
	{
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

void bst_init(BST *bst) 
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) 
{
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) 
{
    NODEBST *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) 
{
    if (!bst_find(bst, value)) 
	{
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) 
{
    if (bst_find(bst, value)) 
	{
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

void bst_inorder(BST *bst) 
{
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) 
{
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) 
{
    __bst__preorder(bst->_root);
}


int bst_left(BST *bst, int value) 
{
    NODEBST *temp = __bst__search(bst->_root, value);
    if(temp->key == value) 
	{
        if(temp->left!=NULL)
		{
            temp = temp->left;
            return temp->key;
        }
    }
    return 0;
}

int bst_right(BST *bst, int value) 
{
    NODEBST *temp = __bst__search(bst->_root, value);
    if(temp->key == value) 
	{
        if(temp->right!=NULL) 
		{
            temp = temp->right;
            return temp->key;
        }
    }
    return 0;
}

NODEBST* __bst__searchParent(NODEBST *root, int value) 
{
    NODEBST *temp = NULL;
    while (root != NULL) 
	{
        if (value < root->key) 
		{
            temp = root;
            root = root->left;
        }else if (value > root->key)
		{
            temp = root;
            root = root->right;
        }else
		{
            return temp;
        }
    }
    return temp;
}

int bst_findParent(BST *bst, int value) 
{
    NODEBST *temp = __bst__searchParent(bst->_root, value);
    if(temp == NULL) 
	{
        return -1;
    } else 
	{
        return temp->key;
    }
}

int main()
{
    BST tree;
    bst_init(&tree);

    int n, m, i;
    scanf("%d", &n);

    for(i=0; i<n; i++) 
	{
        int x;
        scanf("%d", &x);
        bst_insert(&tree, x);
    }
    scanf("%d", &m);
    
    for(i=0; i<m; i++) 
	{
        int a, x, y, z;
        scanf("%d", &x);
        if(bst_find(&tree, x) == false)
		{
            printf("404 Not Found\n");
        } else 
		{
            a = bst_findParent(&tree, x);
            y = bst_right(&tree, x);
            z = bst_left(&tree, x);
                if(y == 0 && z == 0)
				{
                printf("%d\n", a);
            } else if (y == 0)
			{
                printf("%d %d\n", a, z);
            } else if(z == 0)
			{
                printf("%d %d\n", a, y);
            } else 
			{
                   printf("%d %d %d\n", a, z, y);
            }
        }
    }
    
    return 0;
}
