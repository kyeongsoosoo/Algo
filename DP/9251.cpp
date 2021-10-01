#include <iostream>
#include <algorithm>

using namespace std;

string word1;
string word2;
int DP[1001][1001] = {{0,}};
int length1;
int length2;

void input(){
    cin >> word1;
    cin >> word2;
    length1 = word1.length();
    length2 = word2.length();
}

void setDP(){
    for(int i=1; i <= length1; i++){
        for(int j = 1; j <= length2; j++){
            if(word1[i-1] == word2[j-1]){
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
}

int main() {
    input();
    setDP();

    cout << DP[length1][length2];

    return 0;
}