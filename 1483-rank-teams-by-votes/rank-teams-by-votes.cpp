class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes[0].size();  // number of teams
        vector<vector<int>> rank(26, vector<int>(m, 0));  // voting rank count
        vector<bool> teams(26, false);  // track if a team exists

        // Populate ranking data based on votes
        for (const auto& vote : votes) {
            for (int i = 0; i < m; ++i) {
                teams[vote[i] - 'A'] = true;
                rank[vote[i] - 'A'][i]++;
            }
        }

        // Initialize a vector to hold team indices
        vector<int> ans(26);
        for (int i = 0; i < 26; ++i) ans[i] = i;

        // Sort based on the custom comparison function
        sort(ans.begin(), ans.end(), [&](int x, int y) {
            for (int i = 0; i < m; ++i) {
                if (rank[x][i] != rank[y][i]) return rank[x][i] > rank[y][i];
            }
            return x < y;  // If tied, sort alphabetically
        });

        // Form the result string from sorted teams
        string result;
        for (int i = 0; i < 26; ++i) {
            if (teams[ans[i]]) result += (char)('A' + ans[i]);
        }

        return result;
    }
};