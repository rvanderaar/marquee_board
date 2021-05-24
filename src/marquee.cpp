#include "marquee.h"
#include <pigpiod_if2.h>
#include <iostream>
#include <thread>
#include "matrix.h"

using namespace std;

Marquee::Marquee(){
    clk_ =	14;
    data_0_ = 15;
    data_1_ = 18;
    data_2_ = 23;
    data_3_ = 24;
    data_4_ = 25;
    data_5_ = 8;
    data_6_ = 7;
}

Marquee::~Marquee(){

}

bool Marquee::Initialise(){
    // Connect to local Pi.
    pi_gpio_ = pigpio_start(0, 0); 

    if(pi_gpio_ < 0)
    {
        cout << "Can't connect to pi gpio daemon" << endl;
        return false;
    }

    set_mode(pi_gpio_, clk_, PI_OUTPUT);
    set_mode(pi_gpio_, data_0_, PI_OUTPUT);
    set_mode(pi_gpio_, data_1_, PI_OUTPUT);
    set_mode(pi_gpio_, data_2_, PI_OUTPUT);
    set_mode(pi_gpio_, data_3_, PI_OUTPUT);
    set_mode(pi_gpio_, data_4_, PI_OUTPUT);
    set_mode(pi_gpio_, data_5_, PI_OUTPUT);
    set_mode(pi_gpio_, data_6_, PI_OUTPUT);
    set_pull_up_down(pi_gpio_, clk_, PI_PUD_OFF); 
    set_pull_up_down(pi_gpio_, data_0_, PI_PUD_OFF); 
    set_pull_up_down(pi_gpio_, data_1_, PI_PUD_OFF); 
    set_pull_up_down(pi_gpio_, data_2_, PI_PUD_OFF); 
    set_pull_up_down(pi_gpio_, data_3_, PI_PUD_OFF); 
    set_pull_up_down(pi_gpio_, data_4_, PI_PUD_OFF); 
    set_pull_up_down(pi_gpio_, data_5_, PI_PUD_OFF); 
    set_pull_up_down(pi_gpio_, data_6_, PI_PUD_OFF);

    return true;
}

void Marquee::Cleanup(){
    // Disconnect from local Pi.
    pigpio_stop(pi_gpio_); 
}

void Marquee::Test1(){
    int val = 0;

    for(int i=0; i <= 48; i++)
    {
        if(i % 24 == 0) val = 0;
        else val = 1;

        gpio_write(pi_gpio_, clk_, 1);  // On
        gpio_write(pi_gpio_, data_0_, val);
        gpio_write(pi_gpio_, data_1_, val);
        gpio_write(pi_gpio_, data_2_, val);
        gpio_write(pi_gpio_, data_3_, val);
        gpio_write(pi_gpio_, data_4_, val);
        gpio_write(pi_gpio_, data_5_, val);
        gpio_write(pi_gpio_, data_6_, val);

        this_thread::sleep_for(50ms);
        gpio_write(pi_gpio_, clk_, 0);	  // Off
        this_thread::sleep_for(50ms);
    }
}

void Marquee::Test2(){
    int val = 0;

    val = 0;
    gpio_write(pi_gpio_, data_0_, val);
    gpio_write(pi_gpio_, data_1_, val);
    gpio_write(pi_gpio_, data_2_, val);
    gpio_write(pi_gpio_, data_3_, val);
    gpio_write(pi_gpio_, data_4_, val);
    gpio_write(pi_gpio_, data_5_, val);
    gpio_write(pi_gpio_, data_6_, val);

    for(int i=0; i <= 24; i++)
    {
        gpio_write(pi_gpio_, clk_, 0);	  // Off
        this_thread::sleep_for(10us);
        gpio_write(pi_gpio_, clk_, 1);  // On
        this_thread::sleep_for(10us);
    }

    this_thread::sleep_for(1s);

    val = 1;
    gpio_write(pi_gpio_, data_0_, val);
    gpio_write(pi_gpio_, data_1_, val);
    gpio_write(pi_gpio_, data_2_, val);
    gpio_write(pi_gpio_, data_3_, val);
    gpio_write(pi_gpio_, data_4_, val);
    gpio_write(pi_gpio_, data_5_, val);
    gpio_write(pi_gpio_, data_6_, val);

    for(int i=0; i <= 24; i++)
    {
        this_thread::sleep_for(10us);
        gpio_write(pi_gpio_, clk_, 0);	  // Off
        this_thread::sleep_for(10us);
        gpio_write(pi_gpio_, clk_, 1);  // On
    }
    this_thread::sleep_for(1s);
}

void Marquee::Test3(){
    int val = 0;

    std::vector<std::vector<bool>> letter_a {
        { 1,1,1,1,1,1,0},
        { 0,0,0,1,0,0,1},
        { 0,0,0,1,0,0,1},
        { 1,1,1,1,1,1,0},
        { 0,0,0,0,0,0,0}
    };
    std::vector<std::vector<bool>> letter_m {
        { 1,1,1,1,1,1,1},
        { 0,0,0,0,0,0,1},
        { 1,1,1,1,1,1,0},
        { 0,0,0,0,0,0,1},
        { 1,1,1,1,1,1,0},
        { 0,0,0,0,0,0,0}
    };
    std::vector<std::vector<bool>> letter_n {
        { 1,1,1,1,1,1,1},
        { 0,0,0,0,0,0,1},
        { 1,1,1,1,1,1,0},
        { 0,0,0,0,0,0,0}
    };
    std::vector<std::vector<bool>> letter_o {
        { 0,1,1,1,1,1,0},
        { 1,0,0,0,0,0,1},
        { 0,1,1,1,1,1,0},
        { 0,0,0,0,0,0,0}
    };
   std::vector<std::vector<bool>> letter_r {
        { 1,1,1,1,1,1,1},
        { 0,0,0,1,0,0,1},
        { 0,0,0,1,0,0,1},
        { 1,1,1,0,1,1,0},
        { 0,0,0,0,0,0,0}
    };

    std::vector<std::vector<bool>> letters;

    letters.insert(letters.end(), letter_r.begin(), letter_r.end());
    letters.insert(letters.end(), letter_a.begin(), letter_a.end());
    letters.insert(letters.end(), letter_m.begin(), letter_m.end());
    letters.insert(letters.end(), letter_o.begin(), letter_o.end());
    letters.insert(letters.end(), letter_n.begin(), letter_n.end());

    val = 0;
    for(int i=letters.size()-1; i >= 0; i--)
    {
        gpio_write(pi_gpio_, data_0_, !letters[i][6]);
        gpio_write(pi_gpio_, data_1_, !letters[i][5]);
        gpio_write(pi_gpio_, data_2_, !letters[i][4]);
        gpio_write(pi_gpio_, data_3_, !letters[i][3]);
        gpio_write(pi_gpio_, data_4_, !letters[i][2]);
        gpio_write(pi_gpio_, data_5_, !letters[i][1]);
        gpio_write(pi_gpio_, data_6_, !letters[i][0]);
  
        gpio_write(pi_gpio_, clk_, 0);	  // Off
        this_thread::sleep_for(10us);
        gpio_write(pi_gpio_, clk_, 1);  // On
        this_thread::sleep_for(10us);
    }

}
