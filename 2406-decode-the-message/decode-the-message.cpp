class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, int> count;
        string m = "";
        for (int i = 0; i < key.size(); i++) {
            count[key[i]]++;
            if (count[key[i]] == 1 && key[i] != ' ')
                m += key[i];
        }
        for (int i = 0; i < message.size(); i++) {
            if (message[i] == ' ')
                continue;
            else {
                size_t found = m.find(message[i]);
                if (found != string::npos) {
                    message[i] = 'a' + found;
                }
            }
        }
     return message;
    }
};
