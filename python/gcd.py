""""
gcd (greatest common divisor) by Andrew Li
"""


def gcd(int1, int2):
    if int2 == 0:
        return int(int1)
    return gcd(int1, int1 % int2)
