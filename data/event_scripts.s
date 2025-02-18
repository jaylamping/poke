#include "config.h"
#include "constants/global.h"
#include "constants/apprentice.h"
#include "constants/battle.h"
#include "constants/battle_arena.h"
#include "constants/battle_dome.h"
#include "constants/battle_factory.h"
#include "constants/battle_frontier.h"
#include "constants/battle_palace.h"
#include "constants/battle_pike.h"
#include "constants/battle_pyramid.h"
#include "constants/battle_setup.h"
#include "constants/battle_tent.h"
#include "constants/battle_tower.h"
#include "constants/berry.h"
#include "constants/cable_club.h"
#include "constants/coins.h"
#include "constants/contest.h"
#include "constants/daycare.h"
#include "constants/decorations.h"
#include "constants/easy_chat.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/field_poison.h"
#include "constants/field_specials.h"
#include "constants/field_tasks.h"
#include "constants/field_weather.h"
#include "constants/flags.h"
#include "constants/frontier_util.h"
#include "constants/game_stat.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/layouts.h"
#include "constants/lilycove_lady.h"
#include "constants/map_scripts.h"
#include "constants/maps.h"
#include "constants/mauville_old_man.h"
#include "constants/metatile_labels.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/pokemon.h"
#include "constants/roulette.h"
#include "constants/script_menu.h"
#include "constants/secret_bases.h"
#include "constants/songs.h"
#include "constants/sound.h"
#include "constants/species.h"
#include "constants/trade.h"
#include "constants/trainer_hill.h"
#include "constants/trainers.h"
#include "constants/tv.h"
#include "constants/union_room.h"
#include "constants/vars.h"
#include "constants/weather.h"
	.include "asm/macros.inc"
	.include "asm/macros/event.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.set ALLOCATE_SCRIPT_CMD_TABLE, 1
	.include "data/script_cmd_table.inc"

gSpecialVars::
	.4byte gSpecialVar_0x8000
	.4byte gSpecialVar_0x8001
	.4byte gSpecialVar_0x8002
	.4byte gSpecialVar_0x8003
	.4byte gSpecialVar_0x8004
	.4byte gSpecialVar_0x8005
	.4byte gSpecialVar_0x8006
	.4byte gSpecialVar_0x8007
	.4byte gSpecialVar_0x8008
	.4byte gSpecialVar_0x8009
	.4byte gSpecialVar_0x800A
	.4byte gSpecialVar_0x800B
	.4byte gSpecialVar_Facing
	.4byte gSpecialVar_Result
	.4byte gSpecialVar_ItemId
	.4byte gSpecialVar_LastTalked
	.4byte gSpecialVar_ContestRank
	.4byte gSpecialVar_ContestCategory
	.4byte gSpecialVar_MonBoxId
	.4byte gSpecialVar_MonBoxPos
	.4byte gSpecialVar_TextColor
	.4byte gSpecialVar_PrevTextColor
	.4byte gSpecialVar_0x8014
	.4byte gSpecialVar_Unused_0x8014
	.4byte gTrainerBattleOpponent_A

	.include "data/specials.inc"

gStdScripts::
	.4byte Std_ObtainItem              @ STD_OBTAIN_ITEM
	.4byte Std_FindItem                @ STD_FIND_ITEM
	.4byte Std_MsgboxNPC               @ MSGBOX_NPC
	.4byte Std_MsgboxSign              @ MSGBOX_SIGN
	.4byte Std_MsgboxDefault           @ MSGBOX_DEFAULT
	.4byte Std_MsgboxYesNo             @ MSGBOX_YESNO
	.4byte Std_MsgboxAutoclose         @ MSGBOX_AUTOCLOSE
	.4byte Std_ObtainDecoration        @ STD_OBTAIN_DECORATION
	.4byte Std_RegisteredInMatchCall   @ STD_REGISTER_MATCH_CALL
	.4byte Std_MsgboxGetPoints         @ MSGBOX_GETPOINTS
	.4byte Std_MsgboxPokenav           @ MSGBOX_POKENAV
	.4byte Std_PutItemAway             @ STD_PUT_ITEM_AWAY
	.4byte Std_ReceivedItem            @ STD_RECEIVED_ITEM

