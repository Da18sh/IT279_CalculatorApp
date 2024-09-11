#include "Calculator.h"
#include "Stack.h"
#include <iostream>
using namespace std;

//############DaShawn wrote this############//
//Default Constructor
Calculator::Calculator(){}
//integer method with two integer parameters that returns their sum.
int Calculator::add(int a, int b)
{
    cout<<a+b;
    return a + b;
}
//integer method with two integer parameters that returns their difference.
int Calculator::sub(int a, int b)
{
    cout<<a-b;
    return a - b;
}
//integer method with two integer parameters that returns their product.
int Calculator::multi(int a, int b)
{
    cout<<a*b;
    return a * b;
}
//integer method with two integer parameters that returns their quotient.
int Calculator::div(int a, int b)
{
    cout<<a/b;
    return a / b;
}


