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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for(ListNode* list: lists){
            if(list != nullptr)pq.push(list);
        }

        ListNode* res = new ListNode(0);
        ListNode* tail = res;

        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            ListNode* temp = top;
            top = top->next;
            if(top != NULL) pq.push(top);

            tail->next = temp;
            temp->next = NULL;
            tail = tail->next;
        }

        return res->next;
    }
};
