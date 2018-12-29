#include <iostream>
#include <armadillo>
//#include "Model/Heisenberg.hpp"
#include "Algorithm/MonteCarlo.hpp"
#include "Lattice/Square.hpp"
#include "Lattice/Lattice.hpp"
#include <random>
#include <bits/unique_ptr.h>
#include "Model/Ising.hpp"
#include <memory>
#include <cmath>
#include "Plot/MagneticStatePlot.cpp"


using namespace arma;

int main(int argc, char **argv) {
    std::cout << "Phys-sym v. 0.0" << std::endl;
    std::cout << "Simulation software" << std::endl << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl << std::endl;

    std::cout << "Generating Ising model..." << std::endl;
    std::unique_ptr<Model> ising_model_ptr(new Ising(16));

    std::cout << "Generating Monte Carlo algorithm..." << std::endl;
    std::unique_ptr<Algorithm> alg(new MonteCarlo);

    const int n_itr(10);
    alg->simulate(n_itr, ising_model_ptr, 1.0);

//    std::map<std::string, void (*)(void)> demos;
//
//    demos["basic"]                  = demo_basic;
//    demos["binary"]                 = demo_binary;
//    demos["tmpfile"]                = demo_tmpfile;
//    demos["png"]                    = demo_png;
//    demos["vectors"]                = demo_vectors;
//    demos["script_inline_text"]     = demo_inline_text;
//    demos["script_inline_binary"]   = demo_inline_binary;
//    demos["script_external_text"]   = demo_external_text;
//    demos["script_external_binary"] = demo_external_binary;
//    demos["animation"]              = demo_animation;
//    demos["nan"]                    = demo_NaN;
//    demos["segments"]               = demo_segments;
//    demos["image"]                  = demo_image;

//    if(argc < 2) {
//        printf("Usage: %s <demo_name>\n", argv[0]);
//        printf("Choose one of the following demos:\n");
//        typedef std::pair<std::string, void (*)(void)> demo_pair;
//        BOOST_FOREACH(const demo_pair &pair, demos) {
//                        printf("    %s\n", pair.first.c_str());
//                    }
//        return 0;
//    }
//
//    std::string arg(argv[1]);
//    if(!demos.count(arg)) {
//        printf("No such demo '%s'\n", arg.c_str());
//        return 1;
//    }
//
//    demos[arg]();

    demo_basic(ising_model_ptr);

//    for(int i = 0; i < 4; i++)
//        gp << std::string("set arrow ") + std::to_string(i) + " from " + "0," + std::to_string(i) + " to 3," + std::to_string(i) + " nohead ls 1\n";

    std::string lin("set arrow 1 from +3,0 to +3,+3 nohead ls 1\n");
    return 0;
}