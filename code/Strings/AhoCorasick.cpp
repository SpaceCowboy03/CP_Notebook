/*sufijo mas grande en el trie?*/
const int K = 26;
int last_n = 0;

struct Node {
    char c;
    int next[K], go[K]; //next: trie, go: automata
    bool terminal = false;
    int patt = -1;
    int p = -1, link = -1;
    set<int> has_terminals;

    Node(int p=-1, char c = '$') : p(p), c(c) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Node> trie(1);

void insert(string &s, int idx){
    int curr_node = 0;
    for(char ch: s){
        int c = ch-'a';
        if(trie[curr_node].next[c] == -1){
            trie[curr_node].next[c] = ++last_n;
            trie.emplace_back(curr_node, ch);
        }
        curr_node = trie[curr_node].next[c];
    }
    trie[curr_node].terminal = true;
    trie[curr_node].patt = idx;;
}

int go(int v, char ch);

int get_link(int v){
    if (trie[v].link == -1){
        if(v == 0 || trie[v].p == 0){
            trie[v].link = 0;
        }else{
            trie[v].link = go(get_link(trie[v].p), trie[v].c);
        }
    }
    return trie[v].link;
}

int go(int v, char ch){
    int c = ch - 'a';
    if(trie[v].go[c] == -1){
        if(trie[v].next[c] != -1){
            trie[v].go[c] = trie[v].next[c];
        }else{
            trie[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
    }
    return trie[v].go[c]; 
}