//풀이 1
ArrayList<Character> st = new ArrayList<Character>();

for(int i = s.length-1; i>=0;i--){
    st.add(s[i]);
}

for(int i = 0; i<st.size();i++ ){
    s[i] = st.get(i);
}

//
StringBuilder sb = new StringBuilder();
sb.append(s);
sb.reverse();
sb.getChars(0,s.length, s, 0);
