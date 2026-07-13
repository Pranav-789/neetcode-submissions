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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* tail = dummy;
        ListNode* slow = head;
        ListNode* fast = head;

        while(true){
            int cnt = 0;
            for(int i = 0; i < k; i++){
                if(fast){
                    fast = fast->next;
                } 
                else break;
                cnt++;
            }

            if(cnt != k) break;

            // reverse given list;
            int tmp = k;
            ListNode* curr = slow;
            ListNode* prev = NULL;
            ListNode* subHead = NULL;
            while(tmp--){
                if(subHead == NULL) subHead= curr;
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            subHead->next = fast;
            tail->next = prev;

            while(tail->next != fast) tail = tail->next;

            slow = fast;
        }

        return dummy->next;
    }
};
