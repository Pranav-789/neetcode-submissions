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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //supposing n is a valid number
        ListNode* prev = NULL; 
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        while(fast){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        

        if(prev == NULL) return slow->next;
        else{
            prev->next = slow->next;
            delete slow;
        }
        return head;
    }
};


// 1 2 3 4
// s  2 
// f    3