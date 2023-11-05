#include "ElementaryParticle.h"
#include <iostream>
using namespace std;

class ElementaryParticle {
  public:             // Access specifier
    string PartName;
    double Mass;
    bool Boson;
    ElementaryParticle(string x, double y, bool z) { // Constructor with parameters
      PartName = x;
      Mass = y;
      Boson = z;
    }

    void printInfo(){
        cout << "Name of the particle: " << PartName << "\nMass of the particle: " << Mass << "\nIs it a boson:  " << Boson << "\n\n";
    }
};

