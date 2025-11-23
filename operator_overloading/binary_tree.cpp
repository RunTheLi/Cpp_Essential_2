#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    private:
        Node* root;

        Node* insert(Node* node, int val);
        void inorder_print(ostream& os, Node* node) const;
        void destroy(Node* node);  
    public:
        BinaryTree();
        ~BinaryTree();

        void insert(int val); 

        friend ostream& operator<<(ostream& os, const BinaryTree& tree);
};

BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::insert(int val) {
    root = insert(root, val);
}

Node* BinaryTree::insert(Node* node, int val) {
    if(node == nullptr) {
        return new Node(val);
    }

    if(val < node->value) {
        node->left = insert(node->left, val);
    } else if (val > node->value) {
        node->right = insert(node->right, val);
    }

    return node;
}

void BinaryTree::inorder_print(ostream& os, Node* node) const {
    if(node == nullptr) return;

    inorder_print(os, node->left);

    os << node->value << endl;

    inorder_print(os, node->right);
}

ostream& operator<<(ostream& os, const BinaryTree& tree){
    tree.inorder_print(os, tree.root);
    return os;
}

BinaryTree::~BinaryTree() {
    destroy(root);
}

void BinaryTree::destroy(Node* node){
    if(!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

int main(){
    BinaryTree tree;

    tree.insert(3);
    tree.insert(5);
    tree.insert(2);

    cout << tree;

    return 0;
}
