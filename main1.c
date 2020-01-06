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
void movkesh(struct mo x[],int n){
    for (int i = 0; i < n; ++i) {
        printf("%d:%s\n",i+1,x[i].name);
    }
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
void salonw(struct sal x[],int n){
    FILE *p;
    p=fopen("salon.txt","w");
    for (int i = 0; i < n; ++i) {
        fprintf(p,"%d %d %d",x[i].r,x[i].s,x[i].nsans);
        for (int j = 0; j <x[i].nsans; ++j) {
            fprintf(p,"%d %d",x[i].ss[j].t,x[i].ss[j].mov);
            for (int k = 0; k <x[i].r; ++k) {
                for (int l = 0; l < x[i].s; ++l) {
                    fprintf(p,"%d",x[i].ss[j].b[k][l]);
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
int  oksans(struct sal x,time_t t,int tm){

}
void sanssort(struct sal x){

};
int  addsans(struct sal x[], struct mo y[],int m){
    int n,a,b,c;
    time_t t;
    printf("Inter salon's number:\n");
    scanf("%d",&n);
    movkesh(y,m);
    printf("Inter film's number:\n");
    scanf("%d",&a);
    printf("Inter time of sans(Year(>2020) Month Day Hour(24) Minute):\n");
    long long int ye,mo,d,h,mi;
    scanf("%d %d %d %d %d",&ye,&mo,&d,&h,&mi);
    ye-=2020;
    mo--;
    mo+=ye*12;
    d--;
    d+=30*mo;
    h+=24*d;
    mi+=60*h;
    t=mi*60;
    t+=10;
    if(oksans(x[n-1],t,y[a-1].time)){
        x[n-1].ss[x[n-1].nsans].t=t;
        x[n-1].ss[x[n-1].nsans].mov=a-1;
        x[n-1].nsans++;
        sanssort(x[n-1]);
    } else{
        printf("The period is already token !!");
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
    printf("Time=%ld\n",now);
    p=fopen("data.txt","r");
    fscanf(p,"%d\n%d",&nmov,&nsalon);
    fclose(p);
    struct mo movie[nmov+10];
    movr(movie,nmov);
    struct sal salon[nsalon];
    salonr(salon,1);
    //salkesh(salon[0],1);
    //movkesh(movie,nmov);
    addsans(salon,movie,4);
    return 0;
}