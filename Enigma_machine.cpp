#include "Enigma_machine.h"  

Enigma_machine::Enigma_machine(int argc, char **&argv)
{
	number_of_rotors = argc - 2;

	rotors = new Rotor*[number_of_rotors];
	for (int i = 0; i < number_of_rotors; i++) {
		rotors[i] = new Rotor(argv[i + 1]);
	}
 
	plugboard = new Plugboard(argv[argc - 1]);
}

Enigma_machine::~Enigma_machine()
{
	if (plugboard != NULL) {
		delete plugboard;
	}

	for (int i = 0; i < number_of_rotors; i++) {
		delete rotors[i];
  }
 
	 delete[] rotors;
}

char Enigma_machine::encrypt(char ch)
{
	//Character going through plugboard (forwards)
	ch = plugboard->execute(ch);

	// Character going through all rotors (forwards)
	for (int i = 0; i < number_of_rotors; i++) {
		ch = rotors[i]->entering(ch);
	}

	//Character going through reflector 
	ch = reflector.reflect(ch);
	
	//Character returning after reflecting and going through rotors (backwards)
	for (int i = number_of_rotors - 1; i >= 0; i--) {
		ch = rotors[i]->leaving(ch);
	}

	//Character returning and entering plugboard to get correct mapping (backwards)
	ch = plugboard->execute(ch);
	
	//Increments the number of rotations in the appropriate rotors
	if (number_of_rotors > 0) {
	
		int first_rotor = 0;
		rotors[first_rotor]->inc_rotations();
		
		for (int i = 1; i < number_of_rotors; i++) {
			if ((rotors[i - 1]->get_rotations() == 0) 
				&& (rotors[0]->get_rotations()) == 0) {
				rotors[i]->inc_rotations();
			}
		} 
	}
	return ch;
}
