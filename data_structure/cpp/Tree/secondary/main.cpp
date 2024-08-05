#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
template<typename T>
class BinaryTree {

    private:
    T data;
    BinaryTree * left {};
    BinaryTree * right {};
    public:
    void add(vector<T> values, vector<char> direction) {
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
    BinaryTree(int data) :
			data(data) {
	}
	BinaryTree(string str) {
		int total_nodes = -1;
		this->data = str[str.size()-1]; // root
		vector<char> nodes;
		for(int i = 1; i<str.size() ; i++){
			nodes.push_back(str[i]);
			total_nodes+=1;
		}
		reverse(nodes.begin() , nodes.end());
		bool flag = false;
		int counter = 0;
		while(total_nodes--){
			if(!flag){
				vector<char> a(1);
				a[counter] = nodes[counter];
				add(a , {'L'});
				counter++;
			}else {
				vector<char> a(1);
				a[counter] = nodes[counter];
				add(a , {'R'});
				counter++;
				
			}
		}
	}
};
int main () {
    BinaryTree<string> tree("23+4*");
	cout << "\n\n!! NO RTE !!\n\n";
}