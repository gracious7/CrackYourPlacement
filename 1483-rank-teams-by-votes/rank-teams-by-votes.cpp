
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes[0].size();  // Number of teams
        map<char, vector<int>> rank_map;  // Map to store rankings for each team

        // Initialize rank map for all teams in the first vote
        for (char team : votes[0]) {
            rank_map[team] = vector<int>(m, 0);
        }

        // Update rankings based on votes
        for (const auto& vote : votes) {
            for (int i = 0; i < m; ++i) {
                rank_map[vote[i]][i]++;
            }
        }

        // Create a vector of all teams for sorting
        vector<char> teams(votes[0].begin(), votes[0].end());

        // Sort teams based on the ranking counts and lexicographically if tied
        sort(teams.begin(), teams.end(), [&](char a, char b) {
            for (int i = 0; i < m; ++i) {
                if (rank_map[a][i] != rank_map[b][i]) {
                    return rank_map[a][i] > rank_map[b][i];
                }
            }
            return a < b;  // If tied, sort alphabetically
        });

        // Form the result string from sorted teams
        string result(teams.begin(), teams.end());
        return result;
    }
};
