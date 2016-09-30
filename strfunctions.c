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
  dest[len] = 0;
  return dest;
}

char * nfstrncpy(char *dest, char *source, int n) {
  if (n < 0) {
    return dest;
  }
  int len = n;
  int lenCounter = len;
  while (lenCounter) {
    dest[len-lenCounter] = source[len-lenCounter];
    lenCounter--;
  }
  dest[len] = 0;
  return dest;
}

char * nfstrcat(char *dest, char *source) {
  int startingPos = nfstrlen(dest);
  int len = nfstrlen(source);
  int lenCounter = len;
  while (lenCounter) {
    dest[startingPos+len-lenCounter] = source[len-lenCounter];
    lenCounter--;
  }
  dest[startingPos+len] = 0;
  return dest;
}

char * nfstrncat(char *dest, char *source, int n) {
  if (n < 0) {
    return dest;
  }
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
    if (s1[len-lenCounter] != s2[len-lenCounter]) {
      return s1[len-lenCounter]-s2[len-lenCounter];
    }
    lenCounter--;
  }
  if (nfstrlen(s1) == nfstrlen(s2)) {
    return 0;
  } else if (nfstrlen(s1) > nfstrlen(s2)) {
    return s1[nfstrlen(s1)-1];
  } else {
    return 0-s2[nfstrlen(s2)-1];
  }
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

char * nfstrstr(char *s1, char *s2) {
  if (nfstrchr(s1,s2[0]) == NULL) {
    return NULL;
  }
  char *rest = nfstrchr(s1,s2[0]);
  int lenOf2 = nfstrlen(s2);
  char s2cp[lenOf2];
  char *s2cpy = s2cp;
  char restcp[nfstrlen(rest)];
  char *restcpy = restcp;
  nfstrcpy(s2cpy,s2);
  nfstrncpy(restcpy,rest,lenOf2);
  if (strcmp(restcpy,s2cpy)) {
    return NULL;
  }
  return rest;
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
  printf("s2 after copy of s: %s\n",nfstrcpy(s2,s));

  //strncpy test - working
  printf("\n===strncpy===\n");
  char s8[5];
  char s9[] = "testingtesting123";
  printf("s before copy: %s\n",s);
  printf("s8 before copy: %s\n",s8);
  printf("s8 after copy of s, n = 2: %s\n",nfstrncpy(s8,s,2));
  printf("s9 before copy: %s\n",s9);
  printf("s8 after copy of s9, n = -1: %s\n",nfstrncpy(s8,s9,-1));

  //strcat test - working
  printf("\n===strcat===\n");
  char s10[] = "testingtesting456";
  printf("s10: %s\n",s10);
  printf("s10 after cat of s9: %s\n",nfstrcat(s10,s9));

  //strncat test - working
  printf("\n===strncat===\n");
  char s3[20] = "Hello there";
  printf("s3: %s\n",s3);
  printf("s3 after ncat of s, n = 3: %s\n",nfstrncat(s3,s,3));
  printf("s3 after ncat of s, n = -1: %s\n",nfstrncat(s3,s,-1));

  //strcmp test - working
  printf("\n===strcmp===\n");
  char s4[] = "Goodbye";
  char s5[] = "Ok.";
  char s11[] = "ab";
  char s12[] = "abc";
  printf("%s compared to %s: %d (expecting %d)\n",s,s,nfstrcmp(s,s),strcmp(s,s));
  printf("%s compared to %s: %d (expecting %d)\n",s,s4,nfstrcmp(s,s4),strcmp(s,s4));
  printf("%s compared to %s: %d (expecting %d)\n",s4,s5,nfstrcmp(s4,s5),strcmp(s4,s5));
  printf("%s compared to %s: %d (expecting %d)\n",s11,s12,nfstrcmp(s11,s12),strcmp(s11,s12));
  printf("%s compared to %s: %d (expecting %d)\n",s12,s11,nfstrcmp(s12,s11),strcmp(s12,s11));

  //strchr test - working
  printf("\n===strchr===\n");
  printf("First occurrence of 'o' in %s: %s (expecting %s)\n", s4, nfstrchr(s4,'o'), strchr(s4,'o'));
  printf("First occurrence of 'a' in %s: %s (expecting %s)\n", s, nfstrchr(s,'a'), strchr(s,'a'));

  //strstr test - working
  printf("\n===strstr===\n");
  char s6[] = "Helloelelel";
  char s7[] = "el";
  printf("First occurrence of %s in %s: %s (expecting %s)\n", s7, s6, nfstrstr(s6,s7), strstr(s6,s7));
  printf("First occurrence of %s in %s: %s (expecting %s)\n", s5, s6, nfstrstr(s6,s5), strstr(s6,s5));

  return 0;
}
