#include <iostream>

using namespace std;

//finds the dot product of 2 2x2 matricies
//results are stored in arg1
void mult(int arg1[2][2], int arg2[2][2]){
    int product[2][2];

    product[0][0]= arg1[0][0] * arg2[0][0] + arg1[0][1] * arg2[1][0];
    product[0][1]= arg1[0][0] * arg2[0][1] + arg1[0][1] * arg2[1][1];
    product[1][0]= arg1[1][0] * arg2[0][0] + arg1[1][1] * arg2[1][0];
    product[1][1]= arg1[1][0] * arg2[0][1] + arg1[1][1] * arg2[1][1];

    arg1[0][0] = product[0][0];
    arg1[0][1] = product[0][1];
    arg1[1][0] = product[1][0];
    arg1[1][1] = product[1][1];
}

int power(int fib[2][2], int n) 
{ 
    //inital matrix
    int init[2][2] = {1, 1, 1, 0}; 
  
    //base cases
    if(n==0) return 0;
    else if (n==1) return fib[0][0]; 
  
    //n is divided by 2 because the matrix is squared
    power(fib, n/2); 
    
    //squares the matrix
    mult(fib, fib); 
    
    //multiplies by the inital matrix for odd valuse on n
    if (n%2 != 0) 
        mult(fib, init); 
  
    return fib[0][1]; 
    
}

int main(void){
    int fib[2][2] = {1, 1, 1, 0};
    cout << "enter the number you wish to find the Fibonacci number of, then press enter: ";
    int n;
    cin >> n;

    cout << "fib of " << n << " = " << power(fib, n) << "\n";

    return 0;
}
