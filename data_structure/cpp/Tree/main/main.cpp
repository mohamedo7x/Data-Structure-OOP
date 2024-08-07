#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

template <typename T>
class BinaryTree final
{
private:
    struct Node
    {
        T data;
        Node *left{};
        Node *right{};
        Node(T data) : data(data) {}
    };
    Node *root{};

    void print_in_order(Node *cur)
    {
        if (!cur)
            return;
        print_in_order(cur->left);
        cout << cur->data << " ";
        print_in_order(cur->right);
    }

    void print_post_order(Node *cur)
    {
        if (!cur)
            return;
        print_post_order(cur->left);
        print_post_order(cur->right);
        cout << cur->data << " ";
    }

    T tree_max(Node *cur)
    {
        if (!cur)
            return 0;
        T left_ = tree_max(cur->left);
        T right_ = tree_max(cur->right);
        return max(cur->data, max(left_, right_));
    }

    int tree_height(Node *cur)
    {
        if (!cur)
            return 0;
        int left_ = 1 + tree_height(cur->left);
        int right_ = 1 + tree_height(cur->right);
        return max(left_, right_);
    }

    int tree_diameter(Node *cur)
    {
        if (!cur)
            return 0;
        int left_ = tree_height(cur->left);
        int right_ = tree_height(cur->right);
        return left_ + right_ + 1;
    }

    int count_all_nodes(Node *cur)
    {
        if (!cur)
            return 0;
        int left_ = count_all_nodes(cur->left);
        int right_ = count_all_nodes(cur->right);
        return 1 + left_ + right_;
    }

    bool search(Node *cur, T value)
    {
        if (!cur)
            return false;
        if (cur->data == value)
            return true;
        return search(cur->left, value) || search(cur->right, value);
    }

    int count_leaf_nodes(Node *cur)
    {
        if (!cur)
            return 0;
        if (!cur->left && !cur->right)
            return 1;
        return count_leaf_nodes(cur->left) + count_leaf_nodes(cur->right);
    }

    bool is_perfect(Node *cur, int d, int level = 0)
    {
        if (!cur)
            return true;
        if (!cur->left && !cur->right)
            return (d == level + 1);
        if (!cur->left || !cur->right)
            return false;
        return is_perfect(cur->left, d, level + 1) && is_perfect(cur->right, d, level + 1);
    }

    void print_in_order_iterative(Node *cur)
    {
        stack<Node *> stk;
        while (true)
        {
            if (cur != nullptr)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                if (stk.empty())
                    break;
                cur = stk.top();
                stk.pop();
                cout << cur->data << " ";
                cur = cur->right;
            }
        }
    }

    void destroy_tree(Node *cur)
    {
        if (cur)
        {
            destroy_tree(cur->left);
            destroy_tree(cur->right);
            delete cur;
        }
    }

public:
    BinaryTree(T data)
    {
        root = new Node(data);
    }

    ~BinaryTree()
    {
        destroy_tree(root);
    }

    void print_in_order()
    {
        print_in_order(root);
        cout << endl;
    }

    void print_post_order()
    {
        print_post_order(root);
        cout << endl;
    }

    void add(vector<int> nodes, vector<char> path)
    {
        assert(nodes.size() == path.size());
        Node *temp = root;
        for (int i = 0; i < (int)path.size(); i++)
        {
            if (path[i] == 'L')
            {
                if (!temp->left)
                {
                    temp->left = new Node(nodes[i]);
                }
                else
                {
                    assert(temp->left->data == nodes[i]);
                }
                temp = temp->left;
            }
            else if (path[i] == 'R')
            {
                if (!temp->right)
                {
                    temp->right = new Node(nodes[i]);
                }
                else
                {
                    assert(temp->right->data == nodes[i]);
                }
                temp = temp->right;
            }
        }
    }

    void build_fast_tree()
    {
        root->data = 2;
        root->left = new Node(3);
        root->right = new Node(13);
        Node *temp = root->right;
        temp->left = new Node(7);
        temp->right = new Node(8);
    }

    void build_fast_tree_v2()
    {
        root->data = 1;
        root->left = new Node(2);
        root->right = new Node(3);
        Node *temp = root->right;
        temp->left = new Node(4);
        temp->right = new Node(5);
    }

    int tree_height()
    {
        return tree_height(root);
    }

    int count_all_nodes()
    {
        return count_all_nodes(root);
    }

    bool search(T data)
    {
        return search(root, data);
    }

    int count_leaf_nodes()
    {
        return count_leaf_nodes(root);
    }

    bool is_perfect()
    {
        int h = tree_height(root);
        return is_perfect(root, h);
    }

    void print_in_order_iterative()
    {
        print_in_order_iterative(root);
    }

    int tree_diameter()
    {
        return tree_diameter(root);
    }

    void level_order_traversal()
    {
        Node * cur = this->root;
        queue<Node*> q;
        q.push(cur);
        while (!q.empty())
        {
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            cout << q.front()->data << " ";
            q.pop();
        }
    }
    void bfs () {
        queue<Node*> q;
        int level = 0 ;
        q.push(this->root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node *cur = q.front();
                q.pop();
                cout << cur->data << ' ';
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right)
                    q.push(cur->right);
            }
            level++;
            cout << endl;
        }
    }
};

int main()
{
    BinaryTree<int> tree(1); // Root
    tree.build_fast_tree_v2();
    tree.level_order_traversal();
    cout << "\n\n!! NO RTE !!\n\n";
    return 0;
}
