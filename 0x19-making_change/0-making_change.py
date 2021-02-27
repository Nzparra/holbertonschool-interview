#!/usr/bin/python3
""" number of coins """


def makeChange(coins, total):
    """
    determining how many coins
    """
    sum = 0
    i = 0
    counter = 0
    if total <= 0:
        return 0
    new_coins = sorted(coins, reverse=True)
    my_coins = len(new_coins)
    aux = total - sum
    while sum < total and i < my_coins:
        while new_coins[i] <= aux:
            sum = sum + new_coins[i]
            counter += 1
            if sum == total:
                return counter
            aux = total - sum
        i += 1
    return -1
