""""
lcd (lowest common denominator) by Andrew Li
"""
from gcd import gcd

def lcd(gcd, int1, int2):
    return int((int1*int2)/gcd)

def lcd_no_gcd(int1, int2):
    return int((int1*int2)/gcd(int1,int2))
