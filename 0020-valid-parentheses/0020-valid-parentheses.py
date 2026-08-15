
class Solution:
    def isValid(self, s: str) -> bool:
        l=[]
        for i in range(len(s)):
            if s[i] in '({[':
                l.append(s[i])
            elif s[i] in ')}]':
                if len(l)==0:
                    return False
                if(s[i]==')' and l[-1]=='(') or (s[i]=='}' and l[-1]=='{') or (s[i]==']' and l[-1]=='['):
                    l.pop()
                else:
                    return False
        if len(l)!=0:
            return False
        else:
            return True
            
            