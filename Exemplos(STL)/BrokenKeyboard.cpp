#include <bits/stdc++.h>
using namespace std;

int main(){

    string rawText;
    
    while(cin >> rawText)
    {
        list<char> finalText;
        auto it = finalText.begin();
        
        for (char c : rawText)
        {
            if (c == '[')
            {
                it = finalText.begin();
               
            }

            else if (c == ']')
            {
                it = finalText.end();               
            }

            else
            {
                it = finalText.insert(it, c);
                it++;
            }
        }

        for (char x : finalText){
            cout << x;
        }
        cout << "\n";
    }


    return 0;
}