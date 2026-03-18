#include <bits/stdc++.h>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;
    
    for(int i = 0; i < testCases; i++ ){
        string windowWord;
        string correctWord;
        
        cin >> windowWord;

        for (int j = windowWord.size() - 1; j >= 0; j--){
            char c = windowWord[j];
            if (c == 'p'){
                correctWord.push_back('q');
            }
            else if (c == 'q'){
                correctWord.push_back('p');
            }
            else{
                correctWord.push_back('w');
            }
        }

        cout << correctWord << "\n";

    }
    return 0;
}