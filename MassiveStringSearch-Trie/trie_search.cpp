#include<iostream>
#include<string>
#include<map>
#include"trie_search.h"
using namespace std;
trie_search::trie_search() {
	//emailÖÐÔÊÐíµÄ×Ö·û
	int value = 0;
	for (char c = '0'; c <= '9'; c++) {
		letter[c] = value++;
	}
	for (char c = 'A'; c <= 'Z'; c++) {
		letter[c] = value++;
	}
	for (char c = 'a'; c <= 'z'; c++) {
		letter[c] = value++;
	}
	letter['-'] = value++;
	letter['.'] = value++;
	letter['_'] = value++;
	letter['@'] = value++;
}
bool trie_search::lookup(const string &s) {
	int curr = letter[s[0]];
	for (char i = 1; i < (char)s.size();i++) {
		int next = letter[s[i]];
		if (!node[curr].l[next])	return false;
		curr = next;
	}
	return  node[curr].n > 0;
}
void trie_search::add(const string &s) {
	int curr = letter[s[0]];
	for (char i = 1; i < (char)s.size();i++) {
		int next = letter[s[i]];
		if (!node[curr].l[next])	node[curr].l[next] = true;
		curr = next;
	}
	node[curr].n++;
}
void trie_search::trie_check(ifstream &fp_strpool, ifstream &fp_checkedstr, ofstream &fp_result) {
	string s;
	while (fp_strpool >> s) {
		add(s);
	}
	while (fp_checkedstr >> s) {
		if (!lookup(s)) {
			fp_result << "no" << endl;
		}
		else {
			fp_result << "yes" << endl;
		}
	}
}