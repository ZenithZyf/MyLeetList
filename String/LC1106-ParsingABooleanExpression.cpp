class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk1; // save the logical operations
        stack<char> stk2; // save the "numbers"
        
        // Go from the beginning to the ending
        for (int i = 0; i < expression.size(); ++i) {
            // If it is a logical operation
            if (expression[i] == '|' || expression[i] == '&' || expression[i] == '!')
                stk1.push(expression[i]);
            // If it is a ")" we want to finish a calculation
            else if (expression[i] == ')') {
                // Count number of true and false
                int t = 0;
                int f = 0;
                // We need to calculate the expression within this "()"
                while (stk2.top() != '(') {
                    if (stk2.top() == 't')
                        t++;
                    if (stk2.top() == 'f')
                        f++;
                    stk2.pop();
                }
                // Pop out the '('
                stk2.pop();
                // X is the logic operator
                char x = stk1.top();
                stk1.pop();
                // Perform the logical calculation
                if (x == '!') {
                    if (t != 0)
                        stk2.push('f');
                    else
                        stk2.push('t');
                }
                else if (x == '&') {
                    if (f != 0)
                        stk2.push('f');
                    else
                        stk2.push('t');
                }
                else if (x == '|') {
                    if (t != 0)
                        stk2.push('t');
                    else
                        stk2.push('f');
                }
            }
            else
                stk2.push(expression[i]);
        }
        if (stk2.top() == 't') return true;
        else return false;
    }
};
