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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode* dummy=new ListNode(-1);
        if(head==NULL) return NULL;
        dummy->next=head;
        ListNode* cur=head;
        ListNode* prev=dummy;
        while(cur!=NULL){
            if(st.find(cur->val)!=st.end()){
                prev->next=cur->next;
                delete cur;
            }
            else{
                prev=cur;
            }
            cur=prev->next;
        }
        return dummy->next;
    }
};