#!/usr/bin/python3
def list_division(my_list_1, my_list_2, list_length):
    count = 0
    n = 0
    n_list = []
    for n in range(list_length):
        try:
            m = my_list_1[n] / my_list_2[n]
        except TypeError:
            print("wrong type")
            m = 0
        except ZeroDivisionError:
            print("division by 0")
            m = 0
        except IndexError:
            print("out of range")
            m = 0
        finally:
            n_list.append(m)
    return n_list
