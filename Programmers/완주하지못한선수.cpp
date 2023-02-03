#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> incompleted;
    
    for(int i=0;i<participant.size();i++){
        incompleted[participant[i]]++;
    }
    
    for(int j=0;j<completion.size();j++){
        incompleted[completion[j]]--;
    }
    
    for(const auto &p: incompleted){
        if(p.second == 1) answer = p.first;
    }
    
    return answer;
}
