#include <iostream>
#include "ElementaryParticle.cpp"

using namespace std;


int main()
{
    //create an object
    ElementaryParticle higgs("Higgs boson", 125, true);
    ElementaryParticle topq("Top Quark", 173.2, false);

    //print the property
    higgs.value(10,11,12);
    higgs.printInfo();
    higgs.transverzal();
    //topq.printInfo();

    //ElementaryParticle *Z= new ElementaryParticle("Z boson", 91.2, true);
    //Z->value(4,5,6);
    //Z->printInfo();
}

