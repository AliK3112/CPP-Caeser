#include<iostream>
#include<fstream>
#include<string>
#include<string.h>

using namespace std;

bool isAlpha(char x)
{
	return (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z');
}

string encrypt(string input, int k)
{
	string value = "\0";
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (isAlpha(input[i]))
			value += ((input[i] + k) % 26) + 'A';
		else
			value += input[i];
	}
	return value;
}

string decrypt(string input, int k)
{
	string value = "\0";
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (isAlpha(input[i]))
			value += ((input[i] - k) % 26) + 'A';
		else
			value += input[i];
	}
	return value;
}

int main(int argc, char** argv)
{
	// Arguments
	// 1 - Input Filename
	// 2 - Output Filename
	// 3 - Value of k
	if (argc < 4) {
		cout << "Arguments\n1 - Input Filename\n2 - Output Filename\n3 - Value of k";
	}

	char *input = argv[1];
	char *output = argv[2];
	int k = -1;

	try {
		k = stoi(argv[3]);
	} 
	catch(exception e)
	{
		cout << "Invalid value of k\nProgram closing!\n";
		return 0;
	}

	// cout << "SUCCESS\n";

	// Opening file
	ifstream read(input, ios::in);
	if (!read.is_open()) {
		cout << "File not found!\nProgram closing!\n";
		return 0;
	}

	// Reading from file
	string inp = "\0";
	getline(read, inp);
	//cout << encrypt(inp, k) << endl;
	read.close();
	string out = encrypt(inp, k);

	// Write to file
	ofstream write(output, ios::out);
	write << out;
	write.close();

	// Testing
	if (inp.compare(decrypt(out, k)) == 0) {
		cout << "Encryption/Decryption successful" << endl;
	}
	return 0;
}