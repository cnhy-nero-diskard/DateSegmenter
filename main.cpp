#include <iostream>
#include "segmenter.h"
using namespace std;

int main(){
    convert gg;
    string * arr = gg.param_setter();
    *(arr) = "2.5";
    *(arr+1) = "months";
    gg.converter();
    int * nums = gg.whole_getter();
    
    for (int x = 0; x < 7; x++){
        cout << *(nums+x)<<endl;
    }
    return 0;
}