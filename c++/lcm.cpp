#include "gcd.cpp"

int lcd(int gcd, int a, int b) {
    return (int)((a*b)/gcd);
}

int lcd(int a, int b) {
    // function overload
    return (int)((a*b)/gcd(a,b));
}