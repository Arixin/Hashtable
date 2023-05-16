#include <iostream>
#include <string>

using namespace std;

class Hashtable {
public:
	bool* hash;
	long* key;
	string* dane;
	int size;
	int* tryouts;

	void reset(int x){
		hash[x] = false;
		key[x] = -1;
		dane[x] = " ";
		tryouts[x] = 0;
	}
		
	void setSize(int size) {
		this->size = size;
		hash = new bool[size];
		key = new long[size];
		dane = new string[size];
		tryouts = new int[size];
		for (int i = 0; i < size; i++) {
			reset(i);
		}

	}


	int hashing(long n,long i) {
		return (n+i) % size;
	}

	void insertItem(long k, string s) {
		for (int i = 0; i < size; i++) {
			int temp = hashing(k,i);
				if (hash[temp] == false) {
					key[temp] = k;
					dane[temp] = s;
					hash[temp] = true;
					tryouts[temp] = i;
					break;
				}
		}
	}

	void showallItems() {
		for (int i = 0; i < size; i++) {
			if (hash[i] == true) {
				cout << i << " " << key[i] << " " << dane[i] << endl;
			}
		}
		cout << endl;
	}

	void recalculate(int dummy) {
	    int x = 0;
		int i = dummy;

		while (x < size) {
			if (tryouts[i] != 0) {
				int q = key[i];
				string p = dane[i];
				reset(i);
				insertItem(q, p);
			}
			if (i +1 < size) i++;
			else i = 0;
			x++;
		}
	}

	void deleteItem(long k) {
		for (int i = 0; i < size; i++) {
			int temp = hashing(k, i);
			if (hash[temp] == true && key[temp] == k) {
				reset(temp);
				recalculate(temp);
				break;
			}
		}
	}

	void endoftest() {
		delete[] hash;
		delete[] key;
		delete[] dane;
		delete[] tryouts;
	}


};

int main()
{
	Hashtable ht;
	int testy;
	cin >> testy;

	while (testy > 0) {
		string komenda;
		cin >> komenda;
		if (komenda == "print") {
			ht.showallItems();
		}
		else if (komenda == "delete") {
			long key;
			cin >> key;
			ht.deleteItem(key);
		}
		else if (komenda == "add") {
			long k;
			string s;
			cin >> k;
			cin >> s;
			ht.insertItem(k,s); 
		}
		else if (komenda == "stop") {
			testy--;
			ht.endoftest();
		}
		else if (komenda == "size") {
			int size;
			cin >> size;
			ht.setSize(size);
		}
	}



	return 0;

}
