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
    bool isPalindrome(ListNode* head) {
        static const auto fast=[](){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return nullptr;}();
        // if(!head->next) return true;
        ListNode *mid = head, *fst=head;
        while(fst!=NULL && fst->next!=NULL){
            mid=mid->next;
            fst=fst->next->next;
        }
        ListNode *cur= mid, *prev=NULL, *next;
        while(cur!=NULL){
            next = cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        while(prev!=NULL){
            if(head->val!=prev->val){
                return false;
            }
            head=head->next;
            prev=prev->next;
        }
        return true;
    }
};