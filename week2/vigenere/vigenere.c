/*
Specification
Design and implement a program that encrypts messages using Vigenère’s cipher.
Implement your program in a file called vigenere.c in a directory called
vigenere.
Your program must accept a single command-line argument: a keyword, k, composed
entirely of alphabetical characters.

If your program is executed without any command-line arguments, with more than
one command-line argument, or with one command-line argument that contains any
non-alphabetical character, your program should print an error (of your choice)
and exit immediately, with main returning 1 (thereby signifying an error).

Otherwise, your program must proceed to prompt the user for a string of
plaintext, p, (as by a prompt for plaintext:) which it must then encrypt
according to Vigenère’s cipher with k, ultimately printing the result
(prepended with ciphertext: and ending with a newline) and exiting, with main
returning 0.

With respect to the characters in k, you must treat A and a as 0, B and b as
1, …​ , and Z and z as 25.

Your program must only apply Vigenère’s cipher to a character in p if that
character is a letter. All other characters (numbers, symbols, spaces,
punctuation marks, etc.) must be outputted unchanged. Moreover, if your code
is about to apply the jth character of k to the ith character of p, but the
latter proves to be a non-alphabetical character, you must wait to apply that
jth character of k to the next alphabetical character in p; you must not yet
advance to the next character in k.

Your program must preserve the case of each letter in p.
Compile with:
clang -ggdb3 -O0 -std=c11 -Wall -Werror vigenere.c -lcs50 -lm -o vigenere
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool containsOnlyLetters(string s);
int* convertToNumbers(string s);
string encrypt(string p, int* k);

int main(int argc, string argv[]) {
  // Make sure the correct number of arguments were supplied.
  if (argc < 2 || argc > 2) {
    printf("Error: Program takes exactly 1 argument.\n");
    return 1;
  }

  string k = argv[1];

  // Check to see if the command line argument contains any non-alpha chars.
  if (!containsOnlyLetters(k)) {
    printf("Error: Argument must contain only letters.\n");
    return 1;
  }

  // If it contains only letters, convert the key to it's numeric equivalent.
  int* key = convertToNumbers(k);

  // TESTING ONLY: Print key
  // printf("Key: ");
  // for (int i = 0, n = strlen(k); i < n; i++) {
  //   printf("%i", key[i]);
  // }
  // printf("\n");

  printf("Enter a string of plaintext: ");
  string p = GetString();
  // printf("Plaintext: %s\n", p);

  string cipher = encrypt(p, key);
  printf("%s\n", cipher);
  
  return 0;
}

/* *************************************************************************
End main. Begin custom function definitions.
************************************************************************* */

bool containsOnlyLetters(string s) {
  // Return true if s contains only letters. Otherwise return false.
  for (int i = 0, n = strlen(s); i < n; i++) {
    if ((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z')) {
      return false;
    }
  }
  return true;
}

int* convertToNumbers(string s) {
  /*
  Arguments: String of upper and lower case letters
  Returns: Array of ints corresponding to the letters in s.
  Ex: A/a = 0, B/b = 2, C/c = 3
  */
  int* array = malloc(sizeof(int) * strlen(s));

  for (int i = 0, n = strlen(s); i < n; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      array[i] = s[i] - 97;
    } else {
      array[i] = s[i] - 65;
    }
  }
  return array;
}

string encrypt(string p, int* k) {
  // Use Vigenere's cipher to encrypt string p with key k.
  string c = p;
  int counter = 0;
  int keyLength = sizeof(k) / sizeof(k[0]);

  for (int i = 0, n = strlen(p); i < n; i++) {
    // Only encrypt if p[i] is a letter.
    if ((p[i] >= 'a' || p[i] <= 'z') && (p[i] >= 'A' || p[i] <= 'Z')) {
      c[i] = (char) (p[i] + k[counter]);

      // Counter logic to continuously loop through k.
      if (counter < keyLength) {
        counter += 1;
      } else {
        counter = 0;
      }
    } else {
      // Otherwise, leave the character unchanged.
      c[i] = p[i];
    }
  }

  return (c);
}