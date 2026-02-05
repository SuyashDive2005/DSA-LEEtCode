class Solution {
public:
    bool isoperator(string x){
        return (x=="+" || x=="-" || x=="/" || x=="*");
    }

    int eval(int a,int b,string op){
        if(op=="+") return a+b;
        if(op=="-") return a-b;
        if(op=="*") return a*b;
        if(op=="/") return a/b;
        return -1;
    }  

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string &c : tokens) {
            if (!isoperator(c)){
                st.push(stoi(c));
            }else{
                int b=st.top();st.pop();
                int a=st.top();st.pop();

                st.push(eval(a,b,c));
            }
        }
        return st.top();
    }
};