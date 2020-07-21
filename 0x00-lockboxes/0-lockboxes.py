#!/usr/bin/python3
""" Method that determines if all the boxes can be opened """


def canUnlockAll(boxes):
    """ Method that determine if all the boxes can be opened  """
    for i in range(1, len(boxes) - 1):
        opened = False
        for j in range(len(boxes)):
            if i in boxes[j] and i != j:
                opened = True
        if not opened:
            return False
    return True
