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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL or headB == NULL) return NULL;
        
        map<ListNode*, int>m; 

        while(headA != NULL){
            m[headA] = 1; // marking as visited
            headA = headA->next;
        }

        while(headB != NULL){
            if(m[headB] == 1){
                return headB;
            }

            headB = headB->next;
        }

        return NULL;



    }
};