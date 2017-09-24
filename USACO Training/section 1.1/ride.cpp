/*
ID: joonas.4
PROG: ride
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");

    char s[8]={}, p[8]={};
    fscanf (fin, "%s %s ", s, p);
    int a1 = s[0]-'A'+1, a2 = p[0]-'A'+1;
    for(int i=1; s[i]; ++i) a1 = (a1 * (s[i]-'A'+1)) % 47;
    for(int i=1; p[i]; ++i) a2 = (a2 * (p[i]-'A'+1)) % 47;
    fprintf (fout, "%s\n", a1 == a2 ? "GO" : "STAY");
    return 0;
}