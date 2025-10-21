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
    ListNode* reverse(ListNode*slow){
        ListNode*temp=slow;
        ListNode*temp2=slow->next;
        while(temp2!=NULL){
            ListNode*temp3=temp2->next;
            temp2->next=temp;
            temp=temp2;
            temp2=temp3;
        }
        slow->next=NULL;
        return temp;
    }

    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*rear=reverse(slow);
        ListNode*temp=head;
        while(temp!=NULL&&rear!=NULL){
            cout<<temp->val<<" "<<rear->val<<endl;
            if(temp->val!=rear->val){
                return false;
            }
            temp=temp->next;
            rear=rear->next;
        }
        return true;
    }
};
