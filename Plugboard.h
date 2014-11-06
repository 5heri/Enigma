#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "EnigmaParts.h"

using namespace std;

class Plugboard
{
	public:
		Plugboard(char* input_file);
		char execute(char input_char);

	private:
		vector<char> pairing;
		vector<int> plugboard_numbers;
		char* file_name;
		void swap_for_entry(int index1, int index2);
		void initialize_arrays();
		void update_vectors();
};

#endif
