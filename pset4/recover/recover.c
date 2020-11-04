#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Invalid entry, try again!\n");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    FILE *img = NULL;
    if(!file)
    {
        printf("Could not open the file for reading\n");
        return 1;
    }
    BYTE* buff = malloc(512 * sizeof(BYTE)); //the buff can take up to 512 bytes, aka one block of memory inside the memory card
    int file_no = 0; //counter for .jpg files name
    char filename[8] ; // the name of each file can take up to 7 chars + \0 -> "03i.jpg"
    do{
        while (fread(buff, 512, 1, file) == 1)
        {
           if ((buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3] & 0xf0) == 0xe0) && file_no == 0)
           {    // if it's the first jpg to be created
               sprintf(filename, "%03i.jpg", 0);
               img = fopen(filename, "w");
               fwrite(buff, 512, 1, img);
               file_no++;
           }
           else if((buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3] & 0xf0) == 0xe0) && file_no != 0)
           {    // if it's not the first jpg to be created
               sprintf(filename, "%03i.jpg", file_no);
               fclose(img);
               img = fopen(filename, "w");
               fwrite(buff, 512, 1, img);
               file_no++;
           }
           else
           { // if writing to the actual jpg should be continued
               if(img)
               {
                   fwrite(buff, 512, 1, img);
               }
           }
        }
    }
    while(!feof(file)); 
    
    if(img)
    {
        fclose(img); 
        
    }
    if(file)
    {
        fclose(file);
    } 
    free(buff); // freeing memory allocated using malloc
    return 0;  
}
