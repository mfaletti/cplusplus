#include <iostream>
using namespace std;

void setValue(int x) {
  x = 2;
}

void setValueToValuePassed(int *x) {
  *x = 3;
}

void setValueWithReference(int &x) {
  x = 5;
}

int main()
{
  int x = 1; // x is an integer

  // a pointer is a variable that holds a memory address where a variable lives.
  int *p; // initialize a pointer to an integer. currently points nowhere.

  cout <<"p is pointing to memory address "<<p;
  cout <<"\nvalue of x is "<< x <<". it is stored at memory address "<<&x;

  p = &x; // assigning p to the address of k
  cout<<"\np is now pointing to memory address of x: "<<p;

  cout<<"\nThe value stored at the memory address p is currently pointing to: "<<*p;

  cout<<"\nThe memory address where p is stored: "<<&p;

  /*
   * in C++, variables are passed by value. When calling a function with an argument, a new copy of the variable
   * is created inside the function and assigned the value passed in the function call.
   * Any modifications to the value inside the function call only affects the new variable, the variable that was
   * invoked with the function call is unchanged.
   */
  setValue(x);

  cout <<"\nThe value of x after setValue(): " <<x;

  /*
   * We can perform the intended task by passing a pointer as argument. This lowers the memory footprint of the program.
   * unnecessary duplicate variables are not created. The function can modify the variable's value directly. Any modification
   * to the variable inside the function affects the variable outside the scope of the function.
   */
  setValueToValuePassed(&x); // &x is the memory address of x. A pointer
  cout <<"\nThe value of x after modification inside setValueToValuePassed(): " <<x;

  /*
   * In C++ (not in C), you can pass a variable by reference, so that any modifications to the variable inside
   * the function will also affect the variable outside the scope of the function.
   */

  setValueWithReference(x);
  cout <<"\nThe value of x after modification inside setValueWithReference(): " <<x;

  // which style should you use? it's up to you.

  return 0;
}
