/* 
* Tests by Andrew Li
* Description: A test for all the classes
*/ 
#include <iostream>
#include "../alg/lcm.cpp"
#include "../alg/q_sqrt.cpp"
using namespace std;

int main() {
    /* gcd and lcm/lcd */
    int a = 21, b = 42, c = 75;
    cout << "GCD:" << endl;
    cout << gcd(a,b) << endl;
    cout << "LCM:" << endl;
    cout << lcm(a,c) << endl;

    /* quick square root */
    float num = 10;
    cout << "Quick Square Root:\n" << q_sqrt(num) << " : " << q_sqrt2(num) << endl;

    return 0;
}
