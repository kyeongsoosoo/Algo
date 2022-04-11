#include <iostream>

using namespace std;

typedef long long ll;

int K;
int X, Y, C;

int A[128][128];

void solve(int sx, int sy, int fx, int fy, int len){
    if(len == 2){
        ++C;

        for(int i = sy; i < sy + 2; i++){
            for(int j = sx; j < sx + 2; j++){
                if(i != fy || j != fx) A[i][j] = C;
            }
        }
        return;
    }

    /*
    0|1
    - -
    2|3*/

    int region = 0;

    if(fy >= sy + len / 2) region += 2;
    if(fx >= sx + len / 2) region += 1;

    int cy[4] = {sy + (len / 2) - 1, sy + (len / 2) - 1, sy + len / 2, sy + len / 2};
    int cx[4] = {sx + (len / 2) - 1, sx + (len / 2), sx + (len / 2) - 1, sx + (len / 2)};

    int nsx[4] = {sx, sx + len / 2, sx , sx + len / 2};
    int nsy[4] = {sy, sy, sy + len / 2, sy + len / 2};

    solve(nsx[region], nsy[region], fx, fy, len/2);
    ++C;
    for (int d=0; d<4; d++){
        if (d == region) continue;
        A[cy[d]][cx[d]] = C;
    }   
    for (int d=0; d<4; d++){
        if (d == region) continue;
        solve(nsx[d], nsy[d], cx[d], cy[d], len/2);
    }
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> X >> Y;
    X -= 1;
    Y = (1 << K) - Y;
    A[Y][X] = -1;

}

int main(){
    input();
    solve(0, 0, X, Y, 1<<K);
    for (int i=0; i<(1<<K); i++){
        for (int j=0; j<(1<<K); j++){
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}