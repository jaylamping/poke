#include "global.h"
#include "graphics.h"
#include "palette.h"
#include "util.h"
#include "battle_transition.h"
#include "task.h"
#include "battle_transition.h"
#include "fieldmap.h"

static EWRAM_DATA struct
{
    const u16 *src;
    u16 *dest;
    u16 size;
} sTilesetDMA3TransferBuffer[20] = {0};

static u8 sTilesetDMA3TransferBufferSize;
static u16 sPrimaryTilesetAnimCounter;
static u16 sPrimaryTilesetAnimCounterMax;
static u16 sSecondaryTilesetAnimCounter;
static u16 sSecondaryTilesetAnimCounterMax;
static void (*sPrimaryTilesetAnimCallback)(u16);
static void (*sSecondaryTilesetAnimCallback)(u16);

// Hoenn

static void _InitPrimaryTilesetAnimation(void);
static void _InitSecondaryTilesetAnimation(void);
static void TilesetAnim_Hoenn_General(u16);
static void TilesetAnim_Hoenn_Building(u16);
static void TilesetAnim_Hoenn_Rustboro(u16);
static void TilesetAnim_Hoenn_Dewford(u16);
static void TilesetAnim_Hoenn_Slateport(u16);
static void TilesetAnim_Hoenn_Mauville(u16);
static void TilesetAnim_Hoenn_Lavaridge(u16);
static void TilesetAnim_Hoenn_Fallarbor(u16);
static void TilesetAnim_Hoenn_Fortree(u16);
static void TilesetAnim_Hoenn_Lilycove(u16);
static void TilesetAnim_Hoenn_Mossdeep(u16);
static void TilesetAnim_Hoenn_EverGrande(u16);
static void TilesetAnim_Hoenn_Pacifidlog(u16);
static void TilesetAnim_Hoenn_Sootopolis(u16);
static void TilesetAnim_Hoenn_BattleFrontierOutsideWest(u16);
static void TilesetAnim_Hoenn_BattleFrontierOutsideEast(u16);
static void TilesetAnim_Hoenn_Underwater(u16);
static void TilesetAnim_Hoenn_SootopolisGym(u16);
static void TilesetAnim_Hoenn_Cave(u16);
static void TilesetAnim_Hoenn_EliteFour(u16);
static void TilesetAnim_Hoenn_BattleDome(u16);
static void TilesetAnim_Hoenn_BattlePyramid(u16);
static void TilesetAnim_Hoenn_MauvilleGym(u16);
static void TilesetAnim_Hoenn_BikeShop(u16);
static void TilesetAnim_Hoenn_BattleDome(u16);
static void QueueAnimTiles_Hoenn_General_Flower(u16);
static void QueueAnimTiles_Hoenn_General_Water(u16);
static void QueueAnimTiles_Hoenn_General_SandWaterEdge(u16);
static void QueueAnimTiles_Hoenn_General_Waterfall(u16);
static void QueueAnimTiles_Hoenn_General_LandWaterEdge(u16);
static void QueueAnimTiles_Hoenn_Building_TVTurnedOn(u16);
static void QueueAnimTiles_Hoenn_Rustboro_WindyWater(u16, u8);
static void QueueAnimTiles_Hoenn_Rustboro_Fountain(u16);
static void QueueAnimTiles_Hoenn_Dewford_Flag(u16);
static void QueueAnimTiles_Hoenn_Slateport_Balloons(u16);
static void QueueAnimTiles_Hoenn_Mauville_Flowers(u16, u8);
static void QueueAnimTiles_Hoenn_BikeShop_BlinkingLights(u16);
static void QueueAnimTiles_Hoenn_BattlePyramid_Torch(u16);
static void QueueAnimTiles_Hoenn_BattlePyramid_StatueShadow(u16);
static void BlendAnimPalette_Hoenn_BattleDome_FloorLights(u16);
static void BlendAnimPalette_Hoenn_BattleDome_FloorLightsNoBlend(u16);
static void QueueAnimTiles_Hoenn_Lavaridge_Steam(u8);
static void QueueAnimTiles_Hoenn_Lavaridge_Lava(u16);
static void QueueAnimTiles_Hoenn_EverGrande_Flowers(u16, u8);
static void QueueAnimTiles_Hoenn_Pacifidlog_LogBridges(u8);
static void QueueAnimTiles_Hoenn_Pacifidlog_WaterCurrents(u8);
static void QueueAnimTiles_Hoenn_Sootopolis_StormyWater(u16);
static void QueueAnimTiles_Hoenn_Underwater_Seaweed(u8);
static void QueueAnimTiles_Hoenn_Cave_Lava(u16);
static void QueueAnimTiles_Hoenn_BattleFrontierOutsideWest_Flag(u16);
static void QueueAnimTiles_Hoenn_BattleFrontierOutsideEast_Flag(u16);
static void QueueAnimTiles_Hoenn_MauvilleGym_ElectricGates(u16);
static void QueueAnimTiles_Hoenn_SootopolisGym_Waterfalls(u16);
static void QueueAnimTiles_Hoenn_EliteFour_GroundLights(u16);
static void QueueAnimTiles_Hoenn_EliteFour_WallLights(u16);

// Kanto
static void TilesetAnim_Kanto_General(u16);
static void TilesetAnim_Kanto_Building(u16);
static void TilesetAnim_Kanto_CeladonCity(u16);
static void TilesetAnim_Kanto_CeladonGym(u16);
static void TilesetAnim_Kanto_SilphCo(u16);
static void TilesetAnim_Kanto_MtEmber(u16);
static void TilesetAnim_Kanto_VermilionGym(u16);
static void QueueAnimTiles_Kanto_General_Flower(u16);
static void QueueAnimTiles_Kanto_General_Water_Current_LandWatersEdge(u16);
static void QueueAnimTiles_Kanto_General_SandWatersEdge(u16);
static void QueueAnimTiles_Kanto_General_Waterfall(u16);
static void QueueAnimTiles_Kanto_General_LandWaterEdge(u16);
static void QueueAnimTiles_Kanto_Building_TVTurnedOn(u16);
static void QueueAnimTiles_Kanto_VermilionGym_MotorizedDoor(u16);
static void QueueAnimTiles_Kanto_MtEmber_Steam(u16);
static void QueueAnimTiles_Kanto_SilphCo_Fountain(u16);
static void QueueAnimTiles_Kanto_CeladonCity_Fountain(u16);
static void QueueAnimTiles_Kanto_CeladonGym_Flowers(u16);
static void QueueAnimTiles_Kanto_General_Flower(u16);
static void QueueAnimTiles_Kanto_General_Water_Current_LandWatersEdge(u16);
static void QueueAnimTiles_Kanto_General_SandWatersEdge(u16);

