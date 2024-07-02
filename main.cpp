#include <iostream>
#include <string.h>

struct pokemon{ // cada pokemon tem nome, ataque, defesa, vida e tipo nessa ordem
  char nome[100];
  int ataque;
  int defesa;
  int vida;
  char tipo[100];
};

struct jogador1{ //N pokemons do jogador 1 (N tem que ser de 1 a 100)
pokemon Pokemon1;
int N;
void numerodepokemons1(N,pokemon1);
};

struct jogador2{ //M pokemons do jogador 2 (M tem que ser de 1 a 100)
pokemon Pokemon2;
int M;
void numerodepokemons2(M,pokemon2);
};

struct arena{ // status da arena(dois jogadores, a batalha entre eles e as condições estabelecidas para a batalha)
jogador1 player1;
jogador2 player2;
void batalha(jogador1, jogador2);// jogador 1 vs jogador 2
void super_efetividade(jogador1, jogador2); // casos de super efetividade
void pouca_efetividade(jogador2, jogador1); // casos de pouca efetividade
};

void arena::batalha(jogador1 player1, jogador2 player2){ // batalha entre os pokemons do jogador 1 e 2, vida = defesa - ataque, imprimir jogador e pokemons vencedores
  while(pokemon1 && pokemon2 !=0){
    if(player1.defesa == player2.ataque){ // se a defesa do jogador 1 for igual ao ataque do jogador 2, ambos os pokemons perdem 1 ponto de vida
      player1.vida --;
      player2.vida --;
    }
    else{
      player1.vida = player1.defesa - player2.ataque;
    }
    if(player2.vida==0) printf("%s venceu %s", player1.nome, player2.nome); //quais pokemons venceram
    if(player1.vida==0) printf("%s venceu %s", player2.nome, player1.nome);
  }
  if(pokemon1==0){
    printf(player2.nome, "O jogador2 venceu");
    for(int i=0; i<M; i++){
      printf("O jogador %s possui %d pokemons sobreviventes", player2.nome, player2.M); //imprimir os pokemons derrotados do jogador 2 caso tenham
    }
  }
  else{
    printf(player1.nome, "O jogador1 venceu");
    for(int i=0; i<N; i++){
      printf("O jogador %s possui %d pokemons sobreviventes", player1.nome, player1.N); //imprimir os pokemons sobreviventes do jogador 1 caso tenham
    }
  }
}


void arena::super_efetividade(jogador1, jogador2){ //Casos de super efetividade, dano aumentado em 20%
  if (strcmp(player1.tipo, "elétrico") == 0 && strcmp(player2.tipo, "água") == 0) player1.ataque += player1.ataque *0.20;
  if(strcmp(player1.tipo, "água") == 0 && strcmp(player2.tipo, "fogo")==0) player1.ataque += player1.ataque *0.20;
  if(strcmp(player1.tipo, "fogo") == 0 && strcmp(player2.tipo, "gelo")==0) player1.ataque += player1.ataque *0.20;
  if(strcmp(player1.tipo, "gelo") == 0 && strcmp(player2.tipo,"pedra")==0) player1.ataque += player1.ataque *0.20;
  if(strcmp(player1.tipo, "pedra") == 0 && strcmp(player2.tipo, "elétrico")==0) player1.ataque += player1.ataque *0.20;
}

void arena::pouca_efetividade(jogador2, jogador1){ // Casos de pouca efetividade, dano diminuido em 20%
  if (strcmp(player1.tipo, "elétrico") == 0 && strcmp(player2.tipo, "pedra") == 0) player1.ataque -= player1.ataque *0.20;
  if(strcmp(player1.tipo, "água") == 0 && strcmp(player2.tipo, "elétrico")==0) player1.ataque -= player1.ataque *0.20;
  if(strcmp(player1.tipo, "fogo") == 0 && strcmp(player2.tipo, "agua")==0) player1.ataque -= player1.ataque *0.20;
  if(strcmp(player1.tipo, "gelo") == 0 && strcmp(player2.tipo,"fogo")==0) player1.ataque -= player1.ataque *0.20;
  if(strcmp(player1.tipo, "pedra") == 0 && strcmp(player2.tipo, "gelo")==0) player1.ataque -= player1.ataque *0.20;
}

void jogador1::numerodepokemons1(int N,player1){ // quantidade de pokemons do jogador 1
  for(int i = 0; i < player1.N; i++){
     Pokemon1 = malloc(N*(sizeof(pokemon));
  }
}

void jogador2::numerodepokemons2(int M,player2){ // quantidade de pokemons do jogador 2
  for(int j = 0; j < player2.M; j++){
     Pokemon2 = malloc(M*(sizeof(pokemon));
  }
}

int main() {
  jogador1 player1;// player 1
  jogador2 player2;// player 2
  arena Arena;
  int Npokemons_player1, Mpokemons_player2;
  //O numero de pokemons de cada jogador e seus dados sao lidos de um arquivo
  FILE* arquivo = fopen("pokemon.txt", "r"); 
  if(arquivo==NULL)
    printf("erro ao abrir o arquivo");
    while(fscanf(arquivo,"%d %d",&Npokemons_player1,&Mpokemons_player2) >=1 && <=100){ //condição verificada para que o programa continue rodando
        for(int i = 0; i < Npokemons_player1; i++){
          for(int j = 0; j <Mpokemons_player2; j++){            
            fscanf(arquivo, "%s %d %d %d %s", &player1[i].nome, &player1[i].ataque, &player1[i].defesa, player1[i].vida, player1[i].tipo);
            fscanf(arquivo, "%s %d %d %d %s", &player2[j].nome, &player2[j].ataque, &player2[j].defesa, player2[j].vida, player2[j].tipo);
            if(strcmp(player1[i].tipo, "água") != 0  || strcmp(player1[i].tipo, "fogo") != 0 || strcmp(player1[i].tipo, "gelo") != 0 || strcmp(player1[i].tipo, "elétrico") != 0 || strcmp(player1[i].tipo, "pedra") != 0) printf("Tipo invalido");
            break;
            if(strcmp(player2[j].tipo, "água") != 0  || strcmp(player2[j].tipo, "fogo") != 0 || strcmp(player2[j].tipo, "gelo") != 0 || strcmp(player2[j].tipo, "elétrico") != 0 || strcmp(player2[j].tipo, "pedra") != 0) printf("Tipo invalido");
            break;
          }
        }
        for(int i = 0; i < Npokemons_player1; i++){ //Os dados de ambos os jogadores devem ser impressos na tela
          for(int j = 0; j <Mpokemons_player2; j++){            
            fprintf(arquivo, "%s %d %d %d %s", &player1[i].nome, &player1[i].ataque, &player1[i].defesa, player1[i].vida,   player1[i].tipo);
            fprintf(arquivo, "%s %d %d %d %s", &player2[j].nome, &player2[j].ataque, &player2[j].defesa, player2[j].vida,   player2[j].tipo);
          }
        }
    }
  fclose(arquivo);

  

  return 0;

}