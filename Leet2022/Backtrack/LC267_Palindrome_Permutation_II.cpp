class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> meet;
        for (const char c : s) {
            ++meet[c];
        }
        
        string t = "", mid = "";
        for (auto& m : meet) {
            if (m.second % 2 == 1) {
                mid += m.first;
            }
            if (mid.size() >= 2) {
                return {};
            }
            m.second /= 2;
            t += string(m.second, m.first);
        }
        
        vector<string> res;
        permute(t, meet, mid, "", res);
        return res;
    }
private:
    void permute(const string& t, unordered_map<char, int>& meet, const string mid, string out, vector<string>& res) {
        if (out.size() == t.size()) {
            res.emplace_back(out + mid + string(out.rbegin(), out.rend()));
            return;
        }
        for (auto& m : meet) {
            if (m.second > 0) {
                --m.second;
                permute(t, meet, mid, out + m.first, res);
                ++m.second;
            }
        }
    }
};
