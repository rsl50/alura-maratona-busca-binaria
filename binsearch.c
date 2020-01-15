#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================================================
// ==================================================
// https://www.ime.usp.br/~pf/algoritmos-livro/slides/SLIDES-A.pdf
int BuscaBinaria2 (int x, int n, int v[]) {
	return BuscaBinR (x, -1, n, v);
}

int BuscaBinR (int x, int e, int d, int v[]) {
	if (e == d-1) return d;
	else {
		int m = (e + d)/2;
		if (v[m] < x)
			return BuscaBinR (x, m, d, v);
		else
			return BuscaBinR (x, e, m, v);
	}
}
// ==================================================
// ==================================================
int BuscaBinaria (int x, int n, int v[]) {
	int e, m, d;
	e = -1; d = n;
	while (/*X*/ e < d - 1) {
		m = (e + d)/2;
		if (v[m] < x) e = m;
		else d = m;
	}
	return d;
}
// ==================================================
// ==================================================

int busca_binaria_iterativa (int de, int ate, int valor, int s[]) {
    while(de < ate){
        int meio = (de + ate)/2;    
        if(s[meio] < valor)
            de = meio + 1;
        else if(s[meio] == valor)
            ate = meio;
        else
            ate = meio-1;
    }

    if(de > ate)
        return -1;
    else{
        if(s[de] == valor)
            return de;
        else
            return -1;
    }
}
// ==================================================
// ==================================================

int busca_binaria_recursiva (int inicio, int fim, int valor, int array[]) {
	if (inicio > fim) return -1;
	
	if (inicio == fim) {
		if (array[inicio] == valor) return inicio;
		else return -1;
	} 
	
	int meio = (inicio + fim) / 2;
	
	if (array[meio] < valor) {
		return busca_binaria_recursiva(meio + 1, fim, valor, array);
	} else if (array[meio] == valor) {
		return busca_binaria_recursiva(inicio, meio, valor, array);
	} else {
		return busca_binaria_recursiva(inicio, meio - 1, valor, array);
	}
}


int main () {

	FILE * fp;
	fp = freopen("input1.txt", "r", stdin);

	char buf[17];
	memset(buf, 0, 17);

	if (fp != NULL) {
		while(fgets(buf, 17, fp) != NULL) {
			
			long int n, q;
			
			//fgets(buf, 17, fp);
			sscanf(buf, "%d %d", &n, &q);
			//printf("%d %d\n", n, q);
			
			int array[n];
			int i;
			char aux[n * 13 + 2];
			char *pEnd;
			memset(aux, 0, n * 13 + 2);			
			
			fgets(aux, n * 13 + 2, fp);
			for (i = 0; i < n; i++) {
				array[i] = strtof(aux, &pEnd);
				memcpy(aux, &pEnd[1], strlen(pEnd));
				//printf("%d ", array[i]);
			}
			
			for (i = 0; i < q; i++) {
				fgets(buf, 17, fp);
				int val = strtol(buf, NULL, 10);
				//printf("%d\n", val);
				
				printf("%d\n", busca_binaria_recursiva(0, n - 1, val, array));
				//printf("%d\n", busca_binaria_iterativa(0, n - 1, val, array));
			}
		}
	}
	
	return (0);
}
