#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void encrypt(string in, int m, int key[]);																	// initializing functions
void decrypt(string in, int m, int key[]);

int main() {
	int choice = 0, m, z, key[256], length, diff;
	string input;

	cout << "***Program for permutation cypher***" << endl << endl;

	LOOP: while (choice != 2) {
		cout << "Select an option (0, 1, 2):\n0. Encryption\n1. Decryption\n2. Exit" << endl;				// user input for menu
		cin >> choice;
		cin.ignore();

		if (choice == 0) {																					// user input for encryption
			int x = 0, diff = 0;
			cout << "Enter plaintext: ";
			getline(cin, input);
			cout << "Enter block size (m): ";
			cin >> m;
			cout << "Enter permutation key: " << endl;
			for (int i = 0; i < m; i++) {
				cout << i + 1 << ": ";
				cin >> z;
				while (x < m) {																				// checking for repetitive key
					if (key[x] == z) {
						cout << "Invalid Key." << endl;
						memset(key, 0, sizeof(key));
						goto LOOP;
					}
					x++;
				}
				key[i] = z;
			}
			const char * in = input.c_str();
			length = strlen(in);
			while (length % m != 0) {																		// checking if padding is required
				input += 'x';
				length++;
				diff++;
			}
			cout << "Xs added for padding: " << diff << endl << endl;
			encrypt(input, m, key);
			memset(key, 0, sizeof(key));
		}
		else if (choice == 1) {																				// user input for decryption
			int x = 0, diff = 0;
			cout << "Enter ciphertext: ";
			getline(cin, input);
			cout << "Enter block size (m): ";
			cin >> m;
			cout << "Enter permutation key: " << endl;
			for (int i = 0; i < m; i++) {
				cout << i + 1 << ": ";
				cin >> z;
				while (x < m) {																				// checking is key is repetitive
					if (key[x] == z) {
						cout << "Invalid Key." << endl;
						memset(key, 0, sizeof(key));
						goto LOOP;
					}
					x++;
				}
				key[i] = z;
			}
			const char * in = input.c_str();
			length = strlen(in);
			while (length % m != 0) {																		// checking for padding
				input += 'x';
				length++;
			}
			cout << "Xs added for padding: " << diff << endl << endl;
			decrypt(input, m, key);
			memset(key, 0, sizeof(key));
		}
		else
			cout << "Exit" << endl;																			// if invalid input or 2
	}
	return 0;
}

void encrypt(string in, int m, int key[]) {																	// function for permutation encryption
	int length, val, count;
	char arr[256];
	for (int i = 0; i < m; i++) {
		arr[i] = '&';
	}
	string ciphertext;
	length = in.length() / m;																				// no. of blocks in the string
	for (int j = 0; j < length; j++) {
		count = (j) * m;
		for (int i = 0; i < m; i++) {
			val = key[i];																					// getting key one by one
			arr[val-1] = in[count + i];																		// storing each encrypted block in arr
		}
		for (int a = 0; a < m; a++) {
			ciphertext += arr[a];																			// adding encrypted blocks to the string
		}
	}
	cout << "Ciphertext: " << ciphertext << endl;
}

void decrypt(string in, int m, int key[]) {																	// function for decrypting permutation
	int length, val, count;
	char arr[256];
	string plaintext;
	length = in.length() / m;																				// calculating number of blocks in the string
	for (int j = 0; j < length; j++) {
		count = (j)* m;
		for (int i = 0; i < m; i++) {
			val = key[i];																					// getting key one by one
			arr[i] = in[(val-1) + count];																	// storing decrypted characters in arr
		}
		for (int a = 0; a < m; a++) {
			plaintext += arr[a];																			// adding decrypted blocks to the string
		}
	}
	cout << "Ciphertext: " << plaintext << endl;
}