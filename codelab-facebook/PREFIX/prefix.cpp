#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 26; 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
    
    int times = 0;//amount of words going through the node while inserting
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        pCrawl->times += 1;
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 

string searchShortestUniquePrefix(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a';
        if(pCrawl->times == 1){
            return key.substr(0,i);
        }
        pCrawl = pCrawl->children[index]; 
    } 
  
    return key;
} 

// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

 
vector<string> prefix(vector<string> &A) {
    struct TrieNode *root = getNode(); 
    for(int i = 0; i < A.size(); i++)
        insert(root, A[i]);
        
    vector<string> result;
    for(string s : A){
        string prefix = searchShortestUniquePrefix(root, s);
        result.push_back(prefix);
    }
        
    return result;
    
}

void output(vector<string> & out){
    for(string s : out){
        cout << s << " ";
    }
    cout << endl;
}

int main(){

    vector<string> input = {"zebra", "dog", "duck", "dove"};

    vector<string> result = prefix(input);

    output(result);

    return 0;
}