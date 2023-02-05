#include <string>
#include <vector>

using namespace std;

int fib(int n){
    static vector<int> store;
    if(n <= 1) return n;
   
    if(store.size()<=n)
        store.resize(n+1);
    
    if(store[n] == 0)
        store[n] = (fib(n-1)+fib(n-2))%1234567;
  
    return store[n];
    
    
}

int solution(int n) {
    int answer = 0;
    
    answer = fib(n);
    
    return answer;
}
