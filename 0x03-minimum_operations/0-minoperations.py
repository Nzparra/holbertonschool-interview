#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    """
        Given a number n, write a method that calculates the fewest number
        of operations needed to result in exactly n H characters in the file.
    """
    n_ops = 0
    summ = 1
    aux = 0
    while summ < n:
        if (n % summ == 0):
            aux = summ
            summ *= 2
            n_ops += 1
        else:
            summ += aux
        n_ops += 1
    return n_ops
