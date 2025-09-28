#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void oct_to_bin(const char *oct, char *out);
void oct_to_hex(const char *oct, char *out);
void hex_to_bin(const char *hex, char *out);
void to_sign_magnitude(int32_t n, char *out);
void to_ones_complement(int32_t n, char *out);
void to_twos_complement(uint32_t n, char *out);

int main()
{
    FILE *file = fopen("a2_test.txt", "r");
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return 1;
    }

    FILE *outputFile = fopen("output.txt", "w");


    char line[256];
    int test = 1;
    char *splitLine;
    char output[65];
    char testType[65];
    char testInput[65];
    uint32_t tN;
    char testOutput[65];
    int passCount = 0;
    char print_tables_actualOutput[512];
    char print_tables_expectedOutput[512];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';
        if (line[0] == 'o' || line[0] == 'h' || line[0] == 't')
        {
            splitLine = strtok(line, " ");
            if (splitLine != NULL)
                strcpy(testType, splitLine);


            if (strcmp(testType, "oct_to_bin") == 0)   //oct_to_bin case
            {
                splitLine = strtok(NULL, " ");
                if (splitLine != NULL)
                    strcpy(testInput, splitLine);

                splitLine = strtok(NULL, " ");
                if (splitLine != NULL)
                    strcpy(testOutput, splitLine);

                oct_to_bin(testInput, output);
                char testResult[10];
                if (strcmp(output, testOutput) == 0)
                {
                    strcpy(testResult, "[PASS]");
                    passCount++;
                }
                else
                    strcpy(testResult, "[FAIL]");
                fprintf(outputFile, "Test %d: %s(%s) -> Expected: %s, Got: %s %s\n", test, testType, testInput, testOutput, output, testResult);
                test++;
            }
            if (strcmp(testType, "oct_to_hex") == 0)   //oct_to_hex case
            {
                splitLine = strtok(NULL, " ");
                if (splitLine != NULL)
                    strcpy(testInput, splitLine);

                splitLine = strtok(NULL, " ");
                if (splitLine != NULL)
                    strcpy(testOutput, splitLine);

                oct_to_hex(testInput, output);
                char testResult[10];
                if (strcmp(output, testOutput) == 0)
                {
                    strcpy(testResult, "[PASS]");
                    passCount++;
                }
                else
                    strcpy(testResult, "[FAIL]");
                fprintf(outputFile, "Test %d: %s(%s) -> Expected: %s, Got: %s %s\n", test, testType, testInput, testOutput, output, testResult);
                test++;
            }
            if (strcmp(testType, "hex_to_bin") == 0)   //hex_to_bin case
            {
                splitLine = strtok(NULL, " ");
                if (splitLine != NULL)
                    strcpy(testInput, splitLine);

                splitLine = strtok(NULL, " ");
                if (splitLine != NULL)
                    strcpy(testOutput, splitLine);

                hex_to_bin(testInput, output);
                char testResult[10];
                if (strcmp(output, testOutput) == 0)
                {
                    strcpy(testResult, "[PASS]");
                    passCount++;
                }
                else
                    strcpy(testResult, "[FAIL]");
                fprintf(outputFile, "Test %d: %s(%s) -> Expected: %s, Got: %s %s\n", test, testType, testInput, testOutput, output, testResult);
                test++;
            }
            if (strcmp(testType, "to_sign_magnitude") == 0)   //to_sign_magnitude case
            {
                splitLine = strtok(NULL, " ");
                if (splitLine != NULL)
                    strcpy(testInput, splitLine);

                splitLine = strtok(NULL, " ");
                if (splitLine != NULL)
                    strcpy(testOutput, splitLine);

                
                tN = (int32_t)atof(testInput);
                to_sign_magnitude(tN, output);
                char testResult[10];
                if (strcmp(output, testOutput) == 0)
                {
                    strcpy(testResult, "[PASS]");
                    passCount++;
                }
                else
                    strcpy(testResult, "[FAIL]");
                fprintf(outputFile, "Test %d: %s(%s) -> Expected: %s, Got: %s %s\n", test, testType, testInput, testOutput, output, testResult);
                test++;
            }
            if (strcmp(testType, "to_ones_complement") == 0)   //to_ones_complement case
            {
                splitLine = strtok(NULL, " ");
                if (splitLine != NULL)
                    strcpy(testInput, splitLine);

                splitLine = strtok(NULL, " ");
                if (splitLine != NULL)
                    strcpy(testOutput, splitLine);

                
                tN = (int32_t)atof(testInput);
                to_ones_complement(tN, output);
                char testResult[10];
                if (strcmp(output, testOutput) == 0)
                {
                    strcpy(testResult, "[PASS]");
                    passCount++;
                }
                else
                    strcpy(testResult, "[FAIL]");
                fprintf(outputFile, "Test %d: %s(%s) -> Expected: %s, Got: %s %s\n", test, testType, testInput, testOutput, output, testResult);
                test++;
            }
            if (strcmp(testType, "to_twos_complement") == 0)   //to_twos_complement case
            {
                splitLine = strtok(NULL, " ");
                if (splitLine != NULL)
                    strcpy(testInput, splitLine);

                splitLine = strtok(NULL, " ");
                if (splitLine != NULL)
                    strcpy(testOutput, splitLine);

                
                tN = (uint32_t)atof(testInput);
                to_twos_complement(tN, output);
                char testResult[10];
                if (strcmp(output, testOutput) == 0)
                {
                    strcpy(testResult, "[PASS]");
                    passCount++;
                }
                else
                    strcpy(testResult, "[FAIL]");
                fprintf(outputFile, "Test %d: %s(%s) -> Expected: %s, Got: %s %s\n", test, testType, testInput, testOutput, output, testResult);
                test++;
            }
        }
    }

    fclose(file);
    fprintf(outputFile, "\nSummary: %d/%d passed\n", passCount, test - 1);
    fclose(outputFile);
    return 0;
}