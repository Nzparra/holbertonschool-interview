#!/usr/bin/python3
""" rotate matrix """


def rotate_2d_matrix(matrix):
    """ method to rotate matrix """
    matrix_tmp = [list(elem) for elem in matrix]
    matrix_tmp.reverse()
    for i in range(len(matrix_tmp)):
        for j in range(len(matrix_tmp[i])):
            matrix[i][j] = matrix_tmp[j][i]
