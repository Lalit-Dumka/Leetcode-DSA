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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        static const auto fast=[](){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return nullptr;}();
        ListNode *result=NULL, *ptr;
        int sum=0, rem=0;
        while(l1!=NULL || l2!=NULL || rem){
            sum=0;

            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=rem;
            rem=(sum)/10;

            ListNode * newNode = new ListNode(sum%10);

            if(result==NULL){
                result=newNode;
                ptr=result;
                continue;
            }
            ptr->next=newNode;
            ptr=ptr->next;
        }
        return result;
    }
};