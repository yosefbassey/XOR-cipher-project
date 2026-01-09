/*
 * XOR Stream Cipher
 * Author: Joseph Bassey
 * Description: Encrypts/Decrypts files using a single-byte XOR operation.
 * Usage: ./cipher <input_file> <output_file>
 */

#include <stdio.h>  
#include <stdlib.h> 

#define KEY 'D' 

int main(int argc, char *argv[]) {
    if (argc !=3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1; 
    }

    FILE *inputFile = fopen(argv[1], "rb");

    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "wb");

    int atom;
    while((atom = fgetc(inputFile)) != EOF) {
        // XOR operation is applied. The operation is reversible.
        // The original data can be obtained by running this twice.
        int encrypted_atom = atom ^ KEY;
        fputc(encrypted_atom, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}