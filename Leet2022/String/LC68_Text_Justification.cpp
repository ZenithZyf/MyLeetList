class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        size_t i = 0;
        size_t n = words.size();
        vector<string> ans;
        
        while (i < n) {
            bool last_line = false;
            int ll = 0;
            vector<string_view> tw;
            
            while (ll <= maxWidth && i < n) {
                size_t wl = words[i].length();
                int tll = ll + (tw.size() ? 1 : 0) + wl;
                if (tll > maxWidth) {
                    break;
                }
                ll = tll;
                tw.push_back(string_view(words[i]));
                if (++i == n) {
                    last_line = true;
                }
                if (ll == maxWidth) {
                    break;
                }
            }
            
            string line;
            if (!last_line) {
                int tl = 0;
                for (const auto& w : tw) {
                    tl += w.length();
                }
                int avg_space = tw.size() == 1 ? 0 : ((maxWidth - tl) / (tw.size() - 1));
                int extra_space = tw.size() == 1 ? 0 : (maxWidth - avg_space * (tw.size() - 1) - tl);
                for (const auto& w : tw) {
                    if (line.length() > 0) {
                        line.append(avg_space, ' ');
                        if (extra_space > 0) {
                            line += ' ';
                            --extra_space;
                        }
                    }
                    line += w;
                }
            } else {
                for (const auto& w : tw) {
                    if (line.length() > 0) {
                        line += ' ';
                    }
                    line += w;
                }
            }
            line.append(maxWidth - line.length(), ' ');
            ans.push_back(std::move(line));
        }
        return ans;
    }
};
