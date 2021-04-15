#include "Noise.h"

#include <iostream>

Noise::Noise(std::string sim) :SoundIMake(sim)
{
  std::cout << "Constructing Noise " << SoundIMake << std::endl;
}


Noise::~Noise(void)
{
  std::cout << "Destructing Noise " << SoundIMake << std::endl;
}
