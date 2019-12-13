#include "pack_includer.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;


#define mode 1 // 1 means different angles
#define plot_results 1

#define base_path L"D:\\Projects\\Experiments\\Pendulum_signal_processing\\res\\input\\Less_than_90\\*"
#define norm_base_path_def "D:\\Projects\\Experiments\\Pendulum_signal_processing\\res\\input\\Less_than_90\\"
constexpr char* norm_base_path = norm_base_path_def;


bool comp(pair<double, double> v1, pair<double, double> v2){
    return v1.first > v2.first;
}


void quickSort(vector<pair<double, double>> arr, int left, int right) {
      int i = left, j = right;
      double tmp;
      double pivot = arr[(left + right) / 2].first;

      while (i <= j) {
            while (arr[i].first < pivot)
                  i++;
            while (arr[j].first > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i].first;
                  arr[i].first = arr[j].first;
                  arr[j].first = tmp;
                  i++;
                  j--;
            }
      };
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}


int counter = 0;
char all_fname [100] = norm_base_path_def;

vector <char*> paths;

int main(){
    setlocale(LC_ALL, "Russian");
    WIN32_FIND_DATAW wfd;
    HANDLE const hFind = FindFirstFileW(base_path, &wfd);
    
    if (INVALID_HANDLE_VALUE != hFind)
    {
        do
        {
            counter++;
            if(counter > 2){
                assign_string(all_fname, norm_base_path);
                congatonate_strings(norm_base_path, wch_to_ch(&wfd.cFileName[0]), all_fname);
                // congatonate_strings(all_fname, ".txt", all_fname);
                paths.push_back(copy_string(all_fname));
                cout << copy_string(all_fname);
            }
      } while (NULL != FindNextFileW(hFind, &wfd));
 
        FindClose(hFind);
    }
    cout << endl;
    
    vector<pair<double, double>> angle_period;

    for(int file_index = 0; file_index < paths.size(); file_index++){
        char* this_path = new char[100];
        this_path = paths[file_index];
        #if mode

        pair<double, double> data = get_period_and_angle(this_path);
        double angle = data.first;
        double period = data.second;

        cout << "Path: " << this_path << "; " << "Angle: " << angle << "; Period: " << period << endl;
        
        angle_period.push_back(data);

        #else
        cout << "Path: " << this_path << "; " << "Period: ";
        cout << get_period(this_path) << endl;
        #endif
    }
    #if mode
    
    #if plot_results
    clear_plot();
    add_to_plot(angle_period);
    show_sorted_plot();
    #endif
    #endif
    _getch();
    return 0;
}
