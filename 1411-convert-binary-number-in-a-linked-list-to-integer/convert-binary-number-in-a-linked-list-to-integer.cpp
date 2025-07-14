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
    int getDecimalValue(ListNode* head) {
        int n = 0;
        ListNode* h = head;
        while(head != NULL){
            head = head->next;
            n++;
        }
        n--;
        int res = 0;
        while(h != NULL){
            int val = h->val;
            if(val == 1)res += pow(2, n);
            n--;
            h=h->next;
        }

        return res;
    }
};