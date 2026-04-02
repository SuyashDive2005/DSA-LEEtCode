class Solution {
public:
    vector<vector<int>>res;
    void solve(int i,vector<int>&nums,vector<int>&vec){
        if(i>=nums.size()){
            res.push_back(vec);
            return;
        }

        vec.push_back(nums[i]);
        solve(i+1,nums,vec);
        vec.pop_back();
        solve(i+1,nums,vec);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>vec;
        solve(0,nums,vec);
        return res;
    }
};