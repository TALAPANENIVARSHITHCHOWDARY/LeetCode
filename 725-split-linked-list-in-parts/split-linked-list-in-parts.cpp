class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        ListNode* cur = head;
        vector<ListNode*> ans;

        // Step 1: Calculate the total number of nodes in the list
        while (cur != nullptr) {
            count++;
            cur = cur->next;
        }

        // Step 2: Calculate how many nodes should be in each part
        int partSize = count / k;          // Size of each part
        int extraNodes = count % k;        // Extra nodes to distribute in the first few parts

        cur = head;
        for (int i = 0; i < k; i++) {
            ListNode* partHead = cur;      // Start of the current part
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);  // Add extra node to the part if needed
            extraNodes--;

            // Move cur to the end of the current part
            for (int j = 1; j < currentPartSize && cur != nullptr; j++) {
                cur = cur->next;
            }

            // Split the list if there are more nodes
            if (cur != nullptr) {
                ListNode* nextPart = cur->next;
                cur->next = nullptr;       // Break the list
                cur = nextPart;            // Move to the next part
            }

            // Store the part head in the result
            ans.push_back(partHead);
        }

        // Step 3: Return the list of parts
        return ans;
    }
};