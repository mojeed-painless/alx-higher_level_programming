#!/usr/bin/python3
def magic_calculation(p, q, r):
    if p < q:
        return (r)
    elif r > q:
        return (p + q)
    else:
        return (p * q - r)
