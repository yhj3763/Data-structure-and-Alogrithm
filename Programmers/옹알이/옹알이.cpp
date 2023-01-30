//풀이 1
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<string> babbling={"ayaye", "uuuma", "ye", "yemawoo", "ayaa"}; //예시 입력
    int answer = 0;

    string temp2 ="";
    
    for(int i = 0; i<babbling.size();i++){
        string temp = babbling[i];
        temp2 ="";
        int aya = 0;   //중복을 피하기 위한 count용 변수들
        int woo = 0;
        int ma = 0;
        int ye = 0;
        for(int j = 0; j<temp.size(); j++){
            temp2 += temp[j];
       
       		//temp2의 크기가 2고 "ma"나 "ye"면 조건문 안으로 들어가서
            //그 단어가 중복됬는지와 그 단어가 문자열의 마지막인지 확인
            if(temp2.size()==2 && temp2 =="ma" || "ye"){
                if(temp2=="ma"){
                   if(j==temp.size()-1){ 
                      if(ma==0){
                        answer++;   
                      } 
                      break;
                   }
                   ma++;
                   temp2 = "";
                }
                
                if(temp2=="ye"){
                   if(j==temp.size()-1){ 
                      if(ye==0){
                        answer++;   
                      } 
                      break;
                   }
                   ye++;
                   temp2 = "";
                }
                
            }
            
                   
       		//temp2의 크기가 3고 "aya"나 "woo"면 조건문 안으로 들어가서
            //그 단어가 중복됬는지와 그 단어가 문자열의 마지막인지 확인
            if(temp2.size()==3 && temp2 =="woo" || "aya"){
                if(temp2=="woo"){
                   if(j==temp.size()-1){ 
                      if(woo==0){
                        answer++;   
                      } 
                      break;
                   }
                   woo++;
                   temp2 = "";
                }
                
                if(temp2=="aya"){
                   if(j==temp.size()-1){ 
                      if(aya==0){
                        answer++;   
                      } 
                      break;
                   }
                   aya++;
                   temp2 = "";
                }
                
            }
            //크기가 3인데도 불구하고 어디에도 해당되지 않으면 반복문을 빠져나간다.
            if(temp2.size()==3 && temp2 !="woo" && "aya") break;
            
            
        }
    }
    
     cout<<answer<<endl;
}




//
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    unordered_map<string, int> check;   
    string temp2 ="";
    
    for(int i = 0; i<babbling.size();i++){
        string temp = babbling[i];
        temp2 ="";
        check["aya"] = 0;
        check["woo"] = 0;
        check["ye"] = 0;
        check["ma"] = 0;
     
        for(int j = 0; j<temp.size(); j++){
            temp2 += temp[j];
            
            if(temp2 == "aya" ||temp2 == "woo" ||temp2 == "ma" ||temp2 == "ye"){
                if(j == temp.size()-1 && check[temp2] == 0) answer++;
                else {
                    check[temp2]++;
                    temp2 = "";
                }
            }           
            
        }
    }
    
    
    return answer;
}
