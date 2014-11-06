CPPC = g++
CPPFLAGS = -Wall -pedantic -O3 -c

all: enigma

.PHONY: all

enigma: Main.o Reflector.o Plugboard.o Rotor.o Enigma_machine.o
	$(CPPC) $^ -o enigma 

Main.o: Main.cpp EnigmaParts.h
	$(CPPC) $(CPPFLAGS) $^

Reflector.o: Reflector.cpp Reflector.h EnigmaParts.h
	$(CPPC) $(CPPFLAGS) $^

Plugboard.o: Plugboard.cpp Plugboard.h EnigmaParts.h

Rotor.o: Rotor.cpp Rotor.h EnigmaParts.h
	$(CPPC) $(CPPFLAGS) $^

Enigma_machine.o: Enigma_machine.cpp Enigma_machine.h
clean:
	rm -rf enigma *.o *.gch

.PHONY: clean
