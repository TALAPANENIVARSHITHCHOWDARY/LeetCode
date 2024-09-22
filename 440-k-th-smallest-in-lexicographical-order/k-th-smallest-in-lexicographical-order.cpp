class Solution {
public:
    // Helper function to count how many numbers exist in the range [prefix, prefix+1)
    int countSteps(long long prefix, int n) {
        long long current = prefix;
        long long next = prefix + 1;
        int steps = 0;
        
        // Count steps between `prefix` and `prefix + 1`
        while (current <= n) {
            steps += min((long long)n + 1, next) - current;
            current *= 10;
            next *= 10;
        }
        return steps;
    }
    
    int findKthNumber(int n, int k) {
        int current = 1;
        k--; // As we are already at the first number "1"
        
        while (k > 0) {
            int steps = countSteps(current, n);
            
            // If the k-th number is in the current subtree
            if (steps <= k) {
                // Skip the entire subtree of the current prefix
                current++;
                k -= steps;
            } else {
                // Move to the next level in the current subtree
                current *= 10;
                k--;
            }
        }
        return current;
    }
};
