#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
using LL = long long int;
using namespace std;

typedef struct AVLNode_t
{
    LL data;
    struct AVLNode_t *left, *right;
    LL height;
    LL size;
    LL index;
} NodeAVL;

typedef struct AVL_t
{
    NodeAVL *_root;
    unsigned long long int _size;
} AVL;

NodeAVL *_avl_createNode(LL value)
{
    NodeAVL *newNode = (NodeAVL *)malloc(sizeof(NodeAVL));
    newNode->data = value;
    newNode->height = 1;
    newNode->size = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

NodeAVL *_search(NodeAVL *root, LL value)
{
    while (root != NULL)
    {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

LL getNodeSize(NodeAVL *node)
{
    return node ? node->size : 0;
}

LL nodeSize(NodeAVL *node)
{
    if (node)
        return node->size;
    return 0;
}

LL _getHeight(NodeAVL *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

LL _max(LL a, LL b)
{
    return (a > b) ? a : b;
}

NodeAVL *_rightRotate(NodeAVL *pivotNode)
{
    NodeAVL *newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
    pivotNode->size = getNodeSize(pivotNode->left) + getNodeSize(pivotNode->right) + 1;
    newParrent->height = _max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;
    newParrent->size = getNodeSize(newParrent->left) + pivotNode->size + 1;

    return newParrent;
}

NodeAVL *_leftRotate(NodeAVL *pivotNode)
{

    NodeAVL *newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left),_getHeight(pivotNode->right)) + 1;
    pivotNode->size = getNodeSize(pivotNode->left) + getNodeSize(pivotNode->right) + 1;
    newParrent->height = _max(_getHeight(newParrent->left),_getHeight(newParrent->right)) + 1;
    newParrent->size = getNodeSize(newParrent->right) + pivotNode->size + 1;

    return newParrent;
}

LL sort_desc(LL a, LL index, NodeAVL *node)
{
    NodeAVL *temp = node;
    if (a < node->data)
    {
        NodeAVL *r = node->left;
        if (r)
            return sort_desc(a, index + nodeSize(r->right) + 1, node->left);
    }
    else if (a > node->data)
    {
        NodeAVL *r2 = node->right;
        if (r2)
            return sort_desc(a, index - nodeSize(r2->left) - 1, node->right);
    }
    return index;
}

void GetPosition(LL v, AVL *node)
{
    LL index = getNodeSize(node->_root->right);
    cout << sort_desc(v, index, node->_root) + 1 << endl;
}

NodeAVL *_leftCaseRotate(NodeAVL *node)
{
    return _rightRotate(node);
}

NodeAVL *_rightCaseRotate(NodeAVL *node)
{
    return _leftRotate(node);
}

NodeAVL *_leftRightCaseRotate(NodeAVL *node)
{
    node->left = _leftRotate(node->left);
    return _rightRotate(node);
}

NodeAVL *_rightLeftCaseRotate(NodeAVL *node)
{
    node->right = _rightRotate(node->right);
    return _leftRotate(node);
}

LL _getBalanceFactor(NodeAVL *node)
{
    if (node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}

NodeAVL *_insert_AVL(AVL *avl, NodeAVL *node, LL value)
{
    if (node == NULL)
        return _avl_createNode(value);
    if (value < node->data)
        node->left = _insert_AVL(avl, node->left, value);
    else if (value > node->data)
        node->right = _insert_AVL(avl, node->right, value);

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

    LL balanceFactor = _getBalanceFactor(node);

    if (balanceFactor > 1 && value < node->left->data)
        return _leftCaseRotate(node);
    if (balanceFactor > 1 && value > node->left->data)
        return _leftRightCaseRotate(node);
    if (balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if (balanceFactor < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);

    node->size = 1 + nodeSize(node->left) + nodeSize(node->right);

    return node;
}

NodeAVL *_findMinNode(NodeAVL *node)
{
    NodeAVL *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

NodeAVL *_remove_AVL(NodeAVL *node, LL value)
{
    if (node == NULL)
        return node;
    if (value > node->data)
        node->right = _remove_AVL(node->right, value);
    else if (value < node->data)
        node->left = _remove_AVL(node->left, value);
    else
    {
        NodeAVL *temp;
        if ((node->left == NULL) || (node->right == NULL))
        {
            temp = NULL;
            if (node->left == NULL)
                temp = node->right;
            else if (node->right == NULL)
                temp = node->left;

            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else
                *node = *temp;

            free(temp);
        }
        else
        {
            temp = _findMinNode(node->right);
            node->data = temp->data;
            node->right = _remove_AVL(node->right, temp->data);
        }
    }

    if (node == NULL)
        return node;

    node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

    LL balanceFactor = _getBalanceFactor(node);

    if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
        return _leftCaseRotate(node);

    if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
        return _leftRightCaseRotate(node);

    if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
        return _rightCaseRotate(node);

    if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
        return _rightLeftCaseRotate(node);

    return node;
}

void avl_init(AVL *avl)
{
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl)
{
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, LL value)
{
    NodeAVL *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_search(AVL *avl, LL value)
{
    if (avl_find(avl, value))
    {
        NodeAVL *temp = _search(avl->_root, value);
        cout << temp->data;
    }
}

void avl_insert(AVL *avl, LL value)
{
    if (!avl_find(avl, value))
    {
        avl->_root = _insert_AVL(avl, avl->_root, value);
        avl->_size++;
    }
}

int main()
{
    AVL tree_avl;
    avl_init(&tree_avl);
    LL tc, elem;

    cin >> tc;

    while (tc--)
	{
        cin >> elem;
        avl_insert(&tree_avl, elem);
        GetPosition(elem, &tree_avl);
    }
    return 0;
}
