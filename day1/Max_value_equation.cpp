// You are given an array points containing the coordinates of points on a 2D plane, sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. You are also given an integer k.

// Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.

// It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.

 

// Example 1:

// Input: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
// Output: 4
// Explanation: The first two points satisfy the condition |xi - xj| <= 1 and if we calculate the equation we get 3 + 0 + |1 - 2| = 4. Third and fourth points also satisfy the condition and give a value of 10 + -10 + |5 - 6| = 1.
// No other pairs satisfy the condition, so we return the max of 4 and 1.
// Example 2:

// Input: points = [[0,0],[3,0],[9,2]], k = 3
// Output: 3
// Explanation: Only the first two points have an absolute difference of 3 or less in the x-values, and give the value of 0 + 0 + |0 - 3| = 3.
 

// Constraints:

// 2 <= points.length <= 105
// points[i].length == 2
// -108 <= xi, yi <= 108
// 0 <= k <= 2 * 108
// xi < xj for all 1 <= i < j <= points.length
// xi form a strictly increasing sequence.

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, int>>pq;
        int ans = INT_MIN;
        

        for(int i = 0;i<n; i++){
            int x = points[i][0];
            int y = points[i][1];

            while(!pq.empty() and abs(x-pq.top().second) > k) pq.pop();
            if(!pq.empty()){
                ans = max(ans, x+y+pq.top().first);
            }
            pq.push({y-x, x});


        }

        return ans;

        


    }
};


//Explaination

// class Solution {
// public:
// // if points are (xi,yi) and (xj,yj)
// // since vo sorted hai so eq yi+yj-|xi-xj| => yi+yj+xj-xi becus (x2>x1) sorted di hai na
// // club i and j togather  (yi-xi)+(yj+xj) if we are at j we know xj and yj so we just ned to maximise xi-yi
// // points[i][1] means yi points[i][0] means xi and we need to check ki xi-xj is <= k so
// // priority que ch ena da diff padi ty xi pado
// // x dy hisaaab naal sorted hai na os cheez da gfaeda uthana hai

// // SEEEE.. i means any prev point  j means our curr point jidy ty asi huny hegy a

//     int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        
//         priority_queue<pair<int,int>>p;
//         // pair main ek to diffrece rahega jo hmy max chiye that is (yi-xi) means pichly kisi point ka diff
//         // and uska xi bhi rakh lo taki vo curr point ky x ky sath diffrenec calculate kar sakt kyonki
//         // after all conition bhi chk krni hai ki xj-xi<=k or not
//         int ans=INT_MIN;
//         for(int j=0;j<points.size();j++)
//         {
//                                 // means x of curr (xj) - x of prev any jo queue ky second mein hai (xi)
//             while(!p.empty() && (points[j][0]-p.top().second)>k)
//             p.pop();

//             if(!p.empty()) // means eda dif v <=k hai and ehe hun tk de prev da max (yi-xi hega)
//             {
//                 // pher ans update kardo
//                         // xj +   yj +             (yi-xi) jo ki diff hai and queue ky first mein stored thi
//                 int sum=points[j][0]+points[j][1]+p.top().first;
//                 ans= max(ans,sum);
//             }



//             p.push({points[j][1]-points[j][0],points[j][0]}); // diff and xi to chhk k vali condition
            
//         }

//         return ans;

//     }
};