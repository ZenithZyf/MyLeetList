class Solution {
public:
    int maximumSwap(int num) {
        int r_idx = -1;
        int l_idx = -1;
        int max_num = -1;
        int max_idx = -1;
        
        string num_str = to_string(num);
        for (int i = num_str.size() - 1; i >= 0; i--) {
            if (num_str[i] > max_num) {
                max_idx = i;
                max_num = num_str[i];
                continue;
            }
            if (num_str[i] < max_num) {
                l_idx = i;
                r_idx = max_idx;
            }
        }
        
        if (l_idx == -1)
            return num;
        
        swap(num_str[l_idx], num_str[r_idx]);
        
        return stoi(num_str);
    }
};
