'''
Algo Tests
'''
import sys, os
sys.path.insert(0, os.path.abspath('..'))

from alg.gcd import gcd
from alg.lcd import lcm
from alg.matrix_m import multiply_matrix
from alg.util import pp_matrix, generate_matrix
from alg.strassen_m import strassen
from alg.pi import approximate
from alg.powerset import powerset

def main():
    print("GCD")
    assert gcd(12,4) == 4, "GCD failed"
    assert gcd(720,264) == 24, "GCD failed"
    print("LCM")
    assert lcm(gcd(12,4), 12,4) == 12, "LCM failed"
    assert lcm(gcd(613, 99), 613, 99) == 60687, "LCM failed"
    print("Multiply Matrix")
    
    rows = 4
    column = 4
    matrix1 = generate_matrix(rows, column)
    matrix2 = generate_matrix(rows, column)
    # pp_matrix(matrix1)
    # print()
    # pp_matrix(matrix2)
    # print()

    output1 = multiply_matrix(matrix1, matrix2)
    output2 = strassen(matrix1, matrix2)
    # pp_matrix(output1)
    # pp_matrix(output2)
    assert output1 == output2, "matrix multiples are not the same"

    print("Pi approximator")
    approx = approximate(1000)
    assert 3 < approx < 3.25, "Pi approx is not close enough"

    print("Power set")
    assert powerset([1,2,3,4]) == [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3], [4], [1, 4], [2, 4], [1, 2, 4], [3, 4], [1, 3, 4], [2, 3, 4], [1, 2, 3, 4]]
    assert powerset('acd') == [[], ['a'], ['c'], ['a', 'c'], ['d'], ['a', 'd'], ['c', 'd'], ['a', 'c', 'd']]

    print("All tests passed")
    return 0

if __name__ == "__main__":
    main()
