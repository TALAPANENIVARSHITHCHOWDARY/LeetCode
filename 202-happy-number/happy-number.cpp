#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;    
        int num = n;
        while (num != 1) {
            if (seen.find(num) != seen.end()) {
                return false;
            }
            seen.insert(num);    
            int sum = 0;
            while (num > 0) {
                int digit = num % 10;
                sum += digit * digit;
                num /= 10;
            }
            num = sum;
        }
        return true;
    }
};
