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

    ListNode* f(ListNode* head, ListNode* prev){
        if(head == NULL) return prev;

        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
        return f(head, prev); // next iteration of loop

    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return nullptr;
        ListNode* prev = NULL;
        // return f(head, prev);

        while(head != NULL){
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        
        return prev;

    }
};