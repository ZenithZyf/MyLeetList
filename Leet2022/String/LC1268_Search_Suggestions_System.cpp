class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        std::sort(begin(products), end(products));
        string key;
        for (char c : searchWord) {
            key += c;
            auto l = lower_bound(begin(products), end(products), key);
            auto r = upper_bound(begin(products), end(products), key += '~');
            if (l == r) {
                break;
            }
            key.pop_back();
            ans.emplace_back(l, min(l + 3, r));
        }
        while (ans.size() != searchWord.length()) {
            ans.push_back({});
        }
        return ans;
    }
};
