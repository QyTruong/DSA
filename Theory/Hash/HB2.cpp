#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

#define M 7

using namespace std;

struct InternalData {
	char* key;
	int freq;
};

struct Node {
	InternalData* data;
	int next;
};

struct HashTable {
	Node T[M];
	int r;
};

void init(HashTable& ht) {
	for (int i = 0; i < M; i++) {
		ht.T[i].data = NULL;
		ht.T[i].next = -1;
	}
	ht.r = M - 1;
}

int hashFunc(char* x) {
	int k = 0;
	for (int i = 0; i < strlen(x); i++) {
		k += (int)(*(x + i)) * (i + 1);
	}
	return k % M;
}

void insert(HashTable& ht, InternalData* x) {
	int k = hashFunc(x->key);
	if (ht.T[k].data == NULL) {
		ht.T[k].data = x;
	}
	else {
		if (strcmp(ht.T[k].data->key, x->key) == 0) {
			ht.T[k].data->freq += 1;
			return;
		}
		while (ht.T[k].next != -1) {
			k = ht.T[k].next;
			if (strcmp(ht.T[k].data->key, x->key) == 0) {
				ht.T[k].data->freq += 1;
				return;
			}
		}
		
		ht.T[ht.r].data = x;
		ht.T[k].next = ht.r;
	}


	while (ht.r >= 0 && ht.T[ht.r].data != NULL) {
		ht.r--;
	}
}

void printTable(HashTable ht) {
	for (int i = 0; i < M; i++) {
		if (ht.T[i].data != NULL) {
			cout << "Bucket " << i << ": " << ht.T[i].data->key 
				<< "(" << ht.T[i].data->freq << ")" <<  endl;
		}
	}
}

int main() {
	HashTable ht;
	init(ht);

	char s[] = "apple banana apple cherry date banana cherry fig grape date";
	
	char* p = strtok(s, " ");
	while (p != NULL) {
		InternalData* x = new InternalData;
		x->key = p;
		x->freq = 1;
		insert(ht, x);
		p = strtok(NULL, " ");
	}
	
	
	

	printTable(ht);
	return 0;
}