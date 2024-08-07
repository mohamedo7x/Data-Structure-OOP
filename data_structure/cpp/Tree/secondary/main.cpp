#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include <cctype>

using namespace std;

template<typename T>
class BinaryTree {
private:
    T data;
    BinaryTree *left{};
    BinaryTree *right{};

public:
    void add(vector<T> values, vector<char> direction) {
        assert(values.size() == direction.size());
        BinaryTree* current = this;
        for (int i = 0; i < (int)values.size(); ++i) {
            if (direction[i] == 'L') {
                if (!current->left)
                    current->left = new BinaryTree(values[i]);
                else
                    assert(current->left->data == values[i]);
                current = current->left;
            } else {
                if (!current->right)
                    current->right = new BinaryTree(values[i]);
                else
                    assert(current->right->data == values[i]);
                current = current->right;
            }
        }
    }

    void print_inorder() {
        if (left)
            left->print_inorder();
        cout << data << " ";
        if (right)
            right->print_inorder();
    }

	void print_post_order() {
		if (left){
            left->print_inorder();
		}
        if (right){
            right->print_inorder();
		}
		cout << data << " ";
    }

    int tree_max() {
        int res = data;
        if (left)
            res = max(res, left->tree_max());
        if (right)
            res = max(res, right->tree_max());
        return res;
    }

    BinaryTree(T data) : data(data) {}

    BinaryTree(string str) {
        stack<BinaryTree*> stk;
        for (char ch : str) {
            BinaryTree* cur = new BinaryTree(ch);
            if (!isdigit(ch)) {
                cur->right = stk.top();
                stk.pop();
                cur->left = stk.top();
                stk.pop();
            }
            stk.push(cur);
        }
        BinaryTree* root = stk.top();
        stk.pop();
        this->left = root->left;
        this->data = root->data;
        this->right = root->right;
    }

    ~BinaryTree() {
        delete left;
        delete right;
    }
};

int main() {
    BinaryTree<char> tree("23+4*");
    tree.print_post_order();
    cout << "\n\n!! NO RTE !!\n\n";
    return 0;
}
