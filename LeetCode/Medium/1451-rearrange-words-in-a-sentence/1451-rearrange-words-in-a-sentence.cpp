class Solution {
public:
    string arrangeWords(string text) {
        for (char& c : text) {
            c = tolower(c);
        }

        vector<string> vec;
        string word = "";
        for (char c : text) {
            if (c == ' ') {
                vec.push_back(word);
                word = "";
            } else
                word += c;
        }
        vec.push_back(word);

        stable_sort(

            // start of vector
            vec.begin(),

            // end of vector
            vec.end(),

            // lambda function (custom comparison rule)
            [](const string& a, const string& b) {
                // compare length of two words
                // if a is smaller → return true → a comes first
                return a.length() < b.length();
            }
        );

        string res="";
        for(int i=0;i<vec.size();i++){
            res+=vec[i];
            if(i!=vec.size()-1) res+=" ";
        }

        res[0]=toupper(res[0]);

        return res;
    }
};