gStdScripts_End::

	.include "data/maps/hoenn/Hoenn_PetalburgCity/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MauvilleCity/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FortreeCity/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LittlerootTown/scripts.inc"
	.include "data/maps/hoenn/Hoenn_OldaleTown/scripts.inc"
	.include "data/maps/hoenn/Hoenn_DewfordTown/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LavaridgeTown/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FallarborTown/scripts.inc"
	.include "data/maps/hoenn/Hoenn_VerdanturfTown/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PacifidlogTown/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route101/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route102/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route103/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route104/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route105/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route106/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route107/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route108/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route109/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route111/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route112/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route113/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route114/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route115/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route116/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route117/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route118/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route119/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route120/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route121/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route122/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route123/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route124/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route125/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route126/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route127/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route128/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route129/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route130/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route131/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route132/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route133/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route134/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Underwater_Route124/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Underwater_Route126/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Underwater_Route127/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Underwater_Route128/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Underwater_Route129/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Underwater_Route105/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Underwater_Route125/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LittlerootTown_BrendansHouse_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LittlerootTown_BrendansHouse_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LittlerootTown_MaysHouse_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LittlerootTown_MaysHouse_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LittlerootTown_ProfessorBirchsLab/scripts.inc"
	.include "data/maps/hoenn/Hoenn_OldaleTown_House1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_OldaleTown_House2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_OldaleTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_OldaleTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_OldaleTown_Mart/scripts.inc"
	.include "data/maps/hoenn/Hoenn_DewfordTown_House1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_DewfordTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_DewfordTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_DewfordTown_Gym/scripts.inc"
	.include "data/maps/hoenn/Hoenn_DewfordTown_Hall/scripts.inc"
	.include "data/maps/hoenn/Hoenn_DewfordTown_House2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LavaridgeTown_HerbShop/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LavaridgeTown_Gym_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LavaridgeTown_Gym_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LavaridgeTown_House/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LavaridgeTown_Mart/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LavaridgeTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LavaridgeTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FallarborTown_Mart/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FallarborTown_BattleTentLobby/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FallarborTown_BattleTentCorridor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FallarborTown_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FallarborTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FallarborTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FallarborTown_CozmosHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FallarborTown_MoveRelearnersHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_VerdanturfTown_BattleTentLobby/scripts.inc"
	.include "data/maps/hoenn/Hoenn_VerdanturfTown_BattleTentCorridor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_VerdanturfTown_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_VerdanturfTown_Mart/scripts.inc"
	.include "data/maps/hoenn/Hoenn_VerdanturfTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_VerdanturfTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_VerdanturfTown_WandasHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_VerdanturfTown_FriendshipRatersHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_VerdanturfTown_House/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PacifidlogTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PacifidlogTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PacifidlogTown_House1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PacifidlogTown_House2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PacifidlogTown_House3/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PacifidlogTown_House4/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PacifidlogTown_House5/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PetalburgCity_WallysHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PetalburgCity_Gym/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PetalburgCity_House1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PetalburgCity_House2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PetalburgCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PetalburgCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PetalburgCity_Mart/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_SternsShipyard_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_SternsShipyard_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_BattleTentLobby/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_BattleTentCorridor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_NameRatersHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_PokemonFanClub/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_OceanicMuseum_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_OceanicMuseum_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_Harbor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_House/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SlateportCity_Mart/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MauvilleCity_Gym/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MauvilleCity_BikeShop/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MauvilleCity_House1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MauvilleCity_GameCorner/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MauvilleCity_House2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MauvilleCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MauvilleCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MauvilleCity_Mart/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_DevonCorp_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_DevonCorp_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_DevonCorp_3F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_Gym/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_PokemonSchool/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_Mart/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_Flat1_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_Flat1_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_House1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_CuttersHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_House2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_Flat2_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_Flat2_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_Flat2_3F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RustboroCity_House3/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FortreeCity_House1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FortreeCity_Gym/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FortreeCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FortreeCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FortreeCity_Mart/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FortreeCity_House2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FortreeCity_House3/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FortreeCity_House4/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FortreeCity_House5/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FortreeCity_DecorationShop/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_CoveLilyMotel_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_CoveLilyMotel_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_LilycoveMuseum_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_LilycoveMuseum_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_ContestLobby/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_ContestHall/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_UnusedMart/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_PokemonTrainerFanClub/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_Harbor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_MoveDeletersHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_House1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_House2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_House3/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_House4/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_DepartmentStore_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_DepartmentStore_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_DepartmentStore_3F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_DepartmentStore_4F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_DepartmentStore_5F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_DepartmentStoreRooftop/scripts.inc"
	.include "data/maps/hoenn/Hoenn_LilycoveCity_DepartmentStoreElevator/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity_Gym/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity_House1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity_House2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity_Mart/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity_House3/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity_StevensHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity_House4/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity_SpaceCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity_SpaceCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity_GameCorner_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MossdeepCity_GameCorner_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_Gym_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_Gym_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_Mart/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_House1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_House2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_House3/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_House4/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_House5/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_House6/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_House7/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_LotadAndSeedotHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_MysteryEventsHouse_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SootopolisCity_MysteryEventsHouse_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_SidneysRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_PhoebesRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_GlaciasRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_DrakesRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_ChampionsRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_Hall1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_Hall2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_Hall3/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_Hall4/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_Hall5/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_PokemonLeague_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_HallOfFame/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_EverGrandeCity_PokemonLeague_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route104_MrBrineysHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route104_PrettyPetalFlowerShop/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route111_WinstrateFamilysHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route111_OldLadysRestStop/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route112_CableCarStation/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MtChimney_CableCarStation/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route114_FossilManiacsHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route114_FossilManiacsTunnel/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route114_LanettesHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route116_TunnelersRestHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route117_PokemonDayCare/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route121_SafariZoneEntrance/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MeteorFalls_1F_1R/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MeteorFalls_1F_2R/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MeteorFalls_B1F_1R/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MeteorFalls_B1F_2R/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RusturfTunnel/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Underwater_SootopolisCity/scripts.inc"
	.include "data/maps/hoenn/Hoenn_DesertRuins/scripts.inc"
	.include "data/maps/hoenn/Hoenn_GraniteCave_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_GraniteCave_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_GraniteCave_B2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_GraniteCave_StevensRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_PetalburgWoods/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MtChimney/scripts.inc"
	.include "data/maps/hoenn/Hoenn_JaggedPass/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FieryPath/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MtPyre_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MtPyre_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MtPyre_3F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MtPyre_4F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MtPyre_5F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MtPyre_6F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MtPyre_Exterior/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MtPyre_Summit/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AquaHideout_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AquaHideout_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AquaHideout_B2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Underwater_SeafloorCavern/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SeafloorCavern_Entrance/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SeafloorCavern_Room1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SeafloorCavern_Room2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SeafloorCavern_Room3/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SeafloorCavern_Room4/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SeafloorCavern_Room5/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SeafloorCavern_Room6/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SeafloorCavern_Room7/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SeafloorCavern_Room8/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SeafloorCavern_Room9/scripts.inc"
	.include "data/maps/hoenn/Hoenn_CaveOfOrigin_Entrance/scripts.inc"
	.include "data/maps/hoenn/Hoenn_CaveOfOrigin_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_CaveOfOrigin_UnusedRubySapphireMap1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_CaveOfOrigin_UnusedRubySapphireMap2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_CaveOfOrigin_UnusedRubySapphireMap3/scripts.inc"
	.include "data/maps/hoenn/Hoenn_CaveOfOrigin_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_VictoryRoad_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_VictoryRoad_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_VictoryRoad_B2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_ShoalCave_LowTideEntranceRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_ShoalCave_LowTideInnerRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_ShoalCave_LowTideStairsRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_ShoalCave_LowTideLowerRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_ShoalCave_HighTideEntranceRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_ShoalCave_HighTideInnerRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NewMauville_Entrance/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NewMauville_Inside/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AbandonedShip_Deck/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AbandonedShip_Corridors_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AbandonedShip_Rooms_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AbandonedShip_Corridors_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AbandonedShip_Rooms_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AbandonedShip_Rooms2_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AbandonedShip_Underwater1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AbandonedShip_Room_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AbandonedShip_Rooms2_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AbandonedShip_CaptainsOffice/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AbandonedShip_Underwater2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AbandonedShip_HiddenFloorCorridors/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AbandonedShip_HiddenFloorRooms/scripts.inc"
	.include "data/maps/hoenn/Hoenn_IslandCave/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AncientTomb/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Underwater_Route134/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Underwater_SealedChamber/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SealedChamber_OuterRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SealedChamber_InnerRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_ScorchedSlab/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AquaHideout_UnusedRubyMap1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AquaHideout_UnusedRubyMap2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AquaHideout_UnusedRubyMap3/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SkyPillar_Entrance/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SkyPillar_Outside/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SkyPillar_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SkyPillar_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SkyPillar_3F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SkyPillar_4F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_ShoalCave_LowTideIceRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SkyPillar_5F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SkyPillar_Top/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MagmaHideout_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MagmaHideout_2F_1R/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MagmaHideout_2F_2R/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MagmaHideout_3F_1R/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MagmaHideout_3F_2R/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MagmaHideout_4F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MagmaHideout_3F_3R/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MagmaHideout_2F_3R/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MirageTower_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MirageTower_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MirageTower_3F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MirageTower_4F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_DesertUnderpass/scripts.inc"
	.include "data/maps/hoenn/Hoenn_ArtisanCave_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_ArtisanCave_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Underwater_MarineCave/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MarineCave_Entrance/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MarineCave_End/scripts.inc"
	.include "data/maps/hoenn/Hoenn_TerraCave_Entrance/scripts.inc"
	.include "data/maps/hoenn/Hoenn_TerraCave_End/scripts.inc"
	.include "data/maps/hoenn/Hoenn_AlteringCave/scripts.inc"
	.include "data/maps/hoenn/Hoenn_MeteorFalls_StevensCave/scripts.inc"
	.include "data/scripts/shared_secret_base.inc"
	.include "data/maps/hoenn/Hoenn_BattleColosseum_2P/scripts.inc"
	.include "data/maps/hoenn/Hoenn_TradeCenter/scripts.inc"
	.include "data/maps/hoenn/Hoenn_RecordCorner/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleColosseum_4P/scripts.inc"
	.include "data/maps/hoenn/Hoenn_ContestHall/scripts.inc"
	.include "data/maps/hoenn/Hoenn_InsideOfTruck/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SSTidalCorridor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SSTidalLowerDeck/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SSTidalRooms/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattlePyramidSquare01/scripts.inc"
	.include "data/maps/hoenn/Hoenn_UnionRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SafariZone_Northwest/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SafariZone_North/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SafariZone_Southwest/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SafariZone_South/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_OutsideWest/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleTowerLobby/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleTowerElevator/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleTowerCorridor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleTowerBattleRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SouthernIsland_Exterior/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SouthernIsland_Interior/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SafariZone_RestHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SafariZone_Northeast/scripts.inc"
	.include "data/maps/hoenn/Hoenn_SafariZone_Southeast/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_OutsideEast/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleTowerMultiPartnerRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleTowerMultiCorridor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleTowerMultiBattleRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleDomeLobby/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleDomeCorridor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleDomePreBattleRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleDomeBattleRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattlePalaceLobby/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattlePalaceCorridor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattlePalaceBattleRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattlePyramidLobby/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattlePyramidFloor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattlePyramidTop/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleArenaLobby/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleArenaCorridor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleArenaBattleRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleFactoryLobby/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleFactoryPreBattleRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattleFactoryBattleRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattlePikeLobby/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattlePikeCorridor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattlePikeThreePathRoom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattlePikeRoomNormal/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattlePikeRoomFinal/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_BattlePikeRoomWildMons/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_RankingHall/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_Lounge1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_ExchangeServiceCorner/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_Lounge2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_Lounge3/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_Lounge4/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_ScottsHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_Lounge5/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_Lounge6/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_Lounge7/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_ReceptionGate/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_Lounge8/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_Lounge9/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_PokemonCenter_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_PokemonCenter_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BattleFrontier_Mart/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FarawayIsland_Entrance/scripts.inc"
	.include "data/maps/hoenn/Hoenn_FarawayIsland_Interior/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BirthIsland_Exterior/scripts.inc"
	.include "data/maps/hoenn/Hoenn_BirthIsland_Harbor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_TrainerHill_Entrance/scripts.inc"
	.include "data/maps/hoenn/Hoenn_TrainerHill_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_TrainerHill_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_TrainerHill_3F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_TrainerHill_4F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_TrainerHill_Roof/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Exterior/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Harbor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Entrance/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_B1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Fork/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Up1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Up2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Up3/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Up4/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Top/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Down01/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Down02/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Down03/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Down04/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Down05/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Down06/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Down07/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Down08/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Down09/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Down10/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Down11/scripts.inc"
	.include "data/maps/hoenn/Hoenn_NavelRock_Bottom/scripts.inc"
	.include "data/maps/hoenn/Hoenn_TrainerHill_Elevator/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route104_Prototype/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route104_PrototypePrettyPetalFlowerShop/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route109_SeashoreHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110_TrickHouseEntrance/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110_TrickHouseEnd/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110_TrickHouseCorridor/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110_TrickHousePuzzle1/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110_TrickHousePuzzle2/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110_TrickHousePuzzle3/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110_TrickHousePuzzle4/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110_TrickHousePuzzle5/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110_TrickHousePuzzle6/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110_TrickHousePuzzle7/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110_TrickHousePuzzle8/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110_SeasideCyclingRoadSouthEntrance/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route110_SeasideCyclingRoadNorthEntrance/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route113_GlassWorkshop/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route123_BerryMastersHouse/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route119_WeatherInstitute_1F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route119_WeatherInstitute_2F/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route119_House/scripts.inc"
	.include "data/maps/hoenn/Hoenn_Route124_DivingTreasureHuntersHouse/scripts.inc"

	.include "data/maps/kanto/Kanto_ViridianForest/scripts.inc"
	.include "data/maps/kanto/Kanto_MtMoon_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_MtMoon_B1F/scripts.inc"
	.include "data/maps/kanto/Kanto_MtMoon_B2F/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_Exterior/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Corridor/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Corridor/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_3F_Corridor/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_B1F_Corridor/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_Deck/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_Kitchen/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_CaptainsOffice/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room1/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room2/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room3/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room4/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room5/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room7/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Room1/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Room2/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Room3/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Room4/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Room5/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Room6/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_B1F_Room1/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_B1F_Room2/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_B1F_Room3/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_B1F_Room4/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_B1F_Room5/scripts.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room6/scripts.inc"
	.include "data/maps/kanto/Kanto_UndergroundPath_NorthEntrance/scripts.inc"
	.include "data/maps/kanto/Kanto_UndergroundPath_NorthSouthTunnel/scripts.inc"
	.include "data/maps/kanto/Kanto_UndergroundPath_SouthEntrance/scripts.inc"
	.include "data/maps/kanto/Kanto_UndergroundPath_WestEntrance/scripts.inc"
	.include "data/maps/kanto/Kanto_UndergroundPath_EastWestTunnel/scripts.inc"
	.include "data/maps/kanto/Kanto_UndergroundPath_EastEntrance/scripts.inc"
	.include "data/maps/kanto/Kanto_DiglettsCave_NorthEntrance/scripts.inc"
	.include "data/maps/kanto/Kanto_DiglettsCave_B1F/scripts.inc"
	.include "data/maps/kanto/Kanto_DiglettsCave_SouthEntrance/scripts.inc"
	.include "data/maps/kanto/Kanto_VictoryRoad_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_VictoryRoad_3F/scripts.inc"
	.include "data/maps/kanto/Kanto_RocketHideout_B1F/scripts.inc"
	.include "data/maps/kanto/Kanto_RocketHideout_B2F/scripts.inc"
	.include "data/maps/kanto/Kanto_RocketHideout_B3F/scripts.inc"
	.include "data/maps/kanto/Kanto_RocketHideout_B4F/scripts.inc"
	.include "data/maps/kanto/Kanto_RocketHideout_Elevator/scripts.inc"
	.include "data/maps/kanto/Kanto_SilphCo_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_SilphCo_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_SilphCo_3F/scripts.inc"
	.include "data/maps/kanto/Kanto_SilphCo_4F/scripts.inc"
	.include "data/maps/kanto/Kanto_SilphCo_5F/scripts.inc"
	.include "data/maps/kanto/Kanto_SilphCo_6F/scripts.inc"
	.include "data/maps/kanto/Kanto_SilphCo_7F/scripts.inc"
	.include "data/maps/kanto/Kanto_SilphCo_8F/scripts.inc"
	.include "data/maps/kanto/Kanto_SilphCo_9F/scripts.inc"
	.include "data/maps/kanto/Kanto_SilphCo_10F/scripts.inc"
	.include "data/maps/kanto/Kanto_SilphCo_11F/scripts.inc"
	.include "data/maps/kanto/Kanto_SilphCo_Elevator/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonMansion_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonMansion_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonMansion_3F/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonMansion_B1F/scripts.inc"
	.include "data/maps/kanto/Kanto_SafariZone_Center/scripts.inc"
	.include "data/maps/kanto/Kanto_SafariZone_East/scripts.inc"
	.include "data/maps/kanto/Kanto_SafariZone_West/scripts.inc"
	.include "data/maps/kanto/Kanto_SafariZone_Center_RestHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_SafariZone_East_RestHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_SafariZone_North_RestHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_SafariZone_West_RestHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_SafariZone_SecretHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCave_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCave_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCave_B1F/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonLeague_LoreleisRoom/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonLeague_BrunosRoom/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonLeague_AgathasRoom/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonLeague_LancesRoom/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonLeague_ChampionsRoom/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonLeague_HallOfFame/scripts.inc"
	.include "data/maps/kanto/Kanto_RockTunnel_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_RockTunnel_B1F/scripts.inc"
	.include "data/maps/kanto/Kanto_SeafoamIslands_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_SeafoamIslands_B1F/scripts.inc"
	.include "data/maps/kanto/Kanto_SeafoamIslands_B2F/scripts.inc"
	.include "data/maps/kanto/Kanto_SeafoamIslands_B3F/scripts.inc"
	.include "data/maps/kanto/Kanto_SeafoamIslands_B4F/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_3F/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_4F/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_5F/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_6F/scripts.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_7F/scripts.inc"
	.include "data/maps/kanto/Kanto_PowerPlant/scripts.inc"
	.include "data/maps/kanto/Kanto_MtEmber_RubyPath_B4F/scripts.inc"
	.include "data/maps/kanto/Kanto_MtEmber_Exterior/scripts.inc"
	.include "data/maps/kanto/Kanto_MtEmber_SummitPath_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_MtEmber_SummitPath_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_MtEmber_SummitPath_3F/scripts.inc"
	.include "data/maps/kanto/Kanto_MtEmber_Summit/scripts.inc"
	.include "data/maps/kanto/Kanto_MtEmber_RubyPath_B5F/scripts.inc"
	.include "data/maps/kanto/Kanto_MtEmber_RubyPath_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_MtEmber_RubyPath_B1F/scripts.inc"
	.include "data/maps/kanto/Kanto_MtEmber_RubyPath_B2F/scripts.inc"
	.include "data/maps/kanto/Kanto_MtEmber_RubyPath_B3F/scripts.inc"
	.include "data/maps/kanto/Kanto_MtEmber_RubyPath_B1F_Stairs/scripts.inc"
	.include "data/maps/kanto/Kanto_MtEmber_RubyPath_B2F_Stairs/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_BerryForest/scripts.inc"
	.include "data/maps/kanto/Kanto_FourIsland_IcefallCave_Entrance/scripts.inc"
	.include "data/maps/kanto/Kanto_FourIsland_IcefallCave_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_FourIsland_IcefallCave_B1F/scripts.inc"
	.include "data/maps/kanto/Kanto_FourIsland_IcefallCave_Back/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_RocketWarehouse/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_DottedHole_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_DottedHole_B1F/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_DottedHole_B2F/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_DottedHole_B3F/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_DottedHole_B4F/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_DottedHole_SapphireRoom/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_PatternBush/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_AlteringCave/scripts.inc"
	.include "data/maps/kanto/Kanto_TrainerTower_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_TrainerTower_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_TrainerTower_3F/scripts.inc"
	.include "data/maps/kanto/Kanto_TrainerTower_4F/scripts.inc"
	.include "data/maps/kanto/Kanto_TrainerTower_5F/scripts.inc"
	.include "data/maps/kanto/Kanto_TrainerTower_6F/scripts.inc"
	.include "data/maps/kanto/Kanto_TrainerTower_7F/scripts.inc"
	.include "data/maps/kanto/Kanto_TrainerTower_8F/scripts.inc"
	.include "data/maps/kanto/Kanto_TrainerTower_Roof/scripts.inc"
	.include "data/maps/kanto/Kanto_TrainerTower_Lobby/scripts.inc"
	.include "data/maps/kanto/Kanto_TrainerTower_Elevator/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Entrance/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room1/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room2/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room3/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room4/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room5/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room6/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room7/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room8/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room9/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room10/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room11/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room12/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room13/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room14/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_TanobyRuins_MoneanChamber/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_TanobyRuins_LiptooChamber/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_TanobyRuins_WeepthChamber/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_TanobyRuins_DilfordChamber/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_TanobyRuins_ScufibChamber/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_TanobyRuins_RixyChamber/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_TanobyRuins_ViapoisChamber/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_DunsparceTunnel/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_SevaultCanyon_TanobyKey/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_Summit/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_Base/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_SummitPath_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_SummitPath_3F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_SummitPath_4F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_SummitPath_5F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_BasePath_B1F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_BasePath_B2F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_BasePath_B3F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_BasePath_B4F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_BasePath_B5F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_BasePath_B6F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_BasePath_B7F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_BasePath_B8F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_BasePath_B9F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_BasePath_B10F/scripts.inc"
	.include "data/maps/kanto/Kanto_NavelRock_BasePath_B11F/scripts.inc"
	.include "data/maps/kanto/Kanto_OneIsland_KindleRoad_EmberSpa/scripts.inc"
	.include "data/maps/kanto/Kanto_PalletTown/scripts.inc"
	.include "data/maps/kanto/Kanto_ViridianCity/scripts.inc"
	.include "data/maps/kanto/Kanto_PewterCity/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity/scripts.inc"
	.include "data/maps/kanto/Kanto_LavenderTown/scripts.inc"
	.include "data/maps/kanto/Kanto_VermilionCity/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity/scripts.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity/scripts.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland/scripts.inc"
	.include "data/maps/kanto/Kanto_IndigoPlateau_Exterior/scripts.inc"
	.include "data/maps/kanto/Kanto_SaffronCity/scripts.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_Connection/scripts.inc"
	.include "data/maps/kanto/Kanto_OneIsland/scripts.inc"
	.include "data/maps/kanto/Kanto_TwoIsland/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland/scripts.inc"
	.include "data/maps/kanto/Kanto_FourIsland/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland/scripts.inc"
	.include "data/maps/kanto/Kanto_Route1/scripts.inc"
	.include "data/maps/kanto/Kanto_Route2/scripts.inc"
	.include "data/maps/kanto/Kanto_Route3/scripts.inc"
	.include "data/maps/kanto/Kanto_Route4/scripts.inc"
	.include "data/maps/kanto/Kanto_Route5/scripts.inc"
	.include "data/maps/kanto/Kanto_Route6/scripts.inc"
	.include "data/maps/kanto/Kanto_Route7/scripts.inc"
	.include "data/maps/kanto/Kanto_Route8/scripts.inc"
	.include "data/maps/kanto/Kanto_Route9/scripts.inc"
	.include "data/maps/kanto/Kanto_Route10/scripts.inc"
	.include "data/maps/kanto/Kanto_Route11/scripts.inc"
	.include "data/maps/kanto/Kanto_Route12/scripts.inc"
	.include "data/maps/kanto/Kanto_Route13/scripts.inc"
	.include "data/maps/kanto/Kanto_Route14/scripts.inc"
	.include "data/maps/kanto/Kanto_Route15/scripts.inc"
	.include "data/maps/kanto/Kanto_Route16/scripts.inc"
	.include "data/maps/kanto/Kanto_Route17/scripts.inc"
	.include "data/maps/kanto/Kanto_Route18/scripts.inc"
	.include "data/maps/kanto/Kanto_Route19/scripts.inc"
	.include "data/maps/kanto/Kanto_Route20/scripts.inc"
	.include "data/maps/kanto/Kanto_Route21_North/scripts.inc"
	.include "data/maps/kanto/Kanto_Route21_South/scripts.inc"
	.include "data/maps/kanto/Kanto_Route22/scripts.inc"
	.include "data/maps/kanto/Kanto_Route23/scripts.inc"
	.include "data/maps/kanto/Kanto_Route24/scripts.inc"
	.include "data/maps/kanto/Kanto_Route25/scripts.inc"
	.include "data/maps/kanto/Kanto_OneIsland_KindleRoad/scripts.inc"
	.include "data/maps/kanto/Kanto_OneIsland_TreasureBeach/scripts.inc"
	.include "data/maps/kanto/Kanto_TwoIsland_CapeBrink/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_BondBridge/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_Port/scripts.inc"
	.include "data/maps/kanto/Kanto_Prototype_SeviiIsle_6/scripts.inc"
	.include "data/maps/kanto/Kanto_Prototype_SeviiIsle_7/scripts.inc"
	.include "data/maps/kanto/Kanto_Prototype_SeviiIsle_8/scripts.inc"
	.include "data/maps/kanto/Kanto_Prototype_SeviiIsle_9/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_ResortGorgeous/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_WaterLabyrinth/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_Meadow/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_MemorialPillar/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_OutcastIsland/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_GreenPath/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_WaterPath/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_RuinValley/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_TrainerTower/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_SevaultCanyon_Entrance/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_SevaultCanyon/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_TanobyRuins/scripts.inc"
	.include "data/maps/kanto/Kanto_PalletTown_PlayersHouse_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_PalletTown_PlayersHouse_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_PalletTown_RivalsHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_PalletTown_ProfessorOaksLab/scripts.inc"
	.include "data/maps/kanto/Kanto_ViridianCity_House/scripts.inc"
	.include "data/maps/kanto/Kanto_ViridianCity_Gym/scripts.inc"
	.include "data/maps/kanto/Kanto_ViridianCity_School/scripts.inc"
	.include "data/maps/kanto/Kanto_ViridianCity_Mart/scripts.inc"
	.include "data/maps/kanto/Kanto_ViridianCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_ViridianCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_PewterCity_Museum_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_PewterCity_Museum_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_PewterCity_Gym/scripts.inc"
	.include "data/maps/kanto/Kanto_PewterCity_Mart/scripts.inc"
	.include "data/maps/kanto/Kanto_PewterCity_House1/scripts.inc"
	.include "data/maps/kanto/Kanto_PewterCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_PewterCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_PewterCity_House2/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_House1/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_House2/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_House3/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_Gym/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_BikeShop/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_Mart/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_House4/scripts.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_House5/scripts.inc"
	.include "data/maps/kanto/Kanto_LavenderTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_LavenderTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_LavenderTown_VolunteerPokemonHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_LavenderTown_House1/scripts.inc"
	.include "data/maps/kanto/Kanto_LavenderTown_House2/scripts.inc"
	.include "data/maps/kanto/Kanto_LavenderTown_Mart/scripts.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_House1/scripts.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_PokemonFanClub/scripts.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_House2/scripts.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_Mart/scripts.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_Gym/scripts.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_House3/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_DepartmentStore_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_DepartmentStore_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_DepartmentStore_3F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_DepartmentStore_4F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_DepartmentStore_5F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_DepartmentStore_Roof/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_DepartmentStore_Elevator/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Condominiums_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Condominiums_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Condominiums_3F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Condominiums_Roof/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Condominiums_RoofRoom/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_GameCorner/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_GameCorner_PrizeRoom/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Gym/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Restaurant/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_House1/scripts.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Hotel/scripts.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_SafariZone_Entrance/scripts.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_Mart/scripts.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_SafariZone_Office/scripts.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_Gym/scripts.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_House1/scripts.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_WardensHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_House2/scripts.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_House3/scripts.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_Gym/scripts.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_PokemonLab_Entrance/scripts.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_PokemonLab_Lounge/scripts.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_PokemonLab_ResearchRoom/scripts.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_PokemonLab_ExperimentRoom/scripts.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_Mart/scripts.inc"
	.include "data/maps/kanto/Kanto_IndigoPlateau_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_IndigoPlateau_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_CopycatsHouse_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_CopycatsHouse_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_Dojo/scripts.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_Gym/scripts.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_House/scripts.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_Mart/scripts.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_MrPsychicsHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_PokemonTrainerFanClub/scripts.inc"
	.include "data/maps/kanto/Kanto_Route2_ViridianForest_SouthEntrance/scripts.inc"
	.include "data/maps/kanto/Kanto_Route2_House/scripts.inc"
	.include "data/maps/kanto/Kanto_Route2_EastBuilding/scripts.inc"
	.include "data/maps/kanto/Kanto_Route2_ViridianForest_NorthEntrance/scripts.inc"
	.include "data/maps/kanto/Kanto_Route4_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route4_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route5_PokemonDayCare/scripts.inc"
	.include "data/maps/kanto/Kanto_Route5_SouthEntrance/scripts.inc"
	.include "data/maps/kanto/Kanto_Route6_NorthEntrance/scripts.inc"
	.include "data/maps/kanto/Kanto_Route6_UnusedHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_Route7_EastEntrance/scripts.inc"
	.include "data/maps/kanto/Kanto_Route8_WestEntrance/scripts.inc"
	.include "data/maps/kanto/Kanto_Route10_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route10_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route11_EastEntrance_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route11_EastEntrance_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route12_NorthEntrance_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route12_NorthEntrance_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route12_FishingHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_Route15_WestEntrance_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route15_WestEntrance_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route16_House/scripts.inc"
	.include "data/maps/kanto/Kanto_Route16_NorthEntrance_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route16_NorthEntrance_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route18_EastEntrance_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route18_EastEntrance_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_Route19_UnusedHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_Route22_NorthEntrance/scripts.inc"
	.include "data/maps/kanto/Kanto_Route23_UnusedHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_Route25_SeaCottage/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_House_Room1/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_House_Room2/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_Mart/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_UnusedHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_Harbor/scripts.inc"
	.include "data/maps/kanto/Kanto_OneIsland_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_OneIsland_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_OneIsland_House1/scripts.inc"
	.include "data/maps/kanto/Kanto_OneIsland_House2/scripts.inc"
	.include "data/maps/kanto/Kanto_OneIsland_Harbor/scripts.inc"
	.include "data/maps/kanto/Kanto_TwoIsland_JoyfulGameCorner/scripts.inc"
	.include "data/maps/kanto/Kanto_TwoIsland_House/scripts.inc"
	.include "data/maps/kanto/Kanto_TwoIsland_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_TwoIsland_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_TwoIsland_Harbor/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_House1/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_Mart/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_House2/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_House3/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_House4/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_House5/scripts.inc"
	.include "data/maps/kanto/Kanto_FourIsland_PokemonDayCare/scripts.inc"
	.include "data/maps/kanto/Kanto_FourIsland_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_FourIsland_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_FourIsland_House1/scripts.inc"
	.include "data/maps/kanto/Kanto_FourIsland_LoreleisHouse/scripts.inc"
	.include "data/maps/kanto/Kanto_FourIsland_Harbor/scripts.inc"
	.include "data/maps/kanto/Kanto_FourIsland_House2/scripts.inc"
	.include "data/maps/kanto/Kanto_FourIsland_Mart/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_Harbor/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_House1/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_House2/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_PokemonCenter_1F/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_PokemonCenter_2F/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_Harbor/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_House/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_Mart/scripts.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_Harbor/scripts.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_ResortGorgeous_House/scripts.inc"
	.include "data/maps/kanto/Kanto_TwoIsland_CapeBrink_House/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_WaterPath_House1/scripts.inc"
	.include "data/maps/kanto/Kanto_SixIsland_WaterPath_House2/scripts.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_SevaultCanyon_House/scripts.inc"

	; Kanto Texts incs

	.include "data/maps/kanto/Kanto_ViridianForest/text.inc"
	.include "data/maps/kanto/Kanto_MtMoon_1F/text.inc"
	.include "data/maps/kanto/Kanto_MtMoon_B2F/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Corridor/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Corridor/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_3F_Corridor/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_Deck/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_Kitchen/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_CaptainsOffice/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room1/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room2/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room3/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room4/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room5/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room7/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Room1/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Room2/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Room3/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Room4/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Room5/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_2F_Room6/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_B1F_Room1/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_B1F_Room2/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_B1F_Room3/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_B1F_Room4/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_B1F_Room5/text.inc"
	.include "data/maps/kanto/Kanto_SSAnne_1F_Room6/text.inc"
	.include "data/maps/kanto/Kanto_UndergroundPath_SouthEntrance/text.inc"
	.include "data/maps/kanto/Kanto_UndergroundPath_WestEntrance/text.inc"
	.include "data/maps/kanto/Kanto_UndergroundPath_EastEntrance/text.inc"
	.include "data/maps/kanto/Kanto_DiglettsCave_NorthEntrance/text.inc"
	.include "data/maps/kanto/Kanto_DiglettsCave_SouthEntrance/text.inc"
	.include "data/maps/kanto/Kanto_VictoryRoad_2F/text.inc"
	.include "data/maps/kanto/Kanto_VictoryRoad_3F/text.inc"
	.include "data/maps/kanto/Kanto_RocketHideout_B1F/text.inc"
	.include "data/maps/kanto/Kanto_RocketHideout_B2F/text.inc"
	.include "data/maps/kanto/Kanto_RocketHideout_B3F/text.inc"
	.include "data/maps/kanto/Kanto_RocketHideout_B4F/text.inc"
	.include "data/maps/kanto/Kanto_RocketHideout_Elevator/text.inc"
	.include "data/maps/kanto/Kanto_SilphCo_1F/text.inc"
	.include "data/maps/kanto/Kanto_SilphCo_2F/text.inc"
	.include "data/maps/kanto/Kanto_SilphCo_3F/text.inc"
	.include "data/maps/kanto/Kanto_SilphCo_4F/text.inc"
	.include "data/maps/kanto/Kanto_SilphCo_5F/text.inc"
	.include "data/maps/kanto/Kanto_SilphCo_6F/text.inc"
	.include "data/maps/kanto/Kanto_SilphCo_7F/text.inc"
	.include "data/maps/kanto/Kanto_SilphCo_8F/text.inc"
	.include "data/maps/kanto/Kanto_SilphCo_9F/text.inc"
	.include "data/maps/kanto/Kanto_SilphCo_10F/text.inc"
	.include "data/maps/kanto/Kanto_SilphCo_11F/text.inc"
	.include "data/maps/kanto/Kanto_PokemonMansion_1F/text.inc"
	.include "data/maps/kanto/Kanto_PokemonMansion_2F/text.inc"
	.include "data/maps/kanto/Kanto_PokemonMansion_3F/text.inc"
	.include "data/maps/kanto/Kanto_PokemonMansion_B1F/text.inc"
	.include "data/maps/kanto/Kanto_SafariZone_Center/text.inc"
	.include "data/maps/kanto/Kanto_SafariZone_East/text.inc"
	.include "data/maps/kanto/Kanto_SafariZone_West/text.inc"
	.include "data/maps/kanto/Kanto_SafariZone_Center_RestHouse/text.inc"
	.include "data/maps/kanto/Kanto_SafariZone_East_RestHouse/text.inc"
	.include "data/maps/kanto/Kanto_SafariZone_North_RestHouse/text.inc"
	.include "data/maps/kanto/Kanto_SafariZone_West_RestHouse/text.inc"
	.include "data/maps/kanto/Kanto_SafariZone_SecretHouse/text.inc"
	.include "data/maps/kanto/Kanto_CeruleanCave_B1F/text.inc"
	.include "data/maps/kanto/Kanto_PokemonLeague_LoreleisRoom/text.inc"
	.include "data/maps/kanto/Kanto_PokemonLeague_BrunosRoom/text.inc"
	.include "data/maps/kanto/Kanto_PokemonLeague_AgathasRoom/text.inc"
	.include "data/maps/kanto/Kanto_PokemonLeague_LancesRoom/text.inc"
	.include "data/maps/kanto/Kanto_PokemonLeague_ChampionsRoom/text.inc"
	.include "data/maps/kanto/Kanto_PokemonLeague_HallOfFame/text.inc"
	.include "data/maps/kanto/Kanto_RockTunnel_1F/text.inc"
	.include "data/maps/kanto/Kanto_RockTunnel_B1F/text.inc"
	.include "data/maps/kanto/Kanto_SeafoamIslands_B4F/text.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_1F/text.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_2F/text.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_3F/text.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_4F/text.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_5F/text.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_6F/text.inc"
	.include "data/maps/kanto/Kanto_PokemonTower_7F/text.inc"
	.include "data/maps/kanto/Kanto_MtEmber_Exterior/text.inc"
	.include "data/maps/kanto/Kanto_MtEmber_RubyPath_B3F/text.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_BerryForest/text.inc"
	.include "data/maps/kanto/Kanto_FourIsland_IcefallCave_Back/text.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_RocketWarehouse/text.inc"
	.include "data/maps/kanto/Kanto_SixIsland_DottedHole_SapphireRoom/text.inc"
	.include "data/maps/kanto/Kanto_SixIsland_PatternBush/text.inc"
	.include "data/maps/kanto/Kanto_TrainerTower_Lobby/text.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room1/text.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room4/text.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_LostCave_Room10/text.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_DunsparceTunnel/text.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_SevaultCanyon_TanobyKey/text.inc"
	.include "data/maps/kanto/Kanto_OneIsland_KindleRoad_EmberSpa/text.inc"
	.include "data/maps/kanto/Kanto_PalletTown/text.inc"
	.include "data/maps/kanto/Kanto_ViridianCity/text.inc"
	.include "data/maps/kanto/Kanto_PewterCity/text.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity/text.inc"
	.include "data/maps/kanto/Kanto_LavenderTown/text.inc"
	.include "data/maps/kanto/Kanto_VermilionCity/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity/text.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity/text.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland/text.inc"
	.include "data/maps/kanto/Kanto_SaffronCity/text.inc"
	.include "data/maps/kanto/Kanto_OneIsland/text.inc"
	.include "data/maps/kanto/Kanto_TwoIsland/text.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland/text.inc"
	.include "data/maps/kanto/Kanto_FourIsland/text.inc"
	.include "data/maps/kanto/Kanto_FiveIsland/text.inc"
	.include "data/maps/kanto/Kanto_SevenIsland/text.inc"
	.include "data/maps/kanto/Kanto_SixIsland/text.inc"
	.include "data/maps/kanto/Kanto_Route1/text.inc"
	.include "data/maps/kanto/Kanto_Route2/text.inc"
	.include "data/maps/kanto/Kanto_Route3/text.inc"
	.include "data/maps/kanto/Kanto_Route4/text.inc"
	.include "data/maps/kanto/Kanto_Route5/text.inc"
	.include "data/maps/kanto/Kanto_Route6/text.inc"
	.include "data/maps/kanto/Kanto_Route7/text.inc"
	.include "data/maps/kanto/Kanto_Route8/text.inc"
	.include "data/maps/kanto/Kanto_Route9/text.inc"
	.include "data/maps/kanto/Kanto_Route10/text.inc"
	.include "data/maps/kanto/Kanto_Route11/text.inc"
	.include "data/maps/kanto/Kanto_Route12/text.inc"
	.include "data/maps/kanto/Kanto_Route13/text.inc"
	.include "data/maps/kanto/Kanto_Route14/text.inc"
	.include "data/maps/kanto/Kanto_Route15/text.inc"
	.include "data/maps/kanto/Kanto_Route16/text.inc"
	.include "data/maps/kanto/Kanto_Route17/text.inc"
	.include "data/maps/kanto/Kanto_Route18/text.inc"
	.include "data/maps/kanto/Kanto_Route19/text.inc"
	.include "data/maps/kanto/Kanto_Route20/text.inc"
	.include "data/maps/kanto/Kanto_Route21_North/text.inc"
	.include "data/maps/kanto/Kanto_Route21_South/text.inc"
	.include "data/maps/kanto/Kanto_Route22/text.inc"
	.include "data/maps/kanto/Kanto_Route23/text.inc"
	.include "data/maps/kanto/Kanto_Route24/text.inc"
	.include "data/maps/kanto/Kanto_Route25/text.inc"
	.include "data/maps/kanto/Kanto_OneIsland_KindleRoad/text.inc"
	.include "data/maps/kanto/Kanto_OneIsland_TreasureBeach/text.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_BondBridge/text.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_Port/text.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_ResortGorgeous/text.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_WaterLabyrinth/text.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_Meadow/text.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_MemorialPillar/text.inc"
	.include "data/maps/kanto/Kanto_SixIsland_OutcastIsland/text.inc"
	.include "data/maps/kanto/Kanto_SixIsland_GreenPath/text.inc"
	.include "data/maps/kanto/Kanto_SixIsland_WaterPath/text.inc"
	.include "data/maps/kanto/Kanto_SixIsland_RuinValley/text.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_TrainerTower/text.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_SevaultCanyon_Entrance/text.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_SevaultCanyon/text.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_TanobyRuins/text.inc"
	.include "data/maps/kanto/Kanto_PalletTown_PlayersHouse_1F/text.inc"
	.include "data/maps/kanto/Kanto_PalletTown_PlayersHouse_2F/text.inc"
	.include "data/maps/kanto/Kanto_PalletTown_RivalsHouse/text.inc"
	.include "data/maps/kanto/Kanto_PalletTown_ProfessorOaksLab/text.inc"
	.include "data/maps/kanto/Kanto_ViridianCity_House/text.inc"
	.include "data/maps/kanto/Kanto_ViridianCity_Gym/text.inc"
	.include "data/maps/kanto/Kanto_ViridianCity_School/text.inc"
	.include "data/maps/kanto/Kanto_ViridianCity_Mart/text.inc"
	.include "data/maps/kanto/Kanto_ViridianCity_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_PewterCity_Museum_1F/text.inc"
	.include "data/maps/kanto/Kanto_PewterCity_Museum_2F/text.inc"
	.include "data/maps/kanto/Kanto_PewterCity_Gym/text.inc"
	.include "data/maps/kanto/Kanto_PewterCity_Mart/text.inc"
	.include "data/maps/kanto/Kanto_PewterCity_House1/text.inc"
	.include "data/maps/kanto/Kanto_PewterCity_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_PewterCity_House2/text.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_House1/text.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_House2/text.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_House3/text.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_Gym/text.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_BikeShop/text.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_Mart/text.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_House4/text.inc"
	.include "data/maps/kanto/Kanto_CeruleanCity_House5/text.inc"
	.include "data/maps/kanto/Kanto_LavenderTown_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_LavenderTown_VolunteerPokemonHouse/text.inc"
	.include "data/maps/kanto/Kanto_LavenderTown_House1/text.inc"
	.include "data/maps/kanto/Kanto_LavenderTown_House2/text.inc"
	.include "data/maps/kanto/Kanto_LavenderTown_Mart/text.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_House1/text.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_PokemonFanClub/text.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_House2/text.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_Mart/text.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_Gym/text.inc"
	.include "data/maps/kanto/Kanto_VermilionCity_House3/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_DepartmentStore_1F/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_DepartmentStore_2F/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_DepartmentStore_3F/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_DepartmentStore_4F/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_DepartmentStore_5F/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_DepartmentStore_Roof/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Condominiums_1F/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Condominiums_2F/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Condominiums_3F/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Condominiums_Roof/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Condominiums_RoofRoom/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_GameCorner/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_GameCorner_PrizeRoom/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Gym/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Restaurant/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_House1/text.inc"
	.include "data/maps/kanto/Kanto_CeladonCity_Hotel/text.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_SafariZone_Entrance/text.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_Mart/text.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_SafariZone_Office/text.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_Gym/text.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_House1/text.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_WardensHouse/text.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_House2/text.inc"
	.include "data/maps/kanto/Kanto_FuchsiaCity_House3/text.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_Gym/text.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_PokemonLab_Entrance/text.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_PokemonLab_Lounge/text.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_PokemonLab_ResearchRoom/text.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_PokemonLab_ExperimentRoom/text.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_CinnabarIsland_Mart/text.inc"
	.include "data/maps/kanto/Kanto_IndigoPlateau_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_CopycatsHouse_1F/text.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_CopycatsHouse_2F/text.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_Dojo/text.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_Gym/text.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_House/text.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_Mart/text.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_MrPsychicsHouse/text.inc"
	.include "data/maps/kanto/Kanto_SaffronCity_PokemonTrainerFanClub/text.inc"
	.include "data/maps/kanto/Kanto_Route2_ViridianForest_SouthEntrance/text.inc"
	.include "data/maps/kanto/Kanto_Route2_House/text.inc"
	.include "data/maps/kanto/Kanto_Route2_EastBuilding/text.inc"
	.include "data/maps/kanto/Kanto_Route2_ViridianForest_NorthEntrance/text.inc"
	.include "data/maps/kanto/Kanto_Route4_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_Route5_PokemonDayCare/text.inc"
	.include "data/maps/kanto/Kanto_Route5_SouthEntrance/text.inc"
	.include "data/maps/kanto/Kanto_Route6_NorthEntrance/text.inc"
	.include "data/maps/kanto/Kanto_Route7_EastEntrance/text.inc"
	.include "data/maps/kanto/Kanto_Route8_WestEntrance/text.inc"
	.include "data/maps/kanto/Kanto_Route10_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_Route11_EastEntrance_1F/text.inc"
	.include "data/maps/kanto/Kanto_Route11_EastEntrance_2F/text.inc"
	.include "data/maps/kanto/Kanto_Route12_NorthEntrance_1F/text.inc"
	.include "data/maps/kanto/Kanto_Route12_NorthEntrance_2F/text.inc"
	.include "data/maps/kanto/Kanto_Route12_FishingHouse/text.inc"
	.include "data/maps/kanto/Kanto_Route15_WestEntrance_1F/text.inc"
	.include "data/maps/kanto/Kanto_Route15_WestEntrance_2F/text.inc"
	.include "data/maps/kanto/Kanto_Route16_House/text.inc"
	.include "data/maps/kanto/Kanto_Route16_NorthEntrance_1F/text.inc"
	.include "data/maps/kanto/Kanto_Route16_NorthEntrance_2F/text.inc"
	.include "data/maps/kanto/Kanto_Route18_EastEntrance_1F/text.inc"
	.include "data/maps/kanto/Kanto_Route18_EastEntrance_2F/text.inc"
	.include "data/maps/kanto/Kanto_Route25_SeaCottage/text.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_House_Room1/text.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_Mart/text.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_OneIsland_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_OneIsland_House1/text.inc"
	.include "data/maps/kanto/Kanto_OneIsland_House2/text.inc"
	.include "data/maps/kanto/Kanto_TwoIsland_JoyfulGameCorner/text.inc"
	.include "data/maps/kanto/Kanto_TwoIsland_House/text.inc"
	.include "data/maps/kanto/Kanto_TwoIsland_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_House1/text.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_Mart/text.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_House2/text.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_House3/text.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_House4/text.inc"
	.include "data/maps/kanto/Kanto_ThreeIsland_House5/text.inc"
	.include "data/maps/kanto/Kanto_FourIsland_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_FourIsland_House1/text.inc"
	.include "data/maps/kanto/Kanto_FourIsland_LoreleisHouse/text.inc"
	.include "data/maps/kanto/Kanto_FourIsland_Mart/text.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_House1/text.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_House2/text.inc"
	.include "data/maps/kanto/Kanto_SixIsland_PokemonCenter_1F/text.inc"
	.include "data/maps/kanto/Kanto_SixIsland_House/text.inc"
	.include "data/maps/kanto/Kanto_SixIsland_Mart/text.inc"
	.include "data/maps/kanto/Kanto_FiveIsland_ResortGorgeous_House/text.inc"
	.include "data/maps/kanto/Kanto_TwoIsland_CapeBrink_House/text.inc"
	.include "data/maps/kanto/Kanto_SixIsland_WaterPath_House1/text.inc"
	.include "data/maps/kanto/Kanto_SixIsland_WaterPath_House2/text.inc"
	.include "data/maps/kanto/Kanto_SevenIsland_SevaultCanyon_House/text.inc"

	.include "data/scripts/std_msgbox.inc"
	.include "data/scripts/trainer_battle.inc"
	.include "data/scripts/new_game.inc"
	.include "data/scripts/hall_of_fame.inc"

