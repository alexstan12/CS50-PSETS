#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            float average = (float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtBlue = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtRed = round(average);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i=0; i<height; i++)
    {
        for(int j=0; j<width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i=0 ; i < height; i++)
    {
        for(int j=0 ; j < width ; j++)
        {
            if(i==0) // if on first row
            {
                if(j==0) // if on first row, first column
                {
                    temp[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue)/4);
                    temp[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/4);
                    temp[i][j].rgbtRed = round((float)(image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed)/4);

                }
                else if(j==width-1) // if on first row, last column
                {
                    temp[i][j].rgbtBlue = round((float)(image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue)/4);
                    temp[i][j].rgbtGreen = round((float)(image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen)/4);
                    temp[i][j].rgbtRed = round((float)(image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed)/4);

                }
                else{ // if on first row, but not on corners
                    temp[i][j].rgbtBlue = round((float)(image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue  + image[i+1][j+1].rgbtBlue )/6);
                    temp[i][j].rgbtGreen = round((float)(image[i][j-1].rgbtGreen  + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/6);
                    temp[i][j].rgbtRed = round((float)(image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed)/6);
                }
            }
            else if(i == height -1) // if on last row
            {
                if(j==0) // if on last row, first column
                {
                    temp[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue)/4);
                    temp[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen)/4);
                    temp[i][j].rgbtRed = round((float)(image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed)/4);
                }
                else if(j==width-1) // if on last row, last column
                {
                    temp[i][j].rgbtBlue = round((float)(image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue)/4);
                    temp[i][j].rgbtGreen = round((float)(image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen)/4);
                    temp[i][j].rgbtRed = round((float)(image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed)/4);
                }
                else{ // if on last row, but not on corners
                    temp[i][j].rgbtBlue = round((float)(image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue)/6);
                    temp[i][j].rgbtGreen = round((float)(image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen)/6);
                    temp[i][j].rgbtRed = round((float)(image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed)/6);
                }
            }
            else{
                if(j==0) // if not on first or last row, but on first column(edge)
                {
                    temp[i][j].rgbtBlue = round((float)(image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue)/6);
                    temp[i][j].rgbtGreen = round((float)(image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/6);
                    temp[i][j].rgbtRed = round((float)(image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed+ image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed)/6);
                }
                else if(j==width-1) // if not on first or last row, but on last column(edge)
                {
                    temp[i][j].rgbtBlue = round((float)(image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue)/6);
                    temp[i][j].rgbtGreen = round((float)(image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen)/6);
                    temp[i][j].rgbtRed = round((float)(image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed)/6);
                }
                else{ // if anywhere else other than edges or corners
                    temp[i][j].rgbtBlue = round((float)(image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue)/9);
                    temp[i][j].rgbtGreen = round((float)(image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/9);
                    temp[i][j].rgbtRed = round((float)(image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed)/9);
                }
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // returning the image
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    RGBTRIPLE temp[height][width];
    for(int i=0; i<height; i++)
    {
        for(int j=0; j< width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    
    for(int i=0 ; i < height; i++)
    {
        for(int j=0 ; j < width ; j++)
        {
        int redx = 0;
        int greenx = 0;
        int bluex = 0;
        int redy = 0;
        int greeny = 0;
        int bluey = 0;

        //for this particular part i was inspired by an internet post that helped me figure
        //out a relationship between kernel matrix and image pixels
        //otherwise, i would have hard coded every particular situation
        for(int k = 0; k < 3; k++)
        {
            for(int l = 0; l < 3; l++)
            {

                if(i - 1 + k < 0 || i - 1 + k > height - 1 || j - 1 + l < 0 || j - 1 + l > width - 1)
                {
                    continue;
                }
                // working with a temporary copy of the image so that a modified pixel won't influence the next ones
                // thaat aren't modified yet
                // calcuate Gx
                redx = redx + (temp[i-1+k][j-1+l].rgbtRed * Gx[k][l]);
                greenx = greenx + (temp[i-1+k][j-1+l].rgbtGreen * Gx[k][l]);
                bluex = bluex + (temp[i-1+k][j-1+l].rgbtBlue * Gx[k][l]);

                // calculate Gy
                redy = redy + (temp[i-1+k][j-1+l].rgbtRed * Gy[k][l]);
                greeny = greeny + (temp[i-1+k][j-1+l].rgbtGreen * Gy[k][l]);
                bluey = bluey + (temp[i-1+k][j-1+l].rgbtBlue * Gy[k][l]);
            }
        }

        int red = round(sqrt((redx * redx) + (redy * redy)));
        int green = round(sqrt((greenx * greenx) + (greeny * greeny)));
        int blue = round(sqrt((bluex * bluex) + (bluey * bluey)));

        if (red > 255)
            red = 255;
        if (green > 255)
            green = 255;
        if (blue > 255)
            blue = 255;

        // replace color values with new value
        image[i][j].rgbtRed = red;
        image[i][j].rgbtBlue = blue;
        image[i][j].rgbtGreen = green;
        }
    }
    return;
}
