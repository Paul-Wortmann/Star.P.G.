#include <fstream>
#include "game.h"
#include "savegame.h"
#include "levels.h"

extern game_type game;

int Save_Game(int slot)
{
  char save_slot[17];
  if (slot == 0) for(int count = 0; count < 18; count++) save_slot[count] = Slot_00[count];
  if (slot == 1) for(int count = 0; count < 18; count++) save_slot[count] = Slot_01[count];
  if (slot == 2) for(int count = 0; count < 18; count++) save_slot[count] = Slot_02[count];
  if (slot == 3) for(int count = 0; count < 18; count++) save_slot[count] = Slot_03[count];
  if (slot == 4) for(int count = 0; count < 18; count++) save_slot[count] = Slot_04[count];
  std::fstream savegamefile(save_slot,std::ios::out|std::ios::binary|std::ios::trunc); 
  if (savegamefile.is_open())
  {
     savegamefile.write(reinterpret_cast<char*>(&game), sizeof(game_type));
     savegamefile.close();
  }
  else return(1);
  return(0);
};

int Load_Game(int slot)
{
  char save_slot[17];
  if (slot == 0) for(int count = 0; count < 18; count++) save_slot[count] = Slot_00[count];
  if (slot == 1) for(int count = 0; count < 18; count++) save_slot[count] = Slot_01[count];
  if (slot == 2) for(int count = 0; count < 18; count++) save_slot[count] = Slot_02[count];
  if (slot == 3) for(int count = 0; count < 18; count++) save_slot[count] = Slot_03[count];
  if (slot == 4) for(int count = 0; count < 18; count++) save_slot[count] = Slot_04[count];
  std::fstream savegamefile(save_slot,std::ios::in|std::ios::binary); 
  if (savegamefile.is_open())
  {
     savegamefile.read(reinterpret_cast<char*>(&game), sizeof(game_type));
     savegamefile.close();
  }
  else return(1); 
  return(0);
};
