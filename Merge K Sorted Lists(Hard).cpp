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
 class compare{
    public:
    bool operator()(ListNode* a,ListNode* b)
    {
        return a->val>b->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        for(int i=0;i<lists.size();i++)
        {
            ListNode* listhead=lists[i];
            if(lists[i]!=NULL)
            {
                pq.push(listhead);
            }
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(!pq.empty())
        {
            ListNode* topNode=pq.top();
            pq.pop();
            if(head==NULL)
            {
                head=topNode;
                tail=topNode;
                if(tail->next!=NULL)
                {
                    pq.push(tail->next);
                }
            }
            else
            {
                tail->next=topNode;
                tail=topNode;
                if(tail->next!=NULL)
                {
                    pq.push(tail->next);
                }
            }
        }
        return head;
    }
};
