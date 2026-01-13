/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* solve(ListNode* head)
{
    ListNode* fast=head;
    ListNode* slow=head;
    while(slow!=NULL && fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL)fast=fast->next;
        if(slow==fast)return slow;
    }
    return NULL;
}
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {  
        ListNode* intersection=solve(head);
        ListNode* slow=head;
        if(intersection==NULL)return NULL;
        while(slow!=intersection)
        {
            slow=slow->next;
            intersection=intersection->next;
        }
        return slow;

    }
};