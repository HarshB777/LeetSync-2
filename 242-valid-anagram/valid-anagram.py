class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if (len(s) != len(t)):
            return False

        hm1, hm2 = {}, {}

        for i in range(len(s)):
            hm1[s[i]] = 1 + hm1.get(s[i], 0)
            hm2[t[i]] = 1 + hm2.get(t[i], 0)
        

        return hm1 == hm2
