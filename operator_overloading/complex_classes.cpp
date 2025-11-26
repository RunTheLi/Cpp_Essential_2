#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int val) : value(val), left(nullptr), right(nullptr) {}

    void addValue(int val);
};

void BinaryTree::addValue(int val) {
    if (val < value) {
        if (left == nullptr) left = new BinaryTree(val);
        else left->addValue(val);
    } else {
        if (right == nullptr) right = new BinaryTree(val);
        else right->addValue(val);
    }
}

class InorderTree : public BinaryTree {
public:
    InorderTree(int val);

    friend ostream& operator<<(ostream& out, const InorderTree& tree);

    int operator[](int index);

private:
    void traverseInorder(const BinaryTree* node, vector<int>& result) const;
};

class PreorderTree : public BinaryTree{
public:
    PreorderTree(int val);

    friend ostream& operator<<(ostream& out, const PreorderTree& tree);

    int operator[](int index);

private:
    void traversePreorder(const BinaryTree* node, vector<int>& result) const;
};

class PostorderTree : public BinaryTree{
public:
    PostorderTree(int val);

    friend ostream& operator<<(ostream& out, const PostorderTree& tree);

    int operator[](int index);

private:
    void traversePostorder(const BinaryTree* node, vector<int>& result) const;
};

// constructor
InorderTree::InorderTree(int val) : BinaryTree(val) {}
PreorderTree::PreorderTree(int val) : BinaryTree(val) {}
PostorderTree::PostorderTree(int val) : BinaryTree(val) {}

// traversal
void InorderTree::traverseInorder(const BinaryTree* node, vector<int>& result) const {
    if (!node) return;
    traverseInorder(node->left, result);
    result.push_back(node->value);
    traverseInorder(node->right, result);
}

void PreorderTree::traversePreorder(const BinaryTree* node, vector<int>& result) const {
    if (!node) return;
    result.push_back(node->value);
    traversePreorder(node->left, result);
    traversePreorder(node->right, result);
}

void PostorderTree::traversePostorder(const BinaryTree* node, vector<int>& result) const {
    if (!node) return;
    traversePostorder(node->left, result);
    traversePostorder(node->right, result);
    result.push_back(node->value);
}

// operator<<
ostream& operator<<(ostream& out, const InorderTree& tree) {
    vector<int> result;
    tree.traverseInorder(&tree, result);
    for (int i = 0; i < result.size(); i++)
        out << result[i] << " ";
    return out;
}

ostream& operator<<(ostream& out, const PreorderTree& tree) {
    vector<int> result;
    tree.traversePreorder(&tree, result);
    for (int i = 0; i < result.size(); i++)
        out << result[i] << " ";
    return out;
}

ostream& operator<<(ostream& out, const PostorderTree& tree) {
    vector<int> result;
    tree.traversePostorder(&tree, result);
    for (int i = 0; i < result.size(); i++)
        out << result[i] << " ";
    return out;
}

// operator[]
int InorderTree::operator[](int index){
    vector<int> result;
    traverseInorder(this, result);
    return result[index];
}

int PreorderTree::operator[](int index){
    vector<int> result;
    traversePreorder(this, result);
    return result[index];
}

int PostorderTree::operator[](int index){
    vector<int> result;
    traversePostorder(this, result);
    return result[index];
}

// main
int main(){
    InorderTree Tree1(3);
    Tree1.addValue(5);
    Tree1.addValue(6);
    Tree1.addValue(1);

    PreorderTree Tree2(3);
    Tree2.addValue(5);
    Tree2.addValue(6);
    Tree2.addValue(1);

    PostorderTree Tree3(3);
    Tree3.addValue(5);
    Tree3.addValue(6);
    Tree3.addValue(1);

    cout << "Inorder: " << Tree1 << endl;
    cout << "Preorder: " << Tree2 << endl;
    cout << "Postorder: " << Tree3 << endl;

    cout << "Tree1[1] = " << Tree1[1] << endl;
    cout << "Tree2[2] = " << Tree2[2] << endl;
    cout << "Tree3[0] = " << Tree3[0] << endl;

    return 0;
}
