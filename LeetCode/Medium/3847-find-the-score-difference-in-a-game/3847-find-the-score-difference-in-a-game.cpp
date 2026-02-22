class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int player1 = 0, player2 = 0;
        bool pl1 = true, pl2 = false;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 6 == 5) {
                pl1 = !pl1;
                pl2 = !pl2;
            }

            if (nums[i] % 2 != 0) {
                pl1 = !pl1;
                pl2 = !pl2;
            }

            if (pl1) {
                player1 += nums[i];
            }
            
            if (pl2) {
                player2 += nums[i];
            }
        }
        return player1 - player2;
    }
};