const u16 gTilesetAnims_Hoenn_General_Flower_Frame1[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/flower/1.4bpp");
const u16 gTilesetAnims_Hoenn_General_Flower_Frame0[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/flower/0.4bpp");
const u16 gTilesetAnims_Hoenn_General_Flower_Frame2[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/flower/2.4bpp");
const u16 tileset_anims_space_0[16] = {};

const u16 *const gTilesetAnims_Hoenn_General_Flower[] = {
    gTilesetAnims_Hoenn_General_Flower_Frame0,
    gTilesetAnims_Hoenn_General_Flower_Frame1,
    gTilesetAnims_Hoenn_General_Flower_Frame0,
    gTilesetAnims_Hoenn_General_Flower_Frame2};

const u16 gTilesetAnims_Hoenn_General_Water_Frame0[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/0.4bpp");
const u16 gTilesetAnims_Hoenn_General_Water_Frame1[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/1.4bpp");
const u16 gTilesetAnims_Hoenn_General_Water_Frame2[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/2.4bpp");
const u16 gTilesetAnims_Hoenn_General_Water_Frame3[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/3.4bpp");
const u16 gTilesetAnims_Hoenn_General_Water_Frame4[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/4.4bpp");
const u16 gTilesetAnims_Hoenn_General_Water_Frame5[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/5.4bpp");
const u16 gTilesetAnims_Hoenn_General_Water_Frame6[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/6.4bpp");
const u16 gTilesetAnims_Hoenn_General_Water_Frame7[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/water/7.4bpp");

const u16 *const gTilesetAnims_Hoenn_General_Water[] = {
    gTilesetAnims_Hoenn_General_Water_Frame0,
    gTilesetAnims_Hoenn_General_Water_Frame1,
    gTilesetAnims_Hoenn_General_Water_Frame2,
    gTilesetAnims_Hoenn_General_Water_Frame3,
    gTilesetAnims_Hoenn_General_Water_Frame4,
    gTilesetAnims_Hoenn_General_Water_Frame5,
    gTilesetAnims_Hoenn_General_Water_Frame6,
    gTilesetAnims_Hoenn_General_Water_Frame7};

const u16 gTilesetAnims_Hoenn_General_SandWaterEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/0.4bpp");
const u16 gTilesetAnims_Hoenn_General_SandWaterEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/1.4bpp");
const u16 gTilesetAnims_Hoenn_General_SandWaterEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/2.4bpp");
const u16 gTilesetAnims_Hoenn_General_SandWaterEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/3.4bpp");
const u16 gTilesetAnims_Hoenn_General_SandWaterEdge_Frame4[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/4.4bpp");
const u16 gTilesetAnims_Hoenn_General_SandWaterEdge_Frame5[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/5.4bpp");
const u16 gTilesetAnims_Hoenn_General_SandWaterEdge_Frame6[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/sand_water_edge/6.4bpp");

const u16 *const gTilesetAnims_Hoenn_General_SandWaterEdge[] = {
    gTilesetAnims_Hoenn_General_SandWaterEdge_Frame0,
    gTilesetAnims_Hoenn_General_SandWaterEdge_Frame1,
    gTilesetAnims_Hoenn_General_SandWaterEdge_Frame2,
    gTilesetAnims_Hoenn_General_SandWaterEdge_Frame3,
    gTilesetAnims_Hoenn_General_SandWaterEdge_Frame4,
    gTilesetAnims_Hoenn_General_SandWaterEdge_Frame5,
    gTilesetAnims_Hoenn_General_SandWaterEdge_Frame6,
    gTilesetAnims_Hoenn_General_SandWaterEdge_Frame0};

const u16 gTilesetAnims_Hoenn_General_Waterfall_Frame0[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/waterfall/0.4bpp");
const u16 gTilesetAnims_Hoenn_General_Waterfall_Frame1[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/waterfall/1.4bpp");
const u16 gTilesetAnims_Hoenn_General_Waterfall_Frame2[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/waterfall/2.4bpp");
const u16 gTilesetAnims_Hoenn_General_Waterfall_Frame3[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/waterfall/3.4bpp");

const u16 *const gTilesetAnims_Hoenn_General_Waterfall[] = {
    gTilesetAnims_Hoenn_General_Waterfall_Frame0,
    gTilesetAnims_Hoenn_General_Waterfall_Frame1,
    gTilesetAnims_Hoenn_General_Waterfall_Frame2,
    gTilesetAnims_Hoenn_General_Waterfall_Frame3};

const u16 gTilesetAnims_Hoenn_General_LandWaterEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/land_water_edge/0.4bpp");
const u16 gTilesetAnims_Hoenn_General_LandWaterEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/land_water_edge/1.4bpp");
const u16 gTilesetAnims_Hoenn_General_LandWaterEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/land_water_edge/2.4bpp");
const u16 gTilesetAnims_Hoenn_General_LandWaterEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/hoenn_general/anim/land_water_edge/3.4bpp");

const u16 *const gTilesetAnims_Hoenn_General_LandWaterEdge[] = {
    gTilesetAnims_Hoenn_General_LandWaterEdge_Frame0,
    gTilesetAnims_Hoenn_General_LandWaterEdge_Frame1,
    gTilesetAnims_Hoenn_General_LandWaterEdge_Frame2,
    gTilesetAnims_Hoenn_General_LandWaterEdge_Frame3};

const u16 gTilesetAnims_Hoenn_Lavaridge_Steam_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_lavaridge/anim/steam/0.4bpp");
const u16 gTilesetAnims_Hoenn_Lavaridge_Steam_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_lavaridge/anim/steam/1.4bpp");
const u16 gTilesetAnims_Hoenn_Lavaridge_Steam_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_lavaridge/anim/steam/2.4bpp");
const u16 gTilesetAnims_Hoenn_Lavaridge_Steam_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_lavaridge/anim/steam/3.4bpp");

const u16 *const gTilesetAnims_Hoenn_Lavaridge_Steam[] = {
    gTilesetAnims_Hoenn_Lavaridge_Steam_Frame0,
    gTilesetAnims_Hoenn_Lavaridge_Steam_Frame1,
    gTilesetAnims_Hoenn_Lavaridge_Steam_Frame2,
    gTilesetAnims_Hoenn_Lavaridge_Steam_Frame3};

const u16 gTilesetAnims_Hoenn_Pacifidlog_LogBridges_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/log_bridges/0.4bpp");
const u16 gTilesetAnims_Hoenn_Pacifidlog_LogBridges_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/log_bridges/1.4bpp");
const u16 gTilesetAnims_Hoenn_Pacifidlog_LogBridges_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/log_bridges/2.4bpp");

const u16 *const gTilesetAnims_Hoenn_Pacifidlog_LogBridges[] = {
    gTilesetAnims_Hoenn_Pacifidlog_LogBridges_Frame0,
    gTilesetAnims_Hoenn_Pacifidlog_LogBridges_Frame1,
    gTilesetAnims_Hoenn_Pacifidlog_LogBridges_Frame2,
    gTilesetAnims_Hoenn_Pacifidlog_LogBridges_Frame1};

const u16 gTilesetAnims_Hoenn_Underwater_Seaweed_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_underwater/anim/seaweed/0.4bpp");
const u16 gTilesetAnims_Hoenn_Underwater_Seaweed_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_underwater/anim/seaweed/1.4bpp");
const u16 gTilesetAnims_Hoenn_Underwater_Seaweed_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_underwater/anim/seaweed/2.4bpp");
const u16 gTilesetAnims_Hoenn_Underwater_Seaweed_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_underwater/anim/seaweed/3.4bpp");

const u16 *const gTilesetAnims_Hoenn_Underwater_Seaweed[] = {
    gTilesetAnims_Hoenn_Underwater_Seaweed_Frame0,
    gTilesetAnims_Hoenn_Underwater_Seaweed_Frame1,
    gTilesetAnims_Hoenn_Underwater_Seaweed_Frame2,
    gTilesetAnims_Hoenn_Underwater_Seaweed_Frame3};

const u16 gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/0.4bpp");
const u16 gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/1.4bpp");
const u16 gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/2.4bpp");
const u16 gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/3.4bpp");
const u16 gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame4[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/4.4bpp");
const u16 gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame5[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/5.4bpp");
const u16 gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame6[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/6.4bpp");
const u16 gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame7[] = INCBIN_U16("data/tilesets/secondary/hoenn_pacifidlog/anim/water_currents/7.4bpp");

const u16 *const gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents[] = {
    gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame0,
    gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame1,
    gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame2,
    gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame3,
    gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame4,
    gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame5,
    gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame6,
    gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents_Frame7};

const u16 gTilesetAnims_Hoenn_Mauville_Flower1_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_1/0.4bpp");
const u16 gTilesetAnims_Hoenn_Mauville_Flower1_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_1/1.4bpp");
const u16 gTilesetAnims_Hoenn_Mauville_Flower1_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_1/2.4bpp");
const u16 gTilesetAnims_Hoenn_Mauville_Flower1_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_1/3.4bpp");
const u16 gTilesetAnims_Hoenn_Mauville_Flower1_Frame4[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_1/4.4bpp");
const u16 gTilesetAnims_Hoenn_Mauville_Flower2_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_2/0.4bpp");
const u16 gTilesetAnims_Hoenn_Mauville_Flower2_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_2/1.4bpp");
const u16 gTilesetAnims_Hoenn_Mauville_Flower2_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_2/2.4bpp");
const u16 gTilesetAnims_Hoenn_Mauville_Flower2_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_2/3.4bpp");
const u16 gTilesetAnims_Hoenn_Mauville_Flower2_Frame4[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville/anim/flower_2/4.4bpp");
const u16 tileset_anims_space_1[16] = {};

u16 *const gTilesetAnims_Hoenn_Mauville_Flower1_VDests[] = {
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 96)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 100)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 104)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 108)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 112)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 116)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 120)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 124))};

u16 *const gTilesetAnims_Hoenn_Mauville_Flower2_VDests[] = {
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 128)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 132)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 136)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 140)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 144)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 148)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 152)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 156))};

const u16 *const gTilesetAnims_Hoenn_Mauville_Flower1[] = {
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame0,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame0,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame1,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame2,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame3,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame3,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame3,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame3,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame3,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame3,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame2,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame1};

const u16 *const gTilesetAnims_Hoenn_Mauville_Flower2[] = {
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame0,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame0,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame1,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame2,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame3,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame3,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame3,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame3,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame3,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame3,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame2,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame1};

const u16 *const gTilesetAnims_Hoenn_Mauville_Flower1_B[] = {
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame0,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame0,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame4,
    gTilesetAnims_Hoenn_Mauville_Flower1_Frame4};

const u16 *const gTilesetAnims_Hoenn_Mauville_Flower2_B[] = {
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame0,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame0,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame4,
    gTilesetAnims_Hoenn_Mauville_Flower2_Frame4};

const u16 gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/0.4bpp");
const u16 gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/1.4bpp");
const u16 gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/2.4bpp");
const u16 gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/3.4bpp");
const u16 gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame4[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/4.4bpp");
const u16 gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame5[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/5.4bpp");
const u16 gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame6[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/6.4bpp");
const u16 gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame7[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/windy_water/7.4bpp");

u16 *const gTilesetAnims_Hoenn_Rustboro_WindyWater_VDests[] = {
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 128)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 132)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 136)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 140)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 144)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 148)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 152)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 156))};

