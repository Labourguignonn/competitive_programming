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

tuple<int> get_last_numbers(){

}

int main(){
    int testNumbers;
    cin >> testNumbers;
    vector<int> whiteboard;
    for (int i = 0; i <= testNumbers; i++){
        int score = 0;
        whiteboard = process_input();
        for (int j = 0; j <= whiteboardNumbers; j++){

        }

    }

    return 0;
}
