#include "Rotor.h"

Rotor::Rotor(char* input_file)
{
	rotations = 0;
	file_name = input_file;

	ifstream rotor_file(file_name, ios::in);
	int number_from_file;

	if (rotor_file) {
		while (rotor_file >> number_from_file) {
			rotor_numbers.push_back(number_from_file);
		}
	} else {
		cerr << "Rotor File not open" << endl;
		exit(1);
	}
	rotor_file.close();
}

//Calculating offset between the number of rotations and returning value from
//rotor_numbers with correct offset.
char Rotor::entering(char in_char)
{
	int value = (in_char - VALUE_OF_A);
	value = (value + rotations) % NUM_OF_ALPHABETS;
	value = (NUM_OF_ALPHABETS + rotor_numbers[value] - rotations);
	return value % NUM_OF_ALPHABETS + VALUE_OF_A;
}

//Populate map with appropriate key to values and return correct character 
//according to the input character.
char Rotor::leaving(char out_char)
{
	map_rotor.clear();	

	for (int i = 0; i < NUM_OF_ALPHABETS; i++) {
		char tmp = entering(VALUE_OF_A + i);
		map_rotor[tmp] = VALUE_OF_A + i;
	}
	return map_rotor[out_char];
}

int Rotor::get_rotations()
{
	return (rotations % NUM_OF_ALPHABETS);
}

void Rotor::inc_rotations()
{
	rotations = (rotations + 1) % NUM_OF_ALPHABETS;
}

