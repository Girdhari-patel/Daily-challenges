/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]
 

Constraints:

The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.
*/

/*
class Solution {
public:
    vector<int> removeZeroSum(vector<int>v){
        int n = v.size();
        int sum = 0;
        vector<int>ans;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;i++){
                sum+=v[j];
                if(sum==0){
                    i=j+1;
                    break;
                }
            }
            ans.push_back(v[i]);
        }
        return ans;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head || !head->next)return head;

        vector<int>v;
        ListNode* temp = head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        vector<int>  ans = removeZeroSum(v);
        
        ListNode * newhead = new ListNode(-1);
        ListNode * tail = newhead;
        int i=0;
        while(i<v.size()){
            tail->next->val = v[i];
            tail= tail->next;
            i++;
        }
        return newhead->next;

    }
};
*/

// brute force O(n^2);
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* start = front;

        while (start != nullptr) {
            int prefixSum = 0;
            ListNode* end = start->next;

            while (end != nullptr) {
                // Add end's value to the prefix sum
                prefixSum += end->val;
                // Delete zero sum consecutive sequence 
                // by setting node before sequence to node after
                if (prefixSum == 0) {
                    start->next = end->next;
                }
                end = end->next;
            }

            start = start->next;
        }
        return front->next;
    }
};