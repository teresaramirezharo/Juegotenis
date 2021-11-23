#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct mensaje {
	unsigned int numjug;
	unsigned int numpunt;
} m;

int main(int argc, char **argv) {
	int fd;
// borra FIFO por si existía previamente
    unlink("FIFO");
    
    /* crea el FIFO */
    if (mkfifo("FIFO", 0600)<0) {
        perror("No puede crearse el FIFO");
        return(1);
    }
    
    /* Abre el FIFO */
    if ((fd=open("FIFO", O_RDONLY))<0) {
        perror("No puede abrirse el FIFO");
        return(1);
    }
     mensaje m;
     while (read(fd, &m, sizeof(m))==sizeof(m)) {
        fprintf(stderr, "Jugador %d marca 1 punto, lleva un total de %d puntos.\n",m.numjug, m.numpunt);
	continue;
	}
    
    
    close(fd);
    unlink("FIFO");
    return(0);
}
