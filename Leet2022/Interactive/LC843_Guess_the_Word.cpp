/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int cnt = 0;
        for (int i = 0; i < 10; ++i) {
            string guess = wordlist[rand() % wordlist.size()];
            cnt = master.guess(guess);
            vector<string> temp;
            for (auto& word : wordlist) {
                if (match(word, guess) == cnt) {
                   temp.emplace_back(word); 
                }
            }
            wordlist = temp;
        }
    }
private:
    int match(const string& s1, const string& s2) {
        int res = 0;
        for (int i = 0; i < 6; ++i) {
            if (s1[i] == s2[i]) {
                ++res;
            }
        }
        return res;
    }
};
