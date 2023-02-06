#include <string>
#include <vector>

using namespace std;

static int count = 0;

void dfs(int depth,int sum, vector<int> numbers, int target){
    
    if(depth >= numbers.size()){
        if(sum == target){
            count++;
        }
        return;
    }
    
    dfs(depth+1, sum+numbers[depth], numbers, target);
    dfs(depth+1, sum-numbers[depth], numbers, target);
    
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0, 0, numbers, target);
    
    answer = count;
    return answer;
}
