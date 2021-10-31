#include <iostream>
#define MAX 100001

using namespace std;

int G,P;
int gate[MAX];
int numUnion[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> G >> P;

    for(int i = 0; i < P; i++){
        cin >> gate[i];
    }

    for(int i = 0; i <= G; i++){
        numUnion[i] = i;
    }
}

int find(int idx){
    if(numUnion[idx] == idx) return numUnion[idx];
    return numUnion[idx] = find(numUnion[idx]);
}

bool merge(int A, int B){
    int aRoot = find(A);
    int bRoot = find(B);

    if(aRoot == bRoot) return true;

    if(bRoot > aRoot) numUnion[bRoot] = aRoot;
    else numUnion[aRoot] = bRoot;

    return false;
}

int makeGreedy(){
    int count = 0;

    for(int i = 0; i < P; i++){
        int checkGate = find(gate[i]);

        if(checkGate == 0) return count;

        merge(checkGate, checkGate - 1);
        count++;
    }

    return count;
}

int main(){
    input();
    int result = makeGreedy();

    cout << result;
}