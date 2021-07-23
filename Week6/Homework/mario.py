from cs50 import get_int

while True:
    rows = get_int("Height: ")
    if rows in range(1, 9):
        break

for i in range(1, rows + 1):
    # print spaces
    print(" " * (rows-i), end='')
    # print left haf
    print('#' * i, end='')
    # print middle space
    print('  ', end='')
    # print right haf
    print('#' * i)
