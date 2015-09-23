#include<iostream>
#include<string>
#include<fstream>
#include"trie.h"
using namespace std;
int main(int argc, char *argv[]) {
	ifstream fp_strpool(argv[1]);
	ifstream fp_checkedstr(argv[2]);
	ofstream fp_result(argv[3]);
	trie_check(fp_strpool, fp_checkedstr, fp_result);
	fp_result << "------------------trieend---------------------- " ;

}