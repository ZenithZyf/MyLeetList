class Solution {
public:
    bool isUnique(string& s, vector<int>& m) {
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i] - 'a'] >= 1) { return false; }
            m[s[i] - 'a']++;
        }
        return true;
    }
    
    int dfs(vector<string>& arr, int index, vector<int>& m) {
        if (index == arr.size()) {
            return 0;
        }
        
        vector<int> t(m);
        if (isUnique(arr[index], t)) {
            int curLen = arr[index].length();
            int len1 = curLen + dfs(arr, index + 1, t);
            int len2 = dfs(arr, index + 1, m);
            return max(len1, len2);
        }
        return dfs(arr, index + 1, m);
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> m(26, 0);
        return dfs(arr, 0, m);
    }
};