const u16 *const gTilesetAnims_Hoenn_Rustboro_WindyWater[] = {
    gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame0,
    gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame1,
    gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame2,
    gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame3,
    gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame4,
    gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame5,
    gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame6,
    gTilesetAnims_Hoenn_Rustboro_WindyWater_Frame7};

const u16 gTilesetAnims_Hoenn_Rustboro_Fountain_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/fountain/0.4bpp");
const u16 gTilesetAnims_Hoenn_Rustboro_Fountain_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_rustboro/anim/fountain/1.4bpp");
const u16 tileset_anims_space_2[16] = {};

const u16 *const gTilesetAnims_Hoenn_Rustboro_Fountain[] = {
    gTilesetAnims_Hoenn_Rustboro_Fountain_Frame0,
    gTilesetAnims_Hoenn_Rustboro_Fountain_Frame1};

const u16 gTilesetAnims_Hoenn_Lavaridge_Cave_Lava_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_cave/anim/lava/0.4bpp");
const u16 gTilesetAnims_Hoenn_Lavaridge_Cave_Lava_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_cave/anim/lava/1.4bpp");
const u16 gTilesetAnims_Hoenn_Lavaridge_Cave_Lava_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_cave/anim/lava/2.4bpp");
const u16 gTilesetAnims_Hoenn_Lavaridge_Cave_Lava_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_cave/anim/lava/3.4bpp");
const u16 gTilesetAnims_Hoenn_Lavaridge_Cave_Lava_Frame4[] = INCBIN_U16("data/tilesets/secondary/hoenn_cave/anim/lava/4.4bpp");
const u16 gTilesetAnims_Hoenn_Lavaridge_Cave_Lava_Frame5[] = INCBIN_U16("data/tilesets/secondary/hoenn_cave/anim/lava/5.4bpp");
const u16 gTilesetAnims_Hoenn_Lavaridge_Cave_Lava_Frame6[] = INCBIN_U16("data/tilesets/secondary/hoenn_cave/anim/lava/6.4bpp");
const u16 gTilesetAnims_Hoenn_Lavaridge_Cave_Lava_Frame7[] = INCBIN_U16("data/tilesets/secondary/hoenn_cave/anim/lava/7.4bpp");
const u16 tileset_anims_space_3[16] = {};

const u16 *const gTilesetAnims_Hoenn_Lavaridge_Cave_Lava[] = {
    gTilesetAnims_Hoenn_Lavaridge_Cave_Lava_Frame0,
    gTilesetAnims_Hoenn_Lavaridge_Cave_Lava_Frame1,
    gTilesetAnims_Hoenn_Lavaridge_Cave_Lava_Frame2,
    gTilesetAnims_Hoenn_Lavaridge_Cave_Lava_Frame3};

const u16 gTilesetAnims_Hoenn_EverGrande_Flowers_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/0.4bpp");
const u16 gTilesetAnims_Hoenn_EverGrande_Flowers_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/1.4bpp");
const u16 gTilesetAnims_Hoenn_EverGrande_Flowers_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/2.4bpp");
const u16 gTilesetAnims_Hoenn_EverGrande_Flowers_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/3.4bpp");
const u16 gTilesetAnims_Hoenn_EverGrande_Flowers_Frame4[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/4.4bpp");
const u16 gTilesetAnims_Hoenn_EverGrande_Flowers_Frame5[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/5.4bpp");
const u16 gTilesetAnims_Hoenn_EverGrande_Flowers_Frame6[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/6.4bpp");
const u16 gTilesetAnims_Hoenn_EverGrande_Flowers_Frame7[] = INCBIN_U16("data/tilesets/secondary/hoenn_ever_grande/anim/flowers/7.4bpp");
const u16 tileset_anims_space_4[16] = {};

u16 *const gTilesetAnims_Hoenn_EverGrande_VDests[] = {
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 224)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 228)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 232)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 236)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 240)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 244)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 248)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 252))};

const u16 *const gTilesetAnims_Hoenn_EverGrande_Flowers[] = {
    gTilesetAnims_Hoenn_EverGrande_Flowers_Frame0,
    gTilesetAnims_Hoenn_EverGrande_Flowers_Frame1,
    gTilesetAnims_Hoenn_EverGrande_Flowers_Frame2,
    gTilesetAnims_Hoenn_EverGrande_Flowers_Frame3,
    gTilesetAnims_Hoenn_EverGrande_Flowers_Frame4,
    gTilesetAnims_Hoenn_EverGrande_Flowers_Frame5,
    gTilesetAnims_Hoenn_EverGrande_Flowers_Frame6,
    gTilesetAnims_Hoenn_EverGrande_Flowers_Frame7};

const u16 gTilesetAnims_Hoenn_Dewford_Flag_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_dewford/anim/flag/0.4bpp");
const u16 gTilesetAnims_Hoenn_Dewford_Flag_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_dewford/anim/flag/1.4bpp");
const u16 gTilesetAnims_Hoenn_Dewford_Flag_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_dewford/anim/flag/2.4bpp");
const u16 gTilesetAnims_Hoenn_Dewford_Flag_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_dewford/anim/flag/3.4bpp");

const u16 *const gTilesetAnims_Hoenn_Dewford_Flag[] = {
    gTilesetAnims_Hoenn_Dewford_Flag_Frame0,
    gTilesetAnims_Hoenn_Dewford_Flag_Frame1,
    gTilesetAnims_Hoenn_Dewford_Flag_Frame2,
    gTilesetAnims_Hoenn_Dewford_Flag_Frame3};

const u16 gTilesetAnims_Hoenn_BattleFrontierOutsideWest_Flag_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_frontier_outside_west/anim/flag/0.4bpp");
const u16 gTilesetAnims_Hoenn_BattleFrontierOutsideWest_Flag_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_frontier_outside_west/anim/flag/1.4bpp");
const u16 gTilesetAnims_Hoenn_BattleFrontierOutsideWest_Flag_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_frontier_outside_west/anim/flag/2.4bpp");
const u16 gTilesetAnims_Hoenn_BattleFrontierOutsideWest_Flag_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_frontier_outside_west/anim/flag/3.4bpp");

const u16 *const gTilesetAnims_Hoenn_BattleFrontierOutsideWest_Flag[] = {
    gTilesetAnims_Hoenn_BattleFrontierOutsideWest_Flag_Frame0,
    gTilesetAnims_Hoenn_BattleFrontierOutsideWest_Flag_Frame1,
    gTilesetAnims_Hoenn_BattleFrontierOutsideWest_Flag_Frame2,
    gTilesetAnims_Hoenn_BattleFrontierOutsideWest_Flag_Frame3};

const u16 gTilesetAnims_Hoenn_BattleFrontierOutsideEast_Flag_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_frontier_outside_east/anim/flag/0.4bpp");
const u16 gTilesetAnims_Hoenn_BattleFrontierOutsideEast_Flag_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_frontier_outside_east/anim/flag/1.4bpp");
const u16 gTilesetAnims_Hoenn_BattleFrontierOutsideEast_Flag_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_frontier_outside_east/anim/flag/2.4bpp");
const u16 gTilesetAnims_Hoenn_BattleFrontierOutsideEast_Flag_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_frontier_outside_east/anim/flag/3.4bpp");

const u16 *const gTilesetAnims_Hoenn_BattleFrontierOutsideEast_Flag[] = {
    gTilesetAnims_Hoenn_BattleFrontierOutsideEast_Flag_Frame0,
    gTilesetAnims_Hoenn_BattleFrontierOutsideEast_Flag_Frame1,
    gTilesetAnims_Hoenn_BattleFrontierOutsideEast_Flag_Frame2,
    gTilesetAnims_Hoenn_BattleFrontierOutsideEast_Flag_Frame3};

