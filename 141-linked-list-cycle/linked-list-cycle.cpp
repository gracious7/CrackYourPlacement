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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next == NULL) return false;

        map<ListNode*, int>m;

        while(head != NULL){
            if(m[head] == 1){
                return true;
            }

            m[head] = 1;

            head= head->next;
        }

        return false;


    }
};