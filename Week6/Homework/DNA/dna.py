# Simulate a sports tournament

import csv
import sys
import re
import random

# Number of simulations to run
N = 1000


def main():
    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # opening DNA of individual
    with open(sys.argv[2]) as f:
        ind = f.readlines()
    ind = str(ind[0])
    suspects = []
    # TODO: Read teams into memory from file
    with open(sys.argv[1], "r") as file:
        reader = csv.reader(file)
        # store STR types (first column) + name
        header = next(reader)
        STRS = header[1:]
        for row in reader:
            dct = dict()
            dct['name'] = row[0]
            # count of STRs which are stored in a dictionary
            for i in range(1, len(header)):
                dct[header[i]] = int(row[i])
            suspects.append(dct)
    # count longest consecutive STR of different types (distinguished in cvs file header) in individual

    # individual dna
    indna = dict.fromkeys(header)
    indna['name'] = 'individual'
    for STR in STRS:
        groups = re.findall(rf'(?:{STR})+', ind)
        maxstr = max(groups, key=len)
        indna[STR] = int(len(maxstr) / len(STR))
    # print(suspects)

    for person in suspects:
        result = all(person[STR] == indna[STR] for STR in STRS)
        if result == True:
            name = person['name']
            print(f'{name} is a Match')
            return 0
    print('No match')


if __name__ == "__main__":
    main()