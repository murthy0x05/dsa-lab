class Solution:
    def checkDivisibility(self, n: int) -> bool:
        return n % (eval('+'.join(str(n))) + eval('*'.join(str(n)))) == 0