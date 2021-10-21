#include <iostream>
#include <vector>

using namespace std;

vector<int> Q;

int N;

int partition(int start, int end){
    int axis = Q[end];
    int i = start - 1;
    for(int j = start; j < end; j++){
        if(Q[j] <= axis){
            i += 1;
            int tmp = Q[i];
            Q[i] = Q[j];
            Q[j] = tmp;
        }
    }

    Q[end] = Q[i + 1];
    Q[i + 1] = axis;

    return i + 1;
}

void quickSort(int start, int end){
  if(start < end){
      int q = partition(start, end);
      quickSort(start, q - 1);
      quickSort(q + 1, end);
  }
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        Q.push_back(tmp);
    }

    quickSort(0, Q.size() - 1);

    for(int i = 0; i < Q.size(); i++){
        cout << Q[i] << '\n';
    }

    return 0;
}