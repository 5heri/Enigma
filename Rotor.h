#ifndef ROTOR_H
#define ROTOR_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include "EnigmaParts.h"

using namespace std;

class Rotor
{
	public:
		Rotor(char* input_file);
		char entering(char in_char);
		char leaving(char out_char);
		int get_rotations();
		void inc_rotations();
		
	private:
		char* file_name;
		vector<int> rotor_numbers;
		int rotations;
		map<char, char> map_rotor; 
};

#endif
