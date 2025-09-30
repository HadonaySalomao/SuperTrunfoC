#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//agrupando todos os atributos 
typedef struct {
    char nome[20];
    int ataque;
    int defesa;
    int recuo;
}Carta;
//funcao para gerar valores aleatorios
int gerandoValor(){
    
    int resultado = rand() %100 + 1;
    return resultado;
}
//funca para criar a carta do jogandor
Carta criarcarta(int opcao){
    //Aqui como eu criei um struct para armazanar todos os atributos eu crio um variavel do tipo Carta
    Carta c;

    switch(opcao){
        case 1:
            //Quando faço <c.nome> é para guardar o valor no atributo do struct Carta
            sprintf(c.nome, "Brasil");
            break;
        case 2:
            
            sprintf(c.nome, "Estados Unidos");
            break;
        case 3:
            
            sprintf(c.nome, "Argentina");
            break;
        case 4:
            
            sprintf(c.nome, "Alemanha");
            break;
        case 5:
            
            sprintf(c.nome, "Inglaterra");
            break;
        default:
            sprintf(c.nome,"Não escolhido");
            break;
    }
//aq estou gerando valores aleatorios para cada atributo    
c.ataque = gerandoValor();    
c.defesa = gerandoValor();    
c.recuo = gerandoValor();    
//funcao para mostrar as cartas de cada jogador 
void mostrarCarta(Carta c){
    printf("\n=== Carta Escolhida: %s ===\n", c.nome);
    printf("Ataque: %d\n", c.ataque);
    printf("Defesa: %d\n", c.defesa);
    printf("Recuo : %d\n", c.recuo);
    printf("===========================\n");
}

}
int main(){
    srand(time(NULL)); // inicializa os números aleatórios
    int opcao1,opcao2;

    printf("========== MENU ==========\n");
    printf("ESCOLHA SUA CARTA\n");
    printf("1- BRASIL\n");
    printf("2- ESTADOS UNIDOS\n");
    printf("3- ARGENTINA\n");
    printf("4- ALEMANHA\n");
    printf("5- INGLATERRA\n");

    printf("\nJogador 1, escolha sua carta: ");
    scanf("%d", &opcao1);
    printf("Jogador 2, escolha sua carta: ");
    scanf("%d", &opcao2);
    // aqui estou criando a varial jogador para chamar a funcao e criar a carta dos jogadores
    Carta jogador1 = criarcarta(opcao1);
    Carta jogador2 = criarcarta(opcao2);

    //exibindo a carta dos jogadores
    mostrarCarta(jogador1);
    mostrarCarta(jogador2);

    //estou somando os atributos de cada jogador para descobrir o vencedor ou se deu empate
    int total1 = jogador1.ataque + jogador1.defesa + jogador1.recuo;
    int total2 = jogador2.ataque + jogador2.defesa + jogador2.recuo;

    printf("\nResultado da Partida:\n");
    if (total1 > total2) {
        printf("Jogador 1 venceu!\n");
    } else if (total2 > total1) {
        printf("Jogador 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;    
}