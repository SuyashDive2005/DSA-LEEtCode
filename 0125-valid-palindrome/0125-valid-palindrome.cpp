class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(char c:s){
            if(isalnum(c)){
                temp+=tolower(c);
            }else{
                continue;
            }
        }
        cout<<temp;
        string rev=temp;
        reverse(temp.begin(),temp.end());
        return temp==rev;
    }
};