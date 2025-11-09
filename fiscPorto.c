#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define TAM_MAX_STRING 60

typedef struct {
    int numCodigo;
    char *codigo;
    char *cnpj;
    int peso; 
} item;

typedef struct {
    char *code;
    int numCode;
    int kg;
    int difPerc;
} divergente;

int busca_binaria(const item *vetor, int tamanho, item *chave) {
    int esquerda = 0;
    int direita = tamanho - 1;
    
    
    while (esquerda <= direita) {
        
        
        int meio = esquerda + (direita - esquerda) / 2;
        
        
        if (vetor[meio].numCodigo == chave->numCodigo) {
            return meio; 
        } 
        else if (chave->numCodigo < vetor[meio].numCodigo) {
            
            direita = meio - 1;
        } 
        else { 
            
            esquerda = meio + 1;
        }
    }
    
    return -1; 
}

void copiar(item* destino, const item* origem, int32_t tamanho) {
    
    
    memcpy(destino, origem, tamanho * sizeof(item));
}

void intercalar(item* S, item* E, int32_t i,int32_t m, int32_t j) {

    
    int32_t i1 = i, i2 = m + 1, k = i;
    
    while(i1 <= m && i2 <= j) {
        
        if(E[i1].numCodigo <= E[i2].numCodigo) S[k++] = E[i1++];
        else S[k++] = E[i2++];
    }
    
    if(i1 > m) copiar(&S[k], &E[i2], j - i2 + 1);
    else copiar(&S[k], &E[i1], m - i1 + 1);
    copiar(&E[i], &S[i], j - i + 1);

}

void mergesort(item* S, item* E, int32_t i,int32_t j) {

    
    if(i < j) {
        
        int32_t m = i + (j - i) / 2;
        
        mergesort(S, E, i, m);
        mergesort(S, E, m + 1, j);
        
        intercalar(S, E, i, m, j);
    }
} 

void copiarInvertido(divergente* destino, const divergente* origem, int32_t tamanho) {
    
    
    memcpy(destino, origem, tamanho * sizeof(divergente));
}

void intercalarInvertido(divergente* S, divergente* E, int32_t i,int32_t m, int32_t j) {

    
    int32_t i1 = i, i2 = m + 1, k = i;
    
    while(i1 <= m && i2 <= j) {
    
        if(E[i1].difPerc >= E[i2].difPerc) S[k++] = E[i1++];
        else S[k++] = E[i2++];
    }
    
    if(i1 > m) copiarInvertido(&S[k], &E[i2], j - i2 + 1);
    else copiarInvertido(&S[k], &E[i1], m - i1 + 1);
    copiarInvertido(&E[i], &S[i], j - i + 1);

}

void mergesortInvertido(divergente* S, divergente* E, int32_t i, int32_t j){
    if(i<j){
        int32_t m = i + (j-i)/2;
        mergesortInvertido(S, E, i, m);
        mergesortInvertido(S, E, m+1, j);
        intercalarInvertido(S, E, i, m, j);
    }
}




