/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 */
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

// one pass solution (Approach 1)
class Solution {
public:
    int length(ListNode *head){
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int L = length(head);
        
        if(n==L){
            ListNode *temp = head->next;
            delete(head);
            return temp;
        }

        int travl_front = L-n;
        ListNode *temp = head;
        ListNode *prev = NULL;

        while(travl_front--){
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete(temp);
        return head;
    }
};

// two pass solution (approach 2)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * temp = head;

        for(int i=1;i<=n;i++){
            temp = temp->next;
        }

        if(temp==NULL){
            ListNode *temp = head->next;
            delete head;
            return temp;
        }

        ListNode *prev = head;
        
        while(temp!=NULL && temp->next!=NULL){
            prev = prev->next;
            temp = temp->next;
        }

        ListNode *delNode = prev->next;
        prev->next = prev->next->next;
        delete delNode;
        return head;
    }
};