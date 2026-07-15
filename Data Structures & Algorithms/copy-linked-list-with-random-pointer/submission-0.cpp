/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        unordered_map<Node*, Node*> mp;
        while(temp){
            Node* newNode = (mp[temp] != NULL) ? mp[temp] : new Node(temp->val);
            if(mp[temp] == NULL) mp[temp] = newNode;

            tail->next = newNode;
            tail = tail->next;
            tail->next = NULL;
            
            if(mp[temp->random] == NULL && temp->random != NULL){
                mp[temp->random] = new Node(temp->random->val);
            }

            tail->random = mp[temp->random];
            temp = temp->next;
        }

        return dummy->next;
    }
};