EventScript_WhiteOut::
	call EverGrandeCity_HallOfFame_EventScript_ResetEliteFour
	goto EventScript_ResetMrBriney
	end

EventScript_ResetMrBriney::
	goto_if_eq VAR_BRINEY_LOCATION, 1, EventScript_MoveMrBrineyToHouse
	goto_if_eq VAR_BRINEY_LOCATION, 2, EventScript_MoveMrBrineyToDewford
	goto_if_eq VAR_BRINEY_LOCATION, 3, EventScript_MoveMrBrineyToRoute109
	end

EventScript_MoveMrBrineyToHouse::
	setflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	end

EventScript_MoveMrBrineyToDewford::
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	end

EventScript_MoveMrBrineyToRoute109::
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	end

EverGrandeCity_HallOfFame_EventScript_ResetEliteFour::
	clearflag FLAG_DEFEATED_ELITE_4_SIDNEY
	clearflag FLAG_DEFEATED_ELITE_4_PHOEBE
	clearflag FLAG_DEFEATED_ELITE_4_GLACIA
	clearflag FLAG_DEFEATED_ELITE_4_DRAKE
	setvar VAR_ELITE_4_STATE, 0
	return

Common_EventScript_UpdateBrineyLocation::
	goto_if_unset FLAG_RECEIVED_POKENAV, Common_EventScript_NopReturn
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, Common_EventScript_NopReturn
	goto_if_unset FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT, EventScript_SetBrineyLocation_House
	goto_if_unset FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN, EventScript_SetBrineyLocation_Dewford
	goto_if_unset FLAG_HIDE_ROUTE_109_MR_BRINEY, EventScript_SetBrineyLocation_Route109
	return

