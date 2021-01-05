#include <stdio.h>
#include <string.h>
#include "find.h"
int getline(char s[]){
     int c, i, j;
     for(i = 0, j = 0; (c = getchar())!=EOF && c != '\n'; ++i){
          if(i < LINE - 1){
               s[j++] = c;}}
          if(c == '\n'){
               if(i <= lim - 1){
                    s[j++] = c;}
               ++i;}
     s[j] = '\0';
     return i;
}
int getword(char s[]){
    int c, i, j;
    for(i = 0, j = 0; (c = getchar())!=EOF && c != '\n'&& c != '\t'&& c != ' '; ++i){
        if(i < WORD - 1){
            s[j++] = c;}}
    s[j] = '\0';
    return i;
}
int substring( char * str1, char * str2){
     char *cp = str1;
     char *c1, *c2;
     if ( !*str2 )
          return 1;
     while (*cp) {
          c1 = cp;
          c2 = str2;
           while ( *c1 && *c2 && !(*c1-*c2) )
                 c1++, c2++;
                 if (!*c2)
                      return 1;
                 cp++;  }
      return 0;
}
int similar(char *s, char *t, int n) {
     int i;
     while(*s) {
          i=0;
          while(*(t+i) != *s) {
                if(!(*(t+i)))
                     return 0;
                i++;}
           n-=i;
           s=s+1;
           t=t+i+1;}
     return (n==strlen(t));
}
void print_lines(char * str) {
      char line[LINE];
       while(getline(line)) {
             if(substring(line,str))
                  puts(line);}
}
void print_similar_words(char * str) {
       char word[WORD];
       int i;
       while(getword(word)) {
            i=1;
            while(i>=0) {
                  if(similar(str,word,i))
                         printf("%s\n",word);
                   i--; }}
} 