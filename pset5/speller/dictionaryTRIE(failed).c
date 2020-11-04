// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 
  
// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (27) 
  
// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
  

// Represents a node in a hash table
typedef struct node
{
    struct node *children[ALPHABET_SIZE];
    bool isEndOfWord;
}
node;

struct node *root = NULL;

struct node *getNode(void)  // this function initializes a node's children to NULL and sets the current node as 
                            //not being the end of a word
{ 
    struct node *pNode = NULL; 
  
    pNode = (struct node *)malloc(sizeof(struct node)); 
  
    if (pNode) 
    { 
        int i; 
  
        pNode->isEndOfWord = false; 
  
        for (i = 0; i < ALPHABET_SIZE; i++) 
            pNode->children[i] = NULL; 
    } 
  
    return pNode; 
} 


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int level; 
    int length = strlen(word); 
    int index; 
    struct node *pCrawl = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(word[level]); 
  
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
}
// Counts the number of words in your dictionary
unsigned long wordCount = 0;

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
    root = getNode();
    int level;
    int length;
    int index;
    char word[LENGTH];
    while(fscanf(file, "%s", word)!=EOF)
    {
    length = strlen(word); 
    struct node *pCrawl = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(word[level]); 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
    }

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordCount;
}

void free_trie(node *temp)
{
    for(int i=0; i< ALPHABET_SIZE; i++)
    {
        if(temp->children[i] != NULL)
        {
            free_trie(temp->children[i]);
        }
    }
    free(temp);
    return;
}
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node* trav = root;
    free_trie(trav);
    
    return true;
}
