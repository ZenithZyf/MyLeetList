class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        for (int i = 0; i < deadends.size(); ++i) {
            visited.insert(deadends[i]);
        }
        
        if (visited.count("0000")) return -1;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int step = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string cur = q.front();
                q.pop();
                if (cur == target) return step;
                
                for (int j = 0; j < 4; ++j) {
                    string up = plusOne(cur, j);
                    if (!visited.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }
                    
                    string down = minusOne(cur, j);
                    if (!visited.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            ++step;
        }
        
        return -1;
    }
    
private:
    string plusOne(const string cur, const int j) {
        string up = cur;
        if (up[j] == '9')
            up[j] = '0';
        else
            ++up[j];
        return up;
    }
    
    string minusOne(const string cur, const int j) {
        string down = cur;
        if (down[j] == '0')
            down[j] = '9';
        else
            --down[j];
        return down;
    }
};
