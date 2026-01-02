class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> present;
        for(auto &c:nums){
            if(present.count(c)) return c;
            else
            present.insert(c);
        }
        return -1;

    }
};