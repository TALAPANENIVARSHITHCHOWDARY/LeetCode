class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        int count = 0;  // stores the number of words sharing this prefix
    };
    
    class Trie {
    public:
        TrieNode* root;
        
        Trie() {
            root = new TrieNode();
        }
        
        // Insert the word into the trie and update the count of prefixes
        void insert(const string& word) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children.count(c)) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
                node->count++;  // Every node (prefix) that we visit, we increment the count
            }
        }
        
        // Get the sum of scores for all prefixes of the word
        int getPrefixScore(const string& word) {
            TrieNode* node = root;
            int score = 0;
            for (char c : word) {
                if (!node->children.count(c)) {
                    break;
                }
                node = node->children[c];
                score += node->count;  // Sum up the counts of each prefix
            }
            return score;
        }
    };
    
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        // Insert all words into the trie
        for (const string& word : words) {
            trie.insert(word);
        }
        
        // Calculate the prefix score for each word
        vector<int> result;
        for (const string& word : words) {
            result.push_back(trie.getPrefixScore(word));
        }
        
        return result;
    }
};