EventScript_SetBrineyLocation_House::
	setvar VAR_BRINEY_LOCATION, 1
	return

EventScript_SetBrineyLocation_Dewford::
	setvar VAR_BRINEY_LOCATION, 2
	return

EventScript_SetBrineyLocation_Route109::
	setvar VAR_BRINEY_LOCATION, 3
	return

	.include "data/scripts/pkmn_center_nurse.inc"
	.include "data/scripts/obtain_item.inc"
	.include "data/scripts/record_mix.inc"
	.include "data/scripts/pc.inc"

@ scripts/notices.inc? signs.inc? See comment about text/notices.inc
Common_EventScript_ShowPokemartSign::
	msgbox gText_PokemartSign, MSGBOX_SIGN
	end

Common_EventScript_ShowPokemonCenterSign::
	msgbox gText_PokemonCenterSign, MSGBOX_SIGN
	end

Common_ShowEasyChatScreen::
	fadescreen FADE_TO_BLACK
	special ShowEasyChatScreen
	fadescreen FADE_FROM_BLACK
	return

Common_EventScript_ReadyPetalburgGymForBattle::
	clearflag FLAG_HIDE_PETALBURG_GYM_GREETER
	setflag FLAG_PETALBURG_MART_EXPANDED_ITEMS
	return

