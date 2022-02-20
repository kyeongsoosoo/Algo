#include <iostream>
#define MAX 101
#define MAX_BIT 1024
#define LIMIT 1000000000

using namespace std;

int N;
long long DP[MAX][10][MAX_BIT];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < 10; i++){
        int cur_bit = 1 << i;
        DP[0][i][cur_bit] = 1;
    }
}

void makeDP(){
    for(int pos = 1; pos < N; pos++){
        for(int num = 0; num < 10; num++){
            for(int bit = 0; bit < MAX_BIT; bit++){
                if(num == 0){
                    if(!(bit & (1 << 1))) continue;
                    if(!DP[pos - 1][1][bit]) continue;
                    int next_bit = bit | (1 << 0);
                    DP[pos][num][next_bit] += DP[pos - 1][1][bit];
                    DP[pos][num][next_bit] %= LIMIT;
                    // cout << "pos : " << pos << " num: " << num << " nextbit: " << next_bit << " ans: " << DP[pos][num][next_bit] << '\n';
                }
                else if(num == 9){
                    if(!(bit & (1 << 8))) continue;
                    if(!DP[pos - 1][8][bit]) continue;
                    int next_bit = bit | (1 << 9);
                    DP[pos][num][next_bit] += DP[pos - 1][8][bit];
                    DP[pos][num][next_bit] %= LIMIT;
                    // cout << "pos : " << pos << " num: " << num << " nextbit: " << next_bit << " ans: " << DP[pos][num][next_bit] << '\n';
                }
                else{
                    if(bit & (1 << (num - 1)) && DP[pos - 1][num - 1][bit]){
                        int next_bit = bit | (1 << num);
                        DP[pos][num][next_bit] += DP[pos - 1][num - 1][bit];
                        DP[pos][num][next_bit] %= LIMIT;
                        // cout << "pos : " << pos << " num: " << num << " nextbit: " << next_bit << " ans: " << DP[pos][num][next_bit] << '\n';
                    }
                    if(bit & (1 << (num + 1)) && DP[pos - 1][num + 1][bit]){
                        int next_bit = bit | (1 << num);
                        DP[pos][num][next_bit] += DP[pos - 1][num + 1][bit];
                        DP[pos][num][next_bit] %= LIMIT;
                        // cout << "pos : " << pos << " num: " << num << " nextbit: " << next_bit << " ans: " << DP[pos][num][next_bit] << '\n';
                    }
                }
            }
        }
    }
}

void printAns(){
    long long sum = 0;
    for(int i = 1; i < 10; i++){
        // cout << "DP " << DP[N - 1][i][MAX_BIT - 1] << '\n';
        sum += DP[N - 1][i][MAX_BIT - 1];
        sum %= LIMIT;
    }

    cout << sum;
}

int main(){
    input();
    makeDP();
    printAns();
}