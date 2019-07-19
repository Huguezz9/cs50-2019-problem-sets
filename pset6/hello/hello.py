from cs50 import get_string


def main():
    # takes the name as an input from the user.
    name = get_string("What is your name? ")
    # prints Hello + the name.
    print(f"hello, {name}")


main()

