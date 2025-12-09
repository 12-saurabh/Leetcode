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
    int len(ListNode* head){
        if(head==NULL){
            return 0;
        }

        ListNode* temp=head;
        int leng=0;
        while(temp!=NULL){
            temp=temp->next;
            leng++;
        }

        return leng;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int length=len(head);

        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr!=NULL && length!=n){
            prev=curr;
            curr=curr->next;
            length--;
        }

        if(prev==NULL){
            ListNode* nextnode=head->next;
            head->next=NULL;
            delete head;
            return nextnode;
        }

        ListNode* nextnode=curr->next;

        prev->next=nextnode;
        curr->next=NULL;
        delete curr;

        return head;



        
    }
};
