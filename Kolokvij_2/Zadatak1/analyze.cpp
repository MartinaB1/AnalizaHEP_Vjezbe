#include"Analyzer.h"

int main(void){

Analyzer *analyzer = new Analyzer();
cout << "max lambda = " << analyzer -> lambda_max(50,0.6) << endl;
analyzer -> ~Analyzer();

return 0;
}