'''
Strassen's Matrix Multiplication by Andrew Li
Description: based on https://www.geeksforgeeks.org/strassens-matrix-multiplication/ and 
https://github.com/stanislavkozlovski/Algorithms/blob/master/Coursera/algorithms_stanford/Strassen%20Matrix%20Multiplication/python/strassen.py
'''

# matrix operations (alternatively, numpy has these functions as well but u need to use the numpy arrays)
def matrix_add(matrix1, matrix2):
    return [[(matrix1[row][col] + matrix2[row][col]) for col in range(len(matrix1[row]))] for row in range(len(matrix1))]
def matrix_sub(matrix1, matrix2):
    return [[(matrix1[row][col] - matrix2[row][col]) for col in range(len(matrix1[row]))] for row in range(len(matrix1))]

def padding_vertical(matrix):
    matrix.append([0 for _ in range(len(matrix[0]))])

def padding_horizontal(matrix):
    for row in matrix:
        row.append(0)

def split_matrix(matrix):
    # returns each of the 4 quadrents of the matrix
    matrix_len = len(matrix)
    mid = matrix_len//2
    top_left = [[matrix[i][j] for j in range(mid)] for i in range(mid)]
    top_right = [[matrix[i][j] for j in range(mid, matrix_len)] for i in range(mid)]

    bottom_left = [[matrix[i][j] for j in range(mid)] for i in range(mid, matrix_len)]
    bottom_right = [[matrix[i][j] for j in range(mid, matrix_len)] for i in range(mid, matrix_len)]

    return top_left, top_right, bottom_left, bottom_right

def strassen(matrix1, matrix2):
    # takes in any two matrices and multiples them
    if len(matrix1[0]) != len(matrix2):
        raise Expection("Matrix multiplication is not possible!")

    # final dim
    x = len(matrix2[0])
    y = len(matrix1)

    # padding to get even
    for matrix in [matrix1, matrix2]:
        if len(matrix) % 2 == 1:
            padding_vertical(matrix)
        if len(matrix[0]) % 2 == 1:
            padding_horizontal(matrix)
    # padding so each matrix is square even
    for matrix in [matrix1, matrix2]:
        if len(matrix) > len(matrix[0]):
            padding_horizontal(matrix)
            padding_horizontal(matrix)
        elif len(matrix) < len(matrix[0]):
            padding_vertical(matrix)
            padding_vertical(matrix)

    matrix = strassen_helper(matrix1, matrix2)
    new_matrix = []
    for j in range(y):
        row = []
        for i in range(x):
            row.append(matrix[j][i])
        new_matrix.append(row)

    return new_matrix

def strassen_helper(matrix1, matrix2):
    if len(matrix1) == 1:
        try:
            return [[matrix1[0][0] * matrix2[0][0]]]
        except:
            print(matrix1, matrix2)
    a, b, c, d = split_matrix(matrix1)
    e, f, g, h = split_matrix(matrix2)

    p1 = strassen_helper(a, matrix_sub(f, h))
    p2 = strassen_helper(matrix_add(a, b), h)
    p3 = strassen_helper(matrix_add(c, d), e)
    p4 = strassen_helper(d, matrix_sub(g, e))
    p5 = strassen_helper(matrix_add(a, d), matrix_add(e, h))
    p6 = strassen_helper(matrix_sub(b, d), matrix_add(g, h))
    p7 = strassen_helper(matrix_sub(a, c), matrix_add(e, f))

    top_left = matrix_add(matrix_sub(matrix_add(p5, p4), p2), p6)
    top_right = matrix_add(p1, p2)
    bot_left = matrix_add(p3, p4)
    bot_right = matrix_sub(matrix_sub(matrix_add(p1, p5), p3), p7)

    # create a new matrix
    new_matrix = []
    for i in range(len(top_right)):
        new_matrix.append(top_left[i] + top_right[i])
    for i in range(len(bot_right)):
        new_matrix.append(bot_left[i] + bot_right[i])
    return new_matrix

def pp_matrix(matrix):
    # pretty prints matrix
    for row in matrix:
        print(" ".join(map(str, row)))

def main():
    # debug
    # a = [[30, 95, 23],[53, 14, 62],[100, 20, 89]]
    a = [[30, 95, 23],[53, 14, 62],[100, 20, 89],[100, 20, 89]]
    b = [[24, 23, 32],[74, 38, 30],[91, 88, 6]]

    pp_matrix(a)
    print()
    pp_matrix(b)

    matrix = strassen(a,b)

    print()
    pp_matrix(matrix)
    return 0

if __name__ == "__main__":
    main()
