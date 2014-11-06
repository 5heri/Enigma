#include "Reflector.h"

//Return the output value from the reflection formula.
char Reflector::reflect(char alphabet)
{
  return (((alphabet - VALUE_OF_A) + 13) % 26) + VALUE_OF_A;
}
