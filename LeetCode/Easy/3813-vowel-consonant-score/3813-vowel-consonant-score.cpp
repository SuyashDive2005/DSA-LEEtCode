class Solution {
public:
    int vowelConsonantScore(string s) {
        int v=0;
        int c=0;

        for(auto& x:s){
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
                v++;
            }else if((x>='0' && x<='9') || x==' '){
                continue;
            }
            else{
                c++;
            }
        }
        return (c>0?floor(v/c):0);
    }
};