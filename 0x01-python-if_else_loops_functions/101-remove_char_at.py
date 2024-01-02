#!/usr/bin/python3
def remove_char_at(str, x):
    if 0 <= x < len(str):
        return (str.replace(str[x], ""))
    else:
        return (str)
