#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct mo{
    char name[100];
    int time;
    char imdblink[200];
};
struct san {
    int v;
    int t;
    int mov;
    int b[20][20];
};
struct sal{
    int r;
    int s;
    struct san ss[10];
};

void movr(struct mo x[],int n){
    FILE *p;
    p=fopen("film.txt","r");
    for (int i = 0; i < n; ++i) {
        fscanf(p,"%s %d %s",&x[i].name,&x[i].time,&x[i].imdblink);
    }
    fclose(p);
}
void salkesh(struct sal x,int n){
    printf("    ");
    for (int i = 0; i <x.s; ++i) {
        printf("%d ", i+1);
        if(i<9)printf(" ");
    }
    printf("\n");
    for (int j = 0; j < x.r; ++j) {
        printf("%d:",j+1);
        if(j<9)printf(" ");
        for (int i = 0; i < x.s; ++i) {
            if(x.ss[n].b[j][i]==0)printf("%c %c",192,217);
            else printf("%c%c%c",192,223,217);
        }
        printf("\n");
    }
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