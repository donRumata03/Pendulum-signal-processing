#ifndef PLOTTER_CPP
#define PLOTTER_CPP

#include <D:/My_Libs/mylibs.hpp>
#include <iostream>
using namespace std;

#define python_path_plot "C:\\Users\\Vova\\AppData\\Local\\Programs\\Python\\Python37-32\\python.exe \
    D:/My_libs/plotter/Graphic_builder.py \
    D:/My_Libs/plotter/data.txt"

constexpr const char* python_path_sorted_plot = "C:\\Users\\Vova\\AppData\\Local\\Programs\\Python\\Python37-32\\python.exe \
    D:/My_libs/plotter/Graphic_builder.py \
    D:/My_Libs/plotter/data.txt 1";
const char* out_file_name = "D:/My_Libs/plotter/data.txt";

void plot(vector<pair<double, double>> points){
    write_file(points, out_file_name);
    system(python_path_plot);
}

void plot(vector<double> points){
    vector<pair<double, double>> new_points;

    for(int i = 0; i < points.size(); i++){
        new_points.push_back(pair<double, double>(i, points.at(i)));
        cout << new_points.at(i).first <<  " " << new_points.at(i).second << endl;
    }
    write_file(new_points, out_file_name);
    system(python_path_plot);
}


void add_to_plot(vector<pair<double, double>> points){
    append_to_file(points, out_file_name);
    ofstream fout (out_file_name, ios_base::app);
    fout << ";\n";
}


void add_to_plot_line(line l, double x0, double x1, double step){
    vector<pair<double, double>> points;
    cout << x0 << " " << x1 << endl;
    for(double x = x0; x < x1; x+=step){
        points.push_back(pair<double, double> (x, x * l.k + l.b));
    }
    
    add_to_plot(points);
}


void add_to_plot(vector<double> points){
    vector<pair<double, double>> new_points;

    for(int i = 0; i < points.size(); i++){
        new_points.push_back(pair<double, double>(i, points.at(i)));
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


void show_sorted_plot(){
    system(python_path_sorted_plot);
}

#endif