const u16 gTilesetAnims_Hoenn_Slateport_Balloons_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_slateport/anim/balloons/0.4bpp");
const u16 gTilesetAnims_Hoenn_Slateport_Balloons_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_slateport/anim/balloons/1.4bpp");
const u16 gTilesetAnims_Hoenn_Slateport_Balloons_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_slateport/anim/balloons/2.4bpp");
const u16 gTilesetAnims_Hoenn_Slateport_Balloons_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_slateport/anim/balloons/3.4bpp");

const u16 *const gTilesetAnims_Hoenn_Slateport_Balloons[] = {
    gTilesetAnims_Hoenn_Slateport_Balloons_Frame0,
    gTilesetAnims_Hoenn_Slateport_Balloons_Frame1,
    gTilesetAnims_Hoenn_Slateport_Balloons_Frame2,
    gTilesetAnims_Hoenn_Slateport_Balloons_Frame3};

const u16 gTilesetAnims_Hoenn_Building_TvTurnedOn_Frame0[] = INCBIN_U16("data/tilesets/primary/hoenn_building/anim/tv_turned_on/0.4bpp");
const u16 gTilesetAnims_Hoenn_Building_TvTurnedOn_Frame1[] = INCBIN_U16("data/tilesets/primary/hoenn_building/anim/tv_turned_on/1.4bpp");

const u16 *const gTilesetAnims_Hoenn_Building_TvTurnedOn[] = {
    gTilesetAnims_Hoenn_Building_TvTurnedOn_Frame0,
    gTilesetAnims_Hoenn_Building_TvTurnedOn_Frame1};

const u16 gTilesetAnims_Hoenn_SootopolisGym_SideWaterfall_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis_gym/anim/side_waterfall/0.4bpp");
const u16 gTilesetAnims_Hoenn_SootopolisGym_SideWaterfall_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis_gym/anim/side_waterfall/1.4bpp");
const u16 gTilesetAnims_Hoenn_SootopolisGym_SideWaterfall_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis_gym/anim/side_waterfall/2.4bpp");
const u16 gTilesetAnims_Hoenn_SootopolisGym_FrontWaterfall_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis_gym/anim/front_waterfall/0.4bpp");
const u16 gTilesetAnims_Hoenn_SootopolisGym_FrontWaterfall_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis_gym/anim/front_waterfall/1.4bpp");
const u16 gTilesetAnims_Hoenn_SootopolisGym_FrontWaterfall_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis_gym/anim/front_waterfall/2.4bpp");

const u16 *const gTilesetAnims_Hoenn_SootopolisGym_SideWaterfall[] = {
    gTilesetAnims_Hoenn_SootopolisGym_SideWaterfall_Frame0,
    gTilesetAnims_Hoenn_SootopolisGym_SideWaterfall_Frame1,
    gTilesetAnims_Hoenn_SootopolisGym_SideWaterfall_Frame2};

const u16 *const gTilesetAnims_Hoenn_SootopolisGym_FrontWaterfall[] = {
    gTilesetAnims_Hoenn_SootopolisGym_FrontWaterfall_Frame0,
    gTilesetAnims_Hoenn_SootopolisGym_FrontWaterfall_Frame1,
    gTilesetAnims_Hoenn_SootopolisGym_FrontWaterfall_Frame2};

const u16 gTilesetAnims_Hoenn_EliteFour_FloorLight_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_elite_four/anim/floor_light/0.4bpp");
const u16 gTilesetAnims_Hoenn_EliteFour_FloorLight_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_elite_four/anim/floor_light/1.4bpp");
const u16 gTilesetAnims_Hoenn_EliteFour_WallLights_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_elite_four/anim/wall_lights/0.4bpp");
const u16 gTilesetAnims_Hoenn_EliteFour_WallLights_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_elite_four/anim/wall_lights/1.4bpp");
const u16 gTilesetAnims_Hoenn_EliteFour_WallLights_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_elite_four/anim/wall_lights/2.4bpp");
const u16 gTilesetAnims_Hoenn_EliteFour_WallLights_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_elite_four/anim/wall_lights/3.4bpp");
const u16 tileset_anims_space_5[16] = {};

const u16 *const gTilesetAnims_Hoenn_EliteFour_WallLights[] = {
    gTilesetAnims_Hoenn_EliteFour_WallLights_Frame0,
    gTilesetAnims_Hoenn_EliteFour_WallLights_Frame1,
    gTilesetAnims_Hoenn_EliteFour_WallLights_Frame2,
    gTilesetAnims_Hoenn_EliteFour_WallLights_Frame3};

const u16 *const gTilesetAnims_Hoenn_EliteFour_FloorLight[] = {
    gTilesetAnims_Hoenn_EliteFour_FloorLight_Frame0,
    gTilesetAnims_Hoenn_EliteFour_FloorLight_Frame1};

const u16 gTilesetAnims_Hoenn_MauvilleGym_ElectricGates_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville_gym/anim/electric_gates/0.4bpp");
const u16 gTilesetAnims_Hoenn_MauvilleGym_ElectricGates_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_mauville_gym/anim/electric_gates/1.4bpp");
const u16 tileset_anims_space_6[16] = {};

const u16 *const gTilesetAnims_Hoenn_MauvilleGym_ElectricGates[] = {
    gTilesetAnims_Hoenn_MauvilleGym_ElectricGates_Frame0,
    gTilesetAnims_Hoenn_MauvilleGym_ElectricGates_Frame1};

const u16 gTilesetAnims_Hoenn_BikeShop_BlinkingLights_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_bike_shop/anim/blinking_lights/0.4bpp");
const u16 gTilesetAnims_Hoenn_BikeShop_BlinkingLights_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_bike_shop/anim/blinking_lights/1.4bpp");
const u16 tileset_anims_space_7[16] = {};

const u16 *const gTilesetAnims_Hoenn_BikeShop_BlinkingLights[] = {
    gTilesetAnims_Hoenn_BikeShop_BlinkingLights_Frame0,
    gTilesetAnims_Hoenn_BikeShop_BlinkingLights_Frame1};

