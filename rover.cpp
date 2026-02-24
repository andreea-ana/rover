#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

struct poz {
    int lin, col;
};

const int NMAX = 505;
int a[NMAX][NMAX];
int sigur[NMAX][NMAX];
int m[NMAX][NMAX];

int dl[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void lee_cer1(poz xs) {
    deque <poz> q;
    q.push_front(xs);
    a[xs.lin][xs.col] = 0;
    while(!q.empty()) {
        poz x = q.front();
        q.pop_front();
        for(int i = 0; i < 4; i++) {
            poz y;
            y.lin = x.lin + dl[i];
            y.col = x.col + dc[i];
            if(a[y.lin][y.col] == -1) { //nu a fost completat
                if(sigur[y.lin][y.col] == 0) { //este sigur
                    a[y.lin][y.col] = a[x.lin][x.col];
                    q.push_front(y);
                } else { //nu este sigur
                    a[y.lin][y.col] = a[x.lin][x.col] + 1;
                    q.push_back(y);
                }
            }
        }
    }
}

bool posibil(int g, int n) {
    //bordare
    for(int i = 0; i <= n + 1; i++) {
        a[i][0] = a[i][n+1] = a[0][i] = a[n + 1][i] = -2;
        sigur[i][0] = sigur[i][n+1] = sigur[0][i] = sigur[n + 1][i] = -2;
    }

    //facem o matrice cu zone periculoase(resetare)
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] = -1;
            if(m[i][j] < g)
                sigur[i][j] = 1; //1 inseamna periculos si 0 sigur
            else
                sigur[i][j] = 0;
        }
    }
    poz xs;
    xs.lin = 1;
    xs.col = 1;
    lee_cer1(xs);
    if(a[n][n] == 0)
        return true;
    return false;
}

int main() {
    ifstream fin("rover.in");
    ofstream fout("rover.out");

    int cer, n;

    fin >> cer >> n;

    if(cer == 1) {
        int g;
        fin >> g;
        //bordare
        for(int i = 0; i <= n + 1; i++) {
            a[i][0] = a[i][n+1] = a[0][i] = a[n + 1][i] = -2;
            sigur[i][0] = sigur[i][n+1] = sigur[0][i] = sigur[n + 1][i] = -2;
        }

        //facem o matrice cu zone periculoase
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int x;
                fin >> x;
                a[i][j] = -1;
                if(x  < g)
                    sigur[i][j] = 1; //1 inseamna periculos si 0 sigur
            }
        }
        poz xs;
        xs.lin = 1;
        xs.col = 1;
        lee_cer1(xs);
        fout << a[n][n];
    } else {
        int gmax = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                fin >> m[i][j];
                if(m[i][j] > gmax)
                    gmax = m[i][j];
            }
        }

        //cautare binara
        int st = 1;
        int dr = gmax;
        int rez = -1;
        while(st <= dr) {
            int mij = (st + dr) / 2;
            if(posibil(mij, n)){
                rez = mij;
                st = mij + 1;
            }else{
                dr = mij - 1;
            }
        }
        fout << rez;
    }


    fin.close();
    fout.close();
    return 0;
}
