class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            if (!s.empty() && arr[i] < s.top()) {
                int head = s.top(); s.pop();
                while (!s.empty() && arr[i] < s.top())
                    s.pop();
                s.push(head);
            } else {
                s.push(arr[i]);
            }
                
        }
        return s.size();
    }
};
