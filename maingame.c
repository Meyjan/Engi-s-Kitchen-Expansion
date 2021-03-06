#include "interface.h"
#include "game_mechanic.h"

#include "fakestring.c"
#include "Array/modarray.c"
#include "Graph/modgraph.c"
#include "Matriks/modmatriks.c"
#include "Mesin/modmesinkar.c"
#include "Mesin/modmesinkata.c"
#include "Mesin/modmesintree.c"
#include "Point/modpoint.c"
#include "Queue/modqueue.c"
#include "Stack/modstackt.c"
#include "Tree/modpohon.c"

#include "interface.c"
#include "game_mechanic.c"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void clrscr()
{
    system("@cls||clear");
}


////////////////////////////////////////////////////////////////////////////////////////

int main(){
  clrscr();
  boolean customer_chance;
  boolean validmove;
  int choice;
  int money, life, time;
  char *command;
  char *playername;

  Graph MAP;
  Gaddress current_room;

  POINT player;
  POINT mejap; // Masih belum digunakan untuk menunjukkan meja dekat player

  Queue antrian;

  TabInt Order;

  Stack Hand;
  Stack Tray;

  BinTree resep;

  FILE *save;

  command = (char *) malloc (6 * sizeof(char)); //Alokasi string command sepanjang 6 karakter
  playername = (char *) malloc (15 * sizeof(char)); //Alokasi nama player sepanjang 15 karakter
  FakeStrCpy(playername,""); //Inisialisasi string nama player
  printf("player = %s1", playername);
  save = fopen("savefile.txt", "r");
  fscanf(save, "%s", playername);
  fclose(save);

  //Create Empties
  CreateEmptyStack(&Hand);
  CreateEmptyStack(&Tray);
  CreateEmptyArray(&Order);
  CreateEmptyQueue(&antrian, 5);
  CreateEmptyGraph(&MAP);
  printf("Reading tree\n");
  CreateTreeMakanan(&resep);
  printf("Tree telah terbaca\n");
  BacaPeta(&MAP, &player);
  printf("Map telah terbaca\n");
  current_room = SearchRuangan(MAP, CurrentRoom(MAP));
  //Nilai awal
  money = 0;
  life = 3;
  time = 0;

  clrscr();
//  MainMenu();
  printf(">>> ");
  //Membaca pilihan dari player
  scanf("%d", &choice);
  switch(choice){
    case 1:{
      NewGame(playername);
      sleep(1.5);
      StartGame(playername);
      break;
    }
    case 2:{
      StartGame(playername);
      break;
    }
    case 3:{
      clrscr();
      printf(" ______________________________________________________________________ \n");
      printf("|                                                                      |\n");
      printf("|                                CREDIT                                |\n");
      printf("|                                                                      |\n");
      printf("|                     13516080 - Putra Hardi Ramadhan                  |\n");
      printf("|                     13517059 - Nixon Andhika                         |\n");
      printf("|                     13517116 - Ferdy Santoso                         |\n");
      printf("|                     13517131 - Jan Meyer Saragih                     |\n");
      printf("|                     13517137 - Vincent Budianto                      |\n");
      printf("|______________________________________________________________________|\n");
      exit(0);
    }
    default:{
      printf("Wrong choice. Exiting program...");
      exit(0);
    }
  }
  sleep(1.5);
  if(choice == 1 || choice == 2 || choice == 3){
    while(life > 0){
      clrscr();
      validmove = true;
      customer_chance = (rand() % 100) < 5;
      if(customer_chance){
        AddQueue(&antrian);
      }

      Play(playername, money, life, time, current_room, MAP, antrian, Tray, Order, Hand, player);

      printf(">>> ");
      scanf("%s", command);
      if(FakeStrCmp(command, "GU") == 0){
        GoUP(&MAP, &current_room, &player, &validmove);
      } else if(FakeStrCmp(command, "GD") == 0){
        GoDOWN(&MAP, &current_room, &player, &validmove);
      } else if(FakeStrCmp(command, "GL") == 0){
        GoLEFT(&MAP, &current_room, &player, &validmove);
      } else if(FakeStrCmp(command, "GR") == 0){
        GoRIGHT(&MAP, &current_room, &player, &validmove);
      } else if(FakeStrCmp(command, "ORDER") == 0){
        mejap = MejaDekatPlayer(Ruangann(current_room), player);
        if((Ordinat(mejap) == 0)&&(Absis(mejap) == 0)) {
          printf("Tidak ada customer dekat player\n");
          sleep(1.5);
        } else if (!MElmt2(Ruangann(current_room), Ordinat(mejap), Absis(mejap))) {
          printf("Meja tersebut tidak memiliki pelanggan\n");
          sleep(1.5);
        } else{
          AddOrder(&current_room, mejap, &Order);
        }
      } else if(FakeStrCmp(command, "PUT") == 0){
        CreateFood(&Hand, &Tray, current_room, player, resep);
        sleep(1.5);
      } else if(FakeStrCmp(command, "TAKE") == 0){
        TakeFood(&Hand, current_room, player, resep);
        sleep(1.5);
      } else if(FakeStrCmp(command, "CH") == 0){
        EmptyHand(&Hand);
        sleep(1.5);
      } else if(FakeStrCmp(command, "CT") == 0){
        EmptyTray(&Tray);
        sleep(1.5);
      } else if(FakeStrCmp(command, "PLACE") == 0){
        PlaceCustomer(&current_room, &antrian, player);
      } else if(FakeStrCmp(command, "GIVE") == 0){
        GiveFood(&current_room, &Tray, &Order, player,&money);
        sleep(1.5);
      } else if(FakeStrCmp(command, "RECIPE") == 0){
        PrintTree(resep, 2);
        sleep(5);
      } else if(FakeStrCmp(command, "LEGEND") == 0){
        Legend();
        sleep(5);
      } else if(FakeStrCmp(command, "EXIT") == 0){
        clrscr();
        GameOver(playername, money, time);
      } else {
        validmove = false;
        printf("Move tidak valid\n");
        sleep(2);
      }

      if(validmove && FakeStrCmp(command, "RECIPE") != 0 && FakeStrCmp(command, "SAVE") != 0 && FakeStrCmp(command, "LOAD") != 0 && FakeStrCmp(command, "LEGEND") != 0){
        EveryTurn(&MAP, &life, &time, &Order, &antrian);
      }
    }
    clrscr();
    GameOver(playername, money, time);
    sleep(1.5);
    exit(0);
  }
  return 0;
}
