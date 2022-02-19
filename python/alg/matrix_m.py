'''
Naive Matrix Multiple
Description: based on https://github.com/Zeyu-Li/matrix_multiplication/blob/master/src/matrix_multiplication.cpp
'''

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
