#include <iostream>
#include <algorithm>
using namespace std;
const unsigned int MAX_SIZE = 100;
int T_i = 0 , T_j = 0; // counter 

int left_col (int (&arr)[MAX_SIZE][MAX_SIZE], int col) {
  unsigned int value = 0;
  for(int i = 0 ; i<col ; i++){
    value += arr[i][0]; 
  } 
  return  value;
}
int right_col (int (&arr) [MAX_SIZE][MAX_SIZE] ,int row, int col) {
    unsigned int value = 0;
    for(int i = 0 ; i < col ; i++){
        value += arr[i][(row - 1)];
    }
    return value;
}
int left_diagonal (int (&arr)[MAX_SIZE][MAX_SIZE] , int row ,int col) {
    unsigned int value = 0;
   
        for(int i = 0 ; i <= col ; i++){
            value += arr[i][i];
        }
    return value;
}
int right_diagonal (int (&arr)[MAX_SIZE][MAX_SIZE] , int row ,int col) {
unsigned int value = 0;
    
       for(int right = row-1 , left = 0 ; right >=0 ; right -=1 , left+=1){
         value+= arr[right][left];
       }
    
    return value;
}
void Swap_2D_array (int (&arr) [MAX_SIZE][MAX_SIZE] , int x_row , int y_row , int col) {
    for(int i = 0 ; i<col ; i++){
        swap(arr[i][x_row] , arr[i][y_row]);
    }
}
void print_matrix (int (&arr)[MAX_SIZE][MAX_SIZE] , int row ,int col){
    cout << "\n ----- \n";
    for(int i =0 ; i<row ; i++){
        for(int j = 0 ; j<col ; j++){
            cout <<arr[i][j] << " ";
        }
        cout <<endl;
    }
}
void insert(int (&t_arr)[MAX_SIZE][MAX_SIZE] , int value , int col , int row){
    // cout << "INSERT IN " << i << " " << j << " \n";

    t_arr[T_i][T_j] = value;
    T_i+=1;
    if(T_i > col-1){
        T_j+=1;
        T_i=0;
    }
}
bool smaller_row (int (&arr)[MAX_SIZE][MAX_SIZE] , int q_1 , int q_2 , int columns) {
    int row_one = 0 , row_two = 0;
    for(int i = 0 ; i<columns ; i++){
        row_one +=arr[q_1-1][i];
        row_two +=arr[q_2-1][i];
    }
    if(row_one < row_two ){
       return true;
    }else {
       return false;
    }
}
int R_triangular_matrix (int (&arr)[MAX_SIZE][MAX_SIZE] ,int row ) {
    int value = 0 ;
    for(int i = 0 , j =0 ; i < row-1; j++){
        if(j > row-1){
            i++;
            j = i;
        }
        value += arr[i][j];
        
    }
    
   return value;
}
int L_triangular_matrix (int (&arr)[MAX_SIZE][MAX_SIZE] ,int row ) {
    int value = 0 ;
    for(int i = row-1 , j =row-1 ; i > 0 ; j--){
        if(j < 0){
            i--;
            j =i;
        }
        value += arr[i][j];
    }
    return value;
}
void active_Robot () {
    int r , c;

     int x  =0 , y = 0; // x = row , y = columns
 int dir [4][4]={{-1 , 0 , 1 , 0 },{0 , 1 , 0 , -1}}; // 1 - UP , 2 - RIGHT , 3 - DOWN , 4 - LEFT
 for(int i = 0 ; i < 10000000 ; i++){
    int q , k;
    cin >> q >>k; // 2 1 => right ( 1 Move )
   

    if(k>1&&q == 1 || q == 3){
        for(int j = 0 ; j< k ; j++){
            x += dir[0][q-1];
        }
    }else if (k>1&&q ==2 || q == 4 && k>1) {
         for(int j = 0 ; j< k ; j++){
            y += dir[1][q-1];
        }
    }else {
        x += dir[0][q-1];
        y += dir[1][q-1];
    }
        
    if(x < 0 ){
        x = (r-1);
    }
     if (x > (r -1 )){
        x = 0;
    }

    if( y < 0){
        y = (c -1);
    }
    if (y > (c -1)){
        y = 0;
    }

    cout << "YOU IN (" <<x << ","<<y<<")\n";
 }

}
bool check_prime (int value) {
    for(int i =2 ; i<= value/2 ; i++){
        if(value%i == 0 ){
            return false;
        }
    }
    return true;
}
void HM_prime () {
//    int x , i , j;
//     int t;
//     cin >> t;
//     while(t--){
//         int row , col , r_row , c_col , prime = 0;// row -> start row & col = start col , x*y
//         cin >> row >> col >> r_row >> c_col;
//         cout <<"\n -------- " << endl;
//         for(int i = row ; i <=r_row ; i++){
//             for(int j = col ; j<c_col ; j++){
//                 // if(check_prime(x[i][j]) == true){
//                    prime++;
//                 // }
//                 // cout << arr[i][j] << " ";
//             }
//         }
//         // cout << prime;
//         cout <<"\n -------- " << endl;
//     }
}

int main (){
 int r , c ;
 cin >> r >> c;
 int arr[MAX_SIZE][MAX_SIZE] = {0};
 for(int i =  0 ; i< r ; i++){
    for(int j  = 0 ; j<c ; j++){
        cin >> arr[i][j];
    }
 }  
    int dir [2][8] = {{-1 , 1 , 0 , 0 , -1 , 1 ,-1 , 1},{0 , 0 , -1 , 1 , -1 , -1 , 1, 1}};
    int m , k ;
    cin >> m >> k;
    for(int i = 0 ; i< 8 ; i++){
        int newRow = m + dir[0][i];
        int newCol = k + dir[1][i];  
        if(newRow < 0 || newRow >r || newCol < 0 || newCol > c ){
            continue;
        }
        if(arr[newRow][newCol] == 0) continue;
        if( arr[m][k] > arr[newRow][newCol]){
            cout << arr[m][k] << " > " << arr[newRow][newCol] << " \n";
        }
    }

    // print_matrix(arr , c , r);
}