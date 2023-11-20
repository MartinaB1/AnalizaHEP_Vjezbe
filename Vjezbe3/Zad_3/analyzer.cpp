#include <iostream>
#include <fstream>
#include "ElementaryParticle.cpp"
#include "ElementaryParticle.h"

using namespace std;


int main()
{
     ofstream myfile;
    myfile.open ("Analysis.txt");
    myfile << "DecayParticle1_Name DecayParticle1_Boson DecayParticle1_mass DecayParticle1_E DecayParticle1_px DecayParticle1_py DecayParticle1_pz"<<" "
         << "DecayParticle2_Name DecayParticle2_Boson DecayParticle2_mass DecayParticle2_E DecayParticle2_px DecayParticle2_py DecayParticle2_pz" << endl;
    //create an object
    ElementaryParticle *decayParticle_1, *decayParticle_2, *Higgs ;
    srand((unsigned) time(NULL));

    for(int i=1;i<=10000;i++)
    {
        Higgs = new ElementaryParticle("Higgs boson",125,1);
        Higgs->value(-100+rand()%201,-100+rand()%201,-100+rand()%201);
        decayParticle_1 = new ElementaryParticle();
        decayParticle_2 = new ElementaryParticle();
        Higgs->bosonDecay(decayParticle_1,decayParticle_2);
        myfile << decayParticle_1->PartName<<" "<<decayParticle_1->Boson<<" "<<decayParticle_1->Mass<<" "<<decayParticle_1->E
           <<" "<<decayParticle_1->px<<" "<<decayParticle_1->py<<" "<<decayParticle_1->pz<<" "
           <<decayParticle_2->PartName<<" "<<decayParticle_2->Boson<<" "<<decayParticle_2->Mass<<" "<<decayParticle_2->E
           <<" "<<decayParticle_2->px<<" "<<decayParticle_2->py<<" "<<decayParticle_2->pz<<endl;
    }

   myfile.close();
}