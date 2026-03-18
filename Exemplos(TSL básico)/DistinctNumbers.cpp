#include <bits/stdc++.h>
using namespace std;

void transform_into_list(vector<int>& numberList){
    for (int i=0; i < numberList.size(); i++){
        cin >> numberList[i];
    }
}

int main(){
    int arraySize;
    int distinctNumbers = 0;
    int currNumber = 0;
    cin >> arraySize;
    vector<int> numberList(arraySize);
    transform_into_list(numberList);
    sort(numberList.begin(), numberList.end());
    for (int j=0; j < numberList.size(); j++){
        if (numberList[j] != currNumber){
            currNumber = numberList[j];
            distinctNumbers++;
        }
    }

    cout << distinctNumbers << "\n";
    return 0;
}
