#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int data;
    TreeNode * left {};
    TreeNode * right {};
    TreeNode(int data){
        this->data = data;
    }
};
int main () {
    TreeNode *nine = new TreeNode(9);
    TreeNode *four = new TreeNode(4);
    TreeNode *twenty = new TreeNode(20);
    TreeNode *one = new TreeNode(1);
    TreeNode *six = new TreeNode(6);
    TreeNode *fifteen = new TreeNode(15);
    TreeNode *thirty = new TreeNode(30);

    nine->left = four;
    nine->right = twenty;
    four->left = one;
    four->right = six;
    twenty->left = fifteen;
    twenty->right = thirty;

    // BFS 
    vector<int> valuesOfTree;
    queue<TreeNode*> q;
    q.push(nine);
    while(!q.empty()){
        if(q.front()->left){
            q.push(q.front()->left);
        }
        if(q.front()->right){
            q.push(q.front()->right);
        }
        valuesOfTree.push_back(q.front()->data);
        q.pop();
    }
    for(auto &it : valuesOfTree){
        cout << it << " ";
    }
}