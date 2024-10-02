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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return head;
        ListNode* root = new ListNode(-1);
        // root->next = head;
        ListNode* a = root;;
        ListNode* root2 = new ListNode(-1);
        ListNode* b = root2;;
        while(head != nullptr){
            if(head->val < x) {
                a->next = head;
                a = a->next;
            }
            else {
                b->next = head;
                b = b->next;
            }
            head = head->next;
        }

        a->next = root2->next;
        b->next = NULL;
        return root->next;

    }

};