class Solution {
public:
    bool strongPasswordCheckerII(std::string password) {
        int n = password.size();
        if (n < 8) {
            return false;
        }
        for (int i = 0; i < n - 1; i++) {
            if (password[i] == password[i + 1]) {
                return false;
            }
        }
        bool hasLower = false;
        bool hasUpper = false;
        bool hasDigit = false;
        bool hasSpecial = false;
        for (int i = 0; i < n; i++) {
            if (islower(password[i])) {
                hasLower = true;
            } else if (isupper(password[i])) {
                hasUpper = true;
            } else if (isdigit(password[i])) {
                hasDigit = true;
            } else if (ispunct(password[i])) {
                hasSpecial = true;
            }
        }
        return hasLower && hasUpper && hasDigit && hasSpecial;
    }
};
