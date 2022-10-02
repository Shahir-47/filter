#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int b = 0; b < height; b++)
    {
        for (int a = 0; a < width; a++)
        {
            //takes in a rbg value and averages them
            avg = round((image[b][a].rgbtGreen + image[b][a].rgbtBlue + image[b][a].rgbtRed) / 3.0);
            //avg value assigned to each pixel colour for grey scale filter
            image[b][a].rgbtGreen = avg;
            image[b][a].rgbtBlue = avg;
            image[b][a].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    for (int b = 0; b < height; b++)
    {
        for (int a = 0; a < width; a++)
        {
            //coverting image pixel into sepia format using the formula below
            sepiaRed = round(.393 * image[b][a].rgbtRed + .769 * image[b][a].rgbtGreen + .189 * image[b][a].rgbtBlue);
            sepiaGreen = round(.349 * image[b][a].rgbtRed + .686 * image[b][a].rgbtGreen + .168 * image[b][a].rgbtBlue);
            sepiaBlue = round(.272 * image[b][a].rgbtRed + .534 * image[b][a].rgbtGreen + .131 * image[b][a].rgbtBlue);
            // validating the sepia value to not exceede 255
            if (sepiaRed < 256)
            {
                image[b][a].rgbtRed = sepiaRed;
            }
            else
            {
                //if above 255 the value will be stored as 255
                image[b][a].rgbtRed = 255;
            }
            if (sepiaGreen < 256)
            {
                image[b][a].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[b][a].rgbtGreen = 255;
            }
            if (sepiaBlue < 256)
            {
                image[b][a].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[b][a].rgbtBlue = 255;
            }            
        }
    }    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // variable t represents the last column
    int t = width - 1;
    int evenwidth;
    //evenwidth helps reflect the image in a evenly manner or so
    evenwidth = width / 2;
    for (int b = 0; b < height; b++)
    {
        for (int a = 0; a < evenwidth; a++)
        {
            //replacing the value by storing the primary value in the temp and the secondary value in the primary and temp in primary
            int tempred = image[b][a].rgbtRed;
            image[b][a].rgbtRed  = image[b][t].rgbtRed;
            image[b][t].rgbtRed = tempred;

            int tempblue = image[b][a].rgbtBlue;
            image[b][a].rgbtBlue  = image[b][t].rgbtBlue;
            image[b][t].rgbtBlue = tempblue;

            int tempgreen = image[b][a].rgbtGreen;
            image[b][a].rgbtGreen  = image[b][t].rgbtGreen;
            image[b][t].rgbtGreen = tempgreen;

            t = t - 1;

        }
        t = width - 1;
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE fake[height][width];
    int lastw = width - 1;
    int lasth = height - 1;
    for (int b = 0; b < height; b++)
    {
        for (int a = 0; a < width; a++)
        {
            float total = 0;
            int totalred = 0;
            int totalblue = 0;
            int totalgreen = 0;
            //the loops below is so that the element (b,a) neignbours that are 1 column or row can be averaged
            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x ++)
                {
                    //it will continue its loop if rows are outside the image
                    if (a + x > lastw || a + x < 0)
                    {
                        continue;
                    }
                    //it will continue its loop if columns are outside the image                    
                    if (b + y > lasth || b + y < 0)
                    {
                        continue;
                    }
                    //3x3 grid value being summed up
                    totalred = totalred + image[b + y][a + x].rgbtRed;
                    totalblue = totalblue + image[b + y][a + x].rgbtBlue;
                    totalgreen = totalgreen + image[b + y][a + x].rgbtGreen;
                    total = total + 1;
                    
                }
            }
            //3x3 grid values being averaged and stored in the orignal pixel
            fake[b][a].rgbtRed = round(totalred / total);
            fake[b][a].rgbtBlue = round(totalblue / total);
            fake[b][a].rgbtGreen = round(totalgreen / total);
        }   
        
    }
    for (int b = 0; b < height; b++)
    {
        for (int a = 0; a < width; a++)
        {
            //the alteration in the temporary image can now be applied to the original picture 
            image[b][a].rgbtGreen = fake[b][a].rgbtGreen;
            image[b][a].rgbtBlue = fake[b][a].rgbtBlue;
            image[b][a].rgbtRed = fake[b][a].rgbtRed;
        }
    }
    return;

}
