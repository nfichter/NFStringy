#include <stdio.h>
#include <stdlib.h>

int nfstrlen(char *input) {
  int len = 0;
  while (*input) {
    input++;
    len++;
  }
  return len;
}

char * nfstrcpy(char *dest, char *source) {
  int len = nfstrlen(source);
  int lenCounter = len;
  while (lenCounter) {
    dest[len-lenCounter] = source[len-lenCounter];
    lenCounter--;
  }
  return dest;
}

/*
char * nfstrncpy(char *dest, char *source, int n) {

}
*/

/*
char * nfstrcat(char *dest, char *source) {

}
*/

char * nfstrncat(char *dest, char *source, int n) {
  int startingPos = nfstrlen(dest);
  int constN = n;
  while (n) {
    dest[startingPos+constN-n] = source[constN-n];
    n--;
  }
  dest[startingPos+constN] = 0;
  return dest;
}

int strcmp(char *s1, char *s2) {
  if (nfstrlen(s1) < nfstrlen(s2)) {
    len = s1;
  } else {
    len = s2;
  }
  lenCounter = len;
  while (lenCounter) {
    if (s1[lenCounter] != s2[lenCounter]) {
      return s1[lenCounter]-s2[lenCounter];
    }
    lenCounter--;
  }
  return 0;
}
 
int main() {
  //strlen test - working
  printf("\n");
  char s[] = "Hello";
  printf("s: %s\nstrlen(s): %d\n",s,nfstrlen(s));
  //strcpy test - working
  printf("\n");
  char s2[10];
  printf("s: %s\ns2 after copy: %s\n",s,nfstrcpy(s2,s));
  //strncat test - working
  printf("\n");
  char s3[20] = "Hello there";
  printf("s3: %s\ns3 after ncat of s, n = 3: %s\n",s3,nfstrncat(s3,s,3));
  //strcmp test - to be written
}
