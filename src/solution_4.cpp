#include <iostream>
#include <string>
using namespace std;

class Trie {
private:
    Trie* next[26];
    bool finish;
public:
    Trie(): finish(false) {
        fill(next, next+26, nullptr);
    }
    ~Trie() {
        for(int i=0; i<26; i++)
            if(next[i]) delete next[i];
    }
    void insert(string word) {
        Trie* curr = this;
        for(char ch : word) {
            if(curr->next[ch-'a'] == nullptr)
                curr->next[ch-'a'] = new Trie();
            curr = curr->next[ch-'a'];
        }
        curr->finish = true;
    }
    bool search(string word) {
        Trie* curr = this;
        for(char ch : word) {
            if(curr->next[ch-'a'] == nullptr)
                return false;
            curr = curr->next[ch-'a'];
        }
        if(curr->finish) return true;
        else return false;
    }
};

int main() {
    int N;
    cin >> N;
    Trie* root = new Trie();
    for(int i=0; i<N; i++) {
        string word;
        cin >> word;
        root->insert(word);
    }
    string K;
    cin >> K;
    bool result = root->search(K);
    if(result) cout << "있습니다";
    else cout << "없습니다";
    delete root;  // clean up the memory
    return 0;
}