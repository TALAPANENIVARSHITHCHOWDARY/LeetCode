class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      // Map to store the frequency count vector as the key and the list of anagrams as the value
    unordered_map<string, vector<string>> anagrams;

    // Iterate through each string in the input vector
    for (string s : strs) {
        // Create a frequency count vector for the string
        array<int, 26> count = {0};
        for (char c : s) {
            count[c - 'a']++;
        }

        // Convert the frequency count array to a string key
        string key = "";
        for (int i = 0; i < 26; ++i) {
            key += to_string(count[i]) + "#";
        }

        // Add the original string to the corresponding key in the map
        anagrams[key].push_back(s);
    }

    // Collect all the grouped anagrams from the map into a vector
    vector<vector<string>> result;
    for (auto& pair : anagrams) {
        result.push_back(pair.second);
    }

    return result;
      
    }
};