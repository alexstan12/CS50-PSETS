#include <stdio.h>
#include <cs50.h>
#include <math.h>

int length(long number);
bool checksum(long number);
int first_two(long number);

int main(){
    long number = get_long("Number:");
    if(checksum(number)==true) {printf("AMEX\n");}
            else{ printf("INVALID\n");}
        
}

bool checksum(long number){
    long test = number/10;
    int sum = 0;
    int y=0;
    while(test>0){
        y=test%10*2;
        if(y>9){
            sum+=y%10;
            y/=10;
            sum+=y;}
            else{sum+=y;}
        test/=10;
        sum+=test%10;
        }
    if(sum%10==0) return true;
        else return false;
    }

int length(long number){
    int sum=0;
    while(number>9){
        sum+=1;
        number/=10;
    }
    sum+=1;
    return sum;
    }
    
int first_two(long number){
    while(number/100!=0)
            number/=10;
    return number;
}
