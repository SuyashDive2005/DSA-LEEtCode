class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int size=A.size();
        vector<int> res(size);
        vector<int> fre(size+1);
        int cnt=0;
        for(int i=0;i<size;i++){
            if(++fre[A[i]]==2) {
                cnt++;
            }
            if(++fre[B[i]]==2){
                cnt++;
            }
            res[i]=cnt;
        }
        return res;
    }
};