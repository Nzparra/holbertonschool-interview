#!/usr/bin/python3

""" determines if a given data set represents a valid UTF-8 encoding """


def validUTF8(data):
    """
        Return: True if data is a valid UTF-8 encoding, else return False
        A character in UTF-8 can be 1 to 4 bytes long
        The data set can contain multiple characters
        The data will be represented by a list of integers
    """
    check = []
    byte = 0
    for i in data:
        result = i & 255
        if byte == 0:
            if result >= 0 and result <= 247:
                check.append(True)
            else:
                check.append(False)
            if result >= 192 and result <= 223:
                byte = 1
            elif result >= 224 and result <= 239:
                byte = 2
            elif result >= 240 and result <= 247:
                byte = 3
        else:
            if result >= 128 and result <= 191:
                check.append(True)
            else:
                check.append(False)
            byte = byte - 1
    if byte != 0:
        check.append(False)
    result = all(check)
    return result
