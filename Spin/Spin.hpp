//
// Created by solidangle on 10/22/18.
//

class Spin{
    double x;
    double y;
    double z;
public:
    Spin(double x_, double y_, double z_){x = x_; y = y_; z = z_;};
    Spin(){};
    double getX(){return x;};
    double getY(){return y;};
    double getZ(){return z;};
    void print_spin(){std::cout << getX() << ", " << getY() << ", " << getZ() << std::endl;};
};
