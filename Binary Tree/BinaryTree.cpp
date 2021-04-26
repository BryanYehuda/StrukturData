#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

        void inOrder( Node *root) {
            if (root)
            {
                inOrder(root->left);
                printf("%d ",root->data);
                inOrder(root->right);
            }
        }

        void postOrder( Node *root) {
            if (root)
            {

                postOrder(root->left);
                postOrder(root->right);
                printf("%d ",root->data);
            }
        }

        void preOrder( Node *root) {
            if (root)
            {
                printf("%d ",root->data);
                preOrder(root->left);
                preOrder(root->right);
            }
        }

        int findMinNode(Node *node) {
            Node *currNode = node;
            while (currNode && currNode->left != NULL)
                currNode = currNode->left;

            return (currNode->data);
        }

        int findMaxNode(Node *node) {
            Node *currNode = node;
            while (currNode && currNode->right != NULL)
                currNode = currNode->right;

            return (currNode->data);
        }

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    //std::cin >> t;
    cin >> t;

    while(t-- > 0) {
        cin >> data;
        root = myTree.insert(root, data);
    }

    cout << "Ini inOrder: ";
	myTree.inOrder(root);
	cout << "\n";

	cout << "Ini preOrder: ";
	myTree.preOrder(root);
	cout << "\n";

	cout << "Ini postOrder: ";
	myTree.postOrder(root);
	cout << "\n";

    int smallest = myTree.findMinNode(root);
	int biggest = myTree.findMaxNode(root);

	cout << "ini Min node: " << smallest << endl;
	cout << "ini Max node: " << biggest << endl;

    return 0;
}
