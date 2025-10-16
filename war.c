#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIOS 5
#define TAM_NOME 50
#define TAM_COR 20

// Struct Territorio
struct Territorio {
    char nome[TAM_NOME];
    char corExercito[TAM_COR];
    int numeroTropas;
};

int main() {
    // Vetor estático de territórios
    struct Territorio territorios[MAX_TERRITORIOS];
    
    printf("=== CADASTRO DE TERRITORIOS - WAR ===\n\n");
    
    // Cadastro dos territórios
    for(int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("--- Territorio %d ---\n", i + 1);
        
        // Limpar buffer do teclado
        while(getchar() != '\n');
        
        // Nome do território
        printf("Nome: ");
        fgets(territorios[i].nome, TAM_NOME, stdin);
        // Remove o \n do final
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';
        
        // Cor do exército
        printf("Cor do Exercito: ");
        fgets(territorios[i].corExercito, TAM_COR, stdin);
        territorios[i].corExercito[strcspn(territorios[i].corExercito, "\n")] = '\0';
        
        // Número de tropas
        printf("Numero de Tropas: ");
        scanf("%d", &territorios[i].numeroTropas);
        
        printf("\n");
    }
    
    // Exibir estado atual do mapa
    printf("=== MAPA ATUAL ===\n");
    printf("------------------------------------------------------------\n");
    printf("%-3s | %-20s | %-15s | %-10s\n", "#", "TERRITORIO", "COR DO EXERCITO", "TROPAS");
    printf("------------------------------------------------------------\n");
    
    for(int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("%-3d | %-20s | %-15s | %-10d\n", 
               i + 1, 
               territorios[i].nome, 
               territorios[i].corExercito, 
               territorios[i].numeroTropas);
    }
    printf("------------------------------------------------------------\n");
    
    return 0;
}