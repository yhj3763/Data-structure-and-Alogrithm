//풀이 1
first, last = 0, len(s)-1  #Initialize first and last

while first < last:
    s[first],s[last] = s[last],s[first]  #Swap first and last contents
    first += 1
    last -= 1
    
    
//풀이 2
s.reverse()