Common_EventScript_BufferTrendyPhrase::
	dotimebasedevents
	setvar VAR_0x8004, 0
	special BufferTrendyPhraseString
	return

EventScript_BackupMrBrineyLocation::
	copyvar VAR_0x8008, VAR_BRINEY_LOCATION
	setvar VAR_BRINEY_LOCATION, 0
	return

	.include "data/scripts/surf.inc"
	.include "data/scripts/rival_graphics.inc"
	.include "data/scripts/set_gym_trainers.inc"

Common_EventScript_ShowBagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end

Common_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	return

Common_EventScript_ShowNoRoomForDecor::
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	release
	end

Common_EventScript_NoRoomForDecor::
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	return

Common_EventScript_SetAbnormalWeather::
	setweather WEATHER_ABNORMAL
	return

Common_EventScript_PlayGymBadgeFanfare::
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	return

Common_EventScript_OutOfCenterPartyHeal::
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	return

EventScript_RegionMap::
	lockall
	msgbox Common_Text_LookCloserAtMap, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special FieldShowRegionMap
	waitstate
	releaseall
	end

Common_EventScript_PlayBrineysBoatMusic::
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_SAILING, FALSE
	return

Common_EventScript_StopBrineysBoatMusic::
	clearflag FLAG_DONT_TRANSITION_MUSIC
	fadedefaultbgm
	return

	.include "data/scripts/prof_birch.inc"

