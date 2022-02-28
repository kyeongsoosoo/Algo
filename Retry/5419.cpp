#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 75000
#define INF 1000000001

using namespace std;
typedef pair<int, int> P;

int TC;
int N;
vector<pair<int, int> > map;
vector<int> new_map;
int *seg;
int height;
long long result = 0;

bool asc_y_sort(P a1, P a2){
    if(a1.second < a2.second) return true;
    return false;
}

bool asc_x_dsc_y_sort(P a1, P a2){
    if(a1.first < a2.first) return true;
    else if(a1.first == a2.first){
        if(a1.second > a2.second) return true;
    }
    return false;
}

void build_seg(){

}

void update_seg(int node, int target, int left, int right, int diff){
    if(right < target || target < left) return;
    if(left == right){
        seg[node] += diff;
        // cout << " node: " << node << " val: " << seg[node] << '\n';
        return;
    }

    seg[node] += diff;
    int mid = (left + right) / 2;


    update_seg(node * 2 + 1, target, mid + 1, right, diff);
    update_seg(node * 2, target, left, mid, diff);
}

long long find_seg(int node, int left, int right, int start, int end){
    if(right < start || end < left) return (long long)0;
    if(left <= start && end <= right) return (long long)seg[node];

    int mid = (start + end) / 2;

    return find_seg(node * 2, left, right, start, mid) + find_seg(node * 2 + 1, left, right, mid + 1, end);
}

void compress_map(){
    int a = -INF;
    int counter = -1;
    for(int i = 0; i < N; i++){
        int y_coord = map[i].second;
        if(y_coord != a){
            counter += 1;
            a = y_coord;
            new_map.push_back(counter);
            continue;
        }
        new_map.push_back(counter);
    }

    for(int i = 0; i < N; i++){
        map[i].second = new_map[i];
    }
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
}

void caseInput(){
    map.clear();
    new_map.clear();
    result = 0;
    cin >> N;

    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        map.push_back(make_pair(a, b));
    }

    seg = new int[(1 << 18)];

    sort(map.begin(), map.end(), asc_y_sort);
    compress_map();
    sort(map.begin(), map.end(), asc_x_dsc_y_sort);
}

void find_ans(){
    for(int i =0; i < N; i++){
        P elem = map[i];

        long long ans = find_seg(1, elem.second, MAX - 1, 0, MAX - 1);

        // cout << "x: " << elem.first << " y: " << elem.second << " "<< ans << '\n';
        result += ans;

        update_seg(1, elem.second, 0, MAX - 1, 1);
    }
}

int main(){
    input();

    while(TC--){
        caseInput();
        find_ans();
        cout << result << '\n';
    }
}