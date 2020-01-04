#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct mo{
    char name[100];
    int time;
    char imdblink[200];
};
struct san {
    time_t t;
    int mov;
    int b[20][20];
};
struct sal{
    int r;
    int s;
    int nsans;
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
void movw(struct mo x[],int n){
    FILE *p;
    p=fopen("film.txt","w");
    for (int i = 0; i < n; ++i) {
        fprintf(p,"%s %d %s\n",x[i].name,x[i].time,x[i].imdblink);
    }
    fclose(p);
}
void salonr(struct sal x[],int n){
    FILE *p;
    p=fopen("salon.txt","r");
    for (int i = 0; i < n; ++i) {
        fscanf(p,"%d %d %d",&x[i].r,&x[i].s,&x[i].nsans);
        for (int j = 0; j <x[i].nsans; ++j) {
            fscanf(p,"%d %d",&x[i].ss[j].t,&x[i].ss[j].mov);
            for (int k = 0; k <x[i].r; ++k) {
                for (int l = 0; l < x[i].s; ++l) {
                    fscanf(p,"%d",&x[i].ss[j].b[k][l]);
                }
            }
        }
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
    time_t now;
    time(&now);
    now-=1577824219;
    p=fopen("data.txt","r");
    fscanf(p,"%d\n%d",&nmov,&nsalon);
    fclose(p);
    struct mo movie[nmov+10];
    movr(movie,nmov);
    struct sal salon[nsalon];
    salonr(salon,1);
    salkesh(salon[0],0);
    return 0;
}