const u16 gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/0_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/0_groudon.4bpp");
const u16 gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/1_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/1_groudon.4bpp");
const u16 gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/2_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/2_groudon.4bpp");
const u16 gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/3_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/3_groudon.4bpp");
const u16 gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame4[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/4_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/4_groudon.4bpp");
const u16 gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame5[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/5_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/5_groudon.4bpp");
const u16 gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame6[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/6_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/6_groudon.4bpp");
const u16 gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame7[] = INCBIN_U16("data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/7_kyogre.4bpp", "data/tilesets/secondary/hoenn_sootopolis/anim/stormy_water/7_groudon.4bpp");
const u16 tileset_anims_space_8[16] = {};

const u16 gTilesetAnims_Hoenn_Unused1_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_unused_1/0.4bpp");
const u16 gTilesetAnims_Hoenn_Unused1_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_unused_1/1.4bpp");
const u16 gTilesetAnims_Hoenn_Unused1_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_unused_1/2.4bpp");
const u16 gTilesetAnims_Hoenn_Unused1_Frame3[] = INCBIN_U16("data/tilesets/secondary/hoenn_unused_1/3.4bpp");

const u16 *const gTilesetAnims_Hoenn_Sootopolis_StormyWater[] = {
    gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame0,
    gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame1,
    gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame2,
    gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame3,
    gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame4,
    gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame5,
    gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame6,
    gTilesetAnims_Hoenn_Sootopolis_StormyWater_Frame7};

const u16 gTilesetAnims_Hoenn_BattlePyramid_Torch_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_pyramid/anim/torch/0.4bpp");
const u16 gTilesetAnims_Hoenn_BattlePyramid_Torch_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_pyramid/anim/torch/1.4bpp");
const u16 gTilesetAnims_Hoenn_BattlePyramid_Torch_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_pyramid/anim/torch/2.4bpp");
const u16 tileset_anims_space_9[16] = {};

const u16 gTilesetAnims_Hoenn_BattlePyramid_StatueShadow_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_pyramid/anim/statue_shadow/0.4bpp");
const u16 gTilesetAnims_Hoenn_BattlePyramid_StatueShadow_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_pyramid/anim/statue_shadow/1.4bpp");
const u16 gTilesetAnims_Hoenn_BattlePyramid_StatueShadow_Frame2[] = INCBIN_U16("data/tilesets/secondary/hoenn_battle_pyramid/anim/statue_shadow/2.4bpp");
const u16 tileset_anims_space_10[7808] = {};

const u16 gTilesetAnims_Hoenn_Unused2_Frame0[] = INCBIN_U16("data/tilesets/secondary/hoenn_unused_2/0.4bpp");
const u16 tileset_anims_space_11[224] = {};

const u16 gTilesetAnims_Hoenn_Unused2_Frame1[] = INCBIN_U16("data/tilesets/secondary/hoenn_unused_2/1.4bpp");

const u16 *const gTilesetAnims_Hoenn_BattlePyramid_Torch[] = {
    gTilesetAnims_Hoenn_BattlePyramid_Torch_Frame0,
    gTilesetAnims_Hoenn_BattlePyramid_Torch_Frame1,
    gTilesetAnims_Hoenn_BattlePyramid_Torch_Frame2};

const u16 *const gTilesetAnims_Hoenn_BattlePyramid_StatueShadow[] = {
    gTilesetAnims_Hoenn_BattlePyramid_StatueShadow_Frame0,
    gTilesetAnims_Hoenn_BattlePyramid_StatueShadow_Frame1,
    gTilesetAnims_Hoenn_BattlePyramid_StatueShadow_Frame2};

static const u16 *const sTilesetAnims_Hoenn_BattleDomeFloorLightPals[] = {
    gTilesetAnims_Hoenn_BattleDomePals0_0,
    gTilesetAnims_Hoenn_BattleDomePals0_1,
    gTilesetAnims_Hoenn_BattleDomePals0_2,
    gTilesetAnims_Hoenn_BattleDomePals0_3,
};

// Kanto

static const u16 sTilesetAnims_Kanto_General_Flower_Frame0[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/flower/0.4bpp");
static const u16 sTilesetAnims_Kanto_General_Flower_Frame1[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/flower/1.4bpp");
static const u16 sTilesetAnims_Kanto_General_Flower_Frame2[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/flower/2.4bpp");
static const u16 sTilesetAnims_Kanto_General_Flower_Frame3[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/flower/3.4bpp");
static const u16 sTilesetAnims_Kanto_General_Flower_Frame4[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/flower/4.4bpp");

static const u16 *const sTilesetAnims_Kanto_General_Flower[] = {
    sTilesetAnims_Kanto_General_Flower_Frame0,
    sTilesetAnims_Kanto_General_Flower_Frame1,
    sTilesetAnims_Kanto_General_Flower_Frame2,
    sTilesetAnims_Kanto_General_Flower_Frame3,
    sTilesetAnims_Kanto_General_Flower_Frame4};

static const u16 sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/water_current_landwatersedge/0.4bpp");
static const u16 sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/water_current_landwatersedge/1.4bpp");
static const u16 sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/water_current_landwatersedge/2.4bpp");
static const u16 sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/water_current_landwatersedge/3.4bpp");
static const u16 sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame4[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/water_current_landwatersedge/4.4bpp");
static const u16 sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame5[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/water_current_landwatersedge/5.4bpp");
static const u16 sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame6[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/water_current_landwatersedge/6.4bpp");
static const u16 sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame7[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/water_current_landwatersedge/7.4bpp");

static const u16 *const sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge[] = {
    sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame0,
    sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame1,
    sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame2,
    sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame3,
    sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame4,
    sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame5,
    sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame6,
    sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge_Frame7};

static const u16 sTilesetAnims_Kanto_General_SandWatersEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/sandwatersedge/0.4bpp");
static const u16 sTilesetAnims_Kanto_General_SandWatersEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/sandwatersedge/1.4bpp");
static const u16 sTilesetAnims_Kanto_General_SandWatersEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/sandwatersedge/2.4bpp");
static const u16 sTilesetAnims_Kanto_General_SandWatersEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/sandwatersedge/3.4bpp");
static const u16 sTilesetAnims_Kanto_General_SandWatersEdge_Frame4[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/sandwatersedge/4.4bpp");
static const u16 sTilesetAnims_Kanto_General_SandWatersEdge_Frame5[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/sandwatersedge/5.4bpp");
static const u16 sTilesetAnims_Kanto_General_SandWatersEdge_Frame6[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/sandwatersedge/6.4bpp");
static const u16 sTilesetAnims_Kanto_General_SandWatersEdge_Frame7[] = INCBIN_U16("data/tilesets/primary/kanto_general/anim/sandwatersedge/7.4bpp");

static const u16 *const sTilesetAnims_Kanto_General_SandWatersEdge[] = {
    sTilesetAnims_Kanto_General_SandWatersEdge_Frame0,
    sTilesetAnims_Kanto_General_SandWatersEdge_Frame1,
    sTilesetAnims_Kanto_General_SandWatersEdge_Frame2,
    sTilesetAnims_Kanto_General_SandWatersEdge_Frame3,
    sTilesetAnims_Kanto_General_SandWatersEdge_Frame4,
    sTilesetAnims_Kanto_General_SandWatersEdge_Frame5,
    sTilesetAnims_Kanto_General_SandWatersEdge_Frame6,
    sTilesetAnims_Kanto_General_SandWatersEdge_Frame7};

static const u16 sTilesetAnims_Kanto_CeladonCity_Fountain_Frame0[] = INCBIN_U16("data/tilesets/secondary/kanto_celadon_city/anim/fountain/0.4bpp");
static const u16 sTilesetAnims_Kanto_CeladonCity_Fountain_Frame1[] = INCBIN_U16("data/tilesets/secondary/kanto_celadon_city/anim/fountain/1.4bpp");
static const u16 sTilesetAnims_Kanto_CeladonCity_Fountain_Frame2[] = INCBIN_U16("data/tilesets/secondary/kanto_celadon_city/anim/fountain/2.4bpp");
static const u16 sTilesetAnims_Kanto_CeladonCity_Fountain_Frame3[] = INCBIN_U16("data/tilesets/secondary/kanto_celadon_city/anim/fountain/3.4bpp");
static const u16 sTilesetAnims_Kanto_CeladonCity_Fountain_Frame4[] = INCBIN_U16("data/tilesets/secondary/kanto_celadon_city/anim/fountain/4.4bpp");
static const u16 sTilesetAnims_Kanto_CeladonCity_Fountain_Empty[16] = {};

static const u16 *const sTilesetAnims_Kanto_CeladonCity_Fountain[] = {
    sTilesetAnims_Kanto_CeladonCity_Fountain_Frame0,
    sTilesetAnims_Kanto_CeladonCity_Fountain_Frame1,
    sTilesetAnims_Kanto_CeladonCity_Fountain_Frame2,
    sTilesetAnims_Kanto_CeladonCity_Fountain_Frame3,
    sTilesetAnims_Kanto_CeladonCity_Fountain_Frame4};

static const u16 sTilesetAnims_Kanto_SilphCo_Fountain_Frame0[] = INCBIN_U16("data/tilesets/secondary/kanto_silph_co/anim/fountain/0.4bpp");
static const u16 sTilesetAnims_Kanto_SilphCo_Fountain_Frame1[] = INCBIN_U16("data/tilesets/secondary/kanto_silph_co/anim/fountain/1.4bpp");
static const u16 sTilesetAnims_Kanto_SilphCo_Fountain_Frame2[] = INCBIN_U16("data/tilesets/secondary/kanto_silph_co/anim/fountain/2.4bpp");
static const u16 sTilesetAnims_Kanto_SilphCo_Fountain_Frame3[] = INCBIN_U16("data/tilesets/secondary/kanto_silph_co/anim/fountain/3.4bpp");
static const u16 sTilesetAnims_Kanto_SilphCo_Fountain_Empty[16] = {};

static const u16 *const sTilesetAnims_Kanto_SilphCo_Fountain[] = {
    sTilesetAnims_Kanto_SilphCo_Fountain_Frame0,
    sTilesetAnims_Kanto_SilphCo_Fountain_Frame1,
    sTilesetAnims_Kanto_SilphCo_Fountain_Frame2,
    sTilesetAnims_Kanto_SilphCo_Fountain_Frame3};

static const u16 sTilesetAnims_Kanto_MtEmber_Steam_Frame0[] = INCBIN_U16("data/tilesets/secondary/kanto_mt_ember/anim/steam/0.4bpp");
static const u16 sTilesetAnims_Kanto_MtEmber_Steam_Frame1[] = INCBIN_U16("data/tilesets/secondary/kanto_mt_ember/anim/steam/1.4bpp");
static const u16 sTilesetAnims_Kanto_MtEmber_Steam_Frame2[] = INCBIN_U16("data/tilesets/secondary/kanto_mt_ember/anim/steam/2.4bpp");
static const u16 sTilesetAnims_Kanto_MtEmber_Steam_Frame3[] = INCBIN_U16("data/tilesets/secondary/kanto_mt_ember/anim/steam/3.4bpp");

static const u16 *const sTilesetAnims_Kanto_MtEmber_Steam[] = {
    sTilesetAnims_Kanto_MtEmber_Steam_Frame0,
    sTilesetAnims_Kanto_MtEmber_Steam_Frame1,
    sTilesetAnims_Kanto_MtEmber_Steam_Frame2,
    sTilesetAnims_Kanto_MtEmber_Steam_Frame3};

static const u16 sTilesetAnims_Kanto_VermilionGym_MotorizedDoor_Frame0[] = INCBIN_U16("data/tilesets/secondary/kanto_vermilion_gym/anim/motorizeddoor/0.4bpp");
static const u16 sTilesetAnims_Kanto_VermilionGym_MotorizedDoor_Frame1[] = INCBIN_U16("data/tilesets/secondary/kanto_vermilion_gym/anim/motorizeddoor/1.4bpp");

static const u16 *const sTilesetAnims_Kanto_VermilionGym_MotorizedDoor[] = {
    sTilesetAnims_Kanto_VermilionGym_MotorizedDoor_Frame0,
    sTilesetAnims_Kanto_VermilionGym_MotorizedDoor_Frame1};

static const u16 sTilesetAnims_Kanto_CeladonGym_Flowers_Frame0[] = INCBIN_U16("data/tilesets/secondary/kanto_celadon_gym/anim/flowers/0.4bpp");
static const u16 sTilesetAnims_Kanto_CeladonGym_Flowers_Frame1[] = INCBIN_U16("data/tilesets/secondary/kanto_celadon_gym/anim/flowers/1.4bpp");
static const u16 sTilesetAnims_Kanto_CeladonGym_Flowers_Frame2[] = INCBIN_U16("data/tilesets/secondary/kanto_celadon_gym/anim/flowers/2.4bpp");

static const u16 *const sTilesetAnims_Kanto_CeladonGym_Flowers[] = {
    sTilesetAnims_Kanto_CeladonGym_Flowers_Frame0,
    sTilesetAnims_Kanto_CeladonGym_Flowers_Frame1,
    sTilesetAnims_Kanto_CeladonGym_Flowers_Frame2,
    sTilesetAnims_Kanto_CeladonGym_Flowers_Frame1};

static void ResetTilesetAnimBuffer(void)
{
    sTilesetDMA3TransferBufferSize = 0;
    CpuFill32(0, sTilesetDMA3TransferBuffer, sizeof sTilesetDMA3TransferBuffer);
}

static void AppendTilesetAnimToBuffer(const u16 *src, u16 *dest, u16 size)
{
    if (sTilesetDMA3TransferBufferSize < 20)
    {
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].src = src;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].dest = dest;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].size = size;
        sTilesetDMA3TransferBufferSize++;
    }
}

void TransferTilesetAnimsBuffer(void)
{
    int i;

    for (i = 0; i < sTilesetDMA3TransferBufferSize; i++)
        DmaCopy16(3, sTilesetDMA3TransferBuffer[i].src, sTilesetDMA3TransferBuffer[i].dest, sTilesetDMA3TransferBuffer[i].size);

    sTilesetDMA3TransferBufferSize = 0;
}

void InitTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    _InitPrimaryTilesetAnimation();
    _InitSecondaryTilesetAnimation();
}

void InitSecondaryTilesetAnimation(void)
{
    _InitSecondaryTilesetAnimation();
}

void UpdateTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    if (++sPrimaryTilesetAnimCounter >= sPrimaryTilesetAnimCounterMax)
        sPrimaryTilesetAnimCounter = 0;
    if (++sSecondaryTilesetAnimCounter >= sSecondaryTilesetAnimCounterMax)
        sSecondaryTilesetAnimCounter = 0;

    if (sPrimaryTilesetAnimCallback)
        sPrimaryTilesetAnimCallback(sPrimaryTilesetAnimCounter);
    if (sSecondaryTilesetAnimCallback)
        sSecondaryTilesetAnimCallback(sSecondaryTilesetAnimCounter);
}

static void _InitPrimaryTilesetAnimation(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 0;
    sPrimaryTilesetAnimCallback = NULL;
    if (gMapHeader.mapLayout->primaryTileset && gMapHeader.mapLayout->primaryTileset->callback)
        gMapHeader.mapLayout->primaryTileset->callback();
}

static void _InitSecondaryTilesetAnimation(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 0;
    sSecondaryTilesetAnimCallback = NULL;
    if (gMapHeader.mapLayout->secondaryTileset && gMapHeader.mapLayout->secondaryTileset->callback)
        gMapHeader.mapLayout->secondaryTileset->callback();
}

void InitTilesetAnim_Hoenn_General(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 256;
    sPrimaryTilesetAnimCallback = TilesetAnim_Hoenn_General;
}

void InitTilesetAnim_Kanto_General(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 640;
    sPrimaryTilesetAnimCallback = TilesetAnim_Kanto_General;
}

void InitTilesetAnim_Hoenn_Building(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 256;
    sPrimaryTilesetAnimCallback = TilesetAnim_Hoenn_Building;
}

static void TilesetAnim_Hoenn_General(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Hoenn_General_Flower(timer / 16);
    if (timer % 16 == 1)
        QueueAnimTiles_Hoenn_General_Water(timer / 16);
    if (timer % 16 == 2)
        QueueAnimTiles_Hoenn_General_SandWaterEdge(timer / 16);
    if (timer % 16 == 3)
        QueueAnimTiles_Hoenn_General_Waterfall(timer / 16);
    if (timer % 16 == 4)
        QueueAnimTiles_Hoenn_General_LandWaterEdge(timer / 16);
}

static void TilesetAnim_Kanto_General(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Kanto_General_SandWatersEdge(timer / 8);
    if (timer % 16 == 1)
        QueueAnimTiles_Kanto_General_Water_Current_LandWatersEdge(timer / 16);
    if (timer % 16 == 2)
        QueueAnimTiles_Kanto_General_Flower(timer / 16);
}

static void TilesetAnim_Hoenn_Building(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Hoenn_Building_TVTurnedOn(timer / 8);
}

static void QueueAnimTiles_Hoenn_General_Flower(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_General_Flower);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_General_Flower[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(508)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_General_Water(u16 timer)
{
    u8 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_General_Water);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_General_Water[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(432)), 30 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_General_SandWaterEdge(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_General_SandWaterEdge);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_General_SandWaterEdge[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(464)), 10 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_General_Waterfall(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_General_Waterfall);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_General_Waterfall[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(496)), 6 * TILE_SIZE_4BPP);
}

void InitTilesetAnim_Hoenn_Petalburg(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = NULL;
}

void InitTilesetAnim_Hoenn_Rustboro(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_Rustboro;
}

void InitTilesetAnim_Hoenn_Dewford(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_Dewford;
}

void InitTilesetAnim_Hoenn_Slateport(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_Slateport;
}

void InitTilesetAnim_Hoenn_Mauville(void)
{
    sSecondaryTilesetAnimCounter = sPrimaryTilesetAnimCounter;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_Mauville;
}

void InitTilesetAnim_Hoenn_Lavaridge(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_Lavaridge;
}

void InitTilesetAnim_Hoenn_Fallarbor(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = NULL;
}

void InitTilesetAnim_Hoenn_Fortree(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = NULL;
}

void InitTilesetAnim_Hoenn_Lilycove(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = NULL;
}

void InitTilesetAnim_Hoenn_Mossdeep(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = NULL;
}

void InitTilesetAnim_Hoenn_EverGrande(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_EverGrande;
}

void InitTilesetAnim_Hoenn_Pacifidlog(void)
{
    sSecondaryTilesetAnimCounter = sPrimaryTilesetAnimCounter;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_Pacifidlog;
}

void InitTilesetAnim_Hoenn_Sootopolis(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_Sootopolis;
}

void InitTilesetAnim_Hoenn_BattleFrontierOutsideWest(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_BattleFrontierOutsideWest;
}

void InitTilesetAnim_Hoenn_BattleFrontierOutsideEast(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_BattleFrontierOutsideEast;
}

void InitTilesetAnim_Hoenn_Underwater(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 128;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_Underwater;
}

void InitTilesetAnim_Hoenn_SootopolisGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 240;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_SootopolisGym;
}

void InitTilesetAnim_Hoenn_Cave(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_Cave;
}

void InitTilesetAnim_Hoenn_EliteFour(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 128;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_EliteFour;
}

void InitTilesetAnim_Hoenn_MauvilleGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_MauvilleGym;
}

void InitTilesetAnim_Hoenn_BikeShop(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_BikeShop;
}

void InitTilesetAnim_Hoenn_BattlePyramid(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_BattlePyramid;
}

void InitTilesetAnim_Hoenn_BattleDome(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_BattleDome;
}

void InitTilesetAnim_Kanto_CeladonCity(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 120;
    sSecondaryTilesetAnimCallback = TilesetAnim_Kanto_CeladonCity;
}

void InitTilesetAnim_Kanto_SilphCo(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 160;
    sSecondaryTilesetAnimCallback = TilesetAnim_Kanto_SilphCo;
}

void InitTilesetAnim_Kanto_MtEmber(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_Kanto_MtEmber;
}

void InitTilesetAnim_Kanto_VermilionGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 240;
    sSecondaryTilesetAnimCallback = TilesetAnim_Kanto_VermilionGym;
}

void InitTilesetAnim_Kanto_CeladonGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_Kanto_CeladonGym;
}

static void TilesetAnim_Kanto_CeladonCity(u16 timer)
{
    if (timer % 12 == 0)
        QueueAnimTiles_Kanto_CeladonCity_Fountain(timer / 12);
}

static void TilesetAnim_Kanto_CeladonGym(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Kanto_CeladonGym_Flowers(timer / 16);
}

static void TilesetAnim_Kanto_SilphCo(u16 timer)
{
    if (timer % 10 == 0)
        QueueAnimTiles_Kanto_SilphCo_Fountain(timer / 10);
}

static void TilesetAnim_Kanto_MtEmber(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Kanto_MtEmber_Steam(timer / 16);
}

static void TilesetAnim_Kanto_VermilionGym(u16 timer)
{
    if (timer % 2 == 0)
        QueueAnimTiles_Kanto_VermilionGym_MotorizedDoor(timer / 2);
}

static void TilesetAnim_Hoenn_Rustboro(u16 timer)
{
    if (timer % 8 == 0)
    {
        QueueAnimTiles_Hoenn_Rustboro_WindyWater(timer / 8, 0);
        QueueAnimTiles_Hoenn_Rustboro_Fountain(timer / 8);
    }
    if (timer % 8 == 1)
        QueueAnimTiles_Hoenn_Rustboro_WindyWater(timer / 8, 1);
    if (timer % 8 == 2)
        QueueAnimTiles_Hoenn_Rustboro_WindyWater(timer / 8, 2);
    if (timer % 8 == 3)
        QueueAnimTiles_Hoenn_Rustboro_WindyWater(timer / 8, 3);
    if (timer % 8 == 4)
        QueueAnimTiles_Hoenn_Rustboro_WindyWater(timer / 8, 4);
    if (timer % 8 == 5)
        QueueAnimTiles_Hoenn_Rustboro_WindyWater(timer / 8, 5);
    if (timer % 8 == 6)
        QueueAnimTiles_Hoenn_Rustboro_WindyWater(timer / 8, 6);
    if (timer % 8 == 7)
        QueueAnimTiles_Hoenn_Rustboro_WindyWater(timer / 8, 7);
}

static void TilesetAnim_Hoenn_Dewford(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Hoenn_Dewford_Flag(timer / 8);
}

static void TilesetAnim_Hoenn_Slateport(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Hoenn_Slateport_Balloons(timer / 16);
}

static void TilesetAnim_Hoenn_Mauville(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Hoenn_Mauville_Flowers(timer / 8, 0);
    if (timer % 8 == 1)
        QueueAnimTiles_Hoenn_Mauville_Flowers(timer / 8, 1);
    if (timer % 8 == 2)
        QueueAnimTiles_Hoenn_Mauville_Flowers(timer / 8, 2);
    if (timer % 8 == 3)
        QueueAnimTiles_Hoenn_Mauville_Flowers(timer / 8, 3);
    if (timer % 8 == 4)
        QueueAnimTiles_Hoenn_Mauville_Flowers(timer / 8, 4);
    if (timer % 8 == 5)
        QueueAnimTiles_Hoenn_Mauville_Flowers(timer / 8, 5);
    if (timer % 8 == 6)
        QueueAnimTiles_Hoenn_Mauville_Flowers(timer / 8, 6);
    if (timer % 8 == 7)
        QueueAnimTiles_Hoenn_Mauville_Flowers(timer / 8, 7);
}

static void TilesetAnim_Hoenn_Lavaridge(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Hoenn_Lavaridge_Steam(timer / 16);
    if (timer % 16 == 1)
        QueueAnimTiles_Hoenn_Lavaridge_Lava(timer / 16);
}

static void TilesetAnim_Hoenn_EverGrande(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Hoenn_EverGrande_Flowers(timer / 8, 0);
    if (timer % 8 == 1)
        QueueAnimTiles_Hoenn_EverGrande_Flowers(timer / 8, 1);
    if (timer % 8 == 2)
        QueueAnimTiles_Hoenn_EverGrande_Flowers(timer / 8, 2);
    if (timer % 8 == 3)
        QueueAnimTiles_Hoenn_EverGrande_Flowers(timer / 8, 3);
    if (timer % 8 == 4)
        QueueAnimTiles_Hoenn_EverGrande_Flowers(timer / 8, 4);
    if (timer % 8 == 5)
        QueueAnimTiles_Hoenn_EverGrande_Flowers(timer / 8, 5);
    if (timer % 8 == 6)
        QueueAnimTiles_Hoenn_EverGrande_Flowers(timer / 8, 6);
    if (timer % 8 == 7)
        QueueAnimTiles_Hoenn_EverGrande_Flowers(timer / 8, 7);
}

static void TilesetAnim_Hoenn_Pacifidlog(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Hoenn_Pacifidlog_LogBridges(timer / 16);
    if (timer % 16 == 1)
        QueueAnimTiles_Hoenn_Pacifidlog_WaterCurrents(timer / 16);
}

static void TilesetAnim_Hoenn_Sootopolis(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Hoenn_Sootopolis_StormyWater(timer / 16);
}

static void TilesetAnim_Hoenn_Underwater(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Hoenn_Underwater_Seaweed(timer / 16);
}

static void TilesetAnim_Hoenn_Cave(u16 timer)
{
    if (timer % 16 == 1)
        QueueAnimTiles_Hoenn_Cave_Lava(timer / 16);
}

static void TilesetAnim_Hoenn_BattleFrontierOutsideWest(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Hoenn_BattleFrontierOutsideWest_Flag(timer / 8);
}

static void TilesetAnim_Hoenn_BattleFrontierOutsideEast(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Hoenn_BattleFrontierOutsideEast_Flag(timer / 8);
}

static void QueueAnimTiles_Hoenn_General_LandWaterEdge(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_General_LandWaterEdge);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_General_LandWaterEdge[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(480)), 10 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_Lavaridge_Steam(u8 timer)
{
    u8 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_Lavaridge_Steam);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Lavaridge_Steam[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 288)), 4 * TILE_SIZE_4BPP);

    i = (timer + 2) % (int)ARRAY_COUNT(gTilesetAnims_Hoenn_Lavaridge_Steam);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Lavaridge_Steam[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 292)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_Pacifidlog_LogBridges(u8 timer)
{
    u8 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_Pacifidlog_LogBridges);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Pacifidlog_LogBridges[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 464)), 30 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_Underwater_Seaweed(u8 timer)
{
    u8 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_Underwater_Seaweed);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Underwater_Seaweed[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 496)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_Pacifidlog_WaterCurrents(u8 timer)
{
    u8 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Pacifidlog_WaterCurrents[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 496)), 8 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_Mauville_Flowers(u16 timer_div, u8 timer_mod)
{
    timer_div -= timer_mod;
    if (timer_div < min(ARRAY_COUNT(gTilesetAnims_Hoenn_Mauville_Flower1), ARRAY_COUNT(gTilesetAnims_Hoenn_Mauville_Flower2)))
    {
        timer_div %= min(ARRAY_COUNT(gTilesetAnims_Hoenn_Mauville_Flower1), ARRAY_COUNT(gTilesetAnims_Hoenn_Mauville_Flower2));
        AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Mauville_Flower1[timer_div], gTilesetAnims_Hoenn_Mauville_Flower1_VDests[timer_mod], 4 * TILE_SIZE_4BPP);
        AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Mauville_Flower2[timer_div], gTilesetAnims_Hoenn_Mauville_Flower2_VDests[timer_mod], 4 * TILE_SIZE_4BPP);
    }
    else
    {
        timer_div %= min(ARRAY_COUNT(gTilesetAnims_Hoenn_Mauville_Flower1_B), ARRAY_COUNT(gTilesetAnims_Hoenn_Mauville_Flower2_B));
        AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Mauville_Flower1_B[timer_div], gTilesetAnims_Hoenn_Mauville_Flower1_VDests[timer_mod], 4 * TILE_SIZE_4BPP);
        AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Mauville_Flower2_B[timer_div], gTilesetAnims_Hoenn_Mauville_Flower2_VDests[timer_mod], 4 * TILE_SIZE_4BPP);
    }
}

