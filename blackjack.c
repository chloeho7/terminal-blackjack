#include <stdio.h>
#include <stdlib.h>
#include <time.h>


const int SIZE = 52;
int card [SIZE];
int lastShuffled = 0;

void fillDeck(){
  int counterDeck = 0;
  for(int i = 0; i <= 4; i++){
    for(int j = 1; j <= 13; j++){
      if (j > 10) {
        card[counterDeck++] = 10;  
      }
      else card[counterDeck++] = j;
    }
  }
  //shuffle
  for(int i = 0; i < SIZE; i++){
    int j = (rand()% (i+1));

    int temp = card[i];
    card[i]=card[j];
    card[j] = temp;
  }
}
void showCards(int arr[]){
  for(int i=0;i<10;i++){
    if(arr[i]!=0) printf("%d, ",arr[i]);
  }
}


void showDealerCards(int arr[]){
  for(int i=1;i<10;i++){
    if(arr[i]!=0) printf("%d, ",arr[i]);
  }
}

void givecard(int arr[]){
for(int i = 0; i < 10; i++){
  if (arr[i] == 0){
    arr[i] = card[lastShuffled++];
    break;
    }
  }
}



int cardSum(int arr[]) {
  int sum = 0; 
  for (int i = 0; i < 10; i++) {
    sum += arr[i]; 
  }
  return sum; 
}

void hitStay(int arr[]){
    int choice = 0;
    int checker = 0;
    while (cardSum(arr) <= 21 && choice != 2) { 
      do{
        printf("\n1. Hit\n2. Stay\nWhats your move: ");
        checker = scanf("%d",&choice);
        while (getchar() != '\n');
      }while((choice != 1 && choice != 2) || checker == 0);
      switch(choice) {
        case 1: printf("Heres your next card: ");
                givecard(arr);
                showCards(arr);
                break;
        case 2: break;
      }
    }
}

int dealerCheck(int arr[]) {
  if (cardSum(arr) >= 17) {
    return 1; 
  }
  else {
    return 0; 
  }
}

void winner (int player, int dealer) {
  if (player > 21) {
    printf("\nYOU Lose:(\n"); 
  }
  else if (dealer > 21) {
    printf("\nYOU WIN!!!!\n"); 
  }
  else if ( player == dealer) {
    printf("\nTie\n"); 
  }
  else if (player > dealer && player <= 21) {
    printf("\nYOU WIN!!!!\n"); 
  }
  else {
    printf("\nYOU Lose :(\n"); 
  }
}

int main(){
  srand(time(0));  
  int flag = 1; 
  while (flag) {
    system("clear");
    int playerCards[10] = {0};
    int dealer[10] = {0};
  
    lastShuffled = 0; 
    fillDeck();
    
    printf("Here are your cards:");
    givecard(playerCards);
    givecard(playerCards);
    showCards(playerCards);
    
    printf("\nHere are the dealer's cards: " );
    givecard(dealer);
    givecard(dealer);
    showDealerCards(dealer);
    hitStay(playerCards);
    
    while (dealerCheck(dealer) == 0) {
      givecard(dealer); 
    }
    
    printf("\nHere are your cards: ");
    showCards(playerCards);
    usleep(500000);
    printf("\nHere is the total of your cards: ");
    printf("%d", cardSum(playerCards)); 
    usleep(500000);
    printf("\nHere are the dealer's cards: ");
    showCards(dealer);
    usleep(500000);
    printf("\nHere is the total of the dealer's cards: "); 
    printf("%d", cardSum(dealer)); 
    usleep(500000);

    winner(cardSum(playerCards), cardSum(dealer));

    char playAgain = ' '; 
    printf("Do you want to play another round? (y/n) ");
    scanf(" %c", &playAgain); 
    switch (playAgain) {
      case 'y': break; 
      case 'n': flag = 0; 
            break; 
    }
  }
}
