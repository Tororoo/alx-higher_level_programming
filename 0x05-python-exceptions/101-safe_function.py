#!/usr/bin/python3
from __future__ import print_function
import sys


def safe_function(fct, *args):
    try:
        res = fct(*args)
    except Exception as e:
        exc_type, exc_value, exc_traceback = sys.exc_info()
        print("Exception: {} - {}".format(exc_type.__name__, exc_value), file=sys.stderr)
        return None
    else:
        return res
