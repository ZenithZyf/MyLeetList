class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto alpha_end = std::stable_partition(begin(logs), end(logs), 
                                              [](const string& log){ return isalpha(log.back()); });
        std::sort(begin(logs), alpha_end, [](const string& a, const string& b){
            if (a.substr(a.find(' ')) == b.substr(b.find(' '))) {
                return a < b;
            }
            return a.substr(a.find(' ')) < b.substr(b.find(' ')); 
        });
        return logs;
    }
};
