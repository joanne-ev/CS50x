def main():
    card = input("Card number: ")
    luhn(card)


def card_type(card):
    amex = ("34", "37")
    mastercard = tuple([str(n) for n in range(51, 56)])
    visa = ("4")

    if card.startswith(amex) and len(card) == 15:
        print("AMEX")
    elif card.startswith(mastercard) and len(card) == 16:
        print("MASTERCARD")
    elif card.startswith(visa) and (len(card) == 13 or len(card) == 16):
        print("VISA")
    else:
        print("INVALID")


def luhn(card):
    step1 = []

    # Multiply every other number starting from the penultimate number by two
    for i in range(len(card) - 2, -1, -2):
        step1.append(int(card[i]) * 2)

    step2 = 0

    # Add the products' digits
    for i in step1:
        if i > 9:
            for a in str(i):
                step2 += int(a)
        else:
            step2 += i

    # Add the step2 sum to the sum of digits that weren't initally multiplied
    for i in range(len(card) -1, -1, -2):
        step2 += int(card[i])

    # Check last digit ends with a zero
    step3 = str(step2)

    if step3[-1].endswith("0"):
        card_type(card)
    else:
        print("INVALID")



if __name__ == "__main__":
    main()
