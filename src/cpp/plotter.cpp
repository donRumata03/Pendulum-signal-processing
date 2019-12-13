#include "pack_includer.hpp"
using namespace std;

#define python_path_plot "C:\\Users\\Vova\\AppData\\Local\\Programs\\Python\\Python37-32\\python.exe D:/Projects/Experiments/Pendulum_signal_processing/src/python/Graphic_builder.py D:/Projects/Experiments/Pendulum_signal_processing/res/tests/tests.txt"
const char* out_file_name = "D:/Projects/Experiments/Pendulum_signal_processing/res/tests/tests.txt";

void plot(vector<pair<double, double>> &points){
    write_file(points, out_file_name);
    system(python_path_plot);
}

void plot(vector<double> &points){
    vector<pair<double, double>> new_points;

    for(int i = 0; i < points.size(); i++){
        new_points.push_back(pair<double, double>(i, points.at(i)));
        cout << new_points.at(i).first <<  " " << new_points.at(i).second << endl;
    }
    write_file(new_points, out_file_name);
    system(python_path_plot);
}

void add_to_plot(vector<pair<double, double>> &points){
    append_to_file(points, out_file_name);
    ofstream fout (out_file_name, ios_base::app);
    fout << ";\n";
}


void add_to_plot(vector<double> &points){
    vector<pair<double, double>> new_points;

    for(int i = 0; i < points.size(); i++){
        new_points.push_back(pair<double, double>(i, points.at(i)));
        cout << new_points.at(i).first <<  " " << new_points.at(i).second << endl;
    }
    append_to_file(new_points, out_file_name);
    fstream fout (out_file_name, ios_base::app);
    fout << ";\n";
    fout.close();
}


void clear_plot(){
    remove(out_file_name);
}


void show_plot(){
    system(python_path_plot);
}