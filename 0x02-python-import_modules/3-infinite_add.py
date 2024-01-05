#!/usr/bin/python3
if __name__ == "__main__":
    import sys
    sum = 0
    for j in range(1, len(sys.argv)):
        sum = sum + int(sys.argv[j])
    print(sum)
