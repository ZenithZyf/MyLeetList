class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last_index(128, 0);
        for (int i = 0; i < S.size(); ++i) {
            last_index[S[i]] = i;
        }
        
        int start = 0;
        int end = 0;
        vector<int> ans;
        for (int i = 0; i < S.size(); ++i) {
            end = max(last_index[S[i]], end);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};
