#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000007

using namespace std;

int TestCase;
int PageSum;
int Costs[501];
int Sum[501];
int DP[501][501];


int main(){
    cin >> TestCase;

    while( TestCase-- ){
        cin >> PageSum;
        for(int i = 1; i<= PageSum; i++){
            cin >> Costs[i];
            Sum[i] = Sum[i-1] + Costs[i];
        }

        for(int pageLen = 1; pageLen <= PageSum; pageLen++){
            for(int start = 1; start <= PageSum - pageLen; start++){
                DP[start][start + pageLen] = INF;
                for(int mid = start; mid < start + pageLen; mid++){
                    int originalVal = DP[start][start + pageLen];
                    int comparingVal = DP[start][mid] + DP[mid + 1][start + pageLen] + Sum[start + pageLen ] - Sum[start - 1];
                    DP[start][start + pageLen] = min(originalVal, comparingVal);
                }
            }
        }

        cout << DP[1][PageSum] << endl;
    }
}