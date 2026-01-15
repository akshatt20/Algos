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
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
ListNode* mer(ListNode* l,ListNode* r)
{
    if(l==NULL)return r;
    if(r==NULL)return l;
    ListNode* temp=new ListNode(-1);
    ListNode* ans=temp;
    while(l!=NULL && r!=NULL)
    {
        if(l->val<=r->val)
        {
            temp->next=l;
            temp=l;
            l=l->next;
        }
        else{
         temp->next=r;
            temp=r;
            r=r->next;   
        }
    }
    while(l!=NULL)
    {
         temp->next=l;
            temp=l;
            l=l->next;
    }
     while(r!=NULL)
    {
         temp->next=r;
            temp=r;
            r=r->next;
    }
    return ans->next;
}
    ListNode* sortList(ListNode* head) {
     if(head==NULL || head->next==NULL)return head;
     ListNode* mid=findMiddle(head);
     ListNode* left=head;
     ListNode* right=mid->next;
     mid->next=NULL;
     left=sortList(left);
     right=sortList(right);
     ListNode* res=mer(left,right);
     return res;   
    }
};