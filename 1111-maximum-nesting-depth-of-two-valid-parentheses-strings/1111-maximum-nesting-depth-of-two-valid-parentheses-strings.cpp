class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> vec;
        int d = 0;

        for (char& c : seq) {
            if (c == '(') {
                vec.push_back(d % 2);
                d++;
            } else {
                d--;
                vec.push_back(d % 2);
            }
        }

        return vec;
    }
};