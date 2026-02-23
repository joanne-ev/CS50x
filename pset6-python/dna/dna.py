import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) == 3:
        database = sys.argv[1]
        sequence = sys.argv[2]
    else:
        sys.exit("Error: Missing either database or sequence filename")

    # Read database file into a variable
    data = []
    with open(f"{database}", "r") as file:
        reader = csv.DictReader(file)
        headers = reader.fieldnames

        for row in reader:
            data.append(row)

    # Read DNA sequence file into a variable
    with open(f"{sequence}", "r") as file:
        dna = file.read()

    subsequences = headers[1:]
    finding_dna_match(data, subsequences, dna)

    return


def finding_dna_match(data, subsequences, dna):
     # Check database for matching profiles
    no_match = 0

    for person in data:
        matches = no_matches = 0

        for strs in subsequences:
            # Find longest match of each STR in DNA sequence
            strs_count = longest_match(dna, strs)

            if strs_count == int(person[strs]):
                matches += 1

        if matches == len(subsequences):
            print(f"{person['name']}")
        else:
            no_match += 1

    if no_match == len(subsequences):
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run



if __name__ == "__main__":
    main()
