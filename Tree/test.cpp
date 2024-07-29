#include <iostream>
using namespace std;

void print (int times = 0) {
    if(times == 5){
        return;
    }
    print(times+1);
    cout << "Hellow Worled\n";
}
int main () {
    print(0);
}