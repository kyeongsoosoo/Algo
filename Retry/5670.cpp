#include <iostream>
#include <string>

#define endl "\n"

using namespace std;

struct Trie{
    Trie *go[26];
    bool finish;
    int branch;
    int words;

    Trie(): finish(false), branch(0), words(0){
        fill(go, go + 26, nullptr);
    }
    ~Trie(){
        for(int i = 0; i < 26; i++){
            if(go[i]) delete go[i];
        }
    }

    void insert(char *str);
    long long cntKeyStrokes(bool isRoot);
};

void Trie::insert(char *str){
    if(*str == '\0'){
        branch++;
        finish = true;
    }
    else{
        if(!go[*str - 'a']){
            branch++;
            go[*str - 'a'] = new Trie;
        }
        words++;
        go[*str - 'a']->insert(str + 1);
    }
}

long long Trie::cntKeyStrokes(bool isRoot = false){
    long long result = 0;
    if(isRoot || branch > 1) result = words;

    for(int i = 0; i < 26; i++){
        if(go[i]) result += go[i]->cntKeyStrokes();
    }
    return result;
}


int N;
int TC;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main(){

    while(scanf("%d", &N) > 0){

        Trie *root = new Trie;

        for(int i = 0; i < N; i++){
            char W[81];
            cin >> W;
            root->insert(W);
        }
        cout <<fixed;
        cout.precision(2);
        cout << (1.0 * root->cntKeyStrokes(true) / N) << '\n';

        delete root;
    }
}