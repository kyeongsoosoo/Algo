#include <iostream>
#include <cstring>

#define endl "\n"
#define MAX 1010

using namespace std;

struct COORD{
    int x;
    int y;
};

int N, W;
int DP[MAX][MAX];
COORD Event[MAX];

int find_dist(int x, int y, int xx, int yy){
    return abs(xx - x) + abs(yy - y);
}

int total_distance(int police1, int police2){
    if(police1 == W || police2 == W) return 0;
    if(DP[police1][police2] != -1) return DP[police1][police2];

    int next_event = max(police1, police2) + 1;
    int dist1, dist2;

    if(police1 == 0) dist1 = find_dist(1, 1, Event[next_event].x, Event[next_event].y);
    else dist1 = find_dist(Event[police1].x, Event[police1].y, Event[next_event].x, Event[next_event].y);

    if(police2 == 0) dist2 = find_dist(N, N, Event[next_event].x, Event[next_event].y);
    else dist2 = find_dist(Event[police2].x, Event[police2].y, Event[next_event].x, Event[next_event].y);

    int result1 = dist1 + total_distance(next_event, police2);
    int result2 = dist2 + total_distance(police1, next_event);
    DP[police1][police2] = min(result1, result2);
    return DP[police1][police2];
}

void Route(int P1, int P2)
{
    if (P1 == W || P2 == W) return;
    
    int Next_Event = max(P1, P2) + 1;
    int Dist1, Dist2;
 
    if (P1 == 0) Dist1 = find_dist(1, 1, Event[Next_Event].x, Event[Next_Event].y);
    else Dist1 = find_dist(Event[P1].x, Event[P1].y, Event[Next_Event].x, Event[Next_Event].y);
 
    if (P2 == 0) Dist2 = find_dist(N, N, Event[Next_Event].x, Event[Next_Event].y);
    else Dist2 = find_dist(Event[P2].x, Event[P2].y, Event[Next_Event].x, Event[Next_Event].y);
 
    if (DP[Next_Event][P2] + Dist1 < DP[P1][Next_Event] + Dist2)
    {
        cout << 1 << endl;
        Route(Next_Event, P2);
    }
    else
    {
        cout << 2 << endl;
        Route(P1, Next_Event);
    }
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> W;

    for(int i = 1; i <= W; i++){
        cin >> Event[i].x >> Event[i].y;
    }

    memset(DP, -1, sizeof(DP));
}

void solve(){
    cout << total_distance(0, 0) << '\n';
    Route(0, 0);
}

int main(){
    input();
    solve();
}