int main(int argc, char *argv[]) {
    int tamanhoImpress2 = 0;
    FILE *entrada;
    char *numCadastradosStr;
    numCadastradosStr = (char *) malloc(TAM_MAX_STRING * sizeof(char));
    char *numSelecionadosStr;
    numSelecionadosStr = (char *) malloc(TAM_MAX_STRING * sizeof(char));
    divergente *vetorImpressao2;
    vetorImpressao2 = (divergente *) malloc(100000 * sizeof(divergente));

    int indiceImpress2 = 0;

    // Basicamente é o arquivo
    entrada = fopen(argv[1], "r");
    // armazena o número de cadastrados como string
    fgets(numCadastradosStr, TAM_MAX_STRING, entrada);

    

    // faz casting de string para int
    int numCadastrados = atoi(numCadastradosStr);
    //cria o vetor de item's
    item *vetorCadastrados; 
    vetorCadastrados = (item *) malloc(numCadastrados * sizeof(item));
    //preenche o vetor
    for(int i=0; i<numCadastrados;i++){

        vetorCadastrados[i].codigo = (char *) malloc(TAM_MAX_STRING * sizeof(char));
        vetorCadastrados[i].cnpj = (char *) malloc(TAM_MAX_STRING * sizeof(char));

        char *linha;
        linha = (char *) malloc(TAM_MAX_STRING * sizeof(char));
        

        fgets(linha, TAM_MAX_STRING, entrada);

        sscanf(linha, "%4c%d %s %d", vetorCadastrados[i].codigo, &vetorCadastrados[i].numCodigo, vetorCadastrados[i].cnpj, &vetorCadastrados[i].peso );

        vetorCadastrados[i].codigo[4] = '\0';

        free(linha);

    }
    //printa o vetor
    
   
    
    //armazena o número de selecionados como String
    fgets(numSelecionadosStr, TAM_MAX_STRING, entrada);
    //printa

    //converte essa string em inteiro
    int numSelecionados = atoi(numSelecionadosStr);
    //cria o vetor de Selecionados
    item *vetorSelecionados;
    vetorSelecionados = (item *) malloc(numSelecionados * sizeof(item));
    //preenche o vetor
    for(int i = 0; i<numSelecionados; i++){

        vetorSelecionados[i].codigo = (char *) malloc(TAM_MAX_STRING * sizeof(char));
        vetorSelecionados[i].cnpj = (char *) malloc(TAM_MAX_STRING * sizeof(char));

        char *linha;
        linha = (char *) malloc(TAM_MAX_STRING * sizeof(char));

        fgets(linha, TAM_MAX_STRING, entrada);

        sscanf(linha, "%4c%d %s %d", vetorSelecionados[i].codigo, &vetorSelecionados[i].numCodigo, vetorSelecionados[i].cnpj, &vetorSelecionados[i].peso);

        vetorSelecionados[i].codigo[4] = '\0';

        free(linha);

    }
    //printa o vetor
    

  
    //cria o vetor auxiliar do mergesort e inicializa
    item *vetorAuxSelec;
    vetorAuxSelec = (item *) malloc(numSelecionados * sizeof(item));

    int indiceFinal = numSelecionados - 1;
    //chama o mergesort
    mergesort(vetorAuxSelec, vetorSelecionados, 0, indiceFinal);
    //printa a fração desejada de cada item do vetor
   

    //testes
    FILE *saida;

    saida = fopen(argv[2], "w");

    for(int i=0; i<numCadastrados; i++){
        
        int indice;
        indice = busca_binaria(vetorSelecionados, numSelecionados, &vetorCadastrados[i]);
        if(indice != -1){
            if(strcmp(vetorCadastrados[i].cnpj, vetorSelecionados[indice].cnpj) != 0){
                

                fprintf(saida, "%s%07d:%s<->%s\n", vetorCadastrados[i].codigo, vetorCadastrados[i].numCodigo, vetorCadastrados[i].cnpj, vetorSelecionados[indice].cnpj);

                
                
            } else {
                

                int diferencaKg = abs(vetorCadastrados[i].peso - vetorSelecionados[indice].peso);
                float numerador = diferencaKg * 100;
                float denominador = vetorCadastrados[i].peso;
                int diferencaPercentual = (int)round(numerador/denominador);

                if(diferencaPercentual > 10){

                    vetorImpressao2[indiceImpress2].code = (char *) malloc(TAM_MAX_STRING * sizeof(char));
                    
                    strcpy(vetorImpressao2[indiceImpress2].code, vetorCadastrados[i].codigo);
                    vetorImpressao2[indiceImpress2].numCode = vetorCadastrados[i].numCodigo;
                    vetorImpressao2[indiceImpress2].kg = diferencaKg;
                    vetorImpressao2[indiceImpress2].difPerc = diferencaPercentual;
                    
                    tamanhoImpress2++;
                    indiceImpress2++;

                }

                


            }


        }
        //char
    }

    divergente *vetorAuxImpress;
    vetorAuxImpress = (divergente *) malloc(tamanhoImpress2 * sizeof(divergente));

    int finalIndex = tamanhoImpress2 - 1;

    mergesortInvertido(vetorAuxImpress, vetorImpressao2, 0, finalIndex);
    

    
    for(int i=0; i<tamanhoImpress2; i++){
        

        
        
        if(i != (tamanhoImpress2 - 1)){
            fprintf(saida, "%s%07d:%dkg(%d%%)",  vetorImpressao2[i].code, vetorImpressao2[i].numCode, vetorImpressao2[i].kg, vetorImpressao2[i].difPerc);
            fprintf(saida, "\n");
        } else {
            fprintf(saida, "%s%07d:%dkg(%d%%)",  vetorImpressao2[i].code, vetorImpressao2[i].numCode, vetorImpressao2[i].kg, vetorImpressao2[i].difPerc);
        }

        
    }

    //finalização
    fclose(entrada);

    fclose(saida);

    return EXIT_SUCCESS;


}