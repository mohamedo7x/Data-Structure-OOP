#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef int type;
class Stack
{
private:
    int size{};
    int top{};
    type *array{};

public:
    Stack(int size_t) : size(size_t), top(-1)
    {
        array = new type[size_t];
    }
    ~Stack()
    {
        delete[] array;
    }
    bool isFull()
    {
        return top == size -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(type data)
    {
        assert(!isFull());
        array[++top] = data;
    }
    type pop()
    {
        return array[--top];
    }
    type peek()
    {
        return array[top];
    }
    int siz()
    {
        return top;
    }
    void reverse () {
        for(int i = 0 ; i<(size/2) ; i++){
            swap(array[i] , array[size - i - 1]);
        }
    }
    void print () {
        for(int i = size -1 ; i>= 0 ;i--){
            cout << array[i] << " ";
        }
    }
    void insertbuttom (type data) {
        assert(!isFull());
        ++top;
        for(int i = size -2 ; i>=0 ; i--){
            array[i+1] = array[i];
        }
        array[0] = data;
    }
};
int main()
{
    Stack stk(10);
    for(int i =1 ; i<= 9 ; i++){
        int rand = i *2 - 1;
        stk.push(rand);
    }
    stk.insertbuttom(-9999);
    stk.print();

    cout << "\n!! NO RTE !!";
}