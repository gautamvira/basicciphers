#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void kptattack(string ptext, string ctext) {															// function for known plaintext attack
	char arr[256];
	int m[256], alph[29], calph[29], count, fblock = 0, block = 0, temp, temp1, temp2, key[256];
	static int t, u;
	bool check = true;

	for(int i = 2; i <= ptext.length(); i++){															// finding possible block sizes
		if (ptext.length() % i == 0) {
			m[block] = i;
			block++;
		}
	}
	
	BLOOP:while (block >= 0) {																			// checking characters for each possible block
		block--;
		t = 0, u = 0;
		count = ptext.length() / m[block];
		for (int x = 0; x < count; x++) {																// for each block in the string
			memset(alph, 0, sizeof(alph));
			memset(calph, 0, sizeof(calph));
			for (int i = 0; i < m[block]; i++) {														// if plaintext characters match ciphertext characters
				if (ptext[t] == 'a' || ptext[t] == 'A')
					alph[0]++;
				else if (ptext[t] == 'b' || ptext[t] == 'B')
					alph[1]++;
				else if (ptext[t] == 'c' || ptext[t] == 'C')
					alph[2]++;
				else if (ptext[t] == 'd' || ptext[t] == 'D')
					alph[3]++;
				else if (ptext[t] == 'e' || ptext[t] == 'E')
					alph[4]++;
				else if (ptext[t] == 'f' || ptext[t] == 'F')
					alph[5]++;
				else if (ptext[t] == 'g' || ptext[t] == 'G')
					alph[6]++;
				else if (ptext[t] == 'h' || ptext[t] == 'H')
					alph[7]++;
				else if (ptext[t] == 'i' || ptext[t] == 'I')
					alph[8]++;
				else if (ptext[t] == 'j' || ptext[t] == 'J')
					alph[9]++;
				else if (ptext[t] == 'k' || ptext[t] == 'K')
					alph[10]++;
				else if (ptext[t] == 'l' || ptext[t] == 'L')
					alph[11]++;
				else if (ptext[t] == 'm' || ptext[t] == 'M')
					alph[12]++;
				else if (ptext[t] == 'n' || ptext[t] == 'N')
					alph[13]++;
				else if (ptext[t] == 'o' || ptext[t] == 'O')
					alph[14]++;
				else if (ptext[t] == 'p' || ptext[t] == 'P')
					alph[15]++;
				else if (ptext[t] == 'q' || ptext[t] == 'Q')
					alph[16]++;
				else if (ptext[t] == 'r' || ptext[t] == 'R')
					alph[17]++;
				else if (ptext[t] == 's' || ptext[t] == 'S')
					alph[18]++;
				else if (ptext[t] == 't' || ptext[t] == 'T')
					alph[19]++;
				else if (ptext[t] == 'u' || ptext[t] == 'U')
					alph[20]++;
				else if (ptext[t] == 'v' || ptext[t] == 'V')
					alph[21]++;
				else if (ptext[t] == 'w' || ptext[t] == 'W')
					alph[22]++;
				else if (ptext[t] == 'x' || ptext[t] == 'X')
					alph[23]++;
				else if (ptext[t] == 'y' || ptext[t] == 'Y')
					alph[24]++;
				else if (ptext[t] == 'z' || ptext[t] == 'Z')
					alph[25]++;
				else if (ptext[t] == ' ')
					alph[26]++;
				else if (ptext[t] == ';')
					alph[27]++;
				else if (ptext[t] == '.')
					alph[28]++;
				t++;
			}
			for (int i = 0; i < m[block]; i++) {
				if (ctext[u] == 'a' || ctext[u] == 'A')
					calph[0]++;
				else if (ctext[u] == 'b' || ctext[u] == 'B')
					calph[1]++;
				else if (ctext[u] == 'c' || ctext[u] == 'C')
					calph[2]++;
				else if (ctext[u] == 'd' || ctext[u] == 'D')
					calph[3]++;
				else if (ctext[u] == 'e' || ctext[u] == 'E')
					calph[4]++;
				else if (ctext[u] == 'f' || ctext[u] == 'F')
					calph[5]++;
				else if (ctext[u] == 'g' || ctext[u] == 'G')
					calph[6]++;
				else if (ctext[u] == 'h' || ctext[u] == 'H')
					calph[7]++;
				else if (ctext[u] == 'i' || ctext[u] == 'I')
					calph[8]++;
				else if (ctext[u] == 'j' || ctext[u] == 'J')
					calph[9]++;
				else if (ctext[u] == 'k' || ctext[u] == 'K')
					calph[10]++;
				else if (ctext[u] == 'l' || ctext[u] == 'L')
					calph[11]++;
				else if (ctext[u] == 'm' || ctext[u] == 'M')
					calph[12]++;
				else if (ctext[u] == 'n' || ctext[u] == 'N')
					calph[13]++;
				else if (ctext[u] == 'o' || ctext[u] == 'O')
					calph[14]++;
				else if (ctext[u] == 'p' || ctext[u] == 'P')
					calph[15]++;
				else if (ctext[u] == 'q' || ctext[u] == 'Q')
					calph[16]++;
				else if (ctext[u] == 'r' || ctext[u] == 'R')
					calph[17]++;
				else if (ctext[u] == 's' || ctext[u] == 'S')
					calph[18]++;
				else if (ctext[u] == 't' || ctext[u] == 'T')
					calph[19]++;
				else if (ctext[u] == 'u' || ctext[u] == 'U')
					calph[20]++;
				else if (ctext[u] == 'v' || ctext[u] == 'V')
					calph[21]++;
				else if (ctext[u] == 'w' || ctext[u] == 'W')
					calph[22]++;
				else if (ctext[u] == 'x' || ctext[u] == 'X')
					calph[23]++;
				else if (ctext[u] == 'y' || ctext[u] == 'Y')
					calph[24]++;
				else if (ctext[u] == 'z' || ctext[u] == 'Z')
					calph[25]++;
				else if (ctext[u] == ' ')
					calph[26]++;
				else if (ctext[u] == ';')
					calph[27]++;
				else if (ctext[u] == '.')
					calph[28]++;
				u++;
			}
			for (int j = 0; j < 29; j++) {																// if characters dont match, try for next block
				 if (alph[j] != calph[j]) {
					goto BLOOP;
				}
			}
		}
		if(block>0)
			fblock = m[block];																			// if characters match for a block
	}
	t = 0;
	temp1 = 0;
	temp2 = 0;
	count = ptext.length() / fblock;
	for (int i = 0; i < count; i++){																	// for every block in the ptext
		check = true;
		for (int j = 0; j < fblock; j++) {
			u = t + 1;
			temp = fblock - j;
			while (temp > 0) {																			// searching for a block with all different characters
				if (ptext[t] == ptext[u])
					check = false;
				temp--;
				u++;
			}
			t++;
		}
		if (check == true) {
			temp1 = t - fblock;																			// to start from the beginning of a block
			temp2 = i;
		}
	}
	t = temp1;
	memset(key, 0, sizeof(key));
	for (int i = 0; i < fblock; i++) {																	// finding the key for the block with different characters
		u = temp1;
		while (ctext[t] != ptext[u])
			u++;
		t++;
		u = u - (temp2 * fblock);																		// for the key to be in terms of the first block
		key[u] = t - (temp2 * fblock);
	}
	cout << "The block size is: " << fblock << endl;
	cout << "The key is: ";
	for (int j = 0; j < fblock; j++)
		cout << key[j] << " ";
	cout << endl;
}

int main() {
	string plaintext, cyphertext;
	cout << "***Program for known-plaintext attack on permutation cipher***" << endl << endl;
	LOOP:while (1) {
		cout << "Enter plaintext: ";																	// getting user input for ptext and ctext
		getline(cin, plaintext);
		cout << "Enter cyphertext: ";
		getline(cin, cyphertext);
		if (cyphertext.length() < plaintext.length()) {													// checking if padding is required
			cout << "Invalid inputs." << endl;
		}
		else if (plaintext.length() < cyphertext.length()) {
			cout << "Invalid inputs." << endl;
		}
		else
			kptattack(plaintext, cyphertext);
	}
		 return 0;
}