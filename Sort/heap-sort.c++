#include <iostream>
#include <math.h>
#include <vector>
#define INF 987654321

using namespace std;

class MinHeap{
    private: 
        vector<int> Q;
        int root_idx = 1;



    public: 
        MinHeap(){
            this->Q.push_back(0);
        }
        
        int size(){
            return this->Q.size() - 1;
        }

        void push(int val){
            this->Q.push_back(val);

            int leaf_idx = size();
            int par_idx = floor(leaf_idx / 2);

            while(leaf_idx > root_idx){
                if(this->Q[leaf_idx] < this->Q[par_idx]){
                    int tmp = this->Q[leaf_idx];
                    this->Q[leaf_idx] = this->Q[par_idx];
                    this->Q[par_idx] = tmp;

                    leaf_idx = par_idx;
                    par_idx = floor(par_idx / 2);
                }
                else{
                    break;
                }
            }
        }

        int pop(){
            int pop_val = this->Q[root_idx];

            int leaf = this->Q.back();
            this->Q.pop_back();
            
            this->Q[root_idx] = leaf;

            int leaf_idx = size();
            int start_idx = root_idx;
            int to_idx = 2 * root_idx;

            while(to_idx <= leaf_idx){
                int left = this->Q[to_idx];
                int right = to_idx + 1 <= leaf_idx ? this->Q[to_idx + 1] : left + 1;

                int min_to_val = min(left, right);
                int min_to_idx = min_to_val == left ? to_idx : to_idx + 1;

                if(this->Q[start_idx] > min_to_val){
                    this->Q[min_to_idx] = this->Q[start_idx];
                    this->Q[start_idx] = min_to_val;

                    start_idx = min_to_idx;
                    to_idx = min_to_idx * 2;
                }
                else{
                    break;
                }
            }

            return pop_val;
        }
};

int main(){
    MinHeap H = MinHeap();

    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        H.push(tmp);
    }

    while(H.size()){
        cout << H.pop() << '\n';
    }

    return 0;
}