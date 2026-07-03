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
    ListNode* reverselist(ListNode* root){
        if(root == NULL || root->next == NULL) return root;

        ListNode* curr = root;
        ListNode* prev = NULL;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = slow->next;
        slow->next = NULL;
        newHead = reverselist(newHead);

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        ListNode* t1 = head;
        ListNode* t2 = newHead;

        while(t1 && t2){
            tail->next = t1;
            t1 = t1->next;
            tail = tail->next;

            tail->next = t2;
            t2 = t2->next;
            tail = tail->next;
            tail->next = NULL;
        }

        while(t1){
            tail->next = t1;
            t1 = t1->next;
            tail = tail->next;
            tail->next = NULL;
        }

        head = dummy->next;
        delete dummy;
    }
};
