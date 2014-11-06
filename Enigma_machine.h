#ifndef ENIGMA_MACHINE_R
#define ENIGMA_MACHINE_R

#include "Reflector.h"
#include "Plugboard.h"
#include "Rotor.h"

class Enigma_machine
{
	public:
		Enigma_machine(int argc, char **&argv);
		char encrypt(char ch);
		~Enigma_machine();
	
	private:
	Plugboard* plugboard;
	Reflector reflector;
	Rotor** rotors;
	int number_of_rotors;

};

#endif
