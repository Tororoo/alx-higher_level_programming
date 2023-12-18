#!/usr/bin/python3
def magic_calculation(a, b):
    result = 0
    for i in range(1, 3):
        try:
            if i > a:
                raise Exception('Too far')
            result += a ** b / i
        except Exception as e:
            result = b + a
            print(e)
            break
    else:
        # This block will execute if the loop completes without a 'break'.
        result = result + 10
    return result
