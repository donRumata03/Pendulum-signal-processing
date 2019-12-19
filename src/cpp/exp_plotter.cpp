#include "D:\My_Libs\mylibs.hpp"
#include <iostream>
#include "D:\Cpp_Libs\json\json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;

int main(){
    double A = 3.44, B = -0.39, C = 4.99;
    
    pms data = {point(1.0, 7.32), \
        point(2.0, 6.48), \
        point(3.0,  6.0), \
        point(4.0, 5.71), \
        point(5.0, 5.48), \
        point(6.0,  5.34), \
        point(7.0, 5.41), \
        point(8.0, 4.95), \
        point(9.0, 5.04), \
        point(10.0, 5.1), \
        point(11.0,  5.16), \
        point(12.0,  5.13), \
        point(13.0,  5.1), \
        point(14.0,  4.95), \
        point(15.0,  5.0), \
        point(16.0, 5.0), \
        point(17.0, 5.04), \
        point(18.0, 4.87), \
        point(19.0, 5.02), \
        point(20.0, 4.95)
    };
    
    clear_plot();
    add_to_plot_exp(A, B, C, 1.0, 20.0, 0.01, "red", "plot");
    add_to_plot(data, "green", "scatter");
    show_plot();
    // add_to_plot_exp(A, B, C, 1, 20, 0.1);
    // show_plot();
    _getwch();
    return 0;
}