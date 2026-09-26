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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h1=list1;
        ListNode*h2=list2;
        ListNode*h3=new ListNode(-1);
        ListNode*temp=h3;
        while(h1 && h2){
            if(h1->val<h2->val){
                ListNode*nn=new ListNode(h1->val);
                h1=h1->next;
                temp->next=nn;
                temp=nn;
            }else{
                ListNode*nn=new ListNode(h2->val);
                h2=h2->next;
                temp->next=nn;
                temp=nn;
            }
        }
        while(h1){
            ListNode*nn=new ListNode(h1->val);
            temp->next=nn;
            temp=nn;
            h1=h1->next;
        }
        while(h2){
            ListNode*nn=new ListNode(h2->val);
            temp->next=nn;
            temp=nn;
            h2=h2->next;
        }
        return h3->next;
    }
};
