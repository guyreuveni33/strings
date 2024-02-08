#include "libstr.h"
#include <string.h>
#include <immintrin.h>

#include <stdio.h>

void print_m128i(__m128i value) {
    // Extract 16 bytes from the m128i register
    char result[16];
    _mm_storeu_si128((__m128i*)result, value);

    // Print the values
    for (int i = 0; i < 16; i++) {
        printf("%c ", result[i]);
    }
    printf("\n");
}

void remove_non_base64(char input[MAX_STR], char output[MAX_STR]) {
    // Set up constants for SIMD comparison
    __m128i base64_chars = _mm_setr_epi8(
            'a','z','A','Z','/','9','+','+',0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    );
    int j = 0;
    for (int i = 0; i < strlen(input); i += 16) {
        // Load 16 characters from input
        __m128i input_chars = _mm_loadu_si128((__m128i*)&input[i]);
        // Compare with base64 characters using cmpistrm
        __m128i compare_result = _mm_cmpistrm(base64_chars, input_chars,  0x44);
        // Extract the mask using movemask
        int mask = _mm_movemask_epi8(compare_result);
        // Store base64 characters in output
        for (int k = 0; k < 16; k++) {
            if ((mask & (1 << k)) != 0) {
                output[j++] = input[i + k];
            }
        }
    }

    output[j] = '\0';
}


int b64_distance(char str1[MAX_STR], char str2[MAX_STR]) {
    // Remove non-base 64 characters
    char cleaned_str1[MAX_STR];
    char cleaned_str2[MAX_STR];

    remove_non_base64(str1, cleaned_str1);
    remove_non_base64(str2, cleaned_str2);


    // Calculate base 64 value for cleaned_str1
    int result1 = 0;
    for (int i = 0; i < strlen(cleaned_str1); i++) {
        char c = cleaned_str1[i];
        int base64Value = 0;

        if ('A' <= c && c <= 'Z') {
            base64Value = c - 'A';
        } else if ('a' <= c && c <= 'z') {
            base64Value = c - 'a' + 26;
        } else if ('0' <= c && c <= '9') {
            base64Value = c - '0' + 52;
        } else if (c == '+') {
            base64Value = 62;
        } else if (c == '/') {
            base64Value = 63;
        }

        result1 = 64 * result1 + base64Value;
    }

    // Calculate base 64 value for cleaned_str2
    int result2 = 0;
    for (int i = 0; i < strlen(cleaned_str2); i++) {
        char c = cleaned_str2[i];
        int base64Value = 0;

        if ('A' <= c && c <= 'Z') {
            base64Value = c - 'A';
        } else if ('a' <= c && c <= 'z') {
            base64Value = c - 'a' + 26;
        } else if ('0' <= c && c <= '9') {
            base64Value = c - '0' + 52;
        } else if (c == '+') {
            base64Value = 62;
        } else if (c == '/') {
            base64Value = 63;
        }

        result2 = 64 * result2 + base64Value;
    }

    // Calculate the difference
    int difference = result2 - result1;

    return difference;
}