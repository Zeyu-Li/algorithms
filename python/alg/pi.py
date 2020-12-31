# approximates pi with randomness
# uses Monte Carlo

import random


def distance(x, y):
    return (x ** 2 + y ** 2) ** .5

def main():
    n = int(input("Iteration count: "))
    approx = 0
    total = 0
    for i in range(n):
        x = random.randint(0,100)
        y = random.randint(0,100)

        if distance(x, y) <= 100:
            total+=1
        approx = total/(i+1)

    print(f"Pi is about {approx*4}")
    return 0

if __name__ == "__main__":
    main()
