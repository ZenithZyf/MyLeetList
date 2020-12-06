class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stk1 = [] # to store all the logical operations
        stk2 = [] # to store all the boolean values
        
        for i in expression:
            # if we encountered a logical expression
            if i == '!' or i == '&' or i == '|':
                stk1.append(i)
                continue
            # if we encountered a ')'
            elif i == ')':
                # count for true and false occured
                t = 0
                f = 0
                while stk2[-1] != '(':
                    if stk2[-1] == 't':
                        t += 1
                    elif stk2[-1] == 'f':
                        f += 1
                    stk2.pop()
                # pop out the '('
                stk2.pop()
                # x is our logical operation
                x = stk1.pop()
                # perform the logical calculation
                if x == '!':
                    if t == 1:
                        stk2.append('f')
                    else:
                        stk2.append('t')
                elif x == '&':
                    if f != 0:
                        stk2.append('f')
                    else:
                        stk2.append('t')
                elif x == '|':
                    if t != 0:
                        stk2.append('t')
                    else:
                        stk2.append('f')
            # if we encounter other characters
            else:
                stk2.append(i)
        
        # If the input is valid, there will be one and only one element in stk2
        if stk2[0] == 't': return True
        else: return False
        
                
            
