#include <iostream>
#include <cstring>

#define SIZE 10

typedef char* pchar;

using namespace std;

void printWord (pchar w){
    for ( ; *w != '\0'; w++){
            cout << *w ;
        }

}

bool isGreater (pchar w1, pchar w2){
    bool result = false;

    for (; *w1!='\0' || *w2!='\0'; w1++, w2++){
        if (*w1 >= 'A' && *w1 <= 'Z') *w1 += ' ';
        if (*w2 >= 'A' && *w2 <= 'Z') *w2 += ' ';

        if (*w1 != *w2) {
            if (*w1 > *w2) result = true;
            break;
        }
    }

    return result;
}

int main(){

    char words[SIZE][30];
    pchar pwords[SIZE];
    pchar ptemp;
    int i, j, min;

    for (i=0; i<SIZE; i++){
        cout << "Enter words " << i+1 << " : " ;
        cin.getline (words[i], 30);
        pwords[i] = words[i];

    }

    for (i=0; i<SIZE-1; i++){
        min = i;

        for (j=i+1; j<SIZE; j++){
            if (isGreater(pwords[min], pwords[j])) min = j;
        }

        if (min != i) {
            ptemp = pwords[min];
            pwords[min] = pwords[i];
            pwords[i] = ptemp;
        }

    }

    for (i=0; i<SIZE; i++){
        cout << i+1 << ".  ";
        printWord (pwords[i]);

        cout << endl;
    }

    return 0;
}

