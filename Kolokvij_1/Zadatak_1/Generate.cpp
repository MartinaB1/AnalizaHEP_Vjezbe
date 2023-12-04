#include <Generator.h>

int main()
{
  // Declare 
  Generator *generator;

  generator = new Generator ();

  generator -> GeneratePDF ();

  generator->~Generator();

  return 0;
}