namespace yf {
    int add(int a, int b) { return a + b; }
    int minus(int a, int b) { return a - b; }
    int multiply(int a, int b) { return a * b; }
}

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return ways(input);
    }
private:
    unordered_map<string, vector<int>> m_;
    
    const vector<int>& ways(const string& input) {
        if (m_.count(input)) return m_[input];
        
        vector<int> ans;
        
        for (int i = 0; i < input.size(); ++i) {
            char op = input[i];
            if (op == '+' || op == '-' || op == '*') {
                const string left = input.substr(0, i);
                const string right = input.substr(i + 1);
                const vector<int>& l = ways(left);
                const vector<int>& r = ways(right);
                
                std::function<int(int, int)> f;
                
                switch(op) {
                    case '+': f = yf::add; break;
                    case '-': f = yf::minus; break;
                    case '*': f = yf::multiply; break;
                }
                
                for (int a : l)
                    for (int b : r)
                        ans.push_back(f(a, b));
            }
        }
        
        if (ans.empty())
            ans.push_back(std::stoi(input));
        
        m_[input].swap(ans);
        return m_[input];
    }
};
