//
def solution(babbling):
    answer = 0
    check = {}
    temp2 = ""
    
    for i in range(len(babbling)):
        temp = babbling[i]
        temp2 = ""
        check["aya"] = check["woo"] = check["ma"] = check["ye"] = 0
        
        for j in range(len(temp)):
            temp2 += temp[j]
            
            if temp2 == "aya" or temp2 == "woo" or temp2 == "ye" or temp2 == "ma":
                if j == len(temp)-1 and check[temp2] == 0:
                    answer+= 1
                else:
                    check[temp2]+=1
                    temp2 = ""                
    
    return answer
