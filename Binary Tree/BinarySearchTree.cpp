#include <bits/stdc++.h>

using namespace std;

class Node {
    private:
    int a;

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

        void printLeaves(Node* root)
        {
            if (root)
            {
                if (!root->left && !root->right)
                {
                    cout << root->data << " ";
                    return;
                }

                if (root->left)
                    printLeaves(root->left);

                if (root->right)
                    printLeaves(root->right);
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

        bool hasPath(Node* root, vector<int>& arr, int x)
        {
            if (!root)
                return false;
                
            arr.push_back(root->data);

            if (root->data == x)
                return true;

            if (hasPath(root->left, arr, x) ||
                hasPath(root->right, arr, x))
                return true;
                
            arr.pop_back();
            return false;
        }

        void printPath(Node* root, int x)
        {
            vector<int> arr;

            if (hasPath(root, arr, x))
            {
                for (int i=0; i<arr.size()-1; i++)
                    cout << arr[i] << "->";
                cout << arr[arr.size() - 1];
            }
            else
                cout << "No Path";
        }

        int countNode( Node *root) {
            if (root)
            {
                return (1 + countNode(root->left) + countNode(root->right));
            }
        }

}; //End of Solution

int main() {

    //input
    //20 60 52 30 8 56 6 7 12 21 27 40 15

    Solution myTree;
    Node* root = NULL;

    int data;

    while(cin >> data) {
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

	cout << "Ini Leaves: ";
	myTree.printLeaves(root);
	cout << "\n";

	cout << "Banyak node di kiri Root: ";
	int kiri = myTree.countNode(root->left);
	cout << kiri << "\n";

	cout << "Banyak node di kanan Root: ";
	int kanan = myTree.countNode(root->right);
	cout << kanan << "\n";

	cout << "Path untuk ke 27: ";
	myTree.printPath(root,27);
	cout << "\n";

	cout << "Path untuk ke 7: ";
	myTree.printPath(root,7);
	cout << "\n";
    return 0;
}
