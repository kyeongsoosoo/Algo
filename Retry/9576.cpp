#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1001

using namespace std;

struct student{
    int start;
    int end;
};

struct cmp{
    bool operator()(student A, student B){
        if(A.end > B.end) return true;
        else if(A.end == B.end){
            if(A.start > B.start){
                return true;
            }
        }
        return false;
    }
};

int TC;
int N, M;
priority_queue<student, vector<student>, cmp> PQ;
int ans_count;
bool book[MAX];


void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
}

void caseInput(){
    while(!PQ.empty()) PQ.pop();
    ans_count = 0;
    memset(book, false, sizeof(book));

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;
        PQ.push({start, end});
    }
}

void greedy(){
    while(!PQ.empty()){
        student range = PQ.top(); PQ.pop();
        int end = range.end;
        int start= range.start;

        // cout << "start: " << start << "end: " << end << '\n';

        while(start <= end){
            if(book[start] == false){
                book[start] = true;
                ans_count += 1;
                break;
            }
            start += 1;
        }
    }
}

int main(){
    input();
    while(TC--){
        caseInput();
        greedy();
        cout << (ans_count > N ? N : ans_count) << '\n';
    }
}