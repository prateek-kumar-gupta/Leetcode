class Solution {
public:
    bool isValid(string s) {
        stack<char>st ;
        for(auto & ch : s){
            if(ch=='(' || ch == '{' || ch == '[') st.push(ch);
            if(ch==')'){
                if(st.size()>0 &&st.top()=='(') st.pop() ;
                else return false ;
            }
             if(ch=='}'){
                if(st.size()>0 &&st.top()=='{') st.pop();
                else return false ;
            }
             if(ch==']'){
                if(st.size()>0 && st.top()=='[') st.pop();
                else return false ;
            }
        }
        if(st.empty()) return true ;
        return false ;
    }
};