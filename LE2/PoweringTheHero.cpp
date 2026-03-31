#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test_cases;

    cin >> test_cases;
    for (int t=0; t < test_cases; t++)
    {
        multiset<int> bonus_deck;
        int card, n, bonus_card;
        long long power = 0;
        queue<int> deck;

        cin >> n;

        for (int b=0; b < n; b++)
        {
            cin >> card;
            deck.push(card);
        }

        while (!deck.empty())
        {
            if (deck.front() == 0)
            {
                if (!bonus_deck.empty())
                {
                    bonus_card = *bonus_deck.rbegin();
                    bonus_deck.erase(prev(bonus_deck.end()));
                    power += bonus_card;
                }
                deck.pop();
            }
            else
            {
                bonus_deck.insert(deck.front());
                deck.pop();
            }
        }
        cout << power << "\n";
    }
    return 0;
}