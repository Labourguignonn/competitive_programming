#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test_cases;
    cin >> test_cases;

    queue<int> left_bank;
    queue<int> right_bank;

    for (int i = 0; i < test_cases; i++)
    {
        int ferry_size, number_cars, car_size, cross_times = 0;
        string side;

        cin >> ferry_size >> number_cars;

        ferry_size *= 100;

        for (int j = 0; j < number_cars; j++)
        {
            cin >> car_size >> side;

            if (side == "left")
            {
                left_bank.push(car_size);
            }

            else
            {
                right_bank.push(car_size);
            }
        }

        bool is_left = true;

        while (!right_bank.empty() || !left_bank.empty())
        {
            int sum_size = 0;

            if (is_left)
            {

                while (!left_bank.empty() && sum_size + left_bank.front() <= ferry_size)
                {
                    sum_size += left_bank.front();
                    left_bank.pop();
                }
            }
            else
            {

                while (!right_bank.empty() && sum_size + right_bank.front() <= ferry_size)
                {
                    sum_size += right_bank.front();
                    right_bank.pop();
                }
            }

            cross_times++;
            is_left = !is_left;
        }

        cout << cross_times << "\n";
    }
    return 0;
}