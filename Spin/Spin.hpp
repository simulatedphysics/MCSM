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
    double get_x(){return x;};
    double get_y(){return y;};
    double get_z(){return z;};
    double dot(Spin &second_spin){return x*second_spin.get_x() + y*second_spin.get_y() + z*second_spin.get_z();};
    Spin operator-(Spin & second_spin){return Spin(x-second_spin.get_x(), y-second_spin.get_y(), z-second_spin.get_z());};
    void print_spin(){std::cout << get_x() << ", " << get_y() << ", " << get_z() << std::endl;};
};
