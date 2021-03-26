#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <utility>

using namespace std;

const int MAXC = 26;

class Tnode {
public:
	Tnode* ch[MAXC];
	bool valid;
	Tnode() {
		valid = false;
		for (int i = 0; i < MAXC; i ++)
			ch[i] = NULL;
	}
};

void DelNode(Tnode* node) {
	if (node == NULL) return;
	for (int i = 0; i < MAXC; i ++) {
		if (node->ch[i] != NULL)
			DelNode(node->ch[i]);
	}
	delete node;
}

class FilterSystem {

private:
	Tnode* root;
	int total;

public:

	FilterSystem() {
		root = new Tnode();
		total = 0;
	}

	int Add(string keyword) {
		int len = keyword.size();
		Tnode* ptr = root;
		for (int i = 0; i < len; i ++) {
			int ch_id = keyword[i] - 'a';
			if (ch_id >= 0 && ch_id < MAXC) {
				if (ptr->ch[ch_id] == NULL) {
					ptr->ch[ch_id] = new Tnode();
				}
				ptr = ptr->ch[ch_id];
			}
		}
		if (! ptr->valid) {
			ptr->valid = true;
			total ++;
		}
		return total;
	}

	int Remove(string keyword) {
		int len = keyword.size();
		Tnode* ptr = root;
		bool success = true;
		for (int i = 0; i < len; i ++) {
			int ch_id = keyword[i] - 'a';
			if (ch_id >= 0 && ch_id < MAXC) {
				if (ptr->ch[ch_id] == NULL) {
					success = false;
					break;
				}
				ptr = ptr->ch[ch_id];
			}
		}
		if (! success) return -1;
		if (! ptr->valid) return -1;
		ptr->valid = false;
		total --;
		return total;
	}

	string Filter(string sentence) {
		int len = sentence.size();
		Tnode* ptr = root;
		int last = 0;
		bool failed = false;
		string ret;
		for (int i = 0; i <= len; i ++) {
			int ch_id;
			if (i == len) {
				ch_id = -1;
			} else {
				ch_id = sentence[i] - 'a';
			}
			if (ch_id >= 0 && ch_id < MAXC) {
				if (! failed) {
					if (ptr->ch[ch_id] == NULL) {
						failed = true;
						ptr = root;
						continue;
					} else {
						ptr = ptr->ch[ch_id];
						if (ptr->valid) {
							last = i + 1;
						}
					}
				}
			} else {
				for (int j = last; j < i; j ++) {
					ret.append(1, sentence[j]);
				}
				if (i != len && i > last) {
					ret.append(1, sentence[i]);
				}
				last = i + 1;
				ptr = root;
				failed = false;
			}
		}
		return ret;
	}

	~FilterSystem() {
		DelNode(root);
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int i;
	FilterSystem sys;
	for (i = 0; i < n; i ++) {
		int t;
		char ch;
		string s;
		scanf("%d ", &t);
		getline(cin, s);
		if (t == 1) {
			cout << sys.Add(s) << endl;
		} else if (t == 2) {
			cout << sys.Remove(s) << endl;
		} else {
			cout << sys.Filter(s) << endl;
		}
	}
	return 0;
}
