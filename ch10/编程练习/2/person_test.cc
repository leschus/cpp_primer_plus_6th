#include <iostream>
#include <string>
#include "person.h"

int main() {
    Person one;
    Person two("Smith");
    Person three("Smith", "Kuro");

    one.Show();
    two.Show();
    three.Show();

    std::cout << "-----------------------\n";

    one.FormalShow();
    two.FormalShow();
    three.FormalShow();
}