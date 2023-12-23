#include <bits/stdc++.h>

class Solution {
public:
    int maximumValue(std::vector<std::string>& strs) {
        int m = 0;
        for (int i = 0; i < strs.size(); i++) {
            int a1;
            string a = strs[i];
            bool n = true;
            for (int j = 0; j < a.size(); j++) {
                if (isalpha(a[j])) {
                    n = false;
                    break;
                }
            }
            if (n) {
               a1=stoi(a);
            } else {
                a1 = a.size();
            }
            m = std::max(a1, m);
        }
        return m;
    }
};
