#include <vector>
#include "pack_includer.hpp"
#include <cmath>
#include <iostream>
using namespace std;

vector<pair<double, double>> count_all_derivatives(vector<pair<double, double>> &points, int buff_length){
    int buff_ind, this_index;
    double point_sum, coeff_sum;
    vector<pair<double, double>> result;
    double coeff;
    for(int i = 0; i < points.size(); i++){
        buff_ind = max(1, i - (int)(buff_length/2));
        point_sum = 0;
        coeff_sum = 0;
        for(int j = 0; j < buff_length; j++){
            this_index = j + buff_ind;
            if(this_index >= points.size()){
                break;
            }
            if(this_index == i) coeff = 2;
            else coeff = pow((1.0 / abs((double)this_index - i)), 0.3); 
            coeff_sum += coeff;
            point_sum += (points.at(this_index).second - points.at(this_index - 1).second) / \
                (points.at(this_index).first - points.at(this_index - 1).first) * \
                    coeff;
        }
        result.push_back(pair<double, double>(points.at(i).first, (point_sum / coeff_sum)));
    }
    return result;
}


line aproximate_points(vector<pair<double, double>> &points){
    line ret_line;
    return ret_line;
}

double linear_interpolate(vector<pair<double, double>> &points, double x){
    int right_index;
    if (x > points.at(points.size() - 1).first){
        cout << "x = " << x << "; max_num = " << points.at(points.size() - 1).first << ", so, it`s impossible to interpolate!!!" << endl;
        return 0.0;
    }
    for(int i = 0; i < points.size(); i++){
        if (x <= points[i].first){
            right_index = i;
            break;
        }
    }
    return (points.at(right_index - 1).second * abs(points.at(right_index).first - x) \
        + points.at(right_index).second * abs(points.at(right_index - 1).first - x)) \
         / (abs(points.at(right_index).first - x) + abs(points.at(right_index - 1).first - x));
}


vector<double> find_zeros(vector<pair<double, double>> &points){
    vector<double> result;
    for(int i = 1; i < points.size(); i++){
        if(((points.at(i).second != 0) && (points.at(i - 1).second != 0)) && (sgn(points.at(i).second) != sgn(points.at(i - 1).second))){
            result.push_back((abs(points.at(i).second) * points.at(i).first \
            + abs(points.at(i - 1).second) * points.at(i - 1).first) \
            / (abs(points.at(i).second) + abs(points.at(i - 1).second)));
        }
    }
    return result;
}


vector<pair<double, double>> add_zeros(vector<double> &points){
    vector<pair<double, double>> new_points;
    for(int i = 0; i < points.size(); i++){
        new_points.push_back(pair<double, double> (points.at(i), 0.0));
    }
    return new_points;
}


double find_max_abs_val(vector<pair<double, double>> &points){
    double val = -1.0;
    for(int i = 0; i < points.size(); i++){
        if (abs(points.at(i).second) > val){
            val = abs(points.at(i).second);
        }
    }
    return val;
}


vector<pair<double, double>> execute_function(vector<pair<double, double>> &points){
    double edge = find_max_abs_val(points) / 20;
    int index = -1;
    for(int i = 0; i < points.size(); i++){
        if(abs(points.at(i).second) > edge){
            index = i;
            break;
        }
    }
    vector<pair<double, double>> new_points;
    for(int i = index; i < points.size(); i++){
        new_points.push_back(points.at(i));
    }
    return new_points;
}


double get_period(char* path){
    vector<pair<double, double>> points = read_file(path);
    points = execute_function(points);
    
    vector<pair<double, double>> derivative = count_all_derivatives(points, 100);
    vector<double> zeros = find_zeros(derivative);

    // Ploting:
    
    
    clear_plot();
    add_to_plot(zeros);
    show_plot();

    double average_period = (zeros.at(zeros.size() - 1) - zeros.at(0)) / (zeros.size() - 1);
    return average_period;
}

