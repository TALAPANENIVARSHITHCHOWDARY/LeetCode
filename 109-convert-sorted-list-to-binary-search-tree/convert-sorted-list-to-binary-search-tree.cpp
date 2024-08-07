/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        return sortedListToBSTHelper(head, nullptr);
    }
    
private:
    TreeNode* sortedListToBSTHelper(ListNode* head, ListNode* tail) {
        if (head == tail) return nullptr;
        
        // Find the middle element
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Create the root node with the middle element
        TreeNode* root = new TreeNode(slow->val);
        
        // Recursively construct the left and right subtrees
        root->left = sortedListToBSTHelper(head, slow);
        root->right = sortedListToBSTHelper(slow->next, tail);
        
        return root;
    }
};
