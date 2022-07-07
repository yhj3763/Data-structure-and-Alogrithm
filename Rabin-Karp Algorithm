//This is from answer for leetcode that I used Rabin-Karp Algorithm to solve the problem
//Rabin-Karp is basically multiplying power of choosen value to each digits.
//If target has 5 characters like apple in string, it will be
//a*2^4 + p*2^3 + p*2^2 + l*2^1 + e*2^0
//Therefore, we can have different sum for different characters
//When we want to move to next character, we need to use sum = 2 * (sum - originalstring[charachter we want to remove] * power(usually 2^size of target-1)+originalstring[character we want to add])
class Solution {
public:
    int strStr(string haystack, string needle) {
    
    int nelength = needle.size();
    double flength = 0;
    double hlength = 0;
    double power = 1;

    for (int i = nelength-1; i >= 0; i--) {

        flength += needle[i] * power;
        hlength += haystack[i] * power;
        if(i!=0) power = power * 2;
    }


    int c = 0;
    for (int j = nelength; j <= haystack.size(); j++) {

        if (flength == hlength) {

            return c;
        }

        hlength = 2 * (hlength - haystack[c] * power) + haystack[j];
        c++;
    }
        
    return -1;

    }
};
