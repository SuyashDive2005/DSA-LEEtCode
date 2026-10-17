class Solution {
public:
    int sum(int n) {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 3>> a(n);

        for (int i = 0; i < n; i++)
            a[i] = {sum(nums[i]), nums[i], i};

        sort(a.begin(), a.end());

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || a[i][2] == i) continue;

            int j = i, cycle = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = a[j][2];
                cycle++;
            }

            ans += cycle - 1;
        }

        return ans;
    }
};