#include "GetName.h"

void GetName(const char* filename, vector<string> &vect) {

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
			// Iterate through file to find ** START NAMES ** discarding all lines previous
			string line;
			getline(f, line);
			if (line == "** START NAMES **") {
				// Once ** START NAMES ** found, iterate through all subsequent lines
				while (!f.eof()) {
					getline(f, line);
					vect.push_back(line);
				}
				cout << "[INFO]  " << size(vect)-1 << " Names populated!" << '\r';
			}
		}
	}
	cout << endl;
}