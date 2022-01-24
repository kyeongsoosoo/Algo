#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int n;
vector<int> post;
vector<int> in;
int Idx[MAX];
int Post_Idx[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    post.push_back(0);
    in.push_back(0);

    int tmp;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        in.push_back(tmp);
        Idx[tmp] = i;
    }

    for(int i = 1; i <= n; i++){
        cin >> tmp;
        post.push_back(tmp);
    }
}

void printPre(int inStart, int inEnd, int postStart, int postEnd){
    if(inStart > inEnd || postStart > postEnd) return;

    int rootIndex = Idx[post[postEnd]];
    int leftSize = rootIndex - inStart;
    int rightSize = inEnd - rootIndex;
    cout << in[rootIndex] << ' ';

    printPre(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    printPre(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main(){
    input();
    printPre(1, n, 1, n);
}