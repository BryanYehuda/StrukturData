#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> inorder;
vector<int> postorder;
vector<int> preorder;
struct NodeBST
{
    NodeBST *left, *right;
    int key;
};

struct BST
{
    NodeBST *_root;
    unsigned int _size;

    void init()
    {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool find(int value)
    {
        NodeBST *temp = __search(_root, value);
        if (!temp)
            return false;

        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value)
    {
        if (!find(value))
        {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value)
    {
        if (find(value))
        {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder()
    {
        __inorder(_root);
    }

    void traversePreorder()
    {
        __preorder(_root);
    }

    void traversePostorder()
    {
        __postorder(_root);
    }

private:
    NodeBST *__createNode(int value)
    {
        NodeBST *newNode = (NodeBST *)malloc(sizeof(NodeBST));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    NodeBST *__search(NodeBST *root, int value)
    {
        while (root != NULL)
        {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    NodeBST *__insert(NodeBST *root, int value)
    {
        if (root == NULL)
            return __createNode(value);

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
    }

    NodeBST *__findMinNode(NodeBST *node)
    {
        NodeBST *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;

        return currNode;
    }

    NodeBST *__remove(NodeBST *root, int value)
    {
        if (root == NULL)
            return NULL;

        if (value > root->key)
            root->right = __remove(root->right, value);
        else if (value < root->key)
            root->left = __remove(root->left, value);
        else
        {

            if (root->left == NULL)
            {
                NodeBST *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL)
            {
                NodeBST *leftChild = root->left;
                free(root);
                return leftChild;
            }

            NodeBST *temp = __findMinNode(root->right);
            root->key = temp->key;
            root->right = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(NodeBST *root)
    {
        if (root)
        {
            __inorder(root->left);
            inorder.push_back(root->key);
            __inorder(root->right);
        }
    }

    void __postorder(NodeBST *root)
    {
        if (root)
        {
            __postorder(root->left);
            __postorder(root->right);
            postorder.push_back(root->key);
        }
    }

    void __preorder(NodeBST *root)
    {
        if (root)
        {
            preorder.push_back(root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

int main()
{
    BST set;
    set.init();

    int tc;
    cin >> tc;
    while (tc--)
    {
        int Q;
        cin >> Q;
        if (Q== 1)
        {
            int n;
            cin >> n;
            set.insert(n);
        }
        else
        {
            char command[50];
            int urutan;
            cin >> command;
            cin >> urutan;
            if (strcmp(command, "inorder") == 0)
            {
                set.traverseInorder();
                cout << inorder.at(urutan - 1) << endl;
                inorder.clear();
            }
            else if (strcmp(command, "preorder") == 0)
            {
                set.traversePreorder();
                cout << preorder.at(urutan - 1) << endl;
                preorder.clear();
            }
            else if (strcmp(command, "postorder") == 0)
            {
                set.traversePostorder();
                cout << postorder.at(urutan - 1) << endl;
                postorder.clear();
            }
        }
    }
    return 0;
}
