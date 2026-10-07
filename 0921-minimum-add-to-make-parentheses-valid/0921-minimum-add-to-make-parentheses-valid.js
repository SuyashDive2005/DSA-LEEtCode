/**
 * @param {string} s
 * @return {number}
 */
var minAddToMakeValid = function(s) {
    // int minAddToMakeValid(string s) {
    //     int count = 0;
    //     stack<char> st;

    //     for(int i=0;i<s.length();i++){
    //         if(s[i]=='('){
    //             st.push(s[i]);
    //         }else{
    //             if(!st.empty() && st.top()=='('){
    //                 st.pop();
    //                 count+=2;
    //             }else{
    //                 continue;
    //             }
    //         }
    //     }
    //     return s.length()-count;
    // }

    let cnt=0;
    let st=[];

    for(let i=0;i<s.length;i++){
        if(s[i]=='('){
            st.push(s[i]);
        }else {
            if(s.length>0 && st[st.length-1]=='('){
                st.pop();
                cnt+=2;
            }else continue;
        }
    }

    return s.length-cnt;
};