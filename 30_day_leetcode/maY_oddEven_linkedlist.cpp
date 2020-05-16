/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        
        ListNode* oddpointer=head;
        ListNode* evenpointer=head->next;
        ListNode* evenhead=head->next;
        //2,4,6,1,3,7
        //odd->2
        //even->4
        //odd->next=even->next ie 2->next=4->next ie 2->6->3
        //similary even->next=odd->next ie 4->next=6->next ie 4->1->7
        //atlast odd->next=evenhead ie 2->6->3->4->1->7
        //   return head
        while(oddpointer->next!=nullptr&&evenpointer->next!=nullptr){
            oddpointer->next=evenpointer->next;
            oddpointer=evenpointer->next;
            evenpointer->next=oddpointer->next;
            evenpointer=oddpointer->next;
        }
        
        oddpointer->next=evenhead;
        return head;
    }
};