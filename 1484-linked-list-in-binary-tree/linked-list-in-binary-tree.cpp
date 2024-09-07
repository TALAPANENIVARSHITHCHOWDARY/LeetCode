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
    bool dfs(TreeNode* root, ListNode* head) {
        if (head == NULL) return true;  // If we've traversed the entire linked list
        if (root == NULL) return false;  // If the tree path ends without matching the list

        // If the current values match, continue to check the left and right subtrees
        if (root->val == head->val) {
            return dfs(root->left, head->next) || dfs(root->right, head->next);
        }
        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL) return false;
        // Check if the linked list starts from the current node, or try in the left or right subtrees
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
