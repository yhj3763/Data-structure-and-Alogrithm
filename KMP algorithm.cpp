#include <iostream>
#include <vector>
#include <string>

std::vector<int> getTable(std::string s) {
    int m = s.size();
    std::vector<int> table(m, 0);
    int j = 0;

    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j])
            j = table[j - 1];

        if (s[i] == s[j]) {
            table[i] = ++j;
        }
       
    }

    return table;
}

void KMP(std::string parent, std::string pattern) {
    
    std::vector<int> values = getTable(pattern);
    int si = parent.size();
    int j = 0;
    for (int i = 0; i < si; ++i) {
        while (j > 0 && parent[i] != pattern[j]) {
            j = values[j - 1];
        }
        if (parent[i] == pattern[j]) {
            if (j == pattern.size()-1) {
                std::cout << "It is found at " << i-pattern.size() + 1 << std::endl;
                j = values[j];
            }
            else {
                ++j;
            }
        }

    }

}

int main(){

  std::string a = "abbbacdafcab";
  std::string b = "bacdf";
  KMP(a,b);
  
return 0;
}
