#include <bits/stdc++.h>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;
    cin.ignore();

    for (int i = 0; i <  testCases; i++){
        string countryFullName;
        string acronym;
        bool isInitial = true;
        
        getline(cin, countryFullName);
        
        for (char c : countryFullName){
            if (isInitial){
                acronym.push_back(c);
                isInitial = false;
            }
            else {
                if (c == ' '){
                    isInitial = true;
                }
            }
        }
        cout << acronym << "\n";
    }
    return 0;
}