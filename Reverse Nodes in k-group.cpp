class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==0)
            return NULL;
        ListNode *temp=head;
        int count=0;
        ListNode *prev=0;
        ListNode*ahead=temp;
        int l=0;
        ListNode *f=head;
        while(f!=0)
        {
            f=f->next;
            l++;
        }
        if(l<k)
        {
            return head;
        }
        while(count<k &&temp!=NULL)
        {
            ahead=temp->next;
            temp->next=prev;
            prev=temp;
            temp=ahead;
            count++;
        }
        head->next=reverseKGroup(ahead,k);
        return prev;
    }
};
