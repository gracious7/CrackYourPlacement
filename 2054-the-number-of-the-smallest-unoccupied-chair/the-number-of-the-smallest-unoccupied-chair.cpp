class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        for (int i = 0; i < n; ++i) {
            times[i].push_back(i);
        }

        sort(times.begin(), times.end());

        priority_queue<int, vector<int>, greater<int>> availableChairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leaving;

        int nextAvailableChair = 0;

        for (auto& time : times) {
            int arrival = time[0];
            int leavingTime = time[1];
            int friendIndex = time[2];

            while (!leaving.empty() && leaving.top().first <= arrival) {
                availableChairs.push(leaving.top().second);
                leaving.pop();
            }

            int assignedChair;
            if (!availableChairs.empty()) {
                assignedChair = availableChairs.top();
                availableChairs.pop();
            } else {
                assignedChair = nextAvailableChair++;
            }

            if (friendIndex == targetFriend) {
                return assignedChair;
            }

            leaving.push({leavingTime, assignedChair});
        }

        return -1;
    }
};
