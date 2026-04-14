#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    while (n != 0 || m != 0){
        vector<tuple<int,int,int>> cons;
        for (int i = 0; i < m ; i++){
            int a, b, c;
            cin >> a >> b >> c;
            cons.emplace_back(a, b, c);
        }

        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        int valid = 0;
        
        do {
            vector<int> pos(n);
            for (int j=0; j < n; j++){
                pos[perm[j]] = j;
            }
            bool ok = true;

            for (auto [a,b,c] : cons){
                int dist = abs(pos[a] - pos[b]);

                if(c > 0){
                    if (dist > c){
                        ok = false;
                        break;
                    }  
                }
                else{
                    if (dist < abs(c)){
                        ok = false;
                        break;
                    }
                }

            }

            if (ok) valid++; 
        }while (next_permutation(perm.begin(),perm.end()));

        cout << valid << "\n";

        cin >> n >> m;
    }
    return 0;
}