#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*
   ######################################
   #                                    #
   #       #####   #####   #######      #
   #         #     #   #   #            #
   #         #     #   #   #####        #
   #      #  #     #   #   #            #
   #       ##      #####   #######      #
   #                                    #
   ######################################
 */

bool picked(const vector<int> &v, int x) {
    return find(v.begin(), v.end(), x) != v.end();
}

bool sum_15(const vector<int> &numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            for (int k = j + 1; k < numbers.size(); k++) {
                if (numbers[i] + numbers[j] + numbers[k] == 15) return true;
            }
        }
    }
    return false;
}

int main() {
    fast

    vector<int> v;
    vector<int> player_one, player_two;

    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) cout << "Enter Number, Player " << 1 << " : " << endl;
        else cout << "Enter Number, Player " << 2 << " : " << endl;

        int x; cin >> x;

        if (x < 1 || x > 9 || picked(v, x)) {
            cout << "Please Enter Valid Number (1 to 9) and Not Picked." << endl;
            i--;
            continue;
        }

        v.push_back(x);

        if (i % 2 == 0) player_one.push_back(x);
        else player_two.push_back(x);
    }

    if (sum_15(player_one) && sum_15(player_two)) cout << "Draw" << endl;
    else if (sum_15(player_one)) cout << "Player 1 Wins" << endl;
    else if (sum_15(player_two)) cout << "Player 2 Wins" << endl;
    else cout << "Draw" << endl;

    return 0;
}
