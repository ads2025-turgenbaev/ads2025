#include <iostream>

using namespace std;


class Node {
public:
    int value;
    Node *right;
    Node *left;

    Node(int value) {
        this->value = value;
        right = nullptr;
        left = nullptr;
    }
};


class BinarySearchTree {
public:
    Node *root;


    BinarySearchTree() {
        root = nullptr;
    }

    bool insert(int value) {
        Node *newNode = new Node(value);

        if (root == nullptr) {
            this->root = newNode;
            return false;
        }

        Node *temp = root;
        while (true) {
            if (value == temp->value) {
                return true;
            }
            if (value > temp->value) {
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return true;
                }

                temp = temp->right;
            } else {
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    return true;
                }

                temp = temp->left;
            }
        }
    }

    bool contains(int value) {
        if (root == nullptr) {
            return false;
        }

        Node *temp = root;

        while (temp) {
            if (value == temp->value) {
                return true;
            } else if (value > temp->value) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }

        return false;
    }

    void inorder(Node *node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->value << " ";

        inorder(node->right);
    }

    Node *deleteNode(Node *node, int value) {
        if (node == nullptr) return nullptr;

        if (value < node->value) {
            node->left = deleteNode(node->left, value);
        }else if (value > node->value) {
            node->right = deleteNode(node->right, value);
        }else {
            // Case 1: no children
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Case 2: one child
            else if (node->left == nullptr) {
                Node *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: two children
            else {
                Node *successor = findMin(node->right);
                node->value = successor->value;
                node->right = deleteNode(node->right, successor->value);
            }
        }
        return node;
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

private:
    Node *findMin(Node *node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};


int main() {
    BinarySearchTree *myTree = new BinarySearchTree();

    // cout << myTree->root << endl;

    myTree->insert(17);
    myTree->insert(2);
    myTree->insert(4);
    myTree->insert(6);
    myTree->insert(18);
    myTree->insert(29);
    myTree->insert(34);
    myTree->insert(3);

    // cout << myTree->contains(29) << endl;
    // cout << myTree->contains(28) << endl;


    myTree->inorder(myTree->root);


    return 0;
}