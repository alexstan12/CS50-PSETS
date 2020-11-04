#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int index(int words, int sentences, int letters);

int main(void){
    int count = 0;
    int words = 0;
    int sentences = 0;
    string text = get_string("Text: ");
    for( int i=0; i<strlen(text); i++ ){
        if(isalpha(text[i])) {count++;}
        if(text[i] == ' '){ words++; }
        if(text[i] == '!' || text[i] == '.' || text[i] == '?') { sentences++; }
    }
    words++; // 1 is added to the total number because a word is counted only after the iteration passed it
    if(sentences == 0) sentences++; //if no symbol was encountered and the iteration reached the end, add 1 sentence
    // printf("%i letter(s)\n", count);
    // printf("%i word(s)\n", words); 
    // printf("%i senctence(s)\n", sentences);
    int result = index(words, sentences, count);
    if(result > 16) { printf("Grade 16+\n");}
        else if(result<1){ printf("Before Grade 1\n");}
        else{ printf("Grade %i\n", result); }
}


int index(int words, int sentences, int letters)
{
    double L = (double)(letters * 100)/words;
    double S = (double)(sentences * 100)/words;
    int index = round((0.0588 * L - 0.296 * S) - 15.8);
    return index;
}