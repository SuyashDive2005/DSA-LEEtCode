class Solution {
public:
    vector<int> getRow(int ri) {
        vector<vector<int>> res;

        res.push_back({1});

        vector<int> tmp;
        for(int i=1;i<=ri;i++){
            tmp.push_back(1);

            for(int j=1;j<res[i-1].size();j++){
                tmp.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            tmp.push_back(1);
            res.push_back(tmp);
            tmp.clear();
        }
        return res[ri];
    }
};