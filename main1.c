#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct mo{
    char name[100];
    int time;
    char imdblink[200];
};
struct sa{

};
/***************
 *
 * Mahdi HGZ
 *
 ***************/
int main() {
    int x, y, m, n, q;
    FILE *film;
    film=fopen("film.txt","r");
    fscanf(film,"%d",&x);

    fclose(film);
    return 0;
}