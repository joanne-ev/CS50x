while True:
    try:
        height = int(input("Height: "))
    except ValueError:
        print("Non-numeric value was entered")
    else:
        if 0 < height < 9:
            break
        elif height > 8:
            print("Height is too large")
        else:
            print("Incompatible height")

for i in range(height):
    n = i + 1
    print(" " * (height - n), end="")
    print("#" * n, end="")
    print(" ", end=" ")
    print("#" * (n))
