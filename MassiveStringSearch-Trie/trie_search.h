#ifndef __TRIE_SEARCH__
#define __TRIE_SEARCH__
#include<map>
#include"trie.h"
using namespace std;
class trie_search {
public:
	trie_search();
	bool lookup(const string &s);
	void add(const string &s);
	void trie_check(ifstream &fp_strpool, ifstream &fp_checkedstr, ofstream &fp_result);
private:
	map<char, char> letter;
	TrieNode node[66];
};
#endif