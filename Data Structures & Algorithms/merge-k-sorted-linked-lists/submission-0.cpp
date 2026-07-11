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
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(head1 && head2){
            if(head1->val < head2->val){
                ListNode* tmp = head1;
                head1 = head1->next;
                tmp->next = NULL;
                tail->next = tmp;
                tail = tail->next;
            }else{
                ListNode* tmp = head2;
                head2 = head2->next;
                tmp->next = NULL;
                tail->next = tmp;
                tail = tail->next;
            }
        }

        while(head1){
            ListNode* tmp = head1;
            head1 = head1->next;
            tmp->next = NULL;
            tail->next = tmp;
            tail = tail->next;
        }

        while(head2){
            ListNode* tmp = head2;
            head2 = head2->next;
            tmp->next = NULL;
            tail->next = tmp;
            tail = tail->next;
        }

        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        int n = lists.size();

        for(int i = 0; i < n; i++){
            dummy->next = merge(dummy->next, lists[i]);
        }

        return dummy->next;
    }
};
