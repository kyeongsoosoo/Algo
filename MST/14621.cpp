#include <iostream>
#include <vector>
#include <algorithm>
#define S_MAX 1001
#define R_MAX 10001

using namespace std;

bool MALE = false;
bool FEMALE = true;


int N,M;
bool univ[S_MAX];
vector<pair<int, pair<int, int> > > Coord;
int arr[S_MAX];
int ans = 0;
int edge_n = 0;


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        char tmp;
        cin >> tmp;
        if(tmp == 'M') univ[i] = MALE;
        else univ[i] = FEMALE;
    }

    for(int i = 1; i <= M; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        Coord.push_back(make_pair(cost, make_pair(from, to)));
    }

     for(int i = 1; i <= S_MAX; i++){
        arr[i] = i;
    }

    sort(Coord.begin(), Coord.end());
}

int find(int idx)
{
    if (arr[idx] == idx)
        return idx;

    return arr[idx] = find(arr[idx]);
}

void merge(int a, int b)
{
    int a_idx = find(a);
    int b_idx = find(b);

    if (a_idx == b_idx)
        return;

    arr[a_idx] = b_idx;
}

void makeMST(){
    for(int i = 0; i < Coord.size(); i++){
        int from, to, cost;
        cost = Coord[i].first;
        from = Coord[i].second.first;
        to = Coord[i].second.second;

        int root_from = find(from);
        int root_to = find(to);

        if(root_from == root_to) continue;
        if(univ[from] == univ[to]) continue;
        if(edge_n == N - 1) return;

        ans += cost;
        edge_n += 1;
        merge(from, to);
    }
}

int main(){
    input();
    makeMST();

    if(edge_n != N - 1) cout << -1;
    else cout << ans;
}