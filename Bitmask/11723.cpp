#include <iostream>
#include <string>

using namespace std;

int BIT = 0;
string order;
int val;
int M;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M;
}

void printAns(){
    for(int i = 0; i < M; i++){
        cin >> order;
        if( order == "add"){
            cin >> val;
            BIT = BIT | (1 << val);
        }
        else if(order == "remove"){
            cin >> val;
            BIT = BIT & ~(1 << val);
        }
        else if(order == "check"){
            cin >> val;
            if(BIT & (1 << val))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(order == "toggle"){
            cin >> val;
            BIT = BIT ^ (1 << val);
        }
        else if(order == "all"){
            BIT = (1 << 21) - 1;
        }
        else if(order == "empty"){
            BIT = 0;
        }
    }
}

int main(){
    input();
    printAns();
}