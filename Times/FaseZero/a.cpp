#include <bits/stdc++.h>
using namespace std;
#define MAXN 30

double notas[4];
char line[MAXN];

int main(){
    int n; cin >> n;
    while(n--){
        for(int i = 0; i < 4; i++) notas[i] = 0;
        char nome[21];
        scanf(" %[^\n]", nome);
        scanf(" %[^\n]", line);

        int qnt_numeros = 0;
        int mod4 = 0;
        for(int i = 0; line[i] != '\0'; i++){
            if(mod4 % 4 == 0) notas[qnt_numeros] += line[i] - '0';
            if(mod4 % 4 == 2){
                notas[qnt_numeros] += 0.1*(line[i] - '0');
                qnt_numeros++; 
            }
            mod4++;
        }
        for(int i = 0; nome[i] != '\0'; i++) cout << nome[i]; cout << ": ";

        double res;

        if(qnt_numeros <= 2) res = (notas[0] + notas[1])/2;
        if(qnt_numeros == 3) res = (notas[0] + notas[1] + notas[2])/3;
        if(qnt_numeros == 4){
            double minimo = 99;
            for(int i = 0; i < 4; i++){
                if(minimo > notas[i]){
                    minimo = notas[i];
                }
            }
            res = (notas[0] + notas[1] + notas[2] + notas[3] - minimo);
            res /= 3;
        }

        printf("%0.1lf\n", res);
    }
}
