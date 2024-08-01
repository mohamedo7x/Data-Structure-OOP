#include <iostream>
using namespace std;

struct Node {
    int data {};
    Node * left {};
    Node * right {};
    Node (int data): data(data){} 
};
bool f = false;
void print(Node *node){
    if (node == nullptr){
        return;
    }
    if(f == false){
        f = true;
        cout << node->data<<endl;
    }
    if(node->left != nullptr){
        cout<<node->left->data << endl;
    }
    if(node->right != nullptr){
        cout<<node->right->data << endl;
    }
    print(node->left);
    print(node->right);
}
void print_inoreder (Node *current){
    cout << current->left->data<< " ";
    cout << current->data<< " ";
    cout << current->right->data<< " ";
}
void print_prefix (Node *current){
    cout << current->data<< " ";
    cout << current->left->data<< " ";
    cout << current->right->data<< " ";
}
void print_postfix (Node *current){
    cout << current->left->data<< " ";
    cout << current->right->data<< " ";
    cout << current->data<< " ";
}
int main () {
   // Create Nodes
	Node* root = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4);
	Node* node5 = new Node(5);
	Node* node6 = new Node(6);
	Node* node7 = new Node(7);
	Node* node8 = new Node(8);

	// Link them!
	root->left = node2;
	root->right = node3;

	node2->left = node4;
	node2->right = node5;

	node5->right = node7;

	node3->right = node6;

	node6->left = node8;
    print(root);


    // cout << root->left->right->right->data << "\n";	// 7
	// cout <<      node2->right->right->data << "\n";	// 7
	// cout <<             node5->right->data << "\n";	// 7
	// cout <<                    node7->data << "\n";	// 7

	// cout << root->right->right->data << "\n";		// 6
	// cout << root->right->right->left->data << "\n";	// 8
	// cout << root->right->right->right << "\n";		// 0x00
    delete root , node2 , node3 , node4 , node5 , node6 , node7 , node8;
    return 0;
}