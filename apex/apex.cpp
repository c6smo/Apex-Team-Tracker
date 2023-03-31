#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> get_team_compositions(int players, int teams) {
    vector<vector<int>> team_compositions;

    // Generate all possible team compositions using nested loops
    for (int trios = players / 3; trios >= 0; trios--) {
        for (int duos = (players - trios * 3) / 2; duos >= 0; duos--) {
            int solos = players - trios * 3 - duos * 2;
            if (solos >= 0 && trios + duos + solos == teams) {
                team_compositions.push_back({ trios, duos, solos });
            }
        }
    }

    return team_compositions;
}

int main() {
    int players, teams;
    while (true) {
        cout << "Enter the number of players remaining (or enter -1 to quit): ";
        cin >> players;
        if (players == -1) {
            break;
        }
        cout << "Enter the number of teams remaining: ";
        cin >> teams;
        vector<vector<int>> team_compositions = get_team_compositions(players, teams);
        cout << "Possible team compositions:\n";
        for (int i = 0; i < team_compositions.size(); i++) {
            cout << "Option " << i + 1 << ": " << team_compositions[i][0] << " trios, " << team_compositions[i][1] << " duos, " << team_compositions[i][2] << " solos\n";
        }
    }
    return 0;
}
