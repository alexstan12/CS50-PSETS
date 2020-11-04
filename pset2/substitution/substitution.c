#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

bool duplicateChecker(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("%s\n",argv[1]);
    }
    else if (argc == 1) 
    { 
        printf("You have to enter a cipher to run the program\n");
        return 1;
    }
    for(int i=0; i<strlen(argv[1]);i++)
    {
        if(!isalpha(argv[1][i]))
        { 
        printf("Invalid characters in key\n");
        return 1;
        }
    }
    
    if(strlen(argv[1])!=26)
    { 
        printf("The key does not have the length of 26 chars\n");
        return 1; 
    }
    
    //now, the actual checker for duplicates
    if(duplicateChecker(argv[1]) == false)
        { 
        printf("The key has duplicates\n");
         return 1;
        }

    string inTxt = get_string("plaintext: ");
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //the ENCRYPTION part
    //will store the variable argv[1] in a new container
    string arg = argv[1]; // it is a shallow copy, since 'string' is actually a char*
    for( int i=0; i<strlen(inTxt); i++){
       if( isalpha(inTxt[i])){
        for( int j=0; j<strlen(abc); j++){
                if(inTxt[i] == abc[j]){ 
                    inTxt[i] = toupper(arg[j]);
                    break; 
                    }
                    else if(toupper(inTxt[i]) == abc[j]) 
                            {
                            inTxt[i] = tolower(arg[j]);
                            break; 
                            }
            }

        }
    }
    printf("ciphertext: %s\n", inTxt);
    printf("abc: %s\n", abc);
}

bool duplicateChecker(string key)
{
    int n = strlen(key);
    for( int i=0 ; i < n - 1 ; i++)
    {
         for( int j=i+1 ; j<n ; j++)
         {
                if (key[i]==key[j]) 
                {
                    return false;
                }
        }
    }      
    return true;
}