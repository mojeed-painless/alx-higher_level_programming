#!/usr/bin/python3
    """
    A function that computes the square
    value of all integers of a matrix.
    """

def square_matrix_simple(matrix=[]):
    return [list(map((lambda x: x * x), elm)) for elm in matrix]
