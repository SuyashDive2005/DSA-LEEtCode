class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxposs = 0;
        int maxg = *max_element(lights.begin(), lights.end());

        for (int j = 0; j < arrivalTime.size(); j++) {
            int r = arrivalTime[j] % period;

            if (r >= maxg){
                maxposs=max(maxposs,period-r);
            }
        }

        return maxposs;
    }
};