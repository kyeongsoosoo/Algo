#include <iostream>
#include <functional>
#include <queue>

using namespace std;

struct Jewel{
    int Weight;
    int Value;

    Jewel(int w, int v) : Weight(w), Value(v) {} 

    bool operator<(const Jewel j) const {
        if(this->Weight == j.Weight)
            return this->Value > j.Value;
        return this->Weight > j.Weight;
    }
};

int N, K;
priority_queue<Jewel> Jewels;
priority_queue<int, vector<int>, greater<int>> BackPack;
priority_queue<int, vector<int>, less<int>> Sum;

long long greedy(){
    long long sum = 0;

    while(BackPack.size()){
        int back_weight = BackPack.top();

        while(Jewels.size() && Jewels.top().Weight <= back_weight){
            int jewel_value = Jewels.top().Value;
            Sum.push(jewel_value);
            Jewels.pop();
        }
        if(Sum.size()){
            sum += Sum.top();
            Sum.pop();
        }
        BackPack.pop();

    }

    return sum;
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for(int i = 0; i < N; i++){
        int w, v;
        cin >> w >> v;
        Jewels.push({w, v});
    }

    for(int i = 0; i < K; i++){
        int w;
        cin >> w;
        BackPack.push(w);
    }
}

int main(){
    input();

    long long sum = greedy();

    cout << sum;
}