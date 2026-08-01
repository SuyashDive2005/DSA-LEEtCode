class Solution {
public:
    bool solve(int p1, int p2, int i, int j, vector<int>& nums, int turn)
    {
        if(i > j)
        {
            return p1 >= p2;
        }

        if(turn == 0)
        {
            bool first = solve(p1 + nums[i], p2, i + 1, j, nums, 1);
            bool last  = solve(p1 + nums[j], p2, i, j - 1, nums, 1);

            return first || last;
        }
        else
        {
            bool first = solve(p1, p2 + nums[i], i + 1, j, nums, 0);
            bool last  = solve(p1, p2 + nums[j], i, j - 1, nums, 0);

            return first && last;
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(0, 0, 0, nums.size() - 1, nums, 0);
    }
};