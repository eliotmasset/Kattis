#include <stdio.h>
#include <iostream>

void merge(long long int* nuages, long long int loc, long long int rows, long long int cols) {
    int a = nuages[loc-1];
    int b = nuages[loc-cols];
    if(a == b) return;
    if(a < b) {
        for(long long int i = 0; i <= loc; i++)
            if(nuages[i] == b) nuages[i] = a;
    } else {
        for(long long int i = 0; i <= loc; i++)
            if(nuages[i] == a) nuages[i] = b;
    }
}



int main() {
    long long int row, col, number, a, r1, r2, c1, c2, a1, a2, len, compteur = 0, current_compteur = 0, precedent_haut = -1, precedant_gauche = -1;
    char ch;
    std::cin >> row >> col;
    len = row*col;
    //array of zeros :
    char* arr = new char[len/8];
    long long int* nuages = new long long int[len];
    for(long long int i = 0; i < row; i++) {
        for(long long int j = 0; j < col ; j++) {
            precedent_haut = -1;
            precedant_gauche = -1;
            std::cin >> ch;
            if(ch=='1') arr[(i*col+j)/8] |= (1 << (i*col+j)%8); // ou inclusif
            else arr[(i*col+j)/8] &= ~(1 << (i*col+j)%8); // et
            if( i > 0 ) precedent_haut = ((arr[((i-1)*col+j)/8] >> ((i-1)*col+j)%8)&1);
            if( j > 0 ) precedant_gauche = ((arr[(i*col+j-1)/8] >> (i*col+j-1)%8)&1);
            if( i == 0 && j == 0 ) {
                nuages[i*col+j] = compteur;
                compteur++;
                continue;
            }
            if(  ((arr[(i*col+j)/8] >> (i*col+j)%8)&1) == precedant_gauche && ((arr[(i*col+j)/8] >> (i*col+j)%8)&1) == precedent_haut ) {
                merge(nuages, i*col+j, row, col);
                nuages[i*col+j] = nuages[i*col+j-1];
            } else if(  ((arr[(i*col+j)/8] >> (i*col+j)%8)&1) == precedant_gauche ) nuages[i*col+j] = nuages[i*col+j-1];
            else if(  ((arr[(i*col+j)/8] >> (i*col+j)%8)&1) == precedent_haut ) nuages[i*col+j] = nuages[(i-1)*col+j];
            else nuages[i*col+j] = compteur++;
        }
    }
    std::cin >> number;
    for(long long int i = 0; i < number; i++) {
        std::cin >> r1 >> c1 >> r2 >> c2;
        if(nuages[(r1-1)*col+c1-1] == nuages[(r2-1)*col+c2-1] && (int) ((arr[((r1-1)*col+c1-1)/8] >> ((r1-1)*col+c1-1)%8)&1) == 1)
            std::cout << "decimal" << std::endl;
        else if(nuages[(r1-1)*col+c1-1] == nuages[(r2-1)*col+c2-1] && (int) ((arr[((r1-1)*col+c1-1)/8] >> ((r1-1)*col+c1-1)%8)&1) == 0)
            std::cout << "binary" << std::endl;
        else std::cout << "neither" << std::endl;
    }
    return 0;
}
