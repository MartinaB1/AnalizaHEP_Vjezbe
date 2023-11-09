#include "ElementaryParticle.h"
#include <iostream>
#include <math.h>
using namespace std;

class ElementaryParticle {
  public:             // Access specifier
    string PartName;
    double Mass;
    bool Boson;
    double P[4];
    ElementaryParticle(string x, double y, bool z) { // Constructor with parameters
      PartName = x;
      Mass = y;
      Boson = z;
    }


     void value (double a,double b, double c){
        double E=sqrt(Mass*Mass+pow(sqrt(a*a+b*b+c*c),2));
        P[0]=E;P[1]=a;P[2]=b;P[3]=c;
    }
    void transverzal (){
        cout << "Transverzal momentum: "<< sqrt(P[1]*P[1]+P[2]*P[2]) <<"\n";
    }

    void printInfo(){
        cout << "Name of the particle: " << PartName << "\nMass of the particle: " << Mass << "\nIs it a boson:  " << Boson<<"\nFourvector:  ";
        for(int i =0;i<4;i++)
            cout<<P[i]<<", ";
        cout<<"\n";
    }
};

