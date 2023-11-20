#include <iostream>
#include <fstream>
#include "ElementaryParticle.cpp"
#include "ElementaryParticle.h"

using namespace std;


int main()
{
    //create an object
    ElementaryParticle *decayParticle_1, *decayParticle_2, *higgs ;
    srand((unsigned) time(NULL));

    higgs= new ElementaryParticle("Higgs boson", 125, true);
    decayParticle_1 = new ElementaryParticle();
    decayParticle_2 = new ElementaryParticle();

    higgs->value(-100+rand()%201,-100+rand()%201,-100+rand()%201);
    higgs->bosonDecay(decayParticle_1, decayParticle_2);
    higgs->printInfo();
    decayParticle_1->printInfo();
    decayParticle_2->printInfo();

}