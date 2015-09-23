#include<string>
#include"trie.h"
using namespace std;

bool lookup(TrieNode *root, const string &s) {
	TrieNode *p = root;
	for (auto item : s) {
		if (!p->l[item])	return false;
		p = p->l[item];
	}
	return p->n > 0;
}
void add(TrieNode *root, const string &s) {
	TrieNode *p = root;
	for (auto item : s) {
		if (!p->l[item])	p->l[item] = new TrieNode();
		p = p->l[item];
	}
	p->n++;
}
void trie_check(ifstream &fp_strpool, ifstream &fp_checkedstr, ofstream &fp_result) {
	TrieNode *root = new TrieNode();
	string s;
	while (fp_strpool >> s) {
		add(root, s);
	}
	while (fp_checkedstr >> s) {
		if (!lookup(root, s)) {
			fp_result << "no" << endl;
		}
		else {
			fp_result << "yes" << endl;
		}
	}
}