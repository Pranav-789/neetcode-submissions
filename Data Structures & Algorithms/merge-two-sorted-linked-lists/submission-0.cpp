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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        ListNode* t1 = list1;
        ListNode* t2 = list2;
        
        while(t1 && t2){
            if(t1->val < t2->val){
                tail->next = t1;
                tail = tail->next;
                t1 = t1->next;
                tail->next = NULL;
            }
            else{
                tail->next = t2;
                tail = tail->next;
                t2 = t2->next;
                tail->next = NULL;
            }
        }

        while(t1){
            tail->next = t1;
            tail = tail->next;
            t1 = t1->next;
            tail->next = NULL;
        }
        while(t2){
            tail->next = t2;
            tail = tail->next;
            t2 = t2->next;
            tail->next = NULL;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
