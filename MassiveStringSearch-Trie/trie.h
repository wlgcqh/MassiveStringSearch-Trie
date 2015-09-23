#ifndef __TRIE_H__
#define __TRIE_H__
#include<fstream>
#include<string>
using namespace std;
struct TrieNode {
	bool l[66];
	int n;
	TrieNode() :n(0) {
		fill(begin(l), end(l), false);
	};
};
#endif