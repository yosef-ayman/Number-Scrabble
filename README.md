# 🎯 Number Scrabble Game

## 📝 Problem Statement:
Number Scrabble is played with the numbers from 1 to 9. Each player takes turns picking a number from the list. Once a number has been picked, it cannot be picked again.

- If **any player has 3 numbers that sum to 15**, that player **wins the game**.
- If **all numbers are picked** and no one forms a sum of 15, the game is a **draw**.

### 🔢 Example Game:
(1) 4
(2) 7
(1) 3
(2) 8
(1) 5
(2) 6
(1) 1
(2) 2 → Player 2 wins (7 + 6 + 2 = 15)


## 🧠 Idea:
The code allows two players to enter their numbers alternately. It keeps track of which numbers have been picked and ensures no duplicate or invalid numbers are entered.  
At the end, it checks each player's list for **any combination of three numbers** that sum to 15 using brute-force.

## 💻 Solution:

```cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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
```
## ✅ Status:
- [x] Fully solved and tested  
- [x] Validated input and rules  
- [x] Published on GitHub 🚀
