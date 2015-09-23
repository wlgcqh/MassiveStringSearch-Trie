#ifndef __TRIE_H__
#define __TRIE_H__
#include<fstream>
#include<string>
#include<map>
using namespace std;
struct TrieNode {
	TrieNode* l[128];
	int n;
	TrieNode() :n(0) {
		fill(begin(l), end(l), nullptr);
	};
};
const map<char, int> email_format = {
	{'-',0},
	{}
};
void init(TrieNode *root) {

}
bool lookup(TrieNode *root,const string &s);
void add(TrieNode *root, const string &s);
void trie_check(ifstream &fp_strpool,ifstream &fp_checkedstr,ofstream &fp_result);
#endif