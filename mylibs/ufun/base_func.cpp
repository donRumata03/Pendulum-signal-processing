#ifndef BASE_FUNC_CPP
#define BASE_FUNC_CPP

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


// Types
#define list vector<int>
#define pms vector<point>

// Functions
#define sqr(x) ((x) * (x))
#define dist(a, b) (sqrt(sqr((a.x - b.x)) + sqr((a.y - b.y))))
#define max(a,b) (((a) > (b)) ? (a) : (b))
// #define min(a,b) (((a) < (b)) ? (a) : (b))
#define sgn(x) (((x) > (0)) ? (1) : (-1))


// Printing:

void print_pair_vector(vector<pair<double, double>> &points, const char* point_sep = " ", const char* sep = "; " , const char* end = "\n"){
    cout << "Points: ";
    for(int i = 0; i < points.size(); i++){
        cout << points.at(i).first << point_sep << points.at(i).second << sep;
    }
    cout << end;
}


void print_vector(vector<double> &points, const char* sep = "; " , const char* end = "\n"){
    cout << "Points: ";
    for(int i = 0; i < points.size(); i++){
        cout << points.at(i) << sep;
    }
    cout << end;
}


// Algebra:

vector<pair<double, double>> logariphmate_func(vector<pair<double, double>> &points){
    vector<pair<double, double>> res;
    for(int i = 0; i < points.size(); i++){
        res.push_back(pair<double, double> (points.at(i).first, log(points.at(i).second)));
    }
    return res;
}


// Strings:

void congatonate_strings(char* s1, char* s2, char* res){
    string ss1 (s1);
    string ss2 (s2);
    for(int i = 0; i < ss1.size(); i++){
        res[i] = s1[i];
    }
    for(int i = 0; i < ss2.size(); i++){
        res[i + ss1.size()] = s2[i];
    }
}


void assign_string(char* s1, char* s2){
    string ss1 (s1);
    for(int i = 0; i < ss1.size(); i++){
        s1[i] = '\0';
    }
    string ss2 (s2);
    for(int i = 0; i < ss2.size(); i++){
        s1[i] = s2[i];
    }
}


char* copy_string(char* s){
    string ss1 (s);
    char* res = new char[ss1.size()];
    for(int i = 0; i < ss1.size(); i++){
        res[i] = s[i];
    }
    return res;
}


char* wch_to_ch(wchar_t* v){
    int index = 0;
    
    while(true){
        if(v[index] == (wchar_t)('\0')){
            break;
        }
        index++;
    }
    char* res = new char[index];
    for(int i = 0; i < index; i++){
        res[i] = v[i];
    }
    return res;
}



#endif // !BASE_FUNC_CPP