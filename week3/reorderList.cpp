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
    ListNode* reverse(ListNode* slow){
        ListNode* temp2=slow->next;
        slow->next=NULL;
        while(temp2!=NULL){
            ListNode* temp3=temp2->next;
            temp2->next=slow;
            slow=temp2;
            temp2=temp3;
        }
        return slow;
    }

    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode*fast=head;

        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*rear=reverse(slow);
        ListNode*front=head;
        while(front!=NULL&&rear!=NULL&&front!=rear){
            cout<<front->val<<" "<<rear->val<<endl;
            ListNode*temp=front->next;
            front->next=rear;
            front=rear;
            rear=temp;
        }
    }
};
