#!/usr/bin/python3
""" Write a script that reads stdin line by line and computes metrics """

import sys

sta_code = {'200': 0, '301': 0, '400': 0, '401': 0,
            '403': 0, '404': 0, '405': 0, '500': 0}
size = 0
i = 0
try:
    for j in sys.stdin:
        llist = j.split(" ")
        if len(llist) > 2:
            s = llist[-1]
            code = llist[-2]
            if code in sta_code:
                sta_code[code] += 1
            size += int(s)
            i += 1
            if i == 10:
                print("File size: {:d}".format(size))
                scode = sorted(sta_code.keys())
                for key in scode:
                    if sta_code[key] != 0:
                        print("{}: {}".format(key, sta_code[key]))
                i = 0
except Exception:
    pass
finally:
    print("File size: {}".format(size))
    scode = sorted(sta_code.keys())
    for key in scode:
        if sta_code[key] != 0:
            print("{}: {}".format(key, sta_code[key]))
