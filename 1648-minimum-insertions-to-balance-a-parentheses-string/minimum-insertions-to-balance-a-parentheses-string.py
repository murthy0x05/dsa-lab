class Solution:
    def minInsertions(self, s: str) -> int:
        N = len(s)

        i = 0
        st = []
        result = 0
        while i < N:
            if s[i] == '(':
                st.append(i)
                i += 1
            else:
                if i + 1 < N:
                    if s[i + 1] == ')':
                        if st:
                            st.pop()
                            i += 2
                        else:
                            result += 1
                            i += 2
                    else:
                        if st:
                            st.pop()
                            result += 1
                            i += 1
                        else:
                            result += 2
                            i += 1
                else:
                    if st:
                        result += 1
                        st.pop()

                        i += 1
                    else:
                        result += 2
                        i += 1

        return result + (len(st) << 1)