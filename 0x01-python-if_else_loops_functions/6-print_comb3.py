#!/usr/bin/python3
for n1 in range(10):
    for n2 in range(10):
        if n2 > n1 and n1 != 8:
            print("{}{}".format(n1, n2), end=", ")
        elif n1 == 8 and n2 == 9:
            print("{}{}".format(n1, n2))
            break
