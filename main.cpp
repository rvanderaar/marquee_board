#include <stdio.h>
#include <pigpiod_if2.h>
#include <unistd.h>

#define	CLK	14
#define O0	15
#define O1	18
#define O2	23
#define O3	24
#define O4	25
#define O5	8
#define O6	7


int main(int argc, char *argv[])
{
   int i;
   int val = 1;
   int pi;

   pi = pigpio_start(0, 0); /* Connect to local Pi. */

   if (pi < 0)
   {
      printf("Can't connect to pigpio daemon\n");
      return 1;
   }

   set_mode(pi, CLK, PI_OUTPUT);
   set_mode(pi, O0, PI_OUTPUT);
   set_mode(pi, O1, PI_OUTPUT);
   set_mode(pi, O2, PI_OUTPUT);
   set_mode(pi, O3, PI_OUTPUT);
   set_mode(pi, O4, PI_OUTPUT);
   set_mode(pi, O5, PI_OUTPUT);
   set_mode(pi, O6, PI_OUTPUT);
   set_pull_up_down(pi, CLK, PI_PUD_UP); 
   set_pull_up_down(pi, O0, PI_PUD_UP); 
   set_pull_up_down(pi, O1, PI_PUD_UP); 
   set_pull_up_down(pi, O2, PI_PUD_UP); 
   set_pull_up_down(pi, O3, PI_PUD_UP); 
   set_pull_up_down(pi, O4, PI_PUD_UP); 
   set_pull_up_down(pi, O5, PI_PUD_UP); 
   set_pull_up_down(pi, O6, PI_PUD_UP); 

   while (true)
   {
      if(i == 0) val = 0;
      else val = 1;

      gpio_write(pi, CLK, 1);  // On
      gpio_write(pi, O0, val);
      gpio_write(pi, O1, val);
      gpio_write(pi, O2, val);
      gpio_write(pi, O3, val);
      gpio_write(pi, O4, val);
      gpio_write(pi, O5, val);
      gpio_write(pi, O6, val);

      usleep(50000); // ms
      gpio_write(pi, CLK, 0);	  // Off
      usleep(50000);

      i++;
      i %= 24;
   }

   pigpio_stop(pi); /* Disconnect from local Pi. */
   
   return 0;
}
