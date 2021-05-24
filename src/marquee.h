

class Marquee
{
public:
    Marquee();
    virtual ~Marquee();

    bool Initialise();
    void Cleanup();

    void Test1();
    void Test2();
    void Test3();
private:
    int pi_gpio_;

    int clk_;
    int data_0_;
    int data_1_;
    int data_2_;
    int data_3_;
    int data_4_;
    int data_5_;
    int data_6_;
};
