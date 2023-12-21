#include <string>

class Solution {
public:
    std::string largestGoodInteger(std::string num) {
        int count = 0;
        for (int i = 1; i < num.size() - 1; i++) {
            if (num[i - 1] == num[i] && num[i] == num[i + 1])
                count++;
        }
        if (count == 0)
            return "";

        int n = 0;
        for (int i = 1; i < num.size() - 1; i++) {
            if (num[i - 1] == num[i] && num[i] == num[i + 1] && n < stoi(num.substr(i - 1, 3)))
                n = stoi(num.substr(i - 1, 3));
        }
        string m;
        if(n==0){
         m ="000";
        }
        else{
   m = std::to_string(n);
        }
        return m;
    }
};
