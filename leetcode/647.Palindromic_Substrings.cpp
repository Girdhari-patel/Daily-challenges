/*
647. Palindromic Substrings
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

*/

class Solution {
public:
     int t[1001][1001];
    bool check(string &s, int i, int j) {
        if(i >= j) {
            return true;
        }

        if(t[i][j] != -1) {
            return t[i][j]; //1 : True, 0 : False
        }

        if(s[i] == s[j]) {
            return t[i][j] = check(s, i+1, j-1);
        }

        return t[i][j] = false;

    }

    int countSubstrings(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) { //check all possible substrings
                if(check(s, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};