static void QueueAnimTiles_Hoenn_Rustboro_WindyWater(u16 timer_div, u8 timer_mod)
{
    timer_div -= timer_mod;
    timer_div %= ARRAY_COUNT(gTilesetAnims_Hoenn_Rustboro_WindyWater);
    if (gTilesetAnims_Hoenn_Rustboro_WindyWater[timer_div])
        AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Rustboro_WindyWater[timer_div], gTilesetAnims_Hoenn_Rustboro_WindyWater_VDests[timer_mod], 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_Rustboro_Fountain(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_Rustboro_Fountain);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Rustboro_Fountain[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 448)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_Lavaridge_Lava(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_Lavaridge_Cave_Lava);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Lavaridge_Cave_Lava[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 160)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_EverGrande_Flowers(u16 timer_div, u8 timer_mod)
{
    timer_div -= timer_mod;
    timer_div %= ARRAY_COUNT(gTilesetAnims_Hoenn_EverGrande_Flowers);

    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_EverGrande_Flowers[timer_div], gTilesetAnims_Hoenn_EverGrande_VDests[timer_mod], 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_Cave_Lava(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_Lavaridge_Cave_Lava);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Lavaridge_Cave_Lava[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 416)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_Dewford_Flag(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_Dewford_Flag);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Dewford_Flag[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 170)), 6 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_BattleFrontierOutsideWest_Flag(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_BattleFrontierOutsideWest_Flag);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_BattleFrontierOutsideWest_Flag[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 218)), 6 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_BattleFrontierOutsideEast_Flag(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_BattleFrontierOutsideEast_Flag);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_BattleFrontierOutsideEast_Flag[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 218)), 6 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_Slateport_Balloons(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_Slateport_Balloons);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Slateport_Balloons[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 224)), 4 * TILE_SIZE_4BPP);
}

