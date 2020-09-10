class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0;
        int p2 = 0;
        int n1 = version1.size();
        int n2 = version2.size();
        
        while (p1 < n1 || p2 < n2) {
            if (p1 < n1 && version1[p1] == '.')
                p1++;
            if (p2 < n2 && version2[p2] == '.')
                p2++;
            int cur1 = 0;
            int cur2 = 0;
            while (p1 < n1 && version1[p1] != '.')
                cur1 = cur1 * 10 + (version1[p1++] - '0');
            while (p2 < n2 && version2[p2] != '.')
                cur2 = cur2 * 10 + (version2[p2++] - '0');
            if (cur1 != cur2)
                return cur1 < cur2 ? -1 : 1;
        }
        
        return 0;
    }
};
