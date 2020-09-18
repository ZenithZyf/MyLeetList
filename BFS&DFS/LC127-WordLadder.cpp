class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        
        int l = beginWord.length();
        
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        
        int step = 0;
        
        while (!q1.empty() && !q2.empty()) {
            ++step;
            
            if (q1.size() > q2.size())
                std::swap(q1, q2);
            
            unordered_set<string> q;
            
            for (string w : q1) {
                for (int i = 0; i < l; i++) {
                    char ch = w[i];
                    for (int j = 'a'; j <= 'z'; ++j) {
                        w[i] = j;
                        if (q2.count(w)) return step + 1;
                        if (!words.count(w)) continue;
                        words.erase(w);
                        q.insert(w);
                    }
                    w[i] = ch;
                }
            }
            
            std::swap(q, q1);
            
        }
        
        return 0;
    }
};
