class Solution {
public:
    int evalRPN(vector<string>& tk) {
        stack<int>st;
        int ans = 0;
        for(auto x: tk){
            if(x == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b+a);
                
            }
            else if(x == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b-a);
                
            }
            else if(x == "*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b*a);

            }
            else if(x == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b/a);

            }
            else {
                st.push(stoi(x));
            }
        }
        ans = st.top();
        return ans;
    }
};