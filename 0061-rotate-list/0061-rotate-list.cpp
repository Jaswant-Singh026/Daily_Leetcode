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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr || k == 0) return head;

        int len = 1;
        ListNode* temp = head;
        while(temp -> next != nullptr){
            temp = temp -> next;
            len++;
        }

        k = k % len;
        if(k == 0) return head;

        temp -> next = head;

        int steps = len - k;
        ListNode* temp1 = head;
        for(int i = 1; i < steps; i++){
            temp1 = temp1 -> next;
        }
        ListNode* nextNode = temp1 -> next;
        temp1 -> next = nullptr;

        return nextNode;
    }
};