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
        if(head== nullptr||k==0){
            return head;
        }

        ListNode* curr= head;
        int len=1;

        while(curr->next != nullptr){
            curr =curr->next;
            len++;
        }
        k%=len;

        if(k==0) return head;
        curr->next=head;
        curr=head;
        for(int i=1;i<len-k;i++){
            curr=curr->next;
        }

        head=curr->next;
        curr->next=nullptr;
        return head;

    }
};