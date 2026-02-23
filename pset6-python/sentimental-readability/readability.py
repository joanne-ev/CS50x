def main():
    text = input("Text: ")

    total_words = 1
    total_sentences = 0
    total_letters = 0

    for char in text:
        character = char.lower()

        total_words += count_words(character)
        total_sentences += count_sentences(character)
        total_letters += count_letters(character)

    coleman_liau(total_words, total_sentences, total_letters)


def count_words(character):
    words = 0

    if ord(character) == 32:
        words += 1

    return words


def count_sentences(character):
    sentences = 0

    if ord(character) == 33 or ord(character) == 46 or ord(character) == 63:
        sentences += 1

    return sentences


def count_letters(character):
    letters = 0

    if 96 < ord(character) < 123:
        letters += 1

    return letters


def avg_per_100_words(n, words):
    avg = (n / words) * 100
    return avg


def coleman_liau(total_words, total_sentences, total_letters):
    avg_letters = avg_per_100_words(total_letters, total_words)
    avg_sentences = avg_per_100_words(total_sentences, total_words)

    index = 0.0588 * avg_letters - 0.296 * avg_sentences - 15.8

    if index < 1:
        print("Grade: Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        final_grade = round(index)
        print(f"Grade {final_grade}")


if __name__ == "__main__":
    main()
