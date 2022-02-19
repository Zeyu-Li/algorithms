import random

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
