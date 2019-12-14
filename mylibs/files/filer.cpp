#ifndef FILE_READER_CPP
#define FILE_READER_CPP

#include <vector>
#include <fstream>
using namespace  std;


vector<pair<double, double>> read_file(const char* filename){
    setlocale(LC_ALL, "Russian");
    ifstream file(filename);

    vector<pair<double, double>> points;
    pair<double, double>  p;
    double t, angle, speed, acceleration;
    char str[10000];

    for(int i = 0; i < 6; i++){
        file.getline(str, 10000, '\n');
    }
    
    while(!file.eof()){
        file >> str;
        t = atof(str);
        file >> str;
        angle = atof(str);
        file >> str;
        speed = atof(str);
        file >> str;
        acceleration = atof(str);
        p.first = t;
        p.second = angle;
        points.push_back(p);
    }
    points.pop_back();
    file.close();
    return points;
}


void write_file(vector<pair<double, double>> &points, const char* path){
    ofstream fout (path);
    for(int i = 0; i < points.size(); i++){
        fout << (points.at(i).first) << " " << (points.at(i).second) << endl;
    }
    fout.close();
}


void append_to_file(vector<pair<double, double>> &points, const char* path){
    ofstream fout (path, ios_base::app);
    for(int i = 0; i < points.size(); i++){
        fout << (points.at(i).first) << " " << (points.at(i).second) << endl;
    }
    fout.close();
}

#endif