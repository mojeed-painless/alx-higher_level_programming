#!/usr/bin/python3
<<<<<<< HEAD
"""Module containing the function read_file"""


def read_file(filename=""):
    """Reads a file and prints to stdout.

    Args:
        filename (str, optional): name of file to read. Defaults to "".
    """
    with open(filename, 'r', encoding="utf-8") as f:
        read_data = f.read()
        print(read_data, end='')
=======
"""Module 0-read_file
Reads from a file and prints
"""


def read_file(filename=""):
    """Reads from filename and prints
    its contents to the stdout

    Args:
        - filename: name of the file
    """

    with open(filename) as f:
        read_text = f.read()
        print(read_text, end="")
>>>>>>> 5d175778b39e0503f1eac21966fbecca19cb4bb5
