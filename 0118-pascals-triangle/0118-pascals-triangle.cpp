class Solution {
public:
    vector<vector<int>> generate(int nr) {
        vector<vector<int>> res;
        if(nr==0) return res;

        res.push_back({1});

        vector<int> tmp;
        
       for(int i=1;i<nr;i++){
            tmp.push_back(1);
            for(int j=1;j<res[i-1].size();j++){
                tmp.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            tmp.push_back(1);
            res.push_back(tmp);
            tmp.clear();
       }
        return res;
    }
};