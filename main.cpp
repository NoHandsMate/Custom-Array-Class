#include "array.h"


int main() {

    custom::Array<int, 3> data{1,2,3};
    if(data.empty())
    {
        std::cout<<"empty"<<'\n';
    }
}