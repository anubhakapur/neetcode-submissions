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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return nullptr;
        ListNode*left=new ListNode(-1);
        left->next=head;
        ListNode*dummy=left;
        ListNode*right=head;
        int c=0;
        while(right && c<n){
            right=right->next;
            c++;
        }
        while(right){
            right=right->next;
            left=left->next;
        }
        left->next=left->next->next;
        return dummy->next;
    }
};
