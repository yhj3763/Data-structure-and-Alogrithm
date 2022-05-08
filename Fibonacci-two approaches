#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Fibonacci by using recursion 
int fibo_recur(int n)
{
    //return n when n is 0 or 1. This is condition to end recursion
    if (n <= 1)
    {
        return n;
    }
    //returnn sum of n-1 and n-2 value
    else
    {
        return fibo_recur(n - 1) + fibo_recur(n - 2);
    }
}

//There is one problem when n is bigger and bigger, it takes too much time to calculate all things again each time.
//If we want to calculate big number of n, there are so many same cases we need to calculate to find problem.
//Therefore, we can solve this problem by storing some values we calculated already, so we can use it for bigger value later
//To implment it, we can store value into vector at the first time and then we can use this value later.

int fib(int n) {
    static vector<int> table; // We need to maintain value in this vector, so we need to declare it as static
    if (n <= 1) 
    {
        return n;
    }
    else if (n >= table.size())  // Bigger n than vector size means, there are values that we do not have value in the vector, so we need to make vector bigeer.
    {
        table.resize(n+1);
    }

    if (table[n] == 0) // When we use resize for vector, index that was added has 0 value in it.
    {
        table[n] = fib(n - 1) + fib(n - 2); 
    }


    return table[n];
}


int main()
{
 
    cout << fibo_recur(40) << endl; // Cannot be calculated because of a lot of calculation for same value.
    cout << fib(40) << endl;


    return 0;
}
