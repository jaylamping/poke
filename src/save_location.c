#include "global.h"
#include "save_location.h"

#define LIST_END 0xFFFF

static bool32 IsCurMapInLocationList(const u16 *list)
{
    s32 i;
    u16 map = (gSaveBlock1Ptr->location.mapGroup << 8) + gSaveBlock1Ptr->location.mapNum;

    for (i = 0; list[i] != LIST_END; i++)
    {
        if (list[i] == map)
            return TRUE;
    }

    return FALSE;
}

static const u16 sSaveLocationPokeCenterList[] =
    {
        MAP_HOENN_OLDALE_TOWN_POKEMON_CENTER_1F,
        MAP_HOENN_OLDALE_TOWN_POKEMON_CENTER_2F,
        MAP_HOENN_DEWFORD_TOWN_POKEMON_CENTER_1F,
        MAP_HOENN_DEWFORD_TOWN_POKEMON_CENTER_2F,
        MAP_HOENN_LAVARIDGE_TOWN_POKEMON_CENTER_1F,
        MAP_HOENN_LAVARIDGE_TOWN_POKEMON_CENTER_2F,
        MAP_HOENN_FALLARBOR_TOWN_POKEMON_CENTER_1F,
        MAP_HOENN_FALLARBOR_TOWN_POKEMON_CENTER_2F,
        MAP_HOENN_VERDANTURF_TOWN_POKEMON_CENTER_1F,
        MAP_HOENN_VERDANTURF_TOWN_POKEMON_CENTER_2F,
        MAP_HOENN_PACIFIDLOG_TOWN_POKEMON_CENTER_1F,
        MAP_HOENN_PACIFIDLOG_TOWN_POKEMON_CENTER_2F,
        MAP_HOENN_PETALBURG_CITY_POKEMON_CENTER_1F,
        MAP_HOENN_PETALBURG_CITY_POKEMON_CENTER_2F,
        MAP_HOENN_SLATEPORT_CITY_POKEMON_CENTER_1F,
        MAP_HOENN_SLATEPORT_CITY_POKEMON_CENTER_2F,
        MAP_HOENN_MAUVILLE_CITY_POKEMON_CENTER_1F,
        MAP_HOENN_MAUVILLE_CITY_POKEMON_CENTER_2F,
        MAP_HOENN_RUSTBORO_CITY_POKEMON_CENTER_1F,
        MAP_HOENN_RUSTBORO_CITY_POKEMON_CENTER_2F,
        MAP_HOENN_FORTREE_CITY_POKEMON_CENTER_1F,
        MAP_HOENN_FORTREE_CITY_POKEMON_CENTER_2F,
        MAP_HOENN_LILYCOVE_CITY_POKEMON_CENTER_1F,
        MAP_HOENN_LILYCOVE_CITY_POKEMON_CENTER_2F,
        MAP_HOENN_MOSSDEEP_CITY_POKEMON_CENTER_1F,
        MAP_HOENN_MOSSDEEP_CITY_POKEMON_CENTER_2F,
        MAP_HOENN_SOOTOPOLIS_CITY_POKEMON_CENTER_1F,
        MAP_HOENN_SOOTOPOLIS_CITY_POKEMON_CENTER_2F,
        MAP_HOENN_EVER_GRANDE_CITY_POKEMON_CENTER_1F,
        MAP_HOENN_EVER_GRANDE_CITY_POKEMON_CENTER_2F,
        MAP_HOENN_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F,
        MAP_HOENN_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F,
        MAP_HOENN_BATTLE_FRONTIER_POKEMON_CENTER_1F,
        MAP_HOENN_BATTLE_FRONTIER_POKEMON_CENTER_2F,
        MAP_HOENN_BATTLE_COLOSSEUM_2P,
        MAP_HOENN_TRADE_CENTER,
        MAP_HOENN_RECORD_CORNER,
        MAP_HOENN_BATTLE_COLOSSEUM_4P,
        LIST_END,
};

static bool32 IsCurMapPokeCenter(void)
{
    return IsCurMapInLocationList(sSaveLocationPokeCenterList);
}

static const u16 sSaveLocationReloadLocList[] = // There's only 1 location, and it's presumed its for the save reload feature for battle tower.
    {
        MAP_HOENN_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY,
        LIST_END,
};

static bool32 IsCurMapReloadLocation(void)
{
    return IsCurMapInLocationList(sSaveLocationReloadLocList);
}

// Nulled out list. Unknown what this would have been.
static const u16 sEmptyMapList[] =
    {
        LIST_END,
};

static bool32 IsCurMapInEmptyList(void)
{
    return IsCurMapInLocationList(sEmptyMapList);
}

static void TrySetPokeCenterWarpStatus(void)
{
    if (!IsCurMapPokeCenter())
        gSaveBlock2Ptr->specialSaveWarpFlags &= ~POKECENTER_SAVEWARP;
    else
        gSaveBlock2Ptr->specialSaveWarpFlags |= POKECENTER_SAVEWARP;
}

static void TrySetReloadWarpStatus(void)
{
    if (!IsCurMapReloadLocation())
        gSaveBlock2Ptr->specialSaveWarpFlags &= ~LOBBY_SAVEWARP;
    else
        gSaveBlock2Ptr->specialSaveWarpFlags |= LOBBY_SAVEWARP;
}

// Unknown save warp flag. Never set because map list is empty.
static void TrySetUnknownWarpStatus(void)
{
    if (!IsCurMapInEmptyList())
        gSaveBlock2Ptr->specialSaveWarpFlags &= ~UNK_SPECIAL_SAVE_WARP_FLAG_3;
    else
        gSaveBlock2Ptr->specialSaveWarpFlags |= UNK_SPECIAL_SAVE_WARP_FLAG_3;
}

void TrySetMapSaveWarpStatus(void)
{
    TrySetPokeCenterWarpStatus();
    TrySetReloadWarpStatus();
    TrySetUnknownWarpStatus();
}

// In FRLG, only bits 0, 4, and 5 are set when the Pokédex is received.
// Bits 1, 2, 3, and 15 are instead set by SetPostgameFlags.
// These flags are read by Pokémon Colosseum/XD for linking. XD Additionally requires FLAG_SYS_GAME_CLEAR
void SetUnlockedPokedexFlags(void)
{
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 15);
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 0);
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 1);
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 2);
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 4);
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 5);
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 3);
}

void SetChampionSaveWarp(void)
{
    gSaveBlock2Ptr->specialSaveWarpFlags |= CHAMPION_SAVEWARP;
}