@ Below could be split as ferry.inc aside from the Rusturf tunnel script
Common_EventScript_FerryDepart::
	delay 60
	applymovement VAR_0x8004, Movement_FerryDepart
	waitmovement 0
	return

Movement_FerryDepart:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

EventScript_HideMrBriney::
	setflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 0
	return

RusturfTunnel_EventScript_SetRusturfTunnelOpen::
	removeobject LOCALID_WANDAS_BF
	removeobject LOCALID_WANDA
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDA
	setvar VAR_RUSTURF_TUNNEL_STATE, 6
	setflag FLAG_RUSTURF_TUNNEL_OPENED
	return

EventScript_UnusedBoardFerry::
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Movement_UnusedBoardFerry
	waitmovement 0
	delay 30
	return

Movement_UnusedBoardFerry:
	walk_up
	step_end

Common_EventScript_FerryDepartIsland::
	call_if_eq VAR_FACING, DIR_SOUTH, Ferry_EventScript_DepartIslandSouth
	call_if_eq VAR_FACING, DIR_WEST, Ferry_EventScript_DepartIslandWest
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	call Common_EventScript_FerryDepart
	return

	.include "data/scripts/cave_of_origin.inc"
	.include "data/scripts/kecleon.inc"

Common_EventScript_NameReceivedPartyMon::
	fadescreen FADE_TO_BLACK
	special ChangePokemonNickname
	waitstate
	return

