#include "common.h"

class Trie {
    std::array<Trie *, 31> children;
    bool is_leaf{false};

public:
    Trie() {
        for (int i = 0; i < 31; i++) {
            children[i] = nullptr;
        }
    }

    void insert(string word) {
        auto curr = this;
        for (char c: word) {
            std::cout << c - 'a' << "\n";
            if (curr->children[c - 'a'] == nullptr) {
                Trie *node = new Trie();
                curr->children[c - 'a'] = node;
            }
            curr = curr->children[c - 'a'];
        }
        curr->is_leaf = true;
    }


    bool search(string word) {
        auto curr = this;
        for (char c: word) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->is_leaf;
    }

    bool remove(string word) {
            auto curr = this;
        for (char c: word) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }

        }
    }

    bool startsWith(string prefix) {
        auto curr = this;
        for (char c: prefix) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main() {
    Trie *trie = new Trie();
    trie->insert("apple");
    trie->search("apple"); // return True
    trie->search("app"); // return False
    trie->startsWith("app"); // return True
    trie->insert("app");
    trie->search("app"); // return True
}
