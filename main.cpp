#include <iostream>
#include "segmenter.h"
using namespace std;

int main(){
    convert gg;
    string * arr = gg.param_setter();
    *(arr) = "25.4442";
    *(arr+1) = "months";
    gg.converter();
    int * nums = gg.whole_getter();
    
    
    string gold = gg.output_g();
    cout << gold << endl;
    return 0;
}