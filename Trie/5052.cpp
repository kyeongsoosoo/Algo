#include <iostream>
#include <string>

#define endl "\n"
#define LEN_MAX 11
#define N_MAX 10010
#define NODE_MAX N_MAX * LEN_MAX

using namespace std;

struct TRIE{
    bool finish;
    TRIE *node[LEN_MAX];

    void insert(char *str);
    bool call(char *str);
};

int N, N_idx;
char phone[N_MAX][LEN_MAX];
string answer;
TRIE *root, nodepool[NODE_MAX];

TRIE *nodeset(){
    TRIE *new_node = &nodepool[N_idx++];
    new_node->finish = false;

    for(int i = 0; i < LEN_MAX; i++) new_node->node[i] = NULL;

    return new_node;
}

void TRIE::insert(char *str){
    if(*str == NULL){
        finish = true;
        return;
    }

    int cur = *str - '0';
    if(node[cur] == NULL) node[cur] = nodeset();
    node[cur]->insert(str + 1);
}

bool TRIE::call(char *str){
    if(*str == NULL) return true;
    if(finish == true) return false;

    int cur = *str - '0';
    return node[cur]->call(str + 1 );
}

void initialize(){
    N_idx = 0;
    root = nodeset();
}

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> phone[i];
    }
}

void solution(){
    for(int i = 0; i < N; i++){
        root->insert(phone[i]);
    }
    bool flag = true;
    for(int i = 0; i < N; i++){
        if(flag == true) flag = root->call(phone[i]);
        if(flag == false) break;
    }

    if(flag == true) answer = "YES";
    else answer = "NO";
}


void solve(){
    int tc; cin >> tc;
    for(int T = 1; T <= tc; T++){
        initialize();
        input();
        solution();

        cout << answer << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}