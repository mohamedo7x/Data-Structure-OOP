#include <iostream>

using namespace std;

class Tree {
    private:
    struct Node {
        int data;
        Node * left  { };
        Node * right { };
        Node(int val) : data(val) , left(nullptr) ,right(nullptr){}
    };
    Node * root {};



    void insertNode (Node *cur , int &value) {
        
        if(value < cur->data){
            if(cur->left){
                insertNode(cur->left , value);
            }else {
                cur->left = new Node(value);
                return;
            }
        }
        if(value > cur->data){
            if(cur->right){
                insertNode(cur->right , value);
            }else {
                cur->right = new Node(value);
                return;
            }
        }
    }

    public:
    Node * getRoot () {
        return this->root;
    }
    
    void insert(int value){
        insertNode(this->root , value);
    }
    bool search (Node * cur , int value) {
        if(value == cur->data){
            return true;
        }
        if(cur->left){
            return search(cur->left , value);
        }
        if(cur->right){
            return search(cur->right , value);
        }
        return false;
    }
    void build_fast_tree_v2()
    {
        this->root = new Node(50);
        this->root->left = new Node(20);
        this->root->left->left = new Node(15);
    }

    void print_in_oreder (Node * cur) {
       if(!cur)
        return;
        print_in_oreder(cur->left);
        cout << cur->data << " ";
        print_in_oreder(cur->right);
    }
    int min (Node * cur) {
        if(cur->left){
            return min(cur->left);
        }
        return cur->data;
    }
    Tree() : root(nullptr){}
};

int main () {
    Tree BST;
    BST.build_fast_tree_v2();
    BST.insert(45);
    BST.insert(35);
    // int val = 10;

    BST.print_in_oreder(BST.getRoot());
    // cout << BST.search(BST.getRoot(),val);
    cout << endl;
    cout << BST.min(BST.getRoot());
    cout << "\n\n!! NO RTE !!\n\n";
    return 0;
}