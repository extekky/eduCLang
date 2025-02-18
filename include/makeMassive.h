#ifndef MAKEMASSIVE_H
#define MAKEMASSIVE_H

long **make2dMassive(long col, long row);
void show2DMassive(long **massive, long row, long col);
void free2dMassive(long **massive, long row, short showMassage);

#endif