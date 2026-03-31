#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num_customers, rooms_used = 1, checkin, checkout;;
    set<pair<int, int>> ms; //<checkout, room>
    vector<tuple<int,int, int>> organization; //<checkin, checkout, index_og>
    cin >> num_customers;
    vector<int> rooms(num_customers);

    for (int i; i < num_customers; i++)
    {
        cin >> checkin >> checkout;
        organization.push_back(make_tuple(checkin,checkout, i));

    }
    sort(organization.begin(), organization.end());
    
    for (tuple t : organization)
    {
        pair<int, int> new_customer;

        if (ms.empty())
        {
            new_customer = make_pair(get<1>(t), 1);
            ms.insert(new_customer);
            rooms[get<2>(t)] = new_customer.second;
        }
        else
        {

            if (get<0>(t) > ms.begin()->first)
            {
                new_customer = make_pair(get<1>(t), ms.begin()->second);
                ms.erase(ms.begin());
                ms.insert(new_customer);
                rooms[get<2>(t)] = new_customer.second;
            }
            else
            {
                rooms_used++;
                new_customer = make_pair(get<1>(t), rooms_used);
                ms.insert(new_customer);
                rooms[get<2>(t)] = new_customer.second;
            }
        }
    }
    cout << rooms_used << "\n";

    for (int n : rooms)
    {
        cout << n << " ";
    }

    return 0;
}