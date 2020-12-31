'''
Naive Matrix Multiple by Andrew Li
Description: based on https://github.com/Zeyu-Li/matrix_multiplication/blob/master/src/matrix_multiplication.cpp
'''

import random

def multiply_matrix(input1, input2):
    if len(input1[0]) != len(input2):
        raise Expection("Matrix multiplication is not possible!") 

    # zeros output matrix
    output = [[0 for _ in range(len(input1))] for _ in range(len(input2[0]))]
    for i in range(len(input1)):
        for j in range(len(input2[0])):
            for k in range(len(input2)):
                output[i][j] += input1[i][k] * input2[k][j]

    return output

def generate_matrix(size_y, size_x):
    matrix = []
    for i in range(size_y):
        row = []
        for j in range(size_x):
            row.append(random.randint(0, 100))
        matrix.append(row)

    return matrix

def print_matrix(matrix):
    # prints matrix
    for row in matrix:
        print(row)
def pp_matrix(matrix):
    # pretty prints matrix
    for row in matrix:
        print(", ".join(map(str, row)))

def main():
    rows = 4
    column = 4
    matrix1 = generate_matrix(rows, column)
    pp_matrix(matrix1)
    print()
    matrix2 = generate_matrix(rows, column)
    pp_matrix(matrix2)
    print()

    output = multiply_matrix(matrix1, matrix2)
    pp_matrix(output)

if __name__ == "__main__":
    main()
