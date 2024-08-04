#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
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
    bool search (Node * cur , int value) {
        if(!cur)return false;
        if(cur->data == value) return true;
        bool a=  search(cur->left , value);

        bool b= search(cur->right , value);
        return a || b;
    }
    int count_leaf_node (Node * cur) {
        if(!cur->left& !cur->right ){
            return 1;
        }
        int left = count_leaf_node(cur->left);
        int right = count_leaf_node(cur->right);
        return left+right;
    } 
    bool is_prefect (int highet, Node * cur){
        if(highet == -1){
            highet = this->tree_height(this->root);
        }
        if(!cur->left && !cur->right){
            return 0;
        }
        if(!cur->left && cur->right || !cur->right && cur->left){
            return false;
        }
        bool left = is_prefect(highet , cur->left);
        bool right = is_prefect(highet, cur->left);
        return left && right;
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
    bool search (int data) {
        return this->search(this->root ,data );
    }
    int count_leaf_node () {
        return this->count_leaf_node(this->root);
    }
     bool is_perfect_formula () {
        int h = this->tree_height(this->root);
        int n = this->count_all_node(this->root);
        return pow(2, h+1)-1 == n;
    } 
    bool is_prefect () {
        return this->is_prefect((int)this->tree_height(this->root),this->root);
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

    cout << "print " << tree.is_prefect();
    cout << "\n\n!! NO RTE !!\n\n";
}