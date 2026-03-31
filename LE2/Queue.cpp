#include <bits/stdc++.h>
using namespace std;

int main()
{
int num_proc, q, time, offset = 0;
string process;
cin >> num_proc >> q;
pair<string,int> proc;
queue<pair<string,int>> processes;

for (int i = 0; i < num_proc; i++){
    cin >> process >> time;
    processes.push(make_pair(process, time));
}

while(!processes.empty()){
    proc = processes.front();

    if (proc.second <= q){
        processes.pop();
        cout << proc.first << " " << proc.second + offset << "\n";
        offset += proc.second;
    }
    else{
        proc.second -= q;
        processes.pop();
        processes.push(proc);
        offset += q;
    }
}
    return 0;
}