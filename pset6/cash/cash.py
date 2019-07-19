from cs50 import get_float


def main():
    # loop to prompt the user for a positive number
    while True:
        cents = get_float("Please introduce the change: ")
        if cents > 0:
            break
    # make cents a non-decimal number
    cents *= 100
    change = cents // 25 + (cents % 25) // 10 + ((cents % 25) % 10) // 5 + ((cents % 25) % 10) % 5
    print(change)    


main()
