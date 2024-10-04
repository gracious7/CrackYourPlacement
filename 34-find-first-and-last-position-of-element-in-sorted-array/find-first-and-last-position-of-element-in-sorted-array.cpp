class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        int x = -1, y = -1;
        int n = a.size();
        int s = 0, e = n-1;

        //lower bound
        while(s <= e){
            int m= s + (e-s)/2;
            if(t == a[m]){
                x = m;
                e = m-1;
            }
            else if(t > a[m]){
                s = m+1;
            }
            else e = m-1;

        }


        s =0, e = n-1;
        //upper bound
        while(s <= e){
            int m= s + (e-s)/2;
            if(t == a[m]){
                y = m;
                s = m+1;
            }
            else if(t > a[m]){
                s =m+1;
            }
            else e = m-1;

        }

        return {x, y};
    }
};