#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    list<char> lista;
    int num_op;
    bool is_inverted = false;

    cin >> input >> num_op;
    for (char c : input)
    {
        lista.push_back(c);
    }

    for (int i = 0; i < num_op; i++)
    {
        int t, f;
        char c;
        cin >> t;
        if (t == 1)
        {
            is_inverted = !is_inverted;
        }
        else
        {
            cin >> f >> c;
            if ((f == 1 && !is_inverted) || (f == 2 && is_inverted))
            {
                lista.push_front(c);
            }
            else if ((f == 2 && !is_inverted) || (f == 1 && is_inverted))
            {
                lista.push_back(c);
            }
        }
    }
    if (!is_inverted)
    {
        for (char x : lista)
        {
            cout << x;
        }
    }
    else
    {
        for (auto it = lista.rbegin(); it != lista.rend(); ++it)
        {
            cout << *it;
        }
    }
    return 0;
}