#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void encrypt(string in, char key[]);																	// initializing functions
void decrypt(string in, char key[]);

void invkey(char key[], char alph[], char invert[]) {													// function to find inverse of key for decryption
	memset(invert, '&', sizeof(invert));																// initializing array
	for (int i = 0; i < 29; i++) {																		// checking for every character in the key space
		if (key[i] == 'a' || key[i] == 'A')
			invert[0] = alph[i];
		else if (key[i] == 'b' || key[i] == 'B')
			invert[1] = alph[i];
		else if (key[i] == 'c' || key[i] == 'C')
			invert[2] = alph[i];
		else if (key[i] == 'd' || key[i] == 'D')
			invert[3] = alph[i];
		else if (key[i] == 'e' || key[i] == 'E')
			invert[4] = alph[i];
		else if (key[i] == 'f' || key[i] == 'F')
			invert[5] = alph[i];
		else if (key[i] == 'g' || key[i] == 'G')
			invert[6] = alph[i];
		else if (key[i] == 'h' || key[i] == 'H')
			invert[7] = alph[i];
		else if (key[i] == 'i' || key[i] == 'I')
			invert[8] = alph[i];
		else if (key[i] == 'j' || key[i] == 'J')
			invert[9] = alph[i];
		else if (key[i] == 'k' || key[i] == 'K')
			invert[10] = alph[i];
		else if (key[i] == 'l' || key[i] == 'L')
			invert[11] = alph[i];
		else if (key[i] == 'm' || key[i] == 'M')
			invert[12] = alph[i];
		else if (key[i] == 'n' || key[i] == 'N')
			invert[13] = alph[i];
		else if (key[i] == 'o' || key[i] == 'O')
			invert[14] = alph[i];
		else if (key[i] == 'p' || key[i] == 'P')
			invert[15] = alph[i];
		else if (key[i] == 'q' || key[i] == 'Q')
			invert[16] = alph[i];
		else if (key[i] == 'r' || key[i] == 'R')
			invert[17] = alph[i];
		else if (key[i] == 's' || key[i] == 'S')
			invert[18] = alph[i];
		else if (key[i] == 't' || key[i] == 'T')
			invert[19] = alph[i];
		else if (key[i] == 'u' || key[i] == 'U')
			invert[20] = alph[i];
		else if (key[i] == 'v' || key[i] == 'V')
			invert[21] = alph[i];
		else if (key[i] == 'w' || key[i] == 'W')
			invert[22] = alph[i];
		else if (key[i] == 'x' || key[i] == 'X')
			invert[23] = alph[i];
		else if (key[i] == 'y' || key[i] == 'Y')
			invert[24] = alph[i];
		else if (key[i] == 'z' || key[i] == 'Z')
			invert[25] = alph[i];
		else if (key[i] == ' ')
			invert[26] = alph[i];
		else if (key[i] == ';')
			invert[27] = alph[i];
		else if (key[i] == '.')
			invert[28] = alph[i];
	}
}

int main() {
	int choice = 0;
	string input;
	char k, key[29], invert[29];
	char alph[29] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', ';', '.' };
	memset(key, '&', sizeof(key));
	cout << "***Program for substitution cypher***" << endl << endl;

	LOOP: while (choice!=2) {

		cout << "Select an option (0, 1, 2):\n0. Encryption\n1. Decryption\n2. Exit" << endl;			// user input for menu
		cin >> choice;
		cin.ignore();
		if (choice == 0) {																				// user input for encryption
			cout << "Enter plaintext: ";
			getline(cin, input);
			cout << "Enter Key: " << endl;
			for (int i = 0; i < 29; i++) {
				int x = 0;
				cout << alph[i] << ": ";
				cin.get(k);
				cin.ignore();
				while (x<29) {																			// checking if key is repetitive
					if (key[x] == k) {
						cout << "Invalid Key." << endl;
						memset(key, '&', sizeof(key));
						goto LOOP;
					}
					x++;
				}

			key[i] = k;
			}
			encrypt(input, key);
			memset(key, '&', sizeof(key));
		}
		else if (choice == 1) {																			// user input for decryption
			char dkey[29];
			cout << "Enter ciphertext: ";
			getline(cin, input);
			cout << "Enter Key: " << endl;
			for (int i = 0; i < 29; i++) {
				int x = 0;
				cout << alph[i] << ": ";
				cin.get(k);
				cin.ignore();
				while (x < 29) {																		// checking if key is repetitive
					if (key[x] == k) {
						cout << "Invalid Key." << endl;
						memset(key, '&', sizeof(key));
						goto LOOP;
					}
					x++;
				}

				key[i] = k;
			}
	
			invkey(key, alph, invert);																	// calling function to find inverse of key
			decrypt(input, invert);
			memset(key, '&', sizeof(key));
		}
		else
			cout << "Exit" << endl;																		// if invalid input or 2
	}

	return 0;
}

