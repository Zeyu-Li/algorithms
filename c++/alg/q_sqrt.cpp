/*
* Quick Square Root (~1% inaccuracy)
* From https://www.youtube.com/watch?v=p8u_k2LIZyo&ab_channel=Nemean
*/

float q_sqrt(float num) {
    long address;
    float x, y;
    const float factor = 1.5;

    x = num * 0.5;
    y = num;
    // IEEE 754 to be stored into long via long pointer cast
    address = * (long*) &y;
    address = 0x5f3759df - (address >> 1);

    // cast back
    y = *(float *) &address;
    y *= (factor - (x * y *y)); // Newtonian's method to get closer approximation
    // y *= (factor - (x * y *y)); // Second Iteration of Newtonian's method gets a closer approximation

    return y;
}

float q_sqrt2(float num) {
    long address;
    float x, y;
    const float factor = 1.5;

    x = num * 0.5;
    y = num;
    // IEEE 754 to be stored into long via long pointer cast
    address = * (long*) &y;
    address = 0x5f3759df - (address >> 1);

    // cast back
    y = *(float *) &address;
    y *= (factor - (x * y *y)); // Newtonian's method to get closer approximation
    y *= (factor - (x * y *y)); // Second Iteration of Newtonian's method gets a closer approximation

    return y;
}
