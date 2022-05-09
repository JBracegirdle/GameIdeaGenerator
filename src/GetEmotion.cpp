#include "GetEmotion.h"

void GetEmotion(const char* filename, vector<string> &vect) {

	// Open file
	fstream f;
	f.open(filename, ios::in);

	// Check file has been opened
	if (!f.is_open()) {
		cerr << "[ERROR] File " << filename << " does not exist!" << endl;
		terminate;
	}
	else {
		cout << "[INFO]  Reading " << filename << "!" << endl;
		while (!f.eof()) {
			// Iterate through file to find ** START EMOTIONS ** discarding all lines previous
			string line;
			getline(f, line);
			if (line == "** START EMOTIONS **") {
				// Once ** START EMOTIONS ** found, iterate through all subsequent lines
				while (!f.eof()) {
					getline(f, line);
					vect.push_back(line);
				}
				cout << "[INFO]  " << size(vect) - 1 << " Emotions populated!" << '\r';
			}
		}
	}
	cout << endl;
}