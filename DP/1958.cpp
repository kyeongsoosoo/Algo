#include <iostream>
#define MAX 101

using namespace std;

int DP[MAX][MAX][MAX];
string a,b,c;
int SizeA, SizeB, SizeC;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
}

void makeDP(){
    SizeA = a.size();
    SizeB = b.size();
    SizeC = c.size();

    for(int i = 1; i <= SizeA; i++){
        for(int j = 1; j <= SizeB; j++){
            for(int k = 1; k <= SizeC; k++){
                if((a[i - 1] == b[j - 1]) && (b[j - 1] == c[k - 1])){
                    DP[i][j][k] = DP[i - 1][j - 1][k - 1] + 1;
                }
                else{
                    DP[i][j][k] = max(DP[i - 1][j][k], max(DP[i][j - 1][k], DP[i][j][k - 1]));
                }
            }
        }
    }
}


int main(){
    input();
    makeDP();
    cout << DP[SizeA][SizeB][SizeC];
}