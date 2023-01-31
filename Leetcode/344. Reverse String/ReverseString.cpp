//풀이 1

vector<char> st(s.size());
int j = 0;

//for(int i = s.size()-1, j = 0; i>=0,j<s.size();i--,j++)
for(int i = s.size()-1; i>=0;i--){
    st[j] =s[i];
    j++;
}

for(int i = 0; i<st.size();i++){
    s[i]=st[i];
}

//풀이 2
reverse(s.begin(),s.end());
