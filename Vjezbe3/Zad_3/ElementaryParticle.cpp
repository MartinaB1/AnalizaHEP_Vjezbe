#include "ElementaryParticle.h"
#include <iostream>
#include <math.h>
#include<cmath>
#include <cstdlib> 
#include <bits/stdc++.h>
using namespace std;

class ElementaryParticle {
  public:             // Access specifier
    string PartName;
    double Mass;
    bool Boson;
    double px, py, pz, E;

    ElementaryParticle(){ //override constructor
        PartName = " ";
        Mass = 0;
        Boson = true;
    }
    ElementaryParticle(string x, double y, bool z) { // Constructor with parameters
        PartName = x;
        Mass = y;
        Boson = z;
    }

    void value (double _px,double _py, double _pz){
        px=_px; py=_py; pz=_pz;
        E=sqrt(Mass*Mass+pow(sqrt(_px*_px+_py*_py+_pz*_pz),2));
    }

    void transverzal (){
        cout << "Transverzal momentum: "<< sqrt(px*px+py*py) <<"\n";
    }

    void printInfo(){
        cout << "Name of the particle: " << PartName << "\nMass of the particle: " << Mass << "\nIs it a boson:  " << Boson<<"\nFourvector:  "<< E<< ", "<<px<< ", "<<py<< ", "<<pz<<"\n\n";
    }

    void SetVariables(string x, double y, bool z){
        PartName = x;
        Mass = y;
        Boson = z;
    }

    void bosonDecay(ElementaryParticle *A, ElementaryParticle *B){
        if(this->Boson == false)
            cout << "Not possible";
        else{
            int a = rand()%1001;

            if(a<=214){
                A->SetVariables("W+",80.4,true);
                B->SetVariables("W-",80.4,true);
            }
            else if (a > 214 && a<=278){
                A->SetVariables("tau+",1.78,false);
                B->SetVariables("tau-",1.78,false);
            }
            else if (a> 278 && a<=304){
                A->SetVariables("Z",91.2,true);
                B->SetVariables("Z",91.2,true);
            }
            else{
                A->SetVariables("b_quark",4.18,false);
                B->SetVariables("b_quark",4.18,false);
            }

            B->value(-150+rand()%301,-150+rand()%301,-150+rand()%301); // not stated in exercise but constrain components to a reasonable range
            A->value(this->px - B->px, this->py - B->py, this->pz - B->pz);
        }
    }
      
};
