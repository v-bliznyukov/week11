#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main ()
{
//opening files
int file= open("ex1.txt",O_RDWR);
int file_copy= open("ex1.memcpy.txt",O_RDWR);

//finding size of the file
struct stat my_stat ={};
fstat(file, &my_stat);
off_t filesize=my_stat.st_size;  

//mappind of initial file
char* addr = mmap(NULL, filesize, PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);
//mapping of the copy file with same size as initial
ftruncate(file_copy, filesize);
char* addr_copy = mmap(NULL, filesize, PROT_READ|PROT_WRITE, MAP_SHARED, file_copy, 0);

memcpy (addr_copy, addr, filesize);

close(file);
close(file_copy);
return 0;
}