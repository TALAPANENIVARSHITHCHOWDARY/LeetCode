#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    TrieNode() {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (!currentNode->children.count(ch)) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
    }

    int findLongestPrefix(const std::string& word) {
        TrieNode* currentNode = root;
        int length = 0;
        for (char ch : word) {
            if (currentNode->children.count(ch)) {
                length++;
                currentNode = currentNode->children[ch];
            } else {
                break;
            }
        }
        return length;
    }
};

class Solution {
public:
    int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
        Trie trie;

        // Insert all integers from arr1 into the Trie
        for (int num : arr1) {
            trie.insert(std::to_string(num));
        }

        int maxLength = 0;

        // Find the longest common prefix for each integer in arr2
        for (int num : arr2) {
            maxLength = std::max(maxLength, trie.findLongestPrefix(std::to_string(num)));
        }

        return maxLength;
    }
};
