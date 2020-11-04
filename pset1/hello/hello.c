#include <stdio.h>
#include <cs50.h>

int main(void)
{ // The user will enter his name and it will be stored in name variable, which is a string
    printf("hello, world\n");
    string name = get_string("What is your name?\n");
    printf("hello, %s\n",name);
}
