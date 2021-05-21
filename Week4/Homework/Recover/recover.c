#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;

    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open the raw file (card)
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }


    BYTE buffer[512];
    //char *filename = NULL;
    char filename[8];
    int count = 0;
    FILE *img = NULL;
    //while (fread(&buffer, 512, 1, input) != 512 * sizeof(BYTE))
    while (fread(&buffer, 512, 1, input) != 0)
    {
        //last condition is bitwise arithmetic:
        //just look at the first four bits (first hexadecimal digit) of this 8 bit byte and set the
        //remaining 4 bits to zero.
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count == 0)
            {
                sprintf(filename, "000.jpg");
                img = fopen(filename, "w");
                fwrite(&buffer, 512, 1, img);
                count++;
            }
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(&buffer, 512, 1, img);
                count++;
            }
        }
        else
        {
            if (count != 0)
            {
                fwrite(&buffer, 512, 1, img);
            }
        }

    }
    fclose(input);
}