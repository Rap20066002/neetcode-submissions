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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 1;
        ListNode* t1 = head;

        while(t1->next != NULL){
            len++;
            t1 = t1->next;
        }

        int front = len - n + 1;
        ListNode* t3 = head;
        ListNode* t4 = head->next;
        int counter = 1;

        if(front == 1){
            ListNode* t2 = head;
            head = head->next;
            delete t2;
            return head;
        }else{
            while(counter != front-1){
                t3 = t3->next;
                t4 = t4->next;
                counter++;
            }
            t3->next = t4->next;
            delete t4;
        }
        return head;
        
    }
};
