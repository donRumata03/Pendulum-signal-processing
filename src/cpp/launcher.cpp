#include "pack_includer.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

#define file_path "D:\\Projects\\Experiments\\Pendulum_signal_processing\\res\\input\\Less_than_90\\1.txt"
#define base_path L"D:\\Projects\\Experiments\\Pendulum_signal_processing\\res\\input\\Less_than_30\\First\\*"
#define norm_base_path_def "D:\\Projects\\Experiments\\Pendulum_signal_processing\\res\\input\\Less_than_30\\First\\"
constexpr char* norm_base_path = norm_base_path_def;


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
                congatonate_strings(norm_base_path, (char*)(&wfd.cFileName[0]), all_fname);
                congatonate_strings(all_fname, ".txt", all_fname);
                paths.push_back(copy_string(all_fname));
            }
      } while (NULL != FindNextFileW(hFind, &wfd));
 
        FindClose(hFind);
    }
    
    for(int file_index = 0; file_index < paths.size(); file_index++){
        char* this_path = new char[100];
        this_path = paths[file_index];
        cout << "Path: " << this_path << "; " << "Period: ";
        cout << get_period(this_path) << endl;
    }
    
    _getch();
    return 0;
}