static void TilesetAnim_Hoenn_MauvilleGym(u16 timer)
{
    if (timer % 2 == 0)
        QueueAnimTiles_Hoenn_MauvilleGym_ElectricGates(timer / 2);
}

static void TilesetAnim_Hoenn_SootopolisGym(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Hoenn_SootopolisGym_Waterfalls(timer / 8);
}

static void TilesetAnim_Hoenn_EliteFour(u16 timer)
{
    if (timer % 64 == 1)
        QueueAnimTiles_Hoenn_EliteFour_GroundLights(timer / 64);
    if (timer % 8 == 1)
        QueueAnimTiles_Hoenn_EliteFour_WallLights(timer / 8);
}

static void TilesetAnim_Hoenn_BikeShop(u16 timer)
{
    if (timer % 4 == 0)
        QueueAnimTiles_Hoenn_BikeShop_BlinkingLights(timer / 4);
}

static void TilesetAnim_Hoenn_BattlePyramid(u16 timer)
{
    if (timer % 8 == 0)
    {
        QueueAnimTiles_Hoenn_BattlePyramid_Torch(timer / 8);
        QueueAnimTiles_Hoenn_BattlePyramid_StatueShadow(timer / 8);
    }
}

static void TilesetAnim_Hoenn_BattleDome(u16 timer)
{
    if (timer % 4 == 0)
        BlendAnimPalette_Hoenn_BattleDome_FloorLights(timer / 4);
}

