#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
class BinaryTree final {
    private:// ------------------------------------->>>>>>> PRIVATE <<<<<<-----------------------------------
    struct Node {
        T data;
        Node *left {};
        Node * right {};
        Node (T data):data(data){}
    };
    Node *root {};
    void print_in_oreder (Node * cur) {
        if(!cur)
            return;
        print_in_oreder(cur->left);
        cout << cur->data << " ";
        print_in_oreder(cur->right);
    }
    void print_post_oreder (Node * cur) {
        if(!cur)
            return;
        print_post_oreder(cur->left);
        print_post_oreder(cur->right);
        cout << cur->data << " ";
    }
    T tree_max(Node *cur){ 
        if(!cur)
            return 0;
        int left_ = tree_max(cur->left);
        int right_ = tree_max(cur->right);
        return max(cur->data , max(left_ , right_));
    }
    int tree_height(Node *cur) {
        if(!cur)
            return 0;
        int left_ = 1+tree_height(cur->left);
        int right_ = 1+tree_height(cur->right);
        return max(left_ , right_);
    }
    int count_all_node (Node * cur) {
            if(!cur)
                return 0;
            int left_ = 1+count_all_node(cur->left);
            int right_ = count_all_node(cur->right);
            return left_+right_;
    }
    public: // ------------------------------------->>>>>>> PUBLIC <<<<<<-----------------------------------
    void print_in_order () {
        this->print_in_oreder(this->root);
        cout << endl;
    }
    void print_post_order () {
        this->print_post_oreder(this->root);
        cout << endl;
    }
    void add(vector<int> nodes, vector<char> path) {
    assert(nodes.size() == path.size());
    Node* temp = root;
    for (int i = 0; i < (int)path.size(); i++) {
        if (path[i] == 'L') {
            if (!temp->left) {
                temp->left = new Node(nodes[i]);
            } else {
                assert(temp->left->data == nodes[i]);
            }
            temp = temp->left;
        } else if (path[i] == 'R') {
            if (!temp->right) {
                temp->right = new Node(nodes[i]);
            } else {
                assert(temp->right->data == nodes[i]);
            }
            temp = temp->right;
            }
        }
    }
    void print_root (){
        cout << (T)(root->data) << endl;
    }
    BinaryTree(T data){
        root = new Node(data);
      
    }
    void destoryBtree (Node * cur) {
        if(cur){
            destoryBtree(cur->left);
            destoryBtree(cur->right);
            delete cur;
        }
    }
    int tree_max () {
        return this->tree_max(this->root);
    }
    ~BinaryTree(){
        destoryBtree(root);
    }
    void bulid_fast_tree (){
        root->data = 2;
        root->left = new Node(3);
        root->right = new Node(13);
        Node * temp = root;
        temp = temp->right;
        temp->left = new Node(7);
        temp->right = new Node(8);
    }
    int tree_height () {
        return tree_height(this->root) -1 ;
    }
    int count_all_node () {
        return this->count_all_node(this->root);
    }
    
};
int main(){
    BinaryTree tree(1); // Root
    // tree.add({2,4,7},{'L','L','L'});
    // tree.add({2,4,8},{'L','L','R'});
    // tree.add({2,5,9},{'L','R','R'});
    // tree.add({3,6,10},{'R','R','L'});
    tree.bulid_fast_tree();
    tree.print_post_order();

    cout << "print " << tree.count_all_node();
    cout << "\n\n!! NO RTE !!\n\n";
}