void encrypt(string in, char key[]) {																	// function for substitution encryption
	string cipher;
	int length;
	const char * input = in.c_str();
	length = strlen(input);
	for (int i = 0; i < length; i++) {																	// checking for each character in the plaintext
		if (input[i] == 'a' || input[i] == 'A')															// then adding the key to the ciphertext
			cipher += key[0];
		else if (input[i] == 'b' || input[i] == 'B')
			cipher += key[1];
		else if (input[i] == 'c' || input[i] == 'C')
			cipher += key[2];
		else if (input[i] == 'd' || input[i] == 'D')
			cipher += key[3];
		else if (input[i] == 'e' || input[i] == 'E')
			cipher += key[4];
		else if (input[i] == 'f' || input[i] == 'F')
			cipher += key[5];
		else if (input[i] == 'g' || input[i] == 'G')
			cipher += key[6];
		else if (input[i] == 'h' || input[i] == 'H')
			cipher += key[7];
		else if (input[i] == 'i' || input[i] == 'I')
			cipher += key[8];
		else if (input[i] == 'j' || input[i] == 'J')
			cipher += key[9];
		else if (input[i] == 'k' || input[i] == 'K')
			cipher += key[10];
		else if (input[i] == 'l' || input[i] == 'L')
			cipher += key[11];
		else if (input[i] == 'm' || input[i] == 'M')
			cipher += key[12];
		else if (input[i] == 'n' || input[i] == 'N')
			cipher += key[13];
		else if (input[i] == 'o' || input[i] == 'O')
			cipher += key[14];
		else if (input[i] == 'p' || input[i] == 'P')
			cipher += key[15];
		else if (input[i] == 'q' || input[i] == 'Q')
			cipher += key[16];
		else if (input[i] == 'r' || input[i] == 'R')
			cipher += key[17];
		else if (input[i] == 's' || input[i] == 'S')
			cipher += key[18];
		else if (input[i] == 't' || input[i] == 'T')
			cipher += key[19];
		else if (input[i] == 'u' || input[i] == 'U')
			cipher += key[20];
		else if (input[i] == 'v' || input[i] == 'V')
			cipher += key[21];
		else if (input[i] == 'w' || input[i] == 'W')
			cipher += key[22];
		else if (input[i] == 'x' || input[i] == 'X')
			cipher += key[23];
		else if (input[i] == 'y' || input[i] == 'Y')
			cipher += key[24];
		else if (input[i] == 'z' || input[i] == 'Z')
			cipher += key[25];
		else if (input[i] == ' ')
			cipher += key[26];
		else if (input[i] == ';')
			cipher += key[27];
		else if (input[i] == '.')
			cipher += key[28];
	}

	cout << "Ciphertext: " << cipher << endl;
}

void decrypt(string in, char key[]) {																	// function for substitution decryption
	string plaintext;
	int length;
	const char * input = in.c_str();
	length = strlen(input);
	for (int i = 0; i < length; i++) {																	// checking each character in the ciphertext
		if (input[i] == 'a' || input[i] == 'A')															// then adding the key to the plaintext
			plaintext += key[0];
		else if (input[i] == 'b' || input[i] == 'B')
			plaintext += key[1];
		else if (input[i] == 'c' || input[i] == 'C')
			plaintext += key[2];
		else if (input[i] == 'd' || input[i] == 'D')
			plaintext += key[3];
		else if (input[i] == 'e' || input[i] == 'E')
			plaintext += key[4];
		else if (input[i] == 'f' || input[i] == 'F')
			plaintext += key[5];
		else if (input[i] == 'g' || input[i] == 'G')
			plaintext += key[6];
		else if (input[i] == 'h' || input[i] == 'H')
			plaintext += key[7];
		else if (input[i] == 'i' || input[i] == 'I')
			plaintext += key[8];
		else if (input[i] == 'j' || input[i] == 'J')
			plaintext += key[9];
		else if (input[i] == 'k' || input[i] == 'K')
			plaintext += key[10];
		else if (input[i] == 'l' || input[i] == 'L')
			plaintext += key[11];
		else if (input[i] == 'm' || input[i] == 'M')
			plaintext += key[12];
		else if (input[i] == 'n' || input[i] == 'N')
			plaintext += key[13];
		else if (input[i] == 'o' || input[i] == 'O')
			plaintext += key[14];
		else if (input[i] == 'p' || input[i] == 'P')
			plaintext += key[15];
		else if (input[i] == 'q' || input[i] == 'Q')
			plaintext += key[16];
		else if (input[i] == 'r' || input[i] == 'R')
			plaintext += key[17];
		else if (input[i] == 's' || input[i] == 'S')
			plaintext += key[18];
		else if (input[i] == 't' || input[i] == 'T')
			plaintext += key[19];
		else if (input[i] == 'u' || input[i] == 'U')
			plaintext += key[20];
		else if (input[i] == 'v' || input[i] == 'V')
			plaintext += key[21];
		else if (input[i] == 'w' || input[i] == 'W')
			plaintext += key[22];
		else if (input[i] == 'x' || input[i] == 'X')
			plaintext += key[23];
		else if (input[i] == 'y' || input[i] == 'Y')
			plaintext += key[24];
		else if (input[i] == 'z' || input[i] == 'Z')
			plaintext += key[25];
		else if (input[i] == ' ')
			plaintext += key[26];
		else if (input[i] == ';')
			plaintext += key[27];
		else if (input[i] == '.')
			plaintext += key[28];
	}

	cout << "Plaintext: " << plaintext << endl;
}