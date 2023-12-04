#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s){
    stack<char>st;
    st.push(s[0]);
    for(int i=1; i<s.size(); i++){
        if(!st.empty() && s[i]==st.top()){
            st.pop();
        }
        else st.push(s[i]);
    }
    string ans;
    while(st.size()>0){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

    string s; cin>>s;
    cout<<removeDuplicates(s)<<'\n';
    
    return 0;
}