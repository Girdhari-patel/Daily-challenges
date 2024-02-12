/*
Given an integer n, return the first n elements of Recaman’s sequence.
It is a function with domain and co-domain as whole numbers. It is recursively defined as below:
Specifically, let a(n) denote the (n+1)th term. (0 being the 1st term).
The rule says:
a(0) = 0
a(n) = a(n-1) - n, if a(n-1) - n > 0 and is not included in the sequence previously
       =  a(n-1) + n otherwise.

Example 1:

Input: 
n = 5
Output: 
0 1 3 6 2
Explaination: 
a(0) = 0,
a(1) = a(0)-1 = 0-1 = -1 and -1<0, therefore a(1) = a(0)+1 = 1,
a(2) = a(1)-2 = 1-2 = -1 and -1<0, therefore a(2) = a(1)+2 = 3,
a(3) = a(2)-3 = 3-3 = 0 but since 0 is already present in the sequence, a(3) = a(2)+3 = 3+3 = 6,
a(4) = a(3)-4 = 6-4 = 2.
Therefore the first 5 elements of Recaman's sequence will be 0 1 3 6 2.
Example 2:

Input: 
n = 3
Output: 
0 1 3
Explaination: 
As seen in example 1, the first three elements will be 0 1 3.
https://www.geeksforgeeks.org/problems/recamans-sequence4856/1 */\
class Solution{
public:
    // int  solve(int n, vector<int>&v){
    //     if(n==0){
    //         v.push_back(n);
    //         return 0;
    //     }
    //      int a =solve(n-1, v)-n;
    //      if(a<=0){
    //          int b = solve(n-1,v)+n;
    //          v.push_back(b);
    //      }
    //       v.push_back(a);
    // }
    vector<int> recamanSequence(int n){
        // code here
        
        vector<int>v;
        // v[0]=0;
        unordered_set<int>st;
        st.insert(0);
        v.push_back(0);
        for(int i=1;i<n;i++){
            int a = v[i-1]-i;
            if(st.find(a)!=st.end() || a<0){
                int b = v[i-1]+i;
                st.insert(b);
                v.push_back(b);
            }else{
            v.push_back(a);
            st.insert(a);
           }
     
        }
         
        return v;
    }