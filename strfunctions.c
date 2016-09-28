#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int nfstrcmp(char *s1, char *s2) {
  int len;
  if (nfstrlen(s1) < nfstrlen(s2)) {
    len = nfstrlen(s1);
  } else {
    len = nfstrlen(s2);
  }
  int lenCounter = len;
  while (lenCounter) {
    if (s1[lenCounter] != s2[lenCounter]) {
      return s1[len-lenCounter]-s2[len-lenCounter];
    }
    lenCounter--;
  }
  return 0;
}

char * nfstrchr(char *s, char c) {
  int len = nfstrlen(s);
  int lenCounter = len;
  while (lenCounter) {
    if (s[len-lenCounter] == c) {
      return s+len-lenCounter;
    }
    lenCounter--;
  }
  return NULL;
}
 
int main() {
  //strlen test - working
  printf("\n===strlen===\n");
  char s[] = "Hello";
  printf("s: %s\nstrlen(s): %d\n",s,nfstrlen(s));

  //strcpy test - working
  printf("\n===strcpy===\n");
  char s2[10];
  printf("s before copy: %s\n",s);
  printf("s2 before copy: %s\n",s2);
  printf("s2 after copy: %s\n",nfstrcpy(s2,s));

  //strncat test - working
  printf("\n===strncat===\n");
  char s3[20] = "Hello there";
  printf("s3: %s\n",s3);
  printf("s3 after ncat of s, n = 3: %s\n",nfstrncat(s3,s,3));

  //strcmp test - working
  printf("\n===strcmp===\n");
  char s4[] = "Goodbye";
  char s5[] = "Ok.";
  printf("%s compared to %s: %d (expecting %d)\n",s,s,nfstrcmp(s,s),strcmp(s,s));
  printf("%s compared to %s: %d (expecting %d)\n",s,s4,nfstrcmp(s,s4),strcmp(s,s4));
  printf("%s compared to %s: %d (expecting %d)\n",s4,s5,nfstrcmp(s4,s5),strcmp(s4,s5));

  //strchr test - working
  printf("\n===strchr===\n");
  printf("First occurrence of 'o' in %s: %s\n", s4, strchr(s4,'o'));
  printf("First occurrence of 'a' in %s: %s\n", s, strchr(s,'a'));

  //
}
