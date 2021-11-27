#include <iostream>
#include <vector>
#include <algorithm>
#define EDGE_MAX 50001
#define NODE_MAX 2001
#define INF 987654321

using namespace std;

int TC;
int N, M, T;
int S, G, H;
int Must;
int len[NODE_MAX][NODE_MAX];
vector<int> Candidate;
vector<int> ans;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
}

void caseInput(){
    for(int i = 0; i < NODE_MAX; i++){
        for(int j =0; j < NODE_MAX; j++){
            if(i == j)
                len[i][j] = 0;
            else
                len[i][j] = INF;
        }
    }
    Candidate.clear();
    ans.clear();

    cin >> N >> M >> T;
    cin >> S >> G >> H;

    int A, B, D;
    for(int i = 0; i < M; i++){
        cin >> A >> B >> D;
        len[A][B] = D;
        len[B][A] = D;

        if((G == A && H == B) || (G == B && H == A)) Must = D;
    }
    int X;
    for(int i = 0; i < T; i++){
        cin  >> X;
        Candidate.push_back(X);
    }
}

void floyd(){
    for(int mid = 1; mid <= N; mid++){
        for(int start = 1; start <= N; start++){
            if(start == mid) continue;
            for(int end = 1; end <= N; end++){
                int SM = len[start][mid];
                int ME = len[mid][end];

                if(start == end|| end == mid) continue;

                if(len[start][end] > SM + ME)
                    len[start][end] = SM + ME;
            }
        }
    }
}

void findAns(){
    for(int i = 0; i < Candidate.size(); i++){
        int candi = Candidate[i];
        // cout << "start " << len[S][G] << " " << len[H][candi] << " " << Must << " " << len[S][candi]<< '\n';

        if((len[S][G] + len[H][candi] + Must == len[S][candi]) || (len[S][H] + len[G][candi] + Must == len[S][candi]) )
            ans.push_back(candi);
    }

    sort(ans.begin(), ans.end());
}

void printAns(){
    // cout << "start" << '\n';
    for(int i = 0; i <= ans.size() - 1; i++){
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main(){
    input();
    while(TC--){
        caseInput();
        floyd();
        findAns();
        printAns();
    }
}