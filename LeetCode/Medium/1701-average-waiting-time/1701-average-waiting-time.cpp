class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();

        long long curr=0;
        long long totaltime=0;
        for (auto &it : customers) {
            long long arival=it[0];
            long long timetaken=it[1];
            curr=max(arival,curr)+timetaken;

            totaltime+=(curr-arival);
        
        }

        return (double)totaltime/n;
    }
};