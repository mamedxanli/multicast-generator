#include <iostream>
#include "../include/MulticastGenerator.h"
using namespace std;


int main() {
    MulticastGenerator generator;
    while (true) {
        generator.Generate();
    }
    return 0;
}