Common_EventScript_PlayerHandedOverTheItem::
	bufferitemname STR_VAR_1, VAR_0x8004
	playfanfare MUS_OBTAIN_TMHM
	message gText_PlayerHandedOverTheItem
	waitmessage
	waitfanfare
	removeitem VAR_0x8004
	return

	.include "data/scripts/elite_four.inc"
	.include "data/scripts/movement.inc"
	.include "data/scripts/check_furniture.inc"
	.include "data/text/record_mix.inc"
	.include "data/text/pc.inc"
	.include "data/text/pkmn_center_nurse.inc"
	.include "data/text/mart_clerk.inc"
	.include "data/text/obtain_item.inc"

@ The below and surf.inc could be split into some text/notices.inc
gText_PokemartSign::
	.string "“Selected items for your convenience!”\n"
	.string "POKéMON MART$"

gText_PokemonCenterSign::
	.string "“Rejuvenate your tired partners!”\n"
	.string "POKéMON CENTER$"

gText_MomOrDadMightLikeThisProgram::
	.string "{STR_VAR_1} might like this program.\n"
	.string "… … … … … … … … … … … … … … … …\p"
	.string "Better get going!$"

gText_WhichFloorWouldYouLike::
	.string "Welcome to LILYCOVE DEPARTMENT STORE.\p"
	.string "Which floor would you like?$"

