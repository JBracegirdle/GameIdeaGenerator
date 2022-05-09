#include "GetPersonalityTrait.h"

void GetPersonalityTrait(const char* filename, vector<string> &vect) {

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
			// Iterate through file to find ** START TRAITS ** discarding all lines previous
			string line;
			getline(f, line);
			if (line == "** START TRAITS **") {
				// Once ** START TRAITS ** found, iterate through all subsequent lines
				while (!f.eof()) {
					getline(f, line);
					vect.push_back(line);
				}
				cout << "[INFO]  " << size(vect) - 1 << " Personality traits populated!" << '\r';
			}
		}
	}
	cout << endl;
}