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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* root = new ListNode(0);
        ListNode* head = root;
        ListNode* prev = NULL;

        // 4+9
        // tot = 13
        // caryy = 13/10 = 1;
        // rem = 13%10 = 3; remainder (ye likhenge)

        while(l1 != NULL and l2 != NULL){
            int tot = l1->val + l2->val + carry;
            carry = tot/10;
            int rem = tot%10;

            ListNode* tmp = new ListNode(rem);
            head->next = tmp;
            // head = head->next;
            // or
            head = tmp;

            if(l1->next == NULL and l2->next == NULL and carry == 1){
                ListNode* tmp2 = new ListNode(carry);
                head->next = tmp2;
                head = head->next;
            }

            l1 = l1->next;
            l2 = l2->next;

        }


        while(l1 != NULL){
            int tot = l1->val + carry;
            carry = tot/10;
            int rem = tot%10;

            ListNode* tmp = new ListNode(rem);
            head->next = tmp;
            // head = head->next;
            // or
            head = tmp;

            if(l1->next == NULL and carry == 1){
                ListNode* tmp2 = new ListNode(carry);
                head->next = tmp2;
                head = head->next;
            }

            l1 = l1->next;

        }

        while(l2 != NULL){
            int tot = l2->val + carry;
            carry = tot/10;
            int rem = tot%10;

            ListNode* tmp = new ListNode(rem);
            head->next = tmp;
            // head = head->next;
            // or
            head = tmp;
            if(l2->next == NULL and carry == 1){
                ListNode* tmp2 = new ListNode(carry);
                head->next = tmp2;
                head = head->next;
            }

            l2 = l2->next;

        }


        return root->next;

    }
};


    //     3 4 2
    //     4 6 5
    //    --------
    //     8 0 7
