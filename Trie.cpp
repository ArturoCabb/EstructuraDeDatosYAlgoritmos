/*
    Es bueno para hablar de strings con prefijos
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

class NodeTrie {
private:
    char letter;
    NodeTrie *parent = nullptr;
    NodeTrie* child[26];
public:
    bool end;
    NodeTrie(char c, NodeTrie* p) {
        this->parent = p;
        this->letter = c;
    }
    NodeTrie* getChild(char c) {return child[c - 'a'];}
    void setChild(char c, NodeTrie* node) {child[c - 'a'] = node;}
};

class Trie {
    private:
    NodeTrie *root;
    public:
    Trie() {
        root = new NodeTrie('\0', nullptr);
    }
    void insert(std::string word) {
        NodeTrie* current = root;
        for (char c : word) {
            if(!current->getChild(c)) {
                current->setChild(c, new NodeTrie(c, current));
            }
            current = current->getChild(c);
        }
        current->end = true;
    }

    bool search(std::string word) {
        NodeTrie* current = root;
        for (char c : word) {
            if (!current->getChild(c)) {
                return false;
            }
            current = current->getChild(c);
        }
        return current->end;
    }
};

int main() {

    return 0;
}
