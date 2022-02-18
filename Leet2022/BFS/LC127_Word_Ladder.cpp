class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) {
            return 0;
        }
        int len = beginWord.length();
        unordered_set<string> begin_set{beginWord};
        unordered_set<string> end_set{endWord};
        int step = 0;
        while (!begin_set.empty() && !end_set.empty()) {
            ++step;
            if (begin_set.size() > end_set.size()) {
                std::swap(begin_set, end_set);
            }
            unordered_set<string> cur_set;
            for (string word : begin_set) {
                for (int i = 0; i < len; ++i) {
                    char c = word[i];
                    for (int j = 'a'; j <= 'z'; ++j) {
                        word[i] = j;
                        if (end_set.count(word)) {
                            return step + 1;
                        }
                        if (!dict.count(word)) {
                            continue;
                        }
                        dict.erase(word);
                        cur_set.insert(word);
                    }
                    word[i] = c;
                }
            }
            std::swap(cur_set, begin_set);
        }
        return 0;
    }
};
