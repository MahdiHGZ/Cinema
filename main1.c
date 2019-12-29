#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct mo{
    char name[100];
    int time;
    char imdblink[200];
};
struct sans {
    int t;
    int mov;
};
struct sa{
    int r;
    int s;
    struct sans ss[200];
};

void movr(struct mo x[],int n){
    FILE *p;
    p=fopen("film.txt","r");
    for (int i = 0; i < n; ++i) {
        fscanf(p,"%s %d %s",&x[i].name,&x[i].time,&x[i].imdblink);
    }
    fclose(p);
}

/***************
 *
 * Mahdi HGZ
 *
 ***************/
int main() {
    int x, y, m, n, q,nmov,nsalon;
    FILE *p;
    p=fopen("data.txt","r");
    fscanf(p,"%d\n%d",&nmov,&nsalon);
    fclose(p);
    struct mo movie[nmov];
    movr(movie,nmov);


    return 0;
}