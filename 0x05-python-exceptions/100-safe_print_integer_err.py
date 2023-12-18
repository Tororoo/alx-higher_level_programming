#!/usr/bin/python3

import sys


def safe_print_integer_err(value):
    """Prints an integer with "{:d}".format().

    If a TypeError or ValueError occurs, a corresponding
    message is printed to standard error.

    Args:
        value (int): The integer to print.

    Returns:
        True if successful, False otherwise.
    """
    try:
        print("{:d}".format(value))
        return True
    except (TypeError, ValueError) as e:
        print("Exception: {}".format(e), file=sys.stderr)
        return False
