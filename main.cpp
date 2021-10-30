#include <iostream>
#include <fstream>

#include "myvector/vector.h"


int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    bicycle::Vector<int> m_data;

    for (int i = 0;i < 10; ++i) {
        m_data.push_back(i);
    }

    for (int i : m_data) {
        std::cout << i << std::endl;
    }
    return 0;
}
