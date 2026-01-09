/*
 * Frequency Analysis Breaker
 * Author: Joseph Bassey
 * Description: Cracks single-byte XOR encryption by detecting the most frequent byte
 * and assuming it represents a Space character (ASCII 32).
 */

#include <stdio.h>
#include <stdlib.h>

#define KEY_HINT ' '

int main (int argc, char*  argv[]) {
    if (argc != 2) {
        printf("Usage: %s <encrypted_file> \n", argv[0]);
        return 1;
    }

    FILE *encryptedFile = fopen(argv[1], "rb");
    if (encryptedFile == NULL) return 1;

    int counts[256] = {0};

    int atom;
    // Using the byte value itself as the index (The Data is the Address)
    while((atom = fgetc(encryptedFile)) != EOF) {
        counts[atom]++;
    }

    fclose(encryptedFile);

    int maximum_count = -1;
    int pref_byte = 0;

    // Find the most frequent byte from the File.
    for (int i=0; i < 256; i++) {
        if (counts[i] > maximum_count) {
            maximum_count = counts[i];
            pref_byte = i;
        }
    }

    printf("Most recurring byte: %d (seen %d times)\n", pref_byte, maximum_count);

    // Calculate the Key
    // Assuming the most request byte in the encrypted file corresponds
    // to the KEY_HINT-- the Space character (' ') in the plain text.
    int identified_key = pref_byte ^ KEY_HINT;
    printf("Identified Key: '%c' (Value: %d)\n", identified_key, identified_key);

    return 0;
}