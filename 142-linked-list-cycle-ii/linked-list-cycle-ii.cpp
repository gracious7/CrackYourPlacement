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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next == NULL) return NULL;

        map<ListNode*, int>m;

        while(head != NULL){
            if(m[head] == 1){
                return head;
            }
            m[head] = 1;

            head= head->next;
        }

        return nullptr;
    }
};