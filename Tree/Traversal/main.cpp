#include <iostream>
using namespace std;
struct Node {
    int data {};
    Node * left {};
    Node * right {};
    Node (int data): data(data){} 
};
unsigned int counter = 0  ;
void print_post_oreder (Node * cur) {
    if (cur == nullptr)
        return;
    print_post_oreder(cur->left);
    print_post_oreder(cur->right);
    counter += cur->data;
    // cout << cur->data << " ";
}
void pirnt_in_oreder (Node * cur) {
    if(cur==nullptr)
        return;
    print_post_oreder(cur->left);
    cout << cur->data << " ";
    print_post_oreder(cur->right);
}
int main () {
    // Node * plus = new Node('+');
    // plus->left = new Node ('2');
    // plus->right = new Node ('3');

    // Node * div = new Node('/');
    // div->left = new Node('8');
    // div->right = new Node('4');

    // Node * minus = new Node('-');
    // minus->left = new Node('9');
    // minus->right = div;


    // Node * multiply = new Node('*');
    // multiply->left = plus;
    // multiply->right = minus;

    // print_post_oreder(multiply);
    // pirnt_in_oreder(multiply);
    // delete plus , div, minus , multiply;


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

    print_post_oreder(root);
    printf("counter is %d" , counter);
     delete root , node2 , node3 , node4 , node5 , node6 , node7 , node8;
}