#include <fstream>

#include "glut.h"
#include "DatosMemCompartida.h"
#include "Esfera.h"
#include "Raqueta.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
int fd;
struct stat bstat;
DatosMemCompartida * DMC;
Raqueta *r;
Esfera *e;


fd=open("BOTY", O_RDWR);
fstat(fd, &bstat);

DMC = (DatosMemCompartida*) mmap(0, bstat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);

close(fd);

while(1){
usleep(25000);
 if(r->y1==e->centro.y) DMC->accion=0;
 else {
 	if((r->y1) < (e->centro.y)) DMC->accion=1;
 	else DMC->accion=-1;}

}
munmap(DMC, bstat.st_size);

return 0;

}
