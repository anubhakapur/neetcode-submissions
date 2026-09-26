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
        int totalNodes=0;
        ListNode*temp=head;
        while(temp){
            totalNodes++;
            temp=temp->next;
        }
        if(n>totalNodes)return head;
        if(totalNodes==n){
            head=head->next;
            return head;
        }
        int c=1;
        temp=head;
        while(c<(totalNodes-n)){
            c++;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};
