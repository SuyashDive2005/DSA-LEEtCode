class Solution {
private: 
bool isPal(string &str,int i,int j){
    
    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        else {
            i++;
            j--;
        }
    }
    return true;
}   

public:
    string longestPalindrome(string s) {
        int i=0,j=s.length()-1;
        string temp;
        string lstring="";


        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPal(s,i,j)){
                    temp=s.substr(i,j-i+1);
                    if(temp.length()>lstring.length()){
                        lstring=temp;
                    }
                }
            }
        }
        return lstring;
    }
};