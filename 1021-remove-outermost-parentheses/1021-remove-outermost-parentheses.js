/**
 * @param {string} s
 * @return {string}
 */
var removeOuterParentheses = function(s) {
    let res="";
    let depth=0;
    for(let i=0;i<s.length;i++){
        if(s[i]=='('){
            if(depth>0){
                res+=s[i];
            }
            depth++;
        }else{
            depth--;    
            if(depth>0){
                res+=s[i];
            }
        }
        
    }

    return res;
};