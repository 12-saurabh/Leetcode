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
        ListNode* temp=l1;
        ListNode* temp1=l2;
        ListNode* dup=new ListNode();
        ListNode* sa=dup;
        int carry=0;
        while(temp!=NULL || temp1!=NULL || carry)
        {
            int sum=0;
            if(temp!=NULL)
            {
                sum+=temp->val;
                temp=temp->next;
            }
            if(temp1!=NULL)
            {
                sum+=temp1->val;
                temp1=temp1->next;
            }
            sum+=carry;
            carry=sum/10;
            int digit=sum%10;
            ListNode* newnode=new ListNode(digit);
            sa->next=newnode;
            sa=sa->next;
        }
        return dup->next;
        
    }
};
