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
        if(head == NULL || head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast->next != NULL && fast != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;
        ListNode* after = NULL;

        while(second != NULL){
            after = second->next;
            second->next = prev;
            prev = second;
            second = after;
        }

        second = prev;

        ListNode* first = head;
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        while(second){
            first->next = second;
            second->next = temp1;

            first = temp1;
            temp1 = temp1->next;
            second = temp2;
            temp2 = temp2->next;
        }
        return;
    }
};
