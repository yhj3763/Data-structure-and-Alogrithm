from collections import defaultdict 

def solution(participant, completion):
    answer = ''
    incompleted = defaultdict(int)
    
    for i in participant:
        incompleted[i] +=1
        
    for i in completion:
        incompleted[i] -=1
        
    for key, value in incompleted.items():
        if value == 1:
            answer = key
    
    return answer
