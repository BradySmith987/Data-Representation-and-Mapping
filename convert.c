#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

void oct_to_bin(const char *oct, char *out)
{
    out[0] = '\0';
    int inputLength = strlen(oct);
    for (int i = 0; i < inputLength; i++)
    {
        switch (oct[i])
        {
            case ('0'):
            {
                strcat(out, "000");
                break;
            }
            case ('1'):
            {
                strcat(out, "001");
                break;
            }
            case ('2'):
            {
                strcat(out, "010");
                break;
            }
            case ('3'):
            {
                strcat(out, "011");
                break;
            }
            case ('4'):
            {
                strcat(out, "100");
                break;
            }
            case ('5'):
            {
                strcat(out, "101");
                break;
            }
            case ('6'):
            {
                strcat(out, "110");
                break;
            }
            case ('7'):
            {
                strcat(out, "111");
                break;
            }
        }
    }
}

void oct_to_hex(const char *oct, char *out)
{
    out[0] = '\0';
    
    char oTBOutput[256];
    oTBOutput[0] = '\0';
    oct_to_bin(oct, oTBOutput);
    int length = strlen(oTBOutput);

    char binByFour[5];
    binByFour[0] = '\0';
    int padding = 0;
    char paddingInput[4];
    paddingInput[0] = '\0';

    if (length%4 != 0)
    {
        if (length % 4 == 1)
        {
            padding = 3;
            paddingInput[0] = '0';
            paddingInput[1] = '0';
            paddingInput[2] = '0';
        }
        else if (length % 4 == 2)
        {
            padding = 2;
            paddingInput[0] = '0';
            paddingInput[1] = '0';
        }
        else if (length % 4 == 3)
        {
            padding = 1;
            paddingInput[0] = '0';
        }
        paddingInput[padding] = '\0';
        memmove(oTBOutput + padding, oTBOutput, length + 1);
        memcpy(oTBOutput, paddingInput, padding);
    }
    length = strlen(oTBOutput);

    for (int i = 0; i < length; i++)
    {
        binByFour[i%4] = oTBOutput[i];
        binByFour[(i%4)+1] = '\0';
        int allZeroCheck = 0;
        
        if (strlen(binByFour) == 4)
        {   if (binByFour[0] == '0' && binByFour[1] == '0' && binByFour[2] == '0' && binByFour[3] == '0' && i < 4 && length > 4)
                allZeroCheck = 1;
        }

        if (strlen(binByFour) == 4 && allZeroCheck == 0)
        {
            int bBFValue = 0;
            char hexDigit;
            char temp[2];
            bBFValue = ((binByFour[0] - '0') * 8) + ((binByFour[1] - '0') * 4) + 
                ((binByFour[2] - '0') * 2) + ((binByFour[3] - '0') * 1);
            if (bBFValue < 10)
                hexDigit = '0' + bBFValue;
            else
                hexDigit = 'A' + (bBFValue - 10);

            int outLen = strlen(out);
            out[outLen] = hexDigit;
            out[outLen+1] = '\0';
            binByFour[0] = '\0';
        }
    }
}

