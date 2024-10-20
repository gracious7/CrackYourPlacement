class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  
        for(auto i:s){
            if(i=='(' or i=='{' or i=='[') st.push(i); 
            else {
                if(st.empty() == true) return false;
                else if(st.top()=='(' and i!=')') return false;
                else if(st.top()=='{' and i!='}') return false;
                else if (st.top()=='[' and i!=']') return false;
                st.pop();  
            }
        }
        
        if(st.empty() == true) return true;
        return false;
    }
};