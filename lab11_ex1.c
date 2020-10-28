#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
int main(){
//opening the file
int file= open("ex1.txt",O_RDWR);                                                                                      >fstat(file, &my_stat);
off_t filesize=my_stat.st_size;
//mapping
char* addr = mmap(NULL, filesize, PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);
off_t newsize= 18*sizeof(char);
//setting new size
ftruncate(file, newsize);
//copying
char* phrase = "This is a nice day";
for(int i=0; i<18; i++){
 addr[i]=phrase[i];
}
}