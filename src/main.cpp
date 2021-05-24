#include <iostream>
#include "marquee.h"

int main(int argc, char *argv[])
{
   Marquee marquee;

   marquee.Initialise();

   marquee.Test1();
   marquee.Test2();
   marquee.Test3();

   marquee.Cleanup();

   return 0;
}
