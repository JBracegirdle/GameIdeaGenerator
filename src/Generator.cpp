#include "GetCreature.h"
#include "GetEmotion.h"
#include "GetGenre.h"
#include "GetName.h"
#include "GetPersonalityTrait.h"
#include "GetViewType.h"
#include <random>

int main() {

	//							//
	//		INITIALISATION		//
	//							//

	// Define file path to lists
	const char* creaturefilename = "config/Creatures.txt";
	const char* emotionfilename = "config/Emotions.txt";
	const char* genrefilename = "config/Genres.txt";
	const char* namefilename = "config/Names.txt";
	const char* traitfilename = "config/PersonalityTraits.txt";
	const char* twodsubfilename = "config/2DSubtypes.txt";
	const char* threedsubfilename = "config/3DSubtypes.txt";

	// Define genre info variables
	int genreIndex;
	string genreTitle;
	string genreDesc;
	string genreEx;

	// Define 2nd genre info variables
	int genreIndex2;
	string genreTitle2;
	string genreDesc2;
	string genreEx2;

	// Define 2D/3D variable
	string twoDThreeD;

	// Define Name variables
	int nameIndex;
	string name;

	// Define personality variables
	int traitIndex;
	vector<string> traits = {};

	// Define emotion variables
	int emotionIndex;
	string emotion;

	// Define Creature variables
	int creatureIndex;
	string creature;

	// Initialise PRNG
	random_device rd; // Obtain a random number from hardware
	mt19937 gen(rd()); // Seed the generator

	// Initialise vector of names
	vector<string> namevect = {};
	GetName(namefilename, namevect);
	cout << "[INFO]  Names loaded!" << endl << endl;

	// Initialise vector of personality traits
	vector<string> traitvect = {};
	GetPersonalityTrait(traitfilename, traitvect);
	cout << "[INFO]  Personality Traits loaded!" << endl << endl;

	// Initialise vector of emotions
	vector<string> emotionvect = {};
	GetEmotion(emotionfilename, emotionvect);
	cout << "[INFO]  Emotions loaded!" << endl << endl;

	// Initialise vector of creatures
	vector<string> creaturevect = {};
	GetCreature(creaturefilename, creaturevect);
	cout << "[INFO]  Creatures loaded!" << endl << endl;

	// Initialise 2d vector of genres
	vector<vector<string>> genrevect = { {} };
	GetGenre(genrefilename, genrevect);
	cout << "[INFO]  Genres loaded!" << endl << endl;

	//					//
	//		GENRES		//
	//					//

	// Choose a random genre from 2d vector
	uniform_int_distribution<> distrgenre(0, size(genrevect)-1); // Define the range - starting index of vect (0) to last index of vect
	genreIndex = distrgenre(gen); // Generate random index

	// Store chosen genre details in variables
	genreTitle = genrevect[genreIndex][0];
	genreDesc = genrevect[genreIndex][1];
	genreEx = genrevect[genreIndex][2];

	//						//
	//		2ND GENRE		//
	//						//

	// Choose a random genre from 2d vector ensuring different to 1st
	int tempIndex = distrgenre(gen);
	while (tempIndex == genreIndex) {
		tempIndex = distrgenre(gen);
	}
	genreIndex2 = tempIndex;

	// Store chosen genre details in variables
	genreTitle2 = genrevect[genreIndex2][0];
	genreDesc2 = genrevect[genreIndex2][1];
	genreEx2 = genrevect[genreIndex2][2];

	//					//
	//		2D/3D		//
	//					//

	// Choose between 2D/3D at random
	uniform_int_distribution<> distr2d(1, 2); // Define the range - starting index of vect (0) to last index of vect
	if (distr2d(gen) == 1) { // Generate random and store in variable
		twoDThreeD = "2D";
	}
	else {
		twoDThreeD = "3D";
	}

	//					//
	//		NAME		//
	//					//

	// Choose a random name from vector
	uniform_int_distribution<> distrname(0, size(namevect) - 1); // Define the range - starting index of vect (0) to last index of vect
	nameIndex = distrname(gen); // Generate random index

	// Store chosen genre details in variables
	name = namevect[nameIndex];

	//						//
	//		PERSONALITY		//
	//						//

	// Construct vector of 3 randomly generated traits 
	uniform_int_distribution<> distrtrait(0, size(traitvect) - 1);
	string prevTrait = "";
	string currTrait;
	for (int i = 0; i < 4; i++) {
		do
		{
			currTrait = traitvect[distrtrait(gen)];
		} while (prevTrait == currTrait);
		traits.push_back(currTrait);
		prevTrait = currTrait;
	}

	//						//
	//		EMOTIONS		//
	//						//

	// Choose a random emotion from vector
	uniform_int_distribution<> distremotion(0, size(emotionvect) - 1); // Define the range - starting index of vect (0) to last index of vect
	emotionIndex = distremotion(gen); // Generate random index

	// Store chosen genre details in variables
	emotion = emotionvect[emotionIndex];

	//						//
	//		CREATURE		//
	//						//

	// Choose a random creature from vector
	uniform_int_distribution<> distrcreature(0, size(creaturevect) - 1); // Define the range - starting index of vect (0) to last index of vect
	creatureIndex = distrcreature(gen); // Generate random index

	// Store chosen genre details in variables
	creature = creaturevect[creatureIndex];

	//						//
	//		OBJECTIVE		//
	//						//

	//					//
	//		OUTPUTS		//
	//					//

	// Output 1st genre to console
	cout << "[INFO]  1st Genre chosen: " << genreTitle << "!" << endl;
	// Output 2nd genre to console
	cout << "[INFO]  2nd Genre chosen: " << genreTitle2 << "!" << endl << endl;

	// Output 2D/3D to console
	cout << "[INFO]  2D/3D chosen: " << twoDThreeD << "!" << endl << endl;

	// Output name to console
	cout << "[INFO]  Name chosen: " << name << "!" << endl << endl;

	// Output personality traits to console
	for (int i = 0; i < size(traits) - 1; i++) {
		string pos = "";
		switch (i)
		{
		case 0:
			pos = "First";
			break;
		case 1:
			pos = "Second";
			break;
		default:
			pos = "Third";
			break;
		}
		cout << "[INFO]  " << pos << " personality trait chosen: " << traits[i] << "!" << endl;
	};
	cout << endl;
	
	// Output emotion to console
	cout << "[INFO]  Emotion chosen: " << emotion << "!" << endl << endl;

	// Output creature to console
	cout << "[INFO]  Creature chosen: " << creature << "!" << endl << endl;

	// Pause
	getchar();
}