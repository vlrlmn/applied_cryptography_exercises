#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_LEN 26

char rotor1[ALPHABET_LEN + 1] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
char rotor2[ALPHABET_LEN + 1] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
char rotor3[ALPHABET_LEN + 1] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
char reflector[ALPHABET_LEN + 1] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

int rotor1_pos = 0;
int rotor2_pos = 0;
int rotor3_pos = 0;

void rotate (char *rotor) {
    char first = rotor[0];

    memmove(rotor, rotor + 1, ALPHABET_LEN - 1);
    rotor[ALPHABET_LEN - 1] = first;
}

void rotate_rotors() {
    rotate(rotor1);
    rotor1_pos = (rotor1_pos + 1) % 26;
    if (rotor1_pos == 0) {
        rotate(rotor2);
        rotor2_pos = (rotor2_pos + 1) % 26;
        if (rotor2_pos == 0) {
            rotate(rotor3);
            rotor3_pos = (rotor3_pos + 1) % 26;
        }
    }
}

char forward(char c, char *rotor) {
    return rotor[c - 'A'];
}

char backward(char c, char *rotor) {
    for (int i = 0; i < ALPHABET_LEN; i++) {
        if (c == rotor[i])
            return 'A' + i;
    }
    return c;
}

char rotor_encrypt_char(char c) {
    if (!isalpha(c))
        return c;
    c = toupper(c);
    c = forward(c, rotor1);
    c = forward(c, rotor2);
    c = forward(c, rotor3);
    c = forward(c, reflector);

    c = backward(c, rotor3);
    c = backward(c, rotor2);
    c = backward(c, rotor1);

    rotate_rotors();
    return c;
}

void rotor_encrypt(char *input, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = rotor_encrypt_char(input[i]);
    }
    output[strlen(input)] = '\0'; 
}

int main () {
    char message[] = "HELLO ROTOR";

    char encrypted[100];
    char decrypted[100];

    char r1_orig[ALPHABET_LEN + 1], r2_orig[ALPHABET_LEN + 1], r3_orig[ALPHABET_LEN + 1];
    strcpy(r1_orig, rotor1);
    strcpy(r2_orig, rotor2);
    strcpy(r3_orig, rotor3);

    rotor_encrypt(message, encrypted);
    printf("ENCRYPTED: %s\n", encrypted);

    strcpy(rotor1, r1_orig);
    strcpy(rotor2, r2_orig);
    strcpy(rotor3, r3_orig);

    rotor_encrypt(encrypted, decrypted); 
    printf("\nDECRYPTED: %s\n", decrypted);
}