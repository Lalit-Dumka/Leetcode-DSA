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
    ListNode* rotateRight(ListNode* head, int k) {

        if(k==0 || head==NULL || head->next == NULL) return head;

        ListNode * ptr= head;

        int n = 0;
        while(ptr!=NULL){
            n++;
            ptr=ptr->next;
        }

        k=k%n;

        ListNode * fast = head, * slow = head;

        for(int i=0; i<k; i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        fast->next=head;

        ptr=slow->next;
        slow->next=NULL;

        return ptr;
        
    }
};