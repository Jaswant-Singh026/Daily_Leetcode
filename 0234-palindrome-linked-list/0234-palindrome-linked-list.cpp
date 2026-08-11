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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr != nullptr){
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = prev;
        while(temp2 != nullptr){
            if(temp1 -> val != temp2 -> val) return false;
            else{
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
        }
        return true;
    }
};