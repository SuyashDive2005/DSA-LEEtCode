class Solution {
public:
    vector<string> days = {
        "", "31", "28", "31", "30", "31", "30",
        "31", "31", "30", "31", "30", "31"
    };

    int countDaysTogether(string aAl, string lAl, string arB, string leB) {

        int Aarm = stoi(aAl.substr(0, 2));
        int Ard = stoi(aAl.substr(3, 2));

        int Larm = stoi(lAl.substr(0, 2));
        int Lrd = stoi(lAl.substr(3, 2));

        int Arbm = stoi(arB.substr(0, 2));
        int Arbd = stoi(arB.substr(3, 2));

        int Lebm = stoi(leB.substr(0, 2));
        int Lebd = stoi(leB.substr(3, 2));

        auto getDay = [&](int month, int day) {
            int total = day;

            for (int i = 1; i < month; i++) {
                total += stoi(days[i]);
            }

            return total;
        };

        int alArr = getDay(Aarm, Ard);
        int alLea = getDay(Larm, Lrd);

        int bArr = getDay(Arbm, Arbd);
        int bLea = getDay(Lebm, Lebd);

        int start = max(alArr, bArr);
        int end = min(alLea, bLea);

        return max(0, end - start + 1);
    }
};