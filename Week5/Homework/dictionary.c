// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 256;

// Hash table
node *table[N];

//MINE: Global Variables//
int words = 0;
//END MINE//





// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int bucket = hash(word);
    //create a pointer that points to the linked list
    node *cursor = table[bucket];
    //move cursor one element at a time in linked list, using each node's 'next', until we reach
    //end of the list, which is indicated by NULL value
    while (cursor != NULL)
    {
        //compare given word and the current node's word case-indifferently
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        //move cursor to next node in the linked list
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    //djb2 algorithm
    //source: http://www.cse.yorku.ca/~oz/hash.html
    unsigned long hash = 5381;
    int c;
    while ((c = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open dictionary as readable
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }
    //read words from dictionary until reaching EOF (end of file)
    //while reading, store each word in 'wrd'.
    char wrd[LENGTH + 1];
    while (fscanf(dict, "%s", wrd) != EOF)
    {
        // calculate the value of hash function for the wrd and store it in 'bucket'
        unsigned int bucket = hash(wrd);
        //create a new node, set its word to wrd, and its next to NULL
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, wrd);
        n->next = NULL;

        //if it wasn't the first time we're visiting this particular bucket
        if (table[bucket] != NULL)
        {
            //in order not to orphan the linked list's values, point the new node's next to the list, and
            //then set n as the header of the linked list
            n->next = table[bucket];
            table[bucket] = n;
        }
        //if we have never created this bucket thus far
        else
        {
            //set header of bucket as n
            table[bucket] = n;
        }
        words++;

    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    //done!
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //for each linked list in the array
    for (int i = 0;i < 256;i++)
    {
        //use a 'cursor' to navigate through the current linked list node by node
        //'tmp' keeps track of the nodes by following the 'cursor'
        //we free 'tmp' which frees the node before cursor and we do this until cursor reaches the end of the list
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}