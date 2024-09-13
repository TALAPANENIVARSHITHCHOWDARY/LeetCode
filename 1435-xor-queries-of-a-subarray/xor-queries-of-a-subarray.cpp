class Solution {
public:
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXOR(n);
        prefixXOR[0] = arr[0];
        
        // Compute the prefix XOR
        for (int i = 1; i < n; ++i) {
            prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
        }

        vector<int> ans;
        // Answer each query using the prefix XOR
        for (auto& query : queries) {
            int left = query[0], right = query[1];
            if (left == 0) {
                ans.push_back(prefixXOR[right]);
            } else {
                ans.push_back(prefixXOR[right] ^ prefixXOR[left - 1]);
            }
        }

        return ans;
    }
};