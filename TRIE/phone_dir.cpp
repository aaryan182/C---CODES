#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode() : isTerminal(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isTerminal = true;
    }

    TrieNode* getRoot() {
        return root;
    }
};

void findSuggestions(TrieNode* node, string& prefix, vector<string>& suggestions) {
    if (node->isTerminal) {
        suggestions.push_back(prefix);
    }

    for (const auto& child : node->children) {
        prefix.push_back(child.first);
        findSuggestions(child.second, prefix, suggestions);
        prefix.pop_back();
    }
}

vector<string> phoneDirectory(vector<string>& contactList, string& queryStr) {
    Trie trie;
    for (const string& contact : contactList) {
        trie.insert(contact);
    }

    TrieNode* root = trie.getRoot();
    vector<string> suggestions;
    string prefix;

    TrieNode* node = root;
    for (char ch : queryStr) {
        if (node->children.find(ch) != node->children.end()) {
            prefix.push_back(ch);
            node = node->children[ch];
        } else {
            break;
        }
    }

    findSuggestions(node, prefix, suggestions);

    if (suggestions.empty()) {
        suggestions.push_back("No suggestions found");
    }

    return suggestions;
}

int main() {
    vector<string> contactList = {"apple", "app", "banana", "cherry"};
    string queryStr = "app";

    vector<string> suggestions = phoneDirectory(contactList, queryStr);

    for (const string& suggestion : suggestions) {
        cout << suggestion << endl;
    }

    return 0;
}


// This code implements a phone directory search using a Trie data structure. 

// The TrieNode class represents a node in the Trie. It has an unordered map called children, which maps characters to their corresponding child nodes. It also has a boolean variable called isTerminal, which indicates whether the node represents the end of a word.

// The Trie class represents the Trie data structure. It has a private member variable called root, which is a pointer to the root node of the Trie. The constructor initializes the root node.

// The insert function is used to insert a word into the Trie. It takes a string parameter called word. It starts at the root node and iterates over each character in the word. For each character, it checks if there is a child node corresponding to that character. If not, it creates a new child node and adds it to the children map of the current node. It then moves to the child node. After iterating over all characters in the word, it sets the isTerminal variable of the last node to true, indicating that it represents the end of a word.

// The getRoot function returns a pointer to the root node of the Trie.

// The findSuggestions function is a recursive function that finds all suggestions for a given prefix. It takes three parameters: a pointer to the current node, a string reference called prefix, and a vector of strings called suggestions. If the current node represents the end of a word, it adds the prefix to the suggestions vector. Then, it iterates over each child of the current node. For each child, it appends the character to the prefix, recursively calls the findSuggestions function on the child node, and then removes the last character from the prefix.

// The phoneDirectory function is the main function that performs the phone directory search. It takes two parameters: a vector of strings called contactList, which contains the list of contacts in the phone directory, and a string reference called queryStr, which represents the query string to search for. It creates a Trie object and inserts each contact from the contactList into the Trie. It then initializes variables for the root node, a vector of strings called suggestions, and a string called prefix. It iterates over each character in the queryStr and checks if there is a child node corresponding to that character. If there is, it appends the character to the prefix and moves to the child node. If there is not, it breaks out of the loop. After iterating over all characters in the queryStr, it calls the findSuggestions function with the current node, prefix, and suggestions as parameters. If there are no suggestions, it adds a default "No suggestions found" string to the suggestions vector. Finally, it returns the suggestions vector.