gText_SandstormIsVicious::
	.string "The sandstorm is vicious.\n"
	.string "It's impossible to keep going.$"

gText_SelectWithoutRegisteredItem::
	.string "An item in the BAG can be\n"
	.string "registered to SELECT for easy use.$"

gText_PokemonTrainerSchoolEmail::
	.string "There's an e-mail from POKéMON TRAINER\n"
	.string "SCHOOL.\p"
	.string "… … … … … …\p"
	.string "A POKéMON may learn up to four moves.\p"
	.string "A TRAINER's expertise is tested on the\n"
	.string "move sets chosen for POKéMON.\p"
	.string "… … … … … …$"

gText_PlayerHouseBootPC::
	.string "{PLAYER} booted up the PC.$"

gText_PokeblockLinkCanceled::
	.string "The link was canceled.$"

gText_UnusedNicknameReceivedPokemon::
	.string "Want to give a nickname to\n"
	.string "the {STR_VAR_2} you received?$"

gText_PlayerWhitedOut::
	.string "{PLAYER} is out of usable\n"
	.string "POKéMON!\p{PLAYER} whited out!$"

gText_RegisteredTrainerinPokeNav::
	.string "Registered {STR_VAR_1} {STR_VAR_2}\n"
	.string "in the POKéNAV.$"

gText_ComeBackWithSecretPower::
	.string "Do you know the TM SECRET POWER?\p"
	.string "Our group, we love the TM SECRET\n"
	.string "POWER.\p"
	.string "One of our members will give it to you.\n"
	.string "Come back and show me if you get it.\p"
	.string "We'll accept you as a member and sell\n"
	.string "you good stuff in secrecy.$"

gText_PokerusExplanation::
	.string "Your POKéMON may be infected with\n"
	.string "POKéRUS.\p"
	.string "Little is known about the POKéRUS\n"
	.string "except that they are microscopic life-\l"
	.string "forms that attach to POKéMON.\p"
	.string "While infected, POKéMON are said to\n"
	.string "grow exceptionally well.$"

	.include "data/text/surf.inc"

gText_DoorOpenedFarAway::
	.string "It sounded as if a door opened\n"
	.string "somewhere far away.$"

gText_BigHoleInTheWall::
	.string "There is a big hole in the wall.$"

gText_SorryWirelessClubAdjustments::
	.string "I'm terribly sorry.\n"
	.string "The POKéMON WIRELESS CLUB is\l"
	.string "undergoing adjustments now.$"

gText_UndergoingAdjustments::
	.string "It appears to be undergoing\n"
	.string "adjustments…$"

@ Unused
gText_SorryTradeCenterInspections::
	.string "I'm terribly sorry. The TRADE CENTER\n"
	.string "is undergoing inspections.$"

@ Unused
gText_SorryRecordCornerPreparation::
	.string "I'm terribly sorry. The RECORD CORNER\n"
	.string "is under preparation.$"

gText_PlayerHandedOverTheItem::
	.string "{PLAYER} handed over the\n"
	.string "{STR_VAR_1}.$"

gText_ThankYouForAccessingMysteryGift::
	.string "Thank you for accessing the\n"
	.string "MYSTERY GIFT System.$"

gText_PlayerFoundOneTMHM::
	.string "{PLAYER} found one {STR_VAR_1}\n"
	.string "{STR_VAR_2}!$"

gText_Sudowoodo_Attacked::
	.string "The weird tree doesn't like the\n"
	.string "WAILMER PAIL!\p"
	.string "The weird tree attacked!$"

gText_LegendaryFlewAway::
	.string "The {STR_VAR_1} flew away!$"

	.include "data/text/pc_transfer.inc"
	.include "data/text/questionnaire.inc"
	.include "data/text/abnormal_weather.inc"

EventScript_SelectWithoutRegisteredItem::
	msgbox gText_SelectWithoutRegisteredItem, MSGBOX_SIGN
	end

	.include "data/scripts/field_poison.inc"

Common_EventScript_NopReturn::
	return

@ Unused
EventScript_CableClub_SetVarResult1::
	setvar VAR_RESULT, 1
	return

EventScript_CableClub_SetVarResult0::
	setvar VAR_RESULT, 0
	return

Common_EventScript_UnionRoomAttendant::
	call CableClub_EventScript_UnionRoomAttendant
	end

Common_EventScript_WirelessClubAttendant::
	call CableClub_EventScript_WirelessClubAttendant
	end

Common_EventScript_DirectCornerAttendant::
	call CableClub_EventScript_DirectCornerAttendant
	end

Common_EventScript_RemoveStaticPokemon::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

Common_EventScript_LegendaryFlewAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	release
	end

	.include "data/scripts/pc_transfer.inc"
	.include "data/scripts/questionnaire.inc"
	.include "data/scripts/abnormal_weather.inc"
	.include "data/scripts/trainer_script.inc"
	.include "data/scripts/berry_tree.inc"
	.include "data/scripts/secret_base.inc"
	.include "data/scripts/cable_club.inc"
	.include "data/text/cable_club.inc"
	.include "data/scripts/contest_hall.inc"
	.include "data/text/contest_strings.inc"
	.include "data/text/contest_link.inc"
	.include "data/text/contest_painting.inc"
	.include "data/text/trick_house_mechadolls.inc"
	.include "data/scripts/tv.inc"
	.include "data/text/tv.inc"
	.include "data/scripts/interview.inc"
	.include "data/scripts/gabby_and_ty.inc"
	.include "data/text/pokemon_news.inc"
	.include "data/scripts/mauville_man.inc"
	.include "data/scripts/field_move_scripts.inc"
	.include "data/scripts/item_ball_scripts.inc"
	.include "data/scripts/profile_man.inc"
	.include "data/scripts/day_care.inc"
	.include "data/scripts/flash.inc"
	.include "data/scripts/players_house.inc"
	.include "data/scripts/berry_blender.inc"
	.include "data/text/mauville_man.inc"
	.include "data/text/trainers.inc"
	.include "data/scripts/repel.inc"
	.include "data/scripts/safari_zone.inc"
	.include "data/scripts/roulette.inc"
	.include "data/text/pokedex_rating.inc"
	.include "data/text/lottery_corner.inc"
	.include "data/text/event_ticket_1.inc"
	.include "data/text/braille.inc"
	.include "data/text/berries.inc"
	.include "data/text/shoal_cave.inc"
	.include "data/text/check_furniture.inc"
	.include "data/scripts/cave_hole.inc"
	.include "data/scripts/lilycove_lady.inc"
	.include "data/text/match_call.inc"
	.include "data/scripts/apprentice.inc"
	.include "data/text/apprentice.inc"
	.include "data/text/battle_dome.inc"
	.include "data/scripts/battle_pike.inc"
	.include "data/text/blend_master.inc"
	.include "data/text/battle_tent.inc"
	.include "data/text/event_ticket_2.inc"
	.include "data/text/move_tutors.inc"
	.include "data/scripts/move_tutors.inc"
	.include "data/scripts/trainer_hill.inc"
	.include "data/scripts/test_signpost.inc"
	.include "data/text/frontier_brain.inc"
	.include "data/text/save.inc"
	.include "data/text/birch_speech.inc"
