/*
You are given a positive integer k. You are also given:

a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each
 of the numbers from 1 to k exactly once. 
 The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

The number abovei should appear in a row that is
 strictly above the row at which the number belowi 
 appears for all i from 0 to n - 1.

The number lefti should appear in a column that is 
strictly left of the column at which the number 
righti appears for all i from 0 to m - 1.

Return any matrix that satisfies the conditions.
 If no answer exists, return an empty matrix.
 Example 1:


Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.
Example 2:

Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
Output: []
Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.
 

Constraints:

2 <= k <= 400
1 <= rowConditions.length, colConditions.length <= 104
rowConditions[i].length == colConditions[i].length == 2
1 <= abovei, belowi, lefti, righti <= k
abovei != belowi
lefti != righti

arayn mithal
*/

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        // Store the topologically sorted sequences.
        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        // If no topological sort exists, return empty array.
        if (orderRows.empty() or orderColumns.empty()) return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }

private:
    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n + 1);
        vector<int> order;
        // 0: not visited, 1: visiting, 2: visited
        vector<int> visited(n + 1, 0);
        bool hasCycle = false;

        // Build adjacency list
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
        }

        // Perform DFS for each node
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i, adj, visited, order, hasCycle);
                // Return empty if cycle detected
                if (hasCycle) return {};
            }
        }
        // Reverse to get the correct order
        reverse(order.begin(), order.end());
        return order;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited,
             vector<int>& order, bool& hasCycle) {
        visited[node] = 1;  // Mark node as visiting
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, adj, visited, order, hasCycle);
                // Early exit if a cycle is detected
                if (hasCycle) return;
            } else if (visited[neighbor] == 1) {
                // Cycle detected
                hasCycle = true;
                return;
            }
        }
        // Mark node as visited
        visited[node] = 2;
        // Add node to the order
        order.push_back(node);
    }
};
