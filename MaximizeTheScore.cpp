#include <bits/stdc++.h>
using namespace std;

int whiteboardNumbers;

vector<int> process_input(){
    cin >> whiteboardNumbers;

    vector<int> whiteboard(2 * whiteboardNumbers);
    for (int i=0; i < whiteboard.size(); i++){
        cin >> whiteboard[i];
    }
    sort(whiteboard.begin(), whiteboard.end());
    return whiteboard;
}

 int get_min_from_last_pair(vector<int>& whiteboard){
     int first_last_number, second_last_number;
     
     first_last_number = whiteboard.back();
     whiteboard.pop_back();
     
     second_last_number = whiteboard.back();
     whiteboard.pop_back();
     
     return min(first_last_number, second_last_number);
}

int main(){
    int testsNumber;
    int pair_min;
    vector<int> whiteboard;
    int score = 0;
    cin >> testsNumber;
    
    for (int i = 0; i < testsNumber; i++){
        
        whiteboard = process_input();
        for (int j = 0; j < whiteboardNumbers; j++){
            pair_min = get_min_from_last_pair(whiteboard);
            score += pair_min;
        }
        cout << score << "\n";
        score = 0;
    }

    return 0;
}
