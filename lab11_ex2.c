#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main(void) {
  //buffer is can fit in up to 100 characters
  char buffer[100];
  //create a line buffer which outputs either when it is filled, or when it encounters new line character
  setvbuf(stdout, buffer, _IOLBF,100);
  int i=0;
  //\n for new line, \0 for correct work of strlen()
  char* hello="Hello\n\0";
  //now all characters in hello will be stored in the buffer first, then after(5 sec) \n is encoutered, the word in outputed
  for(int i=0; i<strlen(hello); i++){
     printf("%c", hello[i]);
     sleep(1);
  }
  return 0;
}