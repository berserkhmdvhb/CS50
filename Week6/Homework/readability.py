from cs50 import get_int
from cs50 import get_string
import re


def main():
    text = get_string("Text: ")
    # 3 functions for counting number of sentences, words, letters, respectively
    sc = sent_count(text)
    wc = word_count(text)
    lc = let_count(text)
    # print all the counts
    print("{0} letter(s) \n {1} word(s) \n {2} sentence(s)".format(lc, wc, sc))

    # L is the average number of letters per 100 words in the text,
    L = (lc * 100) / wc
    # S is the average number of sentences per 100 words in the text
    S = (sc * 100) / wc
    # Coleman-Liau index.
    grade = round(0.0588 * L - 0.296 * S - 15.8)
    if (grade > 16):
        print("Grade 16+")
    elif (grade < 1):
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")


def sent_count(text):
    count = 0
    for char in text:
        if char in ['.', '?', '!']:
            count += 1
    return count


def word_count(text):
    count = len(re.findall(r'[\w]* ', text))
    return count+1


def let_count(text):
    # only counts lowercase and uppercase letters
    count = 0
    for char in text:
        if char.islower() or char.isupper():
            count += 1
    return count


if __name__ == "__main__":
    main()
