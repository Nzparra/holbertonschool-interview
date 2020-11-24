#!/usr/bin/python3
""" rain Python"""


def rain(walls):
    """ Rain in to the walls """
    if len(walls) < 3:
        return 0
    left, right = ([], [])
    for i in range(len(walls)):
        left.append(0)
        right.append(0)
    left[0] = walls[0]
    for i in range(1, len(walls)):
        left[i] = max(left[i-1], walls[i])
    right[-1] = walls[-1]
    for i in range(len(walls) - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])
    rain = 0
    for i in range(0, len(walls)):
        first = left[i]
        second = right[i]
        rain += min(first, second) - walls[i]
    return rain
