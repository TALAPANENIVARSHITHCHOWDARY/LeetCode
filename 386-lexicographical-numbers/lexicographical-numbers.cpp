class Solution {
public:
    void dfs(int current, int n, vector<int>& result) {
    if (current > n) return; // Base case: Stop if current exceeds n
    result.push_back(current); // Add the current number to the result
    for (int i = 0; i <= 9; i++) {
        if (current * 10 + i > n) break; // Break if the next number exceeds n
        dfs(current * 10 + i, n, result); // Recursive call for the next number
    }
}

vector<int> lexicalOrder(int n) {
    vector<int> result;
    for (int i = 1; i <= 9; i++) {
        dfs(i, n, result); // Start DFS for each number 1 through 9
    }
    return result;
}
};