#include <iostream>
using namespace std;

class Stack {
    private:
    int size_of_Stack {};
    int it {};
    int *storage;
    public:

    void insert (int data){
        ++it;
        if(it >= size_of_Stack){
            return;
        }
        storage[it] = data;
    }
    int peek () const {
        if(it <= size_of_Stack){return -1;}
        return storage[it];
    }
    void pop () {
        --it;
        if(it < 0){
            return;
        }
        storage[it+1] = 0 ;
    }
    void insertbottom (type data) {
        
    }
    Stack(int size) : size_of_Stack(size) , it(-1) {
        storage = new int [size_of_Stack];
    }
    ~Stack(){
        delete storage;
        storage = nullptr;
    }
};

int main () {
    Stack stk(3);
    stk.insert(10);
    stk.insert(20);
    stk.insert(30);
    stk.pop();
    stk.insert(70);
    stk.insert(200);
    cout << stk.peek();
}