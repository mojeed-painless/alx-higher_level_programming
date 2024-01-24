#!/usr/bin/python3
import sys


def safe_function(fct, *args):
    try:
        r  = fct(*args)
    except BaseException as e:
        r = None
        print("Exception: {}".format(e), file=sys.stderr)
    finally:
        return r
