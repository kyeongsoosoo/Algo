#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1001

using namespace std;

int T;
int N, M;
int case_count = 0;
bool book[MAX];
priority_queue<pair<int, int>> pq;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

void caseInput(){
    memset(book, false, sizeof(book));
    case_count = 0;

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        pq.push(make_pair(-b, -a));
    }
}

void findAns(){
    int from, to;
    while(!pq.empty()){
        from = -pq.top().second;
        to = -pq.top().first;
        pq.pop();

        for(int i = from; i <= to; i++){
            if(book[i] == false){
                book[i] = true;
                case_count++;
                break;
            }
        }
    }
}

int main(){
    input();
    while(T--){
        caseInput();
        findAns();
        cout << case_count << '\n';
    }
}