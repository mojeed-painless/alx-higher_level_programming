#!/usr/bin/python3
"""

Module composed by a function that prints 2 new lines after ".?:" characters

"""


def text_indentation(text):
    """ Function that prints 2 new lines after ".?:" characters

    Args:
        text: input string

    Returns:
        No return

    Raises:
        TypeError: If text is not a string


    """

    if type(text) is not str:
        raise TypeError("text must be a string")

    x = text[:]

    for t in ".?:":
        list_text = x.split(t)
        x = ""
        for j in list_text:
            j = j.strip(" ")
            x = j + t if x is "" else x + "\n\n" + j + t

    print(x[:-3], end="")
