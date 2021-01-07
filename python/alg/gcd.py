""" GCD (greatest common divisor) """

def gcd(int1, int2):
    if int2 == 0:
        return int(int1)
    return gcd(int2, int1 % int2)
