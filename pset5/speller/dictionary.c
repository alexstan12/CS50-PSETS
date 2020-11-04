// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 190000;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    unsigned int hashIndex = hash(word);
    node *trav = table[hashIndex];
    while(trav!=NULL)
    {
        if(strcasecmp(word, trav->word) == 0)
        {
            return true;
        }
        trav = trav->next;
    }
    
    return false;
}
// Counts the number of words in your dictionary
unsigned long wordCount = 0;

// Hashes word to a number
// Hash function derived from djb2, that works efficiently when hashing strings and, more importantly
// is case INSENSITIVE
// credit : https://backworlds.com/hashing-strings/

unsigned int hash(const char *word)
    {
        unsigned int hash = 5381;
        char Ch;
        if(word)
        {
        while ((Ch = *word++))
            hash = ((hash << 5) + hash) + ((Ch >= 'A' && Ch <= 'Z') ? Ch + ('a'-'A') : Ch); /* hash * 33 + c */
        }
        return hash % N;
    }

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if(!file)
    {
        printf("Could not open the dictionary ! \n");
        return false;
    }
    
    char word[LENGTH];
    while(fscanf(file, "%s", word)!=EOF)
    {
        node *n = malloc(sizeof(node));
        if(!n)
        {
            printf("No memory for malloc\n");
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;
        unsigned int hashIndex = hash(n->word);
        n->next = table[hashIndex];
        table[hashIndex] = n;
        wordCount++;
    }
    fclose(file);
    return true;
    
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for(unsigned long i = 0 ; i< N ; i++)
    {
        node *trav = table[i];
        node *temp = table[i];
        while(trav!=NULL)
        {
            temp = trav;
            trav = trav->next;
            free(temp);
        }
    }
    return true;
}
