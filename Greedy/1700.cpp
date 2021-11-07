#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k,ans = 0;
vector<int> order;

int multiTap[101];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < k; i++){
        int in;
        cin >> in;
        order.push_back(in);
    }
}

void makeGreedy(){
    for(int i = 0; i < order.size(); i++){
        int item = order[i];

        bool found = false;
        for(int j = 1; j <= n; j++){
            if(multiTap[j] == item){
                found = true;
                break;
            }
        }

        if(!found){
            bool empty = false;
            for(int j = 1; j <= n; j++){
                if(multiTap[j] == 0){
                    multiTap[j] = item;
                    empty = true;
                    break;
                }
            }

            if(!empty){
                int ind = 0;
                int max_value = 0;
                bool reuse = true;

                for(int j = 1; j <= n; j++){
                    int cnt = 1;
                    bool end = true;

                    for(int l = i; l < order.size(); l++,cnt++){
                        if(multiTap[j] == order[l]){
                            if(cnt > max_value){
                                max_value = cnt;
                                ind = j;
                            }

                            end = false;
                            break;
                        }
                    }

                    if(end){
                        multiTap[j] = item;
                        ans++;
                        reuse = false;
                        break;
                    }
                }

                if(reuse){
                    multiTap[ind] = item;
                    ans++;
                }
            }
        }
    }
}

int main(){
    input();
    makeGreedy();

    cout << ans;
}