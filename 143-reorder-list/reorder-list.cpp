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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return ;
        vector<ListNode* >v;
        ListNode* root = head;
        while(head != NULL){
            v.push_back(head);
            head = head->next;
        }
        head = root;
        int n= v.size();
        int j = 0;
        int nn = 0;
        if(n%2 == 1) nn = n/2+1;
        else nn = n/2;
        for(int i = n-1; i >=nn;i--){
            ListNode* tmp = v[j]->next;
            v[j]->next = v[i];
            v[i]->next = v[j+1];
            j++;
        }
        v[j]->next = NULL;
        

    }
};