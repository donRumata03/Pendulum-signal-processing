#include <vector>
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

int main(){
    fs::path workdir = fs::current_path();

    wcout << workdir << endl;
    _getwch();
    return 0;
}