static void TilesetAnim_Hoenn_BattleDome2(u16 timer)
{
    if (timer % 4 == 0)
        BlendAnimPalette_Hoenn_BattleDome_FloorLightsNoBlend(timer / 4);
}

static void QueueAnimTiles_Hoenn_Building_TVTurnedOn(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_Building_TvTurnedOn);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Building_TvTurnedOn[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(496)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_SootopolisGym_Waterfalls(u16 timer)
{
    u16 i = timer % min(ARRAY_COUNT(gTilesetAnims_Hoenn_SootopolisGym_SideWaterfall), ARRAY_COUNT(gTilesetAnims_Hoenn_SootopolisGym_FrontWaterfall));
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_SootopolisGym_SideWaterfall[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 496)), 12 * TILE_SIZE_4BPP);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_SootopolisGym_FrontWaterfall[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 464)), 20 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_EliteFour_WallLights(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_EliteFour_WallLights);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_EliteFour_WallLights[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 504)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_EliteFour_GroundLights(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_EliteFour_FloorLight);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_EliteFour_FloorLight[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 480)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_MauvilleGym_ElectricGates(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_MauvilleGym_ElectricGates);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_MauvilleGym_ElectricGates[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 144)), 16 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_BikeShop_BlinkingLights(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_BikeShop_BlinkingLights);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_BikeShop_BlinkingLights[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 496)), 9 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_Sootopolis_StormyWater(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_Sootopolis_StormyWater);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_Sootopolis_StormyWater[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 240)), 96 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_BattlePyramid_Torch(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_BattlePyramid_Torch);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_BattlePyramid_Torch[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 151)), 8 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Hoenn_BattlePyramid_StatueShadow(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Hoenn_BattlePyramid_StatueShadow);
    AppendTilesetAnimToBuffer(gTilesetAnims_Hoenn_BattlePyramid_StatueShadow[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 135)), 8 * TILE_SIZE_4BPP);
}

static void BlendAnimPalette_Hoenn_BattleDome_FloorLights(u16 timer)
{
    CpuCopy16(sTilesetAnims_Hoenn_BattleDomeFloorLightPals[timer % ARRAY_COUNT(sTilesetAnims_Hoenn_BattleDomeFloorLightPals)], &gPlttBufferUnfaded[BG_PLTT_ID(8)], PLTT_SIZE_4BPP);
    BlendPalette(BG_PLTT_ID(8), 16, gPaletteFade.y, gPaletteFade.blendColor & 0x7FFF);
    if ((u8)FindTaskIdByFunc(Task_BattleTransition_Intro) != TASK_NONE)
    {
        sSecondaryTilesetAnimCallback = TilesetAnim_Hoenn_BattleDome2;
        sSecondaryTilesetAnimCounterMax = 32;
    }
}

static void BlendAnimPalette_Hoenn_BattleDome_FloorLightsNoBlend(u16 timer)
{
    CpuCopy16(sTilesetAnims_Hoenn_BattleDomeFloorLightPals[timer % ARRAY_COUNT(sTilesetAnims_Hoenn_BattleDomeFloorLightPals)], &gPlttBufferUnfaded[BG_PLTT_ID(8)], PLTT_SIZE_4BPP);
    if ((u8)FindTaskIdByFunc(Task_BattleTransition_Intro) == TASK_NONE)
    {
        BlendPalette(BG_PLTT_ID(8), 16, gPaletteFade.y, gPaletteFade.blendColor & 0x7FFF);
        if (!--sSecondaryTilesetAnimCounterMax)
            sSecondaryTilesetAnimCallback = NULL;
    }
}

// Kanto
static void QueueAnimTiles_Kanto_CeladonGym_Flowers(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(sTilesetAnims_Kanto_CeladonGym_Flowers);
    AppendTilesetAnimToBuffer(sTilesetAnims_Kanto_CeladonGym_Flowers[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(739)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Kanto_VermilionGym_MotorizedDoor(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(sTilesetAnims_Kanto_VermilionGym_MotorizedDoor);
    AppendTilesetAnimToBuffer(sTilesetAnims_Kanto_VermilionGym_MotorizedDoor[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(880)), 7 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Kanto_MtEmber_Steam(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_Kanto_MtEmber_Steam[timer % ARRAY_COUNT(sTilesetAnims_Kanto_MtEmber_Steam)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(896)), 8 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Kanto_SilphCo_Fountain(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_Kanto_SilphCo_Fountain[timer % ARRAY_COUNT(sTilesetAnims_Kanto_SilphCo_Fountain)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(976)), 8 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Kanto_CeladonCity_Fountain(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_Kanto_CeladonCity_Fountain[timer % ARRAY_COUNT(sTilesetAnims_Kanto_CeladonCity_Fountain)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(744)), 8 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Kanto_General_Flower(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_Kanto_General_Flower[timer % ARRAY_COUNT(sTilesetAnims_Kanto_General_Flower)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(508)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Kanto_General_Water_Current_LandWatersEdge(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge[timer % ARRAY_COUNT(sTilesetAnims_Kanto_General_Water_Current_LandWatersEdge)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(416)), 48 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Kanto_General_SandWatersEdge(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_Kanto_General_SandWatersEdge[timer % ARRAY_COUNT(sTilesetAnims_Kanto_General_SandWatersEdge)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(464)), 18 * TILE_SIZE_4BPP);
}