"""" LCD (lowest common denominator) """

def lcd(gcd, int1, int2):
    return int((int1*int2)/gcd)

def lcd_no_gcd(int1, int2):
    from gcd import gcd
    return int((int1*int2)/gcd(int1,int2))

# different name, same thing
def lcm(gcd, int1, int2):
    return int((int1*int2)/gcd)

def lcm_no_gcd(int1, int2):
    from gcd import gcd
    return int((int1*int2)/gcd(int1,int2))