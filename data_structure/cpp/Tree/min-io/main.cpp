#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;
class BinaryTree {

    private:
    int data;
    BinaryTree * left {};
    BinaryTree * right {};
    public:
    BinaryTree(int data) :
			data(data) {
	}
    void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		BinaryTree* current = this;
		// iterate on the path, create all necessary nodes
		for (int i = 0; i < (int) values.size(); ++i) {
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
    int tree_max() {
		int res = data;
		if (left)
			res = max(res, left->tree_max());
		if (right)
			res = max(res, right->tree_max());
		return res;
	}
     
};
int main () {
    BinaryTree tree(1);

}