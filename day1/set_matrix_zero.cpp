// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

 

// Example 1:


// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:


// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
 

// Follow up:

// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?


class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int mm = m.size();
        int n = m[0].size();
        set<int>r;
        set<int>c;
        for(int i = 0; i < mm; i++){
            for(int j = 0;  j < n; j++){
                if(m[i][j] == 0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(auto x:r){
            for(int i = 0; i <  n; i++){
                m[x][i] = 0;
            }
        }
        for(auto x:c){
            for(int i = 0; i <  mm; i++){
                m[i][x] = 0;
            }
        }
        
    }
};