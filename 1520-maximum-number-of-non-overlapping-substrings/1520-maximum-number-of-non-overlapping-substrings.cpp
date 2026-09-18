class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> start(26,-1),end(26);
        vector<bool> isvalid(26,true);
        vector<string>res;
        int n=s.length();
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(start[idx]==-1){
                start[idx]=i;
            }
            end[idx]=i;
        }

        for(int c=0;c<26;c++){
            if(start[c]==-1) continue;
            for(int i=start[c];i<=end[c];i++){
                if(start[s[i]-'a']<start[c]){
                    isvalid[c]=false;
                    break;
                }
                end[c]=max(end[c],end[s[i]-'a']);
            }
        }
        int lasttakenstart = INT_MAX;
        for(int i=n-1;i>=0;i--){
            int c=s[i]-'a';
            if(!isvalid[c]) continue;
            if(i==start[c] && end[c]<lasttakenstart){
                res.push_back(s.substr(i,end[c]-i+1));
                lasttakenstart=i;
            }
        }

        return res;
    }
};