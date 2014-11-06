#include "Plugboard.h"

Plugboard::Plugboard(char* input_file)
{
	file_name = input_file;
	
	ifstream plugboard_file(file_name, ios::in);
	int number_from_file;

	if (plugboard_file) {
		while (plugboard_file >> number_from_file) {
			plugboard_numbers.push_back(number_from_file);
		}
	} else {
		cerr << "Plugboard File not open" << endl;
		exit(1);
	}
	plugboard_file.close();

	initialize_arrays();
	update_vectors();
}

//Public method that is used to return paired value of the input character.
char Plugboard::execute(char input_char)
{
	return pairing[(input_char - VALUE_OF_A)];
}

//Private method to initialize array that is used later.
void Plugboard::initialize_arrays()
{
	for (int i = 0; i < NUM_OF_ALPHABETS; i++) {
		pairing.push_back(i + VALUE_OF_A);
	}
}

//Private method that carries out the pairing between the characters.
void Plugboard::update_vectors()
{
	for (int i = 0; i < plugboard_numbers.size(); i += 2) {
		swap_for_entry(plugboard_numbers[i], plugboard_numbers[i + 1]);
	} 
}

//Private helper method that swaps the element at the two given index.
void Plugboard::swap_for_entry(int index1, int index2) 
{
  swap(pairing[index1], pairing[index2]);
}
