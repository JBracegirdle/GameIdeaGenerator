#include "GetViewType.h"

void GetGenres(const char* filename, vector<vector<string>> &vect) {

	// Initialise variables
	int index = 0;
	const char* delim = "|";

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
			// Iterate through file to find ** START TYPES ** discarding all lines previous
			string line;
			getline(f, line);
			if (line == "** START TYPES **") {
				// Once ** START TYPES ** found, iterate through all subsequent lines
				while (!f.eof()) {
					vect.push_back({});
					getline(f, line);
					size_t pos = 0;
					string token;
					string lineSplit[3];
					// For each line split Genres, Descriptions, Examples using delim |
					// storing each as a seperater element in a vector
					for (int i = 0; i < 3; i++) {
						pos = line.find(delim);
						token = line.substr(0, pos);
						line.erase(0, pos + 1);
						vect[index].push_back(token);
					}
					index++;
					cout << "[INFO]  " << size(vect)-1 << " Genres populated!" << '\r';
				}
			}
		}
	}
	cout << endl;
}