void hex_to_bin(const char *hex, char *out)
{
    out[0] = '\0';
    int length = strlen(hex);
    for (int i = 0; i < length; i++)
    {
        switch (hex[i])
        {
            case ('0'):
            {
                strcat(out, "0000");
                break;
            }
            case ('1'):
            {
                strcat(out, "0001");
                break;
            }
            case ('2'):
            {
                strcat(out, "0010");
                break;
            }
            case ('3'):
            {
                strcat(out, "0011");
                break;
            }
            case ('4'):
            {
                strcat(out, "0100");
                break;
            }
            case ('5'):
            {
                strcat(out, "0101");
                break;
            }
            case ('6'):
            {
                strcat(out, "0110");
                break;
            }
            case ('7'):
            {
                strcat(out, "0111");
                break;
            }
            case ('8'):
            {
                strcat(out, "1000");
                break;
            }
            case ('9'):
            {
                strcat(out, "1001");
                break;
            }
            case ('A'):
            {
                strcat(out, "1010");
                break;
            }
            case ('B'):
            {
                strcat(out, "1011");
                break;
            }
            case ('C'):
            {
                strcat(out, "1100");
                break;
            }
            case ('D'):
            {
                strcat(out, "1101");
                break;
            }
            case ('E'):
            {
                strcat(out, "1110");
                break;
            }
            case ('F'):
            {
                strcat(out, "1111");
                break;
            }
            case ('a'):
            {
                strcat(out, "1010");
                break;
            }
            case ('b'):
            {
                strcat(out, "1011");
                break;
            }
            case ('c'):
            {
                strcat(out, "1100");
                break;
            }
            case ('d'):
            {
                strcat(out, "1101");
                break;
            }
            case ('e'):
            {
                strcat(out, "1110");
                break;
            }
            case ('f'):
            {
                strcat(out, "1111");
                break;
            }
        }
    }
}

void to_sign_magnitude(int32_t n, char *out)
{
    char temp[65];
    int pos = 0;
    int32_t m = n;
    
    if (n < 0)
        n = (n * -1);
        
    while (n > 0)
    {
        int remainder = n % 2;
        n = n / 2;
        temp[pos++] = '0' + remainder;
    }

    for (int i = 0; i < pos; i++)
    {
        out[i] = temp[pos - i - 1];
    }
    out[pos] = '\0';
    
    int padding = 32 - strlen(out);
    int length = strlen(out);
    char paddingInput[33];
    if (m >= 0)
    {
        paddingInput[0] = '0';
        for (int i = 1; i < padding; i++)
        {
            paddingInput[i] = '0';
        }
        paddingInput[padding] = '\0';
    }
    else
    {
        paddingInput[0] = '1';
        for (int i = 1; i < padding; i++)
        {
            paddingInput[i] = '0';
        }
        paddingInput[padding] = '\0';
    }


    memmove(out + padding, out, length + 1);
    memcpy(out, paddingInput, padding);
}

void to_ones_complement(int32_t n, char *out)
{
    char temp[65];
    int pos = 0;
    int32_t m = n;

    if (n < 0)
        n = (n * -1);

    while (n > 0)
    {
        int remainder = n % 2;
        n = n / 2;
        temp[pos++] = '0' + remainder;
    }

    for (int i = 0; i < pos; i++)
    {
        out[i] = temp[pos - i - 1];
    }
    out[pos] = '\0';
    
    int padding = 32 - strlen(out);
    int length = strlen(out);
    char paddingInput[33];

    for (int i = 0; i < padding; i++)
    {
        paddingInput[i] = '0';
    }
    paddingInput[padding] = '\0';


    memmove(out + padding, out, length + 1);
    memcpy(out, paddingInput, padding);

    if (m < 0)
    {
        for (int i = 0; i < 32; i++)
        {
            out[i] = (out[i] == '0') ? '1' : '0';
        }
    }
}

void to_twos_complement(uint32_t n, char *out)
{
    char temp[65];
    int pos = 0;
        
    while (n > 0)
    {
        int remainder = n % 2;
        n = n / 2;
        temp[pos++] = '0' + remainder;
    }

    for (int i = 0; i < pos; i++)
    {
        out[i] = temp[pos - i - 1];
    }
    out[pos] = '\0';
    
    int padding = 32 - strlen(out);
    int length = strlen(out);
    char paddingInput[33];
    if (n >= 0)
    {
        for (int i = 0; i < padding; i++)
        {
            paddingInput[i] = '0';
        }
        paddingInput[padding+1] = '\0';
    }
    else
    {
        paddingInput[0] = '1';
        for (int i = 1; i < padding; i++)
        {
            paddingInput[i] = '0';
        }
        paddingInput[padding+1] = '\0';
    }


    memmove(out + padding, out, length + 1);
    memcpy(out, paddingInput, padding);
}