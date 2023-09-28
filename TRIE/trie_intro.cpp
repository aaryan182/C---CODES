#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assumption word will be in CAPS
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word){
        // base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';

        TrieNode *child;


        // character is present 
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        // character is absent
        else{
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }

    bool removeUtil(TrieNode *root, string word, int index)
    {
        // Base case: If we have reached the end of the word
        if (index == word.length())
        {
            // If the current node is a terminal node, mark it as non-terminal and return true
            if (root->isTerminal)
            {
                root->isTerminal = false;
                return true;
            }
            // If the current node is not a terminal node, return false (word not found)
            return false;
        }

        int charIndex = word[index] - 'A';

        // If the current character is not present in the Trie, return false (word not found)
        if (root->children[charIndex] == NULL)
        {
            return false;
        }

        TrieNode *child = root->children[charIndex];

        // Recursively try to remove the word from the child node
        bool shouldDeleteChild = removeUtil(child, word, index + 1);

        // If the child node is marked for deletion, delete it and set the corresponding child pointer to NULL
        if (shouldDeleteChild)
        {
            delete child;
            root->children[charIndex] = NULL;
            // Check if this node has no other children, and it's not a terminal node, then mark it for deletion as well
            if (!root->isTerminal && rootIsEmpty(root))
            {
                return true;
            }
        }

        return false;
    }

    void removeWord(string word)
    {
        removeUtil(root, word, 0);
    }

    // Helper function to check if a node has no other children
    bool rootIsEmpty(TrieNode *node)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != NULL)
            {
                return false;
            }
        }
        return true;
    }
};



int main()
{
    Trie *t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("PQRST");
    t->insertWord("PQRS");
    t->insertWord("PQR");
    cout<<"Search: "<<t->searchWord("ABCD")<<endl;
    cout<<"Search: "<<t->searchWord("PQRSTU")<<endl;
    return 0;
}


// This code is an implementation of a Trie data structure. A Trie is a tree-like data structure that is commonly used for efficient string searching and storage. 

// The code defines two classes: TrieNode and Trie. 

// The TrieNode class represents a node in the Trie. It has the following attributes:
// - `data`: a character that represents the value of the node.
// - `children`: an array of TrieNode pointers that represents the children of the node. Each element in the array corresponds to a character in the alphabet.
// - `isTerminal`: a boolean value that indicates whether the node represents the end of a word.

// The Trie class represents the Trie data structure. It has the following attributes:
// - `root`: a pointer to the root node of the Trie.

// The Trie class also defines several methods:
// - `insertUtil`: a helper method that recursively inserts a word into the Trie. It takes a TrieNode pointer `root` and a string `word` as parameters. It first checks if the word is empty, and if so, it marks the current node as a terminal node. Otherwise, it extracts the first character of the word and calculates its index in the `children` array. If the child node corresponding to the character already exists, it sets `child` to that node. Otherwise, it creates a new child node and sets `child` to that node. It then recursively calls `insertUtil` with `child` as the new root and the remaining characters of the word. This process continues until all characters of the word have been inserted into the Trie.
// - `insertWord`: a method that inserts a word into the Trie. It simply calls `insertUtil` with the root node and the word as parameters.
// - `searchUtil`: a helper method that recursively searches for a word in the Trie. It takes a TrieNode pointer `root` and a string `word` as parameters. It first checks if the word is empty, and if so, it returns the value of the `isTerminal` attribute of the current node. Otherwise, it extracts the first character of the word and calculates its index in the `children` array. If the child node corresponding to the character exists, it sets `child` to that node. Otherwise, it returns false, indicating that the word is not present in the Trie. It then recursively calls `searchUtil` with `child` as the new root and the remaining characters of the word. This process continues until all characters of the word have been searched in the Trie.
// - `searchWord`: a method that searches for a word in the Trie. It simply calls `searchUtil` with the root node and the word as parameters.

// In summary, this code implements a Trie data structure that allows for efficient insertion and searching of words. The Trie is represented as a tree of TrieNode objects, where each node represents a character in a word. The `insertWord` method inserts a word into the Trie, and the `searchWord` method searches for a word in the Trie.




// FOR REMOVAL OF WORDS FUNCTIONS



// This code is a part of a Trie data structure implementation. The Trie data structure is used to efficiently store and search for strings. 

// The code is specifically for removing a word from the Trie. It takes a word as input and removes it from the Trie if it exists.

// The `removeUtil` function is a recursive function that is called to remove the word from the Trie. It takes three parameters: the current node in the Trie (`root`), the word to be removed (`word`), and the current index of the character being processed in the word (`index`).

// The function starts by checking if the index has reached the end of the word. If it has, it checks if the current node is a terminal node (i.e., the end of a word). If it is, it marks the node as non-terminal and returns true. If it is not a terminal node, it simply returns false, indicating that the word was not found in the Trie.

// If the index has not reached the end of the word, the function calculates the index of the current character in the Trie using the ASCII value of the character. It then checks if the current character is present in the Trie by checking if the corresponding child node is NULL. If it is NULL, it means that the word does not exist in the Trie, so the function returns false.

// If the current character is present in the Trie, the function recursively calls itself with the child node as the new root, the word, and the next index. This is done to continue searching for the word in the Trie.

// After the recursive call, the function checks if the child node should be deleted. This is determined by the return value of the recursive call. If the child node should be deleted, it is deleted using the `delete` keyword, and the corresponding child pointer in the parent node is set to NULL.

// Finally, the function checks if the current node has no other children and is not a terminal node. If this is the case, it returns true, indicating that the current node should also be deleted.

// The `removeWord` function is a wrapper function that calls the `removeUtil` function with the root node of the Trie and the word to be removed.

// The `rootIsEmpty` function is a helper function that checks if a node has no other children. It iterates over all the child pointers of the node and checks if any of them are not NULL. If it finds a non-NULL child pointer, it returns false. If all child pointers are NULL, it returns true, indicating that the node has no other children.