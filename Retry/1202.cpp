#include <iostream>
#include <queue>
#include <algorithm>

#define endl "\n"
#define MAX 300010
typedef long long ll;
using namespace std;

struct JEWEL{
    int weight;
    int price;

    bool operator<(const JEWEL Cmp) const {
        if(this->weight <= Cmp.weight){
            if(this->weight == Cmp.weight){
                if(this->price > Cmp.price){
                    return true;
                }
                return false;
            }
            return true;
        }
        return false;
    }
};

int N, K;
int Bag[MAX];
ll Answer;
JEWEL Arr[MAX];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        Arr[i].weight = a;
        Arr[i].price = b;
    }

    for(int i = 0; i < K; i++){
        cin >> Bag[i];
    }
}

void makeGreedy(){
    sort(Bag, Bag + K);
    sort(Arr, Arr + N);
    priority_queue<int> PQ;

    int idx = 0;
    for(int i = 0; i < K; i++){
        int bag_size = Bag[i];

        while( idx < N){
            int diamond_size = Arr[idx].weight;
            int diamond_price = Arr[idx].price;

            if(diamond_size <= bag_size){
                PQ.push(diamond_price);
                idx++;
            }
            else break;
        }

        if(PQ.empty() == false){
            Answer = Answer + PQ.top(); PQ.pop();
        }
    }

    cout << Answer;
}

int main(){
    input();
    makeGreedy();
}