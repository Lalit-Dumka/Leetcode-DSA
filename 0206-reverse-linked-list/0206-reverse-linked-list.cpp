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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode *p1=NULL, *p2=head, *p3=head->next;
        p2->next=p1;
        while(p3!=NULL){
            p1=p2;
            p2=p3;
            p3=p3->next;
            p2->next=p1;
        }
        return p2;
    }
};