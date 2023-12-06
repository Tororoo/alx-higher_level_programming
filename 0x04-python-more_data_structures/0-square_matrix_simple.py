#!/usr/bin/python3

def square_matrix_simple(matrix=[]):
    return [[x**2 for x in row] for row in matrix]

    new_matrix = square_matrix_simple(matrix)
    print(new_matrix)
    print(matrix)

