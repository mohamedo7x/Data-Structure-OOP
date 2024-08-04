#include <iostream>
using namespace std;

void print (int times = 0) {
    if(times == 5){
        return;
    }
    print(times+1);
    cout << "Hellow Worled\n";
}

int get_max (int (&arr)[] , int counter = 0 ) {
    if(counter ==5 )
        return 0;
    return max(get_max(arr,counter),get_max(arr , counter+1));
}

int main () {
   int arr[] = {1, 2 ,3 ,4,5 };
    cout << get_max(arr)<< " ";
}