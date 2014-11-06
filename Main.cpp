#include <stdexcept>
#include <iostream>
#include <assert.h>
#include "Enigma_machine.h"
#include "EnigmaParts.h"

using namespace std;

int main(int argc, char **argv)
{
	assert (argc >= 2);

	Enigma_machine enigma_machine(argc, argv);

	char input;
	while (cin >> ws >> input) {
	assert(input >= A_CHAR && input <= Z_CHAR);

		cout << enigma_machine.encrypt(input);
	}

  return 0;
}
