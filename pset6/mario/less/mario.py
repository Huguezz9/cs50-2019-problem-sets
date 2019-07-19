from cs50 import get_int


def main():
    while True:
        height = get_int("Height: ")
        if height <= 8 and height >= 1:
            break
    for i in range(height):
        print(" " * (height - (i + 1)) + "#" * (i + 1))
        

main()
