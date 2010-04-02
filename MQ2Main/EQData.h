/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/
namespace EQData
{

// ***************************************************************************
// Defines
// ***************************************************************************

enum PlayerClass
{
	Unknown=								0,
	Warrior=								1,
	Cleric=								2,
	Paladin=								3,
	Ranger=								4,
	Shadowknight=						5,
	Druid=								6,
	Monk=									7,
	Bard=									8,
	Rogue=								9,
	Shaman=								10,
	Necromancer=						11,
	Wizard=								12,
	Mage=									13,
	Enchanter=							14,
	Beastlord=							15,
	Berserker=							16,
	TotalClasses=						16,
};
// class 20 through 35 are the NPC GMs (same class order as above)
// class 41   Merchant
// class 60   LDoN Recruiter
// class 61   LDoN Merchant
// class 63   Tribute Master

typedef struct _ClassInfo
{
	bool CanCast;
	bool PureCaster;
	bool PetClass;
	bool DruidType;
	bool NecroType;
	bool ClericType;
	bool ShamanType;
	char RaidColorOrder;
	PCHAR Name;
	PCHAR ShortName;
} CLASSINFO, *PCLASSINFO;

static _ClassInfo ClassInfo[]=
{
	{0,0,0,0,0,0,0,0,"",""},								//unk
	{0,0,0,0,0,0,0,13,"Warrior","war"},					//war
	{1,1,0,0,0,1,0,2,"Cleric","clr"},					//clr
	{1,0,0,0,0,1,0,8,"Paladin","pal"},					//pal
	{1,0,0,1,0,0,0,9,"Ranger","rng"},					//rng
	{1,0,0,0,1,0,0,11,"Shadowknight","shd"},			//shd
	{1,1,0,1,0,0,0,3,"Druid","dru"},						//dru
	{0,0,0,0,0,0,0,6,"Monk","mnk"},						//mnk
	{1,0,0,0,0,0,0,0,"Bard","brd"},						//brd
	{0,0,0,0,0,0,0,10,"Rogue","rog"},					//rog
	{1,1,1,0,0,0,1,12,"Shaman","shm"},					//shm
	{1,1,1,0,1,0,0,7,"Necromancer","nec"},				//nec
	{1,1,0,0,0,0,0,14,"Wizard","wiz"},					//wiz
	{1,1,1,0,0,0,0,5,"Mage","mag"},						//mag
	{1,1,0,0,0,0,0,4,"Enchanter","enc"},				//enc
	{1,0,1,0,0,0,1,1,"Beastlord","bst"},				//bst
	{0,0,0,0,0,0,0,15,"Berserker","ber"},				//ber
};

enum GroupAbilityLevels { 
   G_MarkNPC=									 0,			//0-3 
   G_NPCHealth=								 1,			//0-1 
   G_DelegateMA=								 3,			//0-1 
   G_DelegateMarkNPC=						 4,			//0-1 
   G_InspectBuffs=							 6,			//0-2 
   G_SpellAwareness=							 8,			//0-1 
   G_OffenseEnhancement=					 9,			//0-5 
   G_ManaEnhancement=						 10,			//0-3 
   G_HealthEnhancement=						 11,			//0-3 
   G_HealthRegen=								 12,			//0-3 
   G_FindPathtoPC=							 13,			//0-1 
   G_HealthofTargetsTarget=				 14,			//0-1 
}; 

enum RaidAbilityLevels { 
   R_MarkNPC=									 0,			//0-3 
   R_NPCHealth=								 1,			//0-1 
   R_DelegateMA=								 3,			//0-3 
   R_DelegateMarkNPC=						 4,			//0-4 
   R_SpellAwareness=							 7,			//0-1 
   R_OffenseEnhancement=					 8,			//0-5 
   R_ManaEnhancement=						 9,			//0-3 
   R_HealthEnhancement=						 10,			//0-3 
   R_HealthRegen=								 11,			//0-3 
   R_FindPathtoPC=							 12,			//0-1 
   R_HealthofTargetsTarget=				 13,			//0-1 
}; 

#define BI_TARGETABLE                   1
#define BI_TRIGGER                      2 
#define BI_TRAP                         4
#define BI_TIMER                        8

typedef struct _BodyInfo
{
	PCHAR Name;
	DWORD Flags;
} BODYINFO, *PBODYINFO;

#define SPAWN_PLAYER                    0
#define SPAWN_NPC                       1
#define SPAWN_CORPSE                    2
//#define SPAWN_ANY                     3
//#define SPAWN_PET                     4

#define ITEM_NORMAL1                    0x0031
#define ITEM_NORMAL2                    0x0036
#define ITEM_NORMAL3                    0x315f
#define ITEM_NORMAL4                    0x3336
#define ITEM_NORMAL5                    0x0032
#define ITEM_NORMAL6                    0x0033
#define ITEM_NORMAL7                    0x0034
#define ITEM_NORMAL8                    0x0039
#define ITEM_CONTAINER                  0x7900
#define ITEM_CONTAINER_PLAIN            0x7953
#define ITEM_BOOK                       0x7379

#define ITEMITEMTYPE_FOOD               0x0e 
#define ITEMITEMTYPE_WATER              0x0f 
#define ITEMITEMTYPE_ALCOHOL            0x26 
#define ITEMITEMTYPE_POISON             0x2a 
#define ITEMITEMTYPE_AUGUMENT           0x36 

#define ITEMEFFECTTYPE_COMBAT           0x00 
#define ITEMEFFECTTYPE_INVENTORY1       0x01 // Bards need to stop sing to cast 
#define ITEMEFFECTTYPE_WORN             0x02 
#define ITEMEFFECTTYPE_INVENTORY2       0x03 
#define ITEMEFFECTTYPE_MUSTEQUIP        0x04 // Bards need to stop sing to cast 
#define ITEMEFFECTTYPE_INVENTORY3       0x05 

#define SKILLMINDAMAGEMOD_BASH          0x00 
#define SKILLMINDAMAGEMOD_BACKSTAB      0x01 
#define SKILLMINDAMAGEMOD_DRAGONPUNCH   0x02 
#define SKILLMINDAMAGEMOD_EAGLESTRIKE   0x03 
#define SKILLMINDAMAGEMOD_FLYINGKICK    0x04 
#define SKILLMINDAMAGEMOD_KICK          0x05 
#define SKILLMINDAMAGEMOD_ROUNDKICK     0x06 
#define SKILLMINDAMAGEMOD_TIGERCLAW     0x07 
#define SKILLMINDAMAGEMOD_FRENZY        0x08 

#define COLOR_DEFAULT                   0x00
#define COLOR_DARKGREY                  0x01
#define COLOR_DARKGREEN                 0x02
#define COLOR_DARKBLUE                  0x03
#define COLOR_PURPLE                    0x05
#define COLOR_LIGHTGREY                 0x06

#define CONCOLOR_GREY                   0x06
#define CONCOLOR_GREEN                  0x02
#define CONCOLOR_LIGHTBLUE              0x12
#define CONCOLOR_BLUE                   0x04
#define CONCOLOR_BLACK                  0x14
#define CONCOLOR_WHITE                  0x0a
#define CONCOLOR_YELLOW                 0x0f
#define CONCOLOR_RED                    0x0d

#define USERCOLOR_SAY                   0xFF +   1 //  1  - Say
#define USERCOLOR_TELL                  0xFF +   2 //  2  - Tell
#define USERCOLOR_GROUP                 0xFF +   3 //  3  - Group
#define USERCOLOR_GUILD                 0xFF +   4 //  4  - Guild
#define USERCOLOR_OOC                   0xFF +   5 //  5  - OOC
#define USERCOLOR_AUCTION               0xFF +   6 //  6  - Auction
#define USERCOLOR_SHOUT                 0xFF +   7 //  7  - Shout
#define USERCOLOR_EMOTE                 0xFF +   8 //  8  - Emote
#define USERCOLOR_SPELLS                0xFF +   9 //  9  - Spells (meming, scribing, casting, etc.)
#define USERCOLOR_YOU_HIT_OTHER         0xFF +  10 //  10 - You hit other
#define USERCOLOR_OTHER_HIT_YOU         0xFF +  11 //  11 - Other hits you
#define USERCOLOR_YOU_MISS_OTHER        0xFF +  12 //  12 - You miss other
#define USERCOLOR_OTHER_MISS_YOU        0xFF +  13 //  13 - Other misses you
#define USERCOLOR_DUELS                 0xFF +  14 //  14 - Some broadcasts (duels)
#define USERCOLOR_SKILLS                0xFF +  15 //  15 - Skills (ups, non-combat use, etc.)
#define USERCOLOR_DISCIPLINES           0xFF +  16 //  16 - Disciplines or special abilities
#define USERCOLOR_UNUSED001             0xFF +  17 //  17 - Unused at this time
#define USERCOLOR_DEFAULT               0xFF +  18 //  18 - Default text and stuff you type
#define USERCOLOR_UNUSED002             0xFF +  19 //  19 - Unused at this time
#define USERCOLOR_MERCHANT_OFFER        0xFF +  20 //  20 - Merchant Offer Price
#define USERCOLOR_MERCHANT_EXCHANGE     0xFF +  21 //  21 - Merchant Buy/Sell
#define USERCOLOR_YOUR_DEATH            0xFF +  22 //  22 - Your death message
#define USERCOLOR_OTHER_DEATH           0xFF +  23 //  23 - Others death message
#define USERCOLOR_OTHER_HIT_OTHER       0xFF +  24 //  24 - Other damage other
#define USERCOLOR_OTHER_MISS_OTHER      0xFF +  25 //  25 - Other miss other
#define USERCOLOR_WHO                   0xFF +  26 //  26 - /who command
#define USERCOLOR_YELL                  0xFF +  27 //  27 - yell for help
#define USERCOLOR_NON_MELEE             0xFF +  28 //  28 - Hit for non-melee
#define USERCOLOR_SPELL_WORN_OFF        0xFF +  29 //  29 - Spell worn off
#define USERCOLOR_MONEY_SPLIT           0xFF +  30 //  30 - Money splits
#define USERCOLOR_LOOT                  0xFF +  31 //  31 - Loot message
#define USERCOLOR_RANDOM                0xFF +  32 //  32 - Dice Roll (/random)
#define USERCOLOR_OTHERS_SPELLS         0xFF +  33 //  33 - Others spells
#define USERCOLOR_SPELL_FAILURE         0xFF +  34 //  34 - Spell Failures (resists, fizzles, missing component, bad target, etc.)
#define USERCOLOR_CHAT_CHANNEL          0xFF +  35 //  35 - Chat Channel Messages
#define USERCOLOR_CHAT_1                0xFF +  36 //  36 - Chat Channel 1
#define USERCOLOR_CHAT_2                0xFF +  37 //  37 - Chat Channel 2
#define USERCOLOR_CHAT_3                0xFF +  38 //  38 - Chat Channel 3
#define USERCOLOR_CHAT_4                0xFF +  39 //  39 - Chat Channel 4
#define USERCOLOR_CHAT_5                0xFF +  40 //  40 - Chat Channel 5
#define USERCOLOR_CHAT_6                0xFF +  41 //  41 - Chat Channel 6
#define USERCOLOR_CHAT_7                0xFF +  42 //  42 - Chat Channel 7
#define USERCOLOR_CHAT_8                0xFF +  43 //  43 - Chat Channel 8
#define USERCOLOR_CHAT_9                0xFF +  44 //  44 - Chat Channel 9
#define USERCOLOR_CHAT_10               0xFF +  45 //  45 - Chat Channel 10
#define USERCOLOR_MELEE_CRIT            0xFF +  46 //  46 - Melee Crits
#define USERCOLOR_SPELL_CRIT            0xFF +  47 //  47 - Spell Crits
#define USERCOLOR_TOO_FAR_AWAY          0xFF +  48 //  48 - Too far away (melee)
#define USERCOLOR_NPC_RAMPAGE           0xFF +  49 //  49 - NPC Rampage
#define USERCOLOR_NPC_FLURRY            0xFF +  50 //  50 - NPC Furry
#define USERCOLOR_NPC_ENRAGE            0xFF +  51 //  51 - NPC Enrage
#define USERCOLOR_ECHO_SAY              0xFF +  52 //  52 - say echo
#define USERCOLOR_ECHO_TELL             0xFF +  53 //  53 - tell echo
#define USERCOLOR_ECHO_GROUP            0xFF +  54 //  54 - group echo
#define USERCOLOR_ECHO_GUILD            0xFF +  55 //  55 - guild echo
#define USERCOLOR_ECHO_OOC              0xFF +  56 //  56 - group echo
#define USERCOLOR_ECHO_AUCTION          0xFF +  57 //  57 - auction echo
#define USERCOLOR_ECHO_SHOUT            0xFF +  58 //  58 - shout echo
#define USERCOLOR_ECHO_EMOTE            0xFF +  59 //  59 - emote echo
#define USERCOLOR_ECHO_CHAT_1           0xFF +  60 //  60 - chat 1 echo
#define USERCOLOR_ECHO_CHAT_2           0xFF +  61 //  61 - chat 2 echo
#define USERCOLOR_ECHO_CHAT_3           0xFF +  62 //  62 - chat 3 echo
#define USERCOLOR_ECHO_CHAT_4           0xFF +  63 //  63 - chat 4 echo
#define USERCOLOR_ECHO_CHAT_5           0xFF +  64 //  64 - chat 5 echo
#define USERCOLOR_ECHO_CHAT_6           0xFF +  65 //  65 - chat 6 echo
#define USERCOLOR_ECHO_CHAT_7           0xFF +  66 //  66 - chat 7 echo
#define USERCOLOR_ECHO_CHAT_8           0xFF +  67 //  67 - chat 8 echo
#define USERCOLOR_ECHO_CHAT_9           0xFF +  68 //  68 - chat 9 echo
#define USERCOLOR_ECHO_CHAT_10          0xFF +  69 //  69 - chat 10 echo
#define USERCOLOR_RESERVED              0xFF +  70 //  70 - "unused at this time" 
#define USERCOLOR_LINK                  0xFF +  71 //  71 - item links 
#define USERCOLOR_RAID                  0xFF +  72 //  72 - raid 
#define USERCOLOR_PET                   0xFF +  73 //  73 - my pet 
#define USERCOLOR_DAMAGESHIELD          0xFF +  74 //  74 - damage shields 
#define USERCOLOR_LEADER                0xFF +  75 //  75 - LAA-related messages 
#define USERCOLOR_PETRAMPFLURRY         0xFF +  76 //  76 - pet rampage/flurry 
#define USERCOLOR_PETCRITS              0xFF +  77 //  77 - pet's critical hits 
#define USERCOLOR_FOCUS                 0xFF +  78 //  78 - focus item activation 
#define USERCOLOR_XP                    0xFF +  79 //  79 - xp gain/loss 
#define USERCOLOR_SYSTEM                0xFF +  80 //  80 - system broadcasts etc 

#define DEITY_Bertoxxulous					 201
#define DEITY_BrellSerilis					 202
#define DEITY_CazicThule					 203
#define DEITY_ErollisiMarr					 204
#define DEITY_Bristlebane					 205
#define DEITY_Innoruuk						 206
#define DEITY_Karana							 207
#define DEITY_MithanielMarr				 208
#define DEITY_Prexus							 209
#define DEITY_Quellious						 210
#define DEITY_RallosZek						 211
#define DEITY_RodcetNife					 212
#define DEITY_SolusekRo						 213
#define DEITY_TheTribunal					 214
#define DEITY_Tunare							 215
#define DEITY_Veeshan						 216

#define ITEMTYPE_NORMAL						 0
#define ITEMTYPE_PACK						 1
#define ITEMTYPE_BOOK						 2

#define COMP_NONE								 0
#define COMP_EQ								 1
#define COMP_NE								 2
#define COMP_GT								 3
#define COMP_LT								 4
#define COMP_GE								 5
#define COMP_LE								 6
#define COMP_CONT								 7
#define COMP_NOTCONT							 8
#define COMP_BITAND							 9
#define COMP_BITOR							 10

#define COMP_TYPE_STRING					 0
#define COMP_TYPE_NUMERIC					 1
#define COMP_TYPE_BIT						 2

#define CMD_MQ									 1
#define CMD_EQ									 2		

#define LASTFIND_NOTFOUND					 96
#define LASTFIND_PRIMARY					 97

#define EVENT_CHAT							 0
#define EVENT_TIMER							 1
#define EVENT_CUSTOM							 2
#define EVENT_EVAL							 3
#define EVENT_EXEC							 4
#define EVENT_PULSE							 5
#define EVENT_SHUTDOWN						 6
#define EVENT_BREAK							 7
#define NUM_EVENTS							 8

#define CHAT_SAY								 1
#define CHAT_TELL								 2
#define CHAT_OOC								 4
#define CHAT_SHOUT							 8
#define CHAT_AUC								 16
#define CHAT_GUILD							 32
#define CHAT_GROUP							 64
#define CHAT_CHAT								 128
#define CHATEVENT(x)							 (gEventChat & x)

#define FILTERSKILL_ALL						 0
#define FILTERSKILL_INCREASE				 1
#define FILTERSKILL_NONE					 2

#define FILTERMACRO_ALL						 0
#define FILTERMACRO_ENHANCED				 1
#define FILTERMACRO_NONE					 2


#define MAX_STRING							 2048
#define MAX_VARNAME							 64

// Defines for CXWnd WindowStyle
#define CWS_VSCROLL							 0x1
#define CWS_HSCROLL							 0x2
#define CWS_TITLE								 0x4
#define CWS_CLOSE								 0x8
//#define CWS_UNKNOWN						 0x10
#define CWS_MINIMIZE							 0x20
#define CWS_BORDER							 0x40
//#define CWS_UNKNOWN						 0x80
//#define CWS_UNKNOWN						 0x100
#define CWS_RESIZEALL						 0x200
#define CWS_TRANSPARENT						 0x400
//#define CWS_UNKNOWN						 0x800
#define CWS_NOMOVE							 0x8000
#define CWS_UNKNOWN							 0x40000
#define ToggleBit(field,bit)				 field^=bit;
#define BitOn(field,bit)					 field|=bit;
#define BitOff(field,bit)					 field&=~bit;
// End CXWnd WindowStyle Defines

enum MOUSE_DATA_TYPES {
   MD_Unknown = -1,
   MD_Button0Click=0,
   MD_Button1Click,
   MD_Button0,
   MD_Button1
};

#define nEQMappableCommands				 0x113

#define MAX_PC_LEVEL                    75

// ***************************************************************************
// Structures
// ***************************************************************************

typedef struct _MOUSESPOOF {
   MOUSE_DATA_TYPES		mdType;
   DWORD						dwData;
   struct _MOUSESPOOF	*pNext;
} MOUSESPOOF, *PMOUSESPOOF;

typedef struct _MOUSECLICK {
   BYTE ConfirmLeftClick;// DO NOT WRITE TO THIS BYTE
   BYTE ConfirmRightClick;// DO NOT WRITE TO THIS BYTE
   BYTE RightClick;
   BYTE LeftClick;
} MOUSECLICK, *PMOUSECLICK;

typedef struct _UILOCATION {
   DWORD x;
   DWORD y;
   DWORD w;
   DWORD h;
   CHAR error[MAX_STRING];
} UILOCATION, *PUILOCATION;

#define ITEM_NAME_LEN         0x40
#define LORE_NAME_LEN         0x70

// size is 0x20 12-05-2006
typedef struct _ITEMSPELLS { 
/*0x00*/ DWORD SpellID; 
/*0x04*/ BYTE  RequiredLevel; 
/*0x05*/ BYTE  EffectType; 
/*0x06*/ BYTE  Unknown[0x2]; 
/*0x08*/ DWORD Unknown0x08;
/*0x0c*/ DWORD MaxCharges;
/*0x10*/ DWORD CastTime;
/*0x14*/ DWORD TimerID;
/*0x18*/ DWORD RecastType;
/*0x1c*/ DWORD ProcRate;
/*0x20*/
} ITEMSPELLS, *PITEMSPELLS; 

// size is 0x4a8 02-16-07
typedef struct _ITEMINFO {
/*0x000*/ CHAR   Name[ITEM_NAME_LEN];
/*0x040*/ CHAR   LoreName[LORE_NAME_LEN];
/*0x0b0*/ CHAR   IDFile[0x20];
/*0x0d0*/ DWORD  ItemNumber;
/*0x0d4*/ DWORD  EquipSlots;
/*0x0d8*/ DWORD  Cost;
/*0x0dc*/ DWORD  IconNumber;
/*0x0e0*/ BYTE   Unknown0xe0[0x9];
/*0x0e9*/ BYTE   Weight;
/*0x0ea*/ BYTE   NoRent; // 0=temp, 1=default
/*0x0eb*/ BYTE   NoDrop; // 0=no drop, 1=can drop
/*0x0ec*/ BYTE   Attuneable;
/*0x0ed*/ BYTE   Size;
/*0x0ee*/ BYTE   Type;
/*0x0ef*/ BYTE   TradeSkills;
/*0x0f0*/ BYTE   Lore;
/*0x0f1*/ BYTE   Unknown0xf1[0x3];
/*0x0f4*/ BYTE   Artifact;
/*0x0f5*/ BYTE   Summoned;
/*0x0f6*/ BYTE   SvCold;
/*0x0f7*/ BYTE   SvFire;
/*0x0f8*/ BYTE   SvMagic;
/*0x0f9*/ BYTE   SvDisease;
/*0x0fa*/ BYTE   SvPoison;
/*0x0fb*/ BYTE   SvCorruption;
/*0x0fc*/ BYTE   STR;
/*0x0fd*/ BYTE   STA;
/*0x0fe*/ BYTE   AGI;
/*0x0ff*/ BYTE   DEX;
/*0x100*/ BYTE   CHA;
/*0x101*/ BYTE   INT;
/*0x102*/ BYTE   WIS;
/*0x103*/ BYTE   Unknown0x103;
/*0x104*/ DWORD  HP;
/*0x108*/ DWORD  Mana;
/*0x10c*/ DWORD  AC;
/*0x110*/ DWORD  RequiredLevel;
/*0x114*/ DWORD  RecommendedLevel;
/*0x118*/ BYTE   RecommendedSkill;
/*0x119*/ BYTE   Unknown0x119[0x3];
/*0x11c*/ BYTE   SkillModType;
/*0x11d*/ BYTE   Unknown0x11d[0x3];
/*0x120*/ DWORD  Unknown0x120;
/*0x124*/ DWORD  SkillModValue;
/*0x128*/ DWORD  BaneDMGRace;
/*0x12c*/ DWORD  BaneDMGBodyType;
/*0x130*/ BYTE   BaneDMGBodyTypeValue;
/*0x131*/ BYTE   BaneDMGRaceValue;
/*0x132*/ BYTE   Unknown0x132[0x6];
/*0x138*/ DWORD  InstrumentType;
/*0x13c*/ DWORD  InstrumentMod;
/*0x140*/ DWORD  Classes;
/*0x144*/ DWORD  Races;
/*0x148*/ DWORD  Diety;
/*0x14c*/ BYTE   Unknown0x14c[0x4];
/*0x150*/ BYTE   Magic;
/*0x151*/ BYTE   Light;
/*0x152*/ BYTE   Delay;
/*0x153*/ BYTE   DmgBonusType;
/*0x154*/ BYTE   DmgBonusVal;
/*0x155*/ BYTE   Range;
/*0x156*/ BYTE   Unknown0x156[0x2];
/*0x158*/ DWORD  Damage;
/*0x15c*/ BYTE   ItemType;
/*0x15d*/ BYTE   Unknown0x15d[0x3];
/*0x160*/ BYTE   Material;
/*0x161*/ BYTE   Unknown0x161[0xb];
/*0x16c*/ DWORD  AugSlot1;
/*0x170*/ DWORD  AugSlot1_Unknown;
/*0x174*/ DWORD  AugSlot2;
/*0x178*/ DWORD  AugSlot2_Unknown;
/*0x17c*/ DWORD  AugSlot3;
/*0x180*/ DWORD  AugSlot3_Unknown;
/*0x184*/ DWORD  AugSlot4;
/*0x188*/ DWORD  AugSlot4_Unknown;
/*0x18c*/ DWORD  AugSlot5;
/*0x190*/ DWORD  AugSlot5_Unknown;
/*0x194*/ DWORD  AugType;
/*0x198*/ DWORD  AugRestrictions;
/*0x19c*/ DWORD  SolventNeeded; //ID# of Solvent (Augs only)
/*0x1a0*/ DWORD  LDTheme;
/*0x1a4*/ DWORD  LDCost;
/*0x1a8*/ DWORD  LDType;
/*0x1ac*/ DWORD  Unknown0x1ac;
/*0x1b0*/ BYTE   Unknown0x1b0[0x4];
/*0x1b4*/ DWORD  FactionModType[0x4];
/*0x1c4*/ DWORD  FactionModValue[0x4];
/*0x1d4*/ BYTE   CharmFile[0x20];
/*0x1f4*/ BYTE   Unknown0x1f4[0x4];
/*0x1f8*/ struct _ITEMSPELLS Clicky;
/*0x218*/ struct _ITEMSPELLS Proc;
/*0x238*/ struct _ITEMSPELLS Worn;
/*0x258*/ struct _ITEMSPELLS Focus;
/*0x278*/ struct _ITEMSPELLS Scroll;
/*0x298*/ BYTE   Unknown0x298[0x168];
/*0x400*/ DWORD  CombatEffects;
/*0x404*/ DWORD  Shielding;
/*0x408*/ DWORD  StunResist;
/*0x40c*/ DWORD  DoTShielding;
/*0x410*/ DWORD  StrikeThrough;
/*0x414*/ DWORD  DmgBonusSkill; // SkillMinDamageMod;
/*0x418*/ DWORD  DmgBonusValue; // MinDamageMod;
/*0x41c*/ DWORD  SpellShield;
/*0x420*/ DWORD  Avoidance;
/*0x424*/ DWORD  Accuracy;
/*0x428*/ DWORD  CharmFileID;
/*0x42c*/ DWORD  CastTime;
/*0x430*/ BYTE   Combine;
/*0x431*/ BYTE   Slots;
/*0x432*/ BYTE   SizeCapacity;
/*0x433*/ BYTE   WeightReduction;
/*0x434*/ BYTE   BookType;      // 0=note, !0=book
/*0x435*/ BYTE   BookLang;
/*0x436*/ CHAR   BookFile[0x1e];
/*0x454*/ DWORD  Favor;         // Tribute Value
/*0x458*/ DWORD  GuildFavor;
/*0x45c*/ DWORD  Unknown0x45c;
/*0x460*/ DWORD  Endurance;
/*0x464*/ DWORD  Attack;
/*0x468*/ DWORD  HPRegen;
/*0x46c*/ DWORD  ManaRegen;
/*0x470*/ DWORD  Unknown0x470;
/*0x474*/ DWORD  Haste;
/*0x478*/ DWORD  DamShield;
/*0x47c*/ BYTE   Unknown0x47c[0x8];
/*0x484*/ BYTE   NoPet;
/*0x485*/ BYTE   Unknown0x485[0xb];
/*0x490*/ DWORD  StackSize;
/*0x494*/ BYTE   Unknown0x494[0x10];
/*0x4a4*/ BYTE   QuestItem;
/*0x4a5*/ BYTE   Unknown0x4a5[0x3];
/*0x4a8*/
} ITEMINFO, *PITEMINFO;

// actual size 0xb0 02-16-2007
typedef struct _CONTENTS {
/*0x00*/  void    *vtable;
/*0x04*/  void    *punknown;
/*0x08*/  DWORD   Price;             // merchant price
/*0x0c*/  BYTE    Unknown0xc[0x1c];
/*0x28*/  BYTE    EvolvingExpOn;
/*0x29*/  BYTE    Unknown0x29[0x7];
/*0x30*/  DOUBLE  EvolvingExpPct;
/*0x38*/  BYTE    Unknown0x38[0xc];
/*0x44*/  BYTE    IsEvolvingItem;
/*0x45*/  BYTE    Unknown0x45[0x3];
/*0x48*/  DWORD   MerchantQuantity;  // amount that a merchant has for sale, -1 for unlimited
/*0x4c*/  DWORD   Open;
/*0x50*/  DWORD   ItemSlot;
/*0x54*/  DWORD   Unknown0x54;
/*0x58*/  DWORD   EvolvingCurrentLevel;
/*0x5c*/  DWORD   Unknown0x5c;
/*0x60*/  DWORD   MerchantSlot;      // slot id on a merchant 
/*0x64*/  DWORD   Unknown0x64;
/*0x68*/  DWORD   Charges;           // charges if positive; some things are neg
/*0x6c*/  struct  _ITEMINFO *Item;
/*0x70*/  struct  _CONTENTS *Contents[0x0a]; //addresses to whats inside the bag if its a bag; augs if an item
/*0x98*/  BYTE    Unknown0x98[0xc];
/*0xa4*/  DWORD   EvolvingMaxLevel;
/*0xa8*/  DWORD   EvolvingLoreGroup; // lore group if it's an evolving item
/*0xac*/  DWORD   StackCount;
/*0xb0*/
} CONTENTS, *PCONTENTS;

// 02-13-2007 Size 0x14
typedef struct _SPELLBUFF {
/*0x00*/    BYTE      Unknown0x00;
/*0x01*/    BYTE      Level;
/*0x02*/    CHAR      Modifier; // bard song modifier, divide by 10 to get 2.8 etc
/*0x03*/    CHAR      DamageShield;  // maybe.. I've noticed this is -1 on a lot of ds's.
/*0x04*/    LONG      SpellID;// -1 or 0 for no spell..
/*0x08*/    DWORD     Duration;
/*0x0c*/    DWORD     DamageAbsorbRemaining;  // Melee or Spellshield type
/*0x10*/    DWORD     Unknown0x10;
/*0x14*/
} SPELLBUFF, *PSPELLBUFF;

// 12-23-2003   TheColonel
typedef struct _INVENTORY { 
/*0x00*/  struct	_CONTENTS* Charm; 
/*0x04*/  struct	_CONTENTS* LeftEar; 
/*0x08*/  struct	_CONTENTS* Head; 
/*0x0c*/  struct	_CONTENTS* Face; 
/*0x10*/  struct	_CONTENTS* RightEar; 
/*0x14*/  struct	_CONTENTS* Neck; 
/*0x18*/  struct	_CONTENTS* Shoulders; 
/*0x1c*/  struct	_CONTENTS* Arms; 
/*0x20*/  struct	_CONTENTS* Back; 
/*0x24*/  struct	_CONTENTS* LeftWrist; 
/*0x28*/  struct	_CONTENTS* RightWrist; 
/*0x2c*/  struct	_CONTENTS* Range; 
/*0x30*/  struct	_CONTENTS* Hands; 
/*0x34*/  struct	_CONTENTS* Primary; 
/*0x38*/  struct	_CONTENTS* Secondary; 
/*0x3c*/  struct	_CONTENTS* LeftFinger; 
/*0x40*/  struct	_CONTENTS* RightFinger; 
/*0x44*/  struct	_CONTENTS* Chest; 
/*0x48*/  struct	_CONTENTS* Legs; 
/*0x4c*/  struct	_CONTENTS* Feet; 
/*0x50*/  struct	_CONTENTS* Waist; 
/*0x54*/  struct	_CONTENTS* PowerSource; 
/*0x58*/  struct	_CONTENTS* Ammo; 
/*0x5c*/  struct	_CONTENTS* Pack[0x8]; 
} INVENTORY, *PINVENTORY; 

#define NUM_ALT_ABILITIES_ARRAY   0x1F7						
#define NUM_ALT_ABILITIES   0x270f

//these two will merge when i get a chance
#define AA_CHAR_MAX         0xF5
#define AA_CHAR_MAX_REAL    0xF0

typedef struct _AALIST { 
/*0x0*/   DWORD		AAIndex;
/*0x4*/   DWORD		PointsSpent;
/*0x8*/   DWORD		ChargeSpent;        // charges spent in the last 10 min?
} AALIST, *PAALIST;

#define      NUM_INV_SLOTS          0x1f
#define      NUM_BANK_SLOTS         0x1a
#define      NUM_BOOK_SLOTS         0x200
#define      NUM_COMBAT_ABILITIES   0x64
#define      BAG_SLOT_START         23
#define ExactLocation		 0

typedef struct _LEADERABILITIES {
/*0x00*/ DWORD MarkNPC;
/*0x04*/ DWORD NPCHealth;
/*0x08*/ DWORD Unknown0x8;
/*0x0c*/ DWORD DelegateMA;
/*0x10*/ DWORD DelegateMarkNPC;
/*0x14*/ DWORD Unknown0x14;
/*0x18*/ DWORD InspectBuffs;
/*0x1c*/ DWORD Unknown0x1c;
/*0x20*/ DWORD SpellAwareness;
/*0x24*/ DWORD OffenseEnhancement;
/*0x28*/ DWORD ManaEnhancement;
/*0x2c*/ DWORD HealthEnhancement;
/*0x30*/ DWORD HealthRegen;
/*0x34*/ DWORD FindPathPC;
/*0x38*/ DWORD HoTT;
/*0x3c*/ DWORD Unknown0x3c;
/*0x40*/
} LEADERABILITIES, *PLEADERABILITIES;

typedef struct _EQC_INFO {
/* 0x0000 */    DWORD   minus4;
/* 0x0004 */    DWORD   stuff_offset;
} EQC_INFO, *PEQC_INFO;

typedef struct _CI_INFO {
/* 0x0000 */    DWORD   minus8;
/* 0x0004 */    DWORD   stuff_offset;
/* 0x0008 */    DWORD   Unknown0x8;    // 2000
/* 0x000c */    DWORD   Unknown0xc;    // 2500
/* 0x0010 */    DWORD   Unknown0x10;   // 3000
/* 0x0014 */    DWORD   Unknown0x14;   // 4000
/* 0x0018 */    DWORD   Unknown0x18;   // 10000
} CI_INFO, *PCI_INFO;

typedef struct _CI2_INFO {
/* 0x0000 */    DWORD   Unknown0x0;
/* 0x0004 */    struct  _CHARINFO2* pCharInfo2;
/* 0x0008 */    struct  _CHARINFO2* pCharInfo3;
/* 0x000c */    BYTE    Unknown0xc[0x14];
/* 0x0010 */    void   *Unknown0x10[0x10];
/* 0x0060 */
} CI2_INFO, *PCI2_INFO;


// actual size 0x11048 02-16-2007
typedef struct _CHARINFO {
/*0x00000*/   void      *vtable1;
/*0x00004*/   void      *punknown;
/*0x00008*/   struct     _CI_INFO* charinfo_info;
/*0x0000c*/   BYTE       Unknown0xc[0xbe4];
/*0x00bf0*/   struct     _LEADERABILITIES MyAbilities; //points spent in each ability (size 0x40)
/*0x00c30*/   BYTE       Unknown0xc30[0xc0];
/*0x00cf0*/   struct     _CONTENTS*   Bank[NUM_BANK_SLOTS];
/*0x00d58*/   BYTE       unknown0xd58[0xdc];
/*0x00e34*/   DWORD      GuildID;
/*0x00e38*/   BYTE       Unknown0xe38[0x1c]; 
/*0x00e54*/   DWORD      AAExp;
/*0x00e58*/   BYTE       Unknown0xe58; 
/*0x00e59*/   BYTE       PercentEXPtoAA;
/*0x00e5a*/   BYTE       Unknown0xe5a[0x42];
/*0x00e9c*/   DWORD      TributeTimer;
/*0x00ea0*/   DWORD      CareerFavor;
/*0x00ea4*/   DWORD      Unknown0xea4;
/*0x00ea8*/   DWORD      CurrFavor;
/*0x00eac*/   BYTE       Unknown0xeac[0xc];
/*0x00eb8*/   DOUBLE     GroupLeadershipExp;
/*0x00ec0*/   DOUBLE     RaidLeadershipExp;
/*0x00ec8*/   DWORD      GroupLeadershipPoints;
/*0x00ecc*/   DWORD      RaidLeadershipPoints;
/*0x00ed0*/   BYTE       Unknown0xed0[0x18c];
/*0x0105c*/   DWORD      RadiantCrystals;
/*0x01060*/   DWORD      Unknown0x1060;
/*0x01064*/   DWORD      EbonCrystals;
/*0x01068*/   BYTE       Unknown0x1068[0x5fc];
/*0x01664*/   CHAR       GroupMember[0x6][0x40];
/*0x017e4*/   CHAR       GroupLeader[0x40];
/*0x01824*/   struct     _LEADERABILITIES ActiveAbilities;//0x1824 //ability levels of the leader of your group (size 0x40)
/*0x01864*/   BYTE       Unknown0x1864[0x264];
/*0x01ac8*/   DWORD      Exp;
/*0x01acc*/   BYTE       Unknown0x1acc[0xd19c];
/*0x0ec68*/   void       *vtable2;
/*0x0ec6c*/   struct     _EQC_INFO* eqc_info;
/*0x0ec70*/   struct     _SPAWNINFO* pSpawn;
/*0x0ec74*/   DWORD      Unknown0xec74;
/*0x0ec78*/   DWORD      Unknown0xec78;
/*0x0ec7c*/   DWORD      CurrWeight;
/*0x0ec80*/   DWORD      Unknown0xec80;
/*0x0ec84*/   DWORD      HPBonus;
/*0x0ec88*/   DWORD      ManaBonus;
/*0x0ec8c*/   DWORD      EnduranceBonus;
/*0x0ec90*/   DWORD      CombatEffectsBonus;
/*0x0ec94*/   DWORD      ShieldingBonus;
/*0x0ec98*/   DWORD      SpellShieldBonus;
/*0x0ec9c*/   DWORD      AvoidanceBonus;
/*0x0eca0*/   DWORD      AccuracyBonus;
/*0x0eca4*/   DWORD      StunResistBonus;
/*0x0eca8*/   DWORD      StrikeThroughBonus;
/*0x0ecac*/   DWORD      SkillMinDamageModBonus[0x9];
/*0x0ecd0*/   DWORD      Unknown0xecd0;
/*0x0ecd4*/   DWORD      DoTShieldBonus;
/*0x0ecd8*/   DWORD      AttackBonus;
/*0x0ecdc*/   DWORD      HPRegenBonus;
/*0x0ece0*/   DWORD      ManaRegenBonus;
/*0x0ece4*/   DWORD      Unknown0xece4;
/*0x0ece8*/   DWORD      DamageShieldBonus;
/*0x0ecec*/   DWORD      AttackSpeed;
/*0x0ecf0*/   BYTE       Unknown0xecf0[0xcc];
/*0x0edbc*/   void       *pUnknown2;
/*0x0edc0*/   struct     _CI2_INFO* pCI2;
/*0x0edc4*/   DWORD      Unknown0xedc4;
/*0x0edc8*/   BYTE       languages[0x20];
/*0x0ede8*/   BYTE       Unknown0xede8[0x10];
/*0x0edf8*/   CHAR       Name[0x40];
/*0x0ee38*/   CHAR       Lastname[0x20];
/*0x0ee58*/   BYTE       Unknown0xee58[0x60];
/*0x0eeb8*/   BYTE       Stunned;
/*0x0eeb9*/   BYTE       Unknown0xeeb9[0x3];
/*0x0eebc*/   WORD       zoneId;
/*0x0eebe*/   WORD       instance;
/*0x0eec0*/   DWORD      standstate;
/*0x0eec4*/   BYTE       Unknown0xeec4[0x24];
/*0x0eee8*/   DWORD      BankSharedPlat;
/*0x0eeec*/   DWORD      BankSharedGold;
/*0x0eef0*/   DWORD      BankSharedSilver;
/*0x0eef4*/   DWORD      BankSharedCopper;
/*0x0eef8*/   DWORD      BankPlat;
/*0x0eefc*/   DWORD      BankGold;
/*0x0ef00*/   DWORD      BankSilver;
/*0x0ef04*/   DWORD      BankCopper;
/*0x0ef08*/   DWORD      STR;
/*0x0ef0c*/   DWORD      STA;
/*0x0ef10*/   DWORD      CHA;
/*0x0ef14*/   DWORD      DEX;
/*0x0ef18*/   DWORD      INT;
/*0x0ef1c*/   DWORD      AGI;
/*0x0ef20*/   DWORD      WIS;
/*0x0ef24*/   DWORD      SavePoison;
/*0x0ef28*/   DWORD      SaveMagic;
/*0x0ef2c*/   DWORD      SaveDisease;
/*0x0ef30*/   DWORD      SaveCorruption;
/*0x0ef34*/   DWORD      SaveFire;
/*0x0ef38*/   DWORD      SaveCold;
/*0x0ef3c*/   BYTE       Unknown0xef3c[0x210c];
/*0x11048*/
} CHARINFO, *PCHARINFO;

// actual size: 0xb3ac 02-16-2007
typedef struct _CHARINFO2 {
/*0x0000*/   BYTE       Unknown0x0[0x10];
union {
/*0x0010*/   struct     _INVENTORY   Inventory;
/*0x0010*/   struct     _CONTENTS*   InventoryArray[NUM_INV_SLOTS];
};
/*0x008c*/   struct     _CONTENTS*   Cursor;
/*0x0090*/   BYTE       Unknown0x90[0x14];
/*0x00a4*/   struct     _SPELLBUFF   Buff[0x19];
/*0x0298*/   struct     _SPELLBUFF   ShortBuff[0x23];
/*0x0554*/   BYTE       Unknown0x554[0x1e0];
/*0x0734*/   DWORD      SpellBook[NUM_BOOK_SLOTS];
/*0x0f34*/   DWORD      MemorizedSpells[0x10];
/*0x0f74*/   DWORD      Skill[0x64];
/*0x1104*/   DWORD      InnateSkill[0x1c]; 
/*0x1174*/   DWORD      Unknown0x1174[0x21];
/*0x11f8*/   DWORD      Gender;
/*0x11fc*/   DWORD      Race;
/*0x1200*/   DWORD      Class;
/*0x1204*/   BYTE       Unknown0x1204[0x10];
/*0x1214*/   DWORD      Level;
/*0x1218*/   DWORD      Mana;
/*0x121c*/   DWORD      Endurance;
/*0x1220*/   DWORD      BaseHP;
/*0x1224*/   DWORD      BaseSTR;
/*0x1228*/   DWORD      BaseSTA;
/*0x122c*/   DWORD      BaseCHA;
/*0x1230*/   DWORD      BaseDEX;
/*0x1234*/   DWORD      BaseINT;
/*0x1238*/   DWORD      BaseAGI;
/*0x123c*/   DWORD      BaseWIS;
/*0x1240*/   DWORD      Unknown0x1240;
/*0x1244*/   DWORD      Plat;
/*0x1248*/   DWORD      Gold;
/*0x124c*/   DWORD      Silver;
/*0x1250*/   DWORD      Copper;
/*0x1254*/   DWORD      CursorPlat;
/*0x1258*/   DWORD      CursorGold;
/*0x125c*/   DWORD      CursorSilver;
/*0x1260*/   DWORD      CursorCopper;
/*0x1264*/   BYTE       Unknown0x1264[0x28];
/*0x128c*/   DWORD      thirstlevel;
/*0x1290*/   DWORD      hungerlevel;
/*0x1294*/   DWORD      Unknown0x1294; 
/*0x1298*/   DWORD      Shrouded;
/*0x129c*/   BYTE       Unknown0x129c[0x74];
/*0x1310*/   DWORD      ZoneBoundID;
/*0x1314*/   FLOAT      ZoneBoundY;
/*0x1318*/   FLOAT      ZoneBoundX;
/*0x131c*/   FLOAT      ZoneBoundZ;
/*0x1320*/   FLOAT      ZoneBoundHeading;
/*0x1324*/   BYTE       Unknown0x1324[0x50];
/*0x1374*/   DWORD      ArmorType[0x16];
/*0x13cc*/   BYTE       Unknown0x13cc[0xb0];
/*0x147c*/   AALIST     AAList[AA_CHAR_MAX_REAL];
/*0x1fbc*/   DWORD      BodyColor[0x9];
/*0x1fe0*/   BYTE       Unknown0x1fe0[0x2000];
/*0x3fe0*/   DWORD      CombatAbilities[NUM_COMBAT_ABILITIES];
/*0x4170*/   BYTE       Unknown0x4170[0x28];
/*0x4198*/   DWORD      CombatAbilityTimes[NUM_COMBAT_ABILITIES];
/*0x4328*/   BYTE       Unknown0x4328[0x1a54];
/*0x5d7c*/   DWORD      Deity;
/*0x5d80*/   BYTE       Unknown0x5d80[0x4];
/*0x5d84*/   DWORD      Drunkenness;
/*0x5d88*/   BYTE       Unknown0x5d88[0x8];
/*0x5d90*/   DWORD      AAPoints;
/*0x5d94*/   BYTE       Unknown0x5d94[0x55f8];
/*0xb38c*/   DWORD      AAPointsSpent;
/*0xb390*/   BYTE       Unknown0xb390[0x1c];
/*0xb3ac*/
} CHARINFO2, *PCHARINFO2;

typedef struct _MODELINFONAME {
/*0x00*/    DWORD Unknown0000;
/*0x04*/    DWORD Unknown0004;
/*0x08*/    PCHAR Name;
/*0x0c*/
} MODELINFONAME, *PMODELINFONAME;

typedef struct _MODELINFO_GENERIC {
/*0x00*/    DWORD Type;
/*0x04*/    DWORD Unknown0x04;
/*0x08*/    DWORD Unknown0x08;
/*0x0c*/    DWORD Unknown0x0c;
/*0x10*/    DWORD Unknown0x10;
/*0x14*/
} MODELINFO_GENERIC, *PMODELINFO_GENERIC;

typedef struct _MODELINFO_48 {
/*0x00*/    struct _MODELINFO_GENERIC Header;
/*0x14*/    FLOAT Float1;
/*0x18*/    FLOAT Float2;
/*0x1c*/    FLOAT Float3;
/*0x20*/    struct _MODELINFONAME *pModelName;
/*0x24*/
} MODELINFO_48, *PMODELINFO_48;

typedef struct _MODELINFO_51 {
/*0x00*/    struct _MODELINFO_GENERIC Header;
/*0x14*/    struct _MODELINFONAME *pFontName;
/*0x18*/    PCHAR LabelText;
/*0x1c*/
} MODELINFO_51, *PMODELINFO_51;

// 10/09/2003 build      plazmic
// 12/24/2003 verified   Amadeus
typedef struct _MODELINFO {
/*0x00*/    DWORD   Unknown;
/*0x04*/    PCHAR NameDAG;
/*0x08*/    struct _MODELINFO_GENERIC *pModelInfo;
/*0x0c*/    struct _MODELINFO *pNextInChain;
/*0x10*/    PVOID pUnknown;
/*0x14*/    struct _MODELINFONAME *pTrack1;
/*0x18*/    struct _MODELINFONAME *pTrack2;
   //moredata
} MODELINFO, *PMODELINFO;

// 4/30/2003 build      eqmule
typedef struct _CAMERAINFO {
/*0x00*/   DWORD Unknown0x00;
/*0x04*/   DWORD Unknown0x04;
/*0x08*/   BYTE Unknown0x08[0x8];
/*0x10*/   FLOAT Y;
/*0x14*/   FLOAT X;
/*0x18*/   FLOAT Z;
/*0x1c*/   FLOAT LightRadius;
/*0x20*/
} CAMERAINFO, *PCAMERAINFO;


#define MODEL_LABEL         0 
#define MODEL_LABELINFO     1
#define MODEL_NULL2         2
#define MODEL_HELD_R        3
#define MODEL_HELD_L        4
#define MODEL_SHIELD        5
#define MODEL_NULL6         6

/*
//Work in progress...
#define MODEL_HEAD			0x00
#define MODEL_HEAD_POINT	0x01
#define MODEL_NULL_1		0x02
#define MODEL_HELD_R		0x03
#define MODEL_HELD_L		0x04
#define MODEL_SHIELD		0x05
#define MODEL_NULL_2		0x06
#define MODEL_TUNIC			0x07
#define MODEL_HAIR			0x08
#define MODEL_BEARD			0x09
#define MODEL_CHEST			0x0a
#define MODEL_GLOVES		0x0b
#define MODEL_GLOVES2		0b0c
*/

typedef struct _ARGBCOLOR {
    union {
        struct {
            BYTE B;
            BYTE G;
            BYTE R;
            BYTE A;
        };
        DWORD ARGB;
    };
} ARGBCOLOR, *PARGBCOLOR;

typedef struct _ARMOR {
/*0x00*/ DWORD  ID; //idfile on Lucy
/*0x04*/ DWORD  Unknown0x04;
/*0x08*/ DWORD  Unknown0x08;
/*0x0c*/
} ARMOR, *PARMOR;

// 10-22-2003 Lax
typedef struct _EQUIPMENT {
   union {
      struct// EQUIPARRAY
      {
         struct _ARMOR Item[9];
      };// Array;
      struct //EQUIPUNIQUE
      {
         struct _ARMOR Head;
         struct _ARMOR Chest;
         struct _ARMOR Arms;
         struct _ARMOR Wrists;
         struct _ARMOR Hands;
         struct _ARMOR Legs;
         struct _ARMOR Feet;
         struct _ARMOR Primary;
         struct _ARMOR Offhand;
      };// Unique;
   };
} EQUIPMENT, *PEQUIPMENT;

// actual size: 0x1a88 02-16-2007
typedef struct _SPAWNINFO {
/*0x0000*/ void     *vtable;
/*0x0004*/ struct   _SPAWNINFO *pPrev;
/*0x0008*/ struct   _SPAWNINFO *pNext;
/*0x000c*/ DWORD    Unknown0xc;
/*0x0010*/ CHAR     Lastname[0x20];
/*0x0030*/ FLOAT    Unknown0x30[0x3];
/*0x003c*/ FLOAT    Y;
/*0x0040*/ FLOAT    X;
/*0x0044*/ FLOAT    Z;
/*0x0048*/ FLOAT    SpeedY;
/*0x004c*/ FLOAT    SpeedX;
/*0x0050*/ FLOAT    SpeedZ;
/*0x0054*/ FLOAT    SpeedRun;
/*0x0058*/ FLOAT    Heading;
/*0x005c*/ FLOAT    SpeedHeading;
/*0x0060*/ FLOAT    Unknown0x60[0x2];
/*0x0068*/ FLOAT    CameraAngle;
/*0x006c*/ DWORD    SpawnID;
/*0x0070*/ DWORD    Unknown0x70;
/*0x0074*/ CHAR     Name[0x40]; // ie priest_of_discord00
/*0x00b4*/ CHAR     DisplayedName[0x40]; // ie Priest of Discord
/*0x00f4*/ DWORD    IsABoat; // 1 = a type of boat
/*0x00f8*/ DWORD    Unknown0xf8;
/*0x00fc*/ struct   _SPAWNINFO *Mount; //NULL if no mount present
/*0x0100*/ BYTE     Unknown0x100[0x10];	
/*0x0110*/ FLOAT    SpeedMultiplier;
/*0x0114*/ BYTE     Unknown0x114[0x14];
/*0x0128*/ DWORD    TimeStamp;
/*0x012c*/ BYTE     Unknown0x12c[0x4];
/*0x0130*/ BYTE     UnderWater;
/*0x0131*/ BYTE     Unknown0x131[0xc];
/*0x013d*/ BYTE     FeetWet;
/*0x013e*/ BYTE     Unknown0x13e;
/*0x013f*/ BYTE     Unknown0x13f;
/*0x0140*/ BYTE     Type;
/*0x0141*/ BYTE     Unknown0x141[0x3];
/*0x0144*/ DWORD    **BodyType;
/*0x0148*/ BYTE     Unknown0x148[0xc];
/*0x0154*/ FLOAT    AvatarHeight; // height of avatar from ground when standing
/*0x0158*/ BYTE     Unknown0x158[0x28];
/*0x0180*/ BYTE     Linkdead;
/*0x0181*/ BYTE     Level;
/*0x0182*/ BYTE     Unknown0x182[0x6];
/*0x0188*/ DWORD    SpellETA; //Calculated TimeStamp when current spell being cast will land. 0 while not casting.
/*0x018c*/ DWORD    CastingSpellID; // -1 = not casting a spell
/*0x0190*/ BYTE     CastingAnimation; //unsure, FF for not casting, low numbers while casting
/*0x0191*/ BYTE     Unknown0x191[0x1b];
/*0x01ac*/ struct   _CONTENTS *pCastingClicky; //contents of the item if you're casting a clicky
/*0x01b0*/ FLOAT    CastingY;
/*0x01b4*/ FLOAT    CastingX;
/*0x01b8*/ BYTE     Unknown0x1b8[0x11];
/*0x01c9*/ BYTE     Light;
/*0x01ca*/ BYTE     FishingEvent;
/*0x01cb*/ BYTE     Unknown0x1cb;
/*0x01cc*/ FLOAT    WalkSpeed;
/*0x01d0*/ BYTE     Unknown0x1d0[0x8];
/*0x01d8*/ BYTE     LFG;
/*0x01d9*/ BYTE     Unknown0x1d9[0x3];
/*0x01dc*/ DWORD    Anon;
/*0x01e0*/ BYTE     Unknown0x1dd[0xc];
/*0x01ec*/ DWORD    HPMax;
/*0x01f0*/ DWORD    GuildStatus;
/*0x01f4*/ BYTE     Sneak;
/*0x01f5*/ BYTE     Unknown0x1f5[0xf];
/*0x0204*/ DWORD    MasterID;
/*0x0208*/ BYTE     StandState;
/*0x0209*/ BYTE     Unknown0x209[0x7];
/*0x0210*/ BYTE     HideMode;
/*0x0211*/ BYTE     Unknown0x20b[0xb];
/*0x021c*/ DWORD    PetID;
/*0x0220*/ BYTE     Unknown0x220[0x18];
/*0x0238*/ DWORD    RespawnTimer; // TimeStamp of when RespawnWnd will close - 0 when you're alive
/*0x023c*/ DWORD    Unknown0x23c;
/*0x0240*/ BYTE     BetaBuffedPlayer;
/*0x0241*/ BYTE     Unknown0x241[0x3];
/*0x0244*/ DWORD    FishingETA;
/*0x0248*/ BYTE     Unknown0x248[0x8];
/*0x0250*/ DWORD    LastTick;
/*0x0254*/ BYTE     Unknown0x254[0x14];
/*0x0268*/ LONG     HPCurrent;
/*0x026c*/ BYTE     Unknown0x26c[0x34];
/*0x02a0*/ DWORD    Trader;
/*0x02a4*/ BYTE     Unknown0x2a4[0x28];
/*0x02cc*/ DWORD    Deity;
/*0x02d0*/ DWORD    Unknown0x2d0;
/*0x02d4*/ FLOAT    RunSpeed;
/*0x02d8*/ BYTE     Unknown0x2d8[0x24];
/*0x02fc*/ WORD     Zone;
/*0x02fe*/ WORD     Instance;
/*0x0300*/ DWORD    Unknown0x300;
/*0x0304*/ CHAR     Title[0x20];
/*0x0324*/ DWORD    AFK;
/*0x0328*/ DWORD    GuildID;
/*0x032c*/ BYTE     Unknown0x32c[0x34];
/*0x0360*/ DWORD    InnateETA; //Calculated TimeStamp when innate skill will be ready (LoH, HT, Bash)
/*0x0364*/ BYTE     Holding;
/*0x0365*/ BYTE     Unknown0x365[0xf];
/*0x0374*/ BYTE     GM;
/*0x0375*/ BYTE     Unknown0x375[0xd7];
/*0x044c*/ BYTE     PvPFlag;
/*0x044d*/ BYTE     Unknown0x44d[0x1b];
/*0x0468*/ DWORD    Buyer;
/*0x046c*/ DWORD    Unknown0x46c;
/*0x0470*/ void     *pCharInfo_vtable2;
/*0x0474*/ BYTE     Unknown0x474[0x8];
/*0x047c*/ CHAR     Suffix[0x20];
/*0x049c*/ BYTE     Unknown0x49c[0xc];
/*0x04a8*/ DWORD    AARank;
/*0x04ac*/ BYTE     Unknown0x4ac[0x918];
/*0x0dc4*/ struct   _SPAWNINFO *WhoFollowing; // NULL if autofollow off
/*0x0dc8*/ struct   _SPAWNINFO *pGroupAssistNPC[1];
/*0x0dcc*/ struct   _SPAWNINFO *pRaidAssistNPC[3];
/*0x0dd8*/ struct   _SPAWNINFO *pGroupMarkNPC[3];
/*0x0de4*/ struct   _SPAWNINFO *pRaidMarkNPC[3];
/*0x0df0*/ struct   _SPAWNINFO *pTargetOfTarget;
/*0x0df4*/ BYTE     Unknown0xdf4[0x34];
/*0x0e28*/ BYTE     InNonPCRaceIllusion;
/*0x0e29*/ BYTE     Unknown0xe29[0x3];
/*0x0e2c*/ BYTE     FaceStyle;
/*0x0e2d*/ BYTE     HairColor;
/*0x0e2e*/ BYTE     FacialHairColor;
/*0x0e2f*/ BYTE     EyeColor1;
/*0x0e30*/ BYTE     EyeColor2;
/*0x0e31*/ BYTE     HairStyle;
/*0x0e32*/ BYTE     FacialHair;
/*0x0e33*/ BYTE     Unknown0xe33;
/*0x0e34*/ DWORD    Race;
/*0x0e38*/ BYTE     Class;
/*0x0e39*/ BYTE     Gender;
/*0x0e3a*/ CHAR     ActorDef[0x40];
/*0x0e7a*/ BYTE     Unknown0xe7a[0x2];
/*0x0e7c*/ ARGBCOLOR ArmorColor[0x9];
/*0x0ea0*/ BYTE     Unknown0xea0[0x4];
/*0x0ea4*/ DWORD    Heritage;  //drakkin only face setting
/*0x0ea8*/ DWORD    Tattoo;    //drakkin only face setting
/*0x0eac*/ DWORD    Details;   //drakkin only face setting
/*0x0eb0*/ struct   _EQUIPMENT Equipment;
/*0x0f1c*/ BYTE     Unknown0xf1c[0x38];
/*0x0f54*/ VOID     *pcactorex;
/*0x0f58*/ DWORD    Unknown0xf58;
/*0x0f5c*/ VOID     *FaceRelatedActorStruct;
/*0x0f60*/ BYTE     Unknown0xf60[0x70];
/*0x0fd0*/ DWORD    Animation;
/*0x0fd4*/ BYTE     Unknown0xfd4[0xd0];
/*0x10a4*/ struct   _MODELINFO *Model[0xe]; // this is wrong dkaa 10/21/06
/*0x10dc*/ DWORD    HideCorpse;
/*0x10e0*/ BYTE     Unknown0x10e0[0x40];
/*0x1120*/ BYTE     InvitedToGroup;
/*0x1121*/ BYTE     Unknown0x1121[0x93f];
/*0x1a60*/ void     *vtable2;
/*0x1a64*/ DWORD    Unknown0x1a64;
/*0x1a68*/ struct   _SPAWNINFO *pSpawn;
/*0x1a6c*/ BYTE     Levitate;
/*0x1a6d*/ BYTE     Unknown0x1a6d[0x1b];
/*0x1a88*/
} SPAWNINFO, *PSPAWNINFO;

#define STANDSTATE_STAND            0x64
#define STANDSTATE_CASTING          0x66
#define STANDSTATE_BIND             0x69
#define STANDSTATE_SIT              0x6E
#define STANDSTATE_DUCK             0x6F
#define STANDSTATE_FEIGN            0x73
#define STANDSTATE_DEAD             0x78

#define MONITOR_SPAWN_X             1
#define MONITOR_SPAWN_Y             2
#define MONITOR_SPAWN_Z             4
#define MONITOR_SPAWN_HEADING       8
#define MONITOR_SPAWN_SPEEDRUN      16
#define MONITOR_SPAWN_HPCURRENT     32

typedef struct _SPAWNMONITORINFO {
    WORD SpawnID;
    FLOAT Y;
    FLOAT X;
    FLOAT Z;
    FLOAT Heading;
    FLOAT SpeedRun;
    DWORD HPCurrent;
    DWORD MonitorMask;
} SPAWNMONITORINFO, *PSPAWNMONITORINFO;

typedef struct _HASHENTRY {
    SPAWNINFO   *spawn;
    DWORD       key;            // same as SpawnID for spawns
    struct      _HASHENTRY *next;
} HASHENTRY, *PHASHENTRY;

typedef struct _HASHTABLE {
    struct _HASHENTRY **table;
    int size;
} HASHTABLE, *PHASHTABLE;

typedef struct _SPAWNMANAGER {
/*0x000*/ void          *vftable;
/*0x004*/ DWORD         random; // rand()%20000
/*0x008*/ struct  _SPAWNINFO        *FirstSpawn;
/*0x00c*/ struct  _SPAWNINFO        *LastSpawn;
/*0x010*/ DWORD         unknown10;
/*0x014*/ struct        _HASHTABLE  *SPHash;
} SPAWNMANAGER, *PSPAWNMANAGER;


#if 0

void *gethashedentry(struct _HASHTABLE  *table, DWORD key)
{
    PHASHENTRY p = NULL;
    p = table->array[key%table->size];

    while(p) {
        if (p->key == key) return p;
        p = p->next;
    }
    return NULL;
}

#endif

typedef struct _EQSWITCH {
/*0x00*/	DWORD		Unknown0x0[0x2];
/*0x08*/	DWORD		UnknownData0x08;
/*0x0c*/	DWORD		UnknownData0x0c;
/*0x10*/	DWORD		Unknown0x10[0x2];
/*0x18*/	DWORD		UnknownData0x18;
/*0x1c*/	DWORD		Unknown0x1c;
/*0x20*/	DWORD		UnknownData0x20;
/*0x24*/	DWORD		Unknown0x24;
/*0x28*/	FLOAT		Y;
/*0x2c*/	FLOAT		X;
/*0x30*/	FLOAT		Z;
/*0x34*/	BYTE		Unknown0x34[0x74]; //A lot of data here.
/*0xa8*/	FLOAT		Y2;
/*0xac*/	FLOAT		X2;
/*0xb0*/	FLOAT		Z2;
/*0xb4*/	DWORD		Unknown0xa4;
/*0xb8*/	FLOAT		Heading;
/*0xbc		Data Continues... */
} EQSWITCH, *PEQSWITCH;

typedef struct _DOOR { 
/*0x00*/   void *vtable; 
/*0x04*/   BYTE Unknown0x4;
/*0x05*/   BYTE ID;
/*0x06*/   CHAR Name[0x0b]; 
/*0x11*/   BYTE Unknown0x0d[0x17]; 
/*0x28*/   FLOAT DefaultY; 
/*0x2c*/   FLOAT DefaultX; 
/*0x30*/   FLOAT DefaultZ; 
/*0x34*/   FLOAT DefaultHeading; 
/*0x38*/   FLOAT DoorAngle;
/*0x3c*/   BYTE  Unknown0x3c[0x8];
/*0x44*/   FLOAT Y; 
/*0x48*/   FLOAT X; 
/*0x4c*/   FLOAT Z; 
/*0x50*/   FLOAT Heading; 
/*0x54*/   BYTE Unknown0x54[0x4c]; 
/*0xa0*/   PEQSWITCH pSwitch; // (class EQSwitch *) 
/*0xa4*/ 
} DOOR, *PDOOR; 

// 7-21-2003    Stargazer
typedef struct _DOORTABLE {
/*0x000*/   DWORD NumEntries;
/*0x004*/   PDOOR pDoor[0x0FF];
/*0x400*/
} DOORTABLE, *PDOORTABLE;

// actual size 0x5c  2-18-2004 lax
// 9-20-2006 ieatacid
typedef struct _GROUNDITEM {
/*0x00*/ struct _GROUNDITEM *pPrev;
/*0x04*/ struct _GROUNDITEM *pNext;
/*0x08*/ DWORD  ID;
/*0x0c*/ DWORD  DropID;
/*0x10*/ DWORD  Unknown0x10;
/*0x14*/ PEQSWITCH pSwitch; // (class EQSwitch *)
/*0x18*/ DWORD  Unknown0x18;
/*0x1c*/ FLOAT  Heading;
/*0x20*/ BYTE   Unknown0x20[0xc];
/*0x2c*/ FLOAT  Z;
/*0x30*/ FLOAT  X;
/*0x34*/ FLOAT  Y;
/*0x38*/ CHAR   Name[0x18];
/*0x50*/
} GROUNDITEM, *PGROUNDITEM;

#define   MAX_ZONES                                    0x3e8
extern    PCHAR szZoneExpansionName[];     //defined in LibEQ_Utilities.cpp

typedef struct _ZONELIST { 
/*0x000*/   DWORD   Header; 
/*0x004*/   DWORD   Unknown0x4;         //pointer to something? 
/*0x008*/   DWORD   Expansion;          // szZoneExpansionName[] 
/*0x00c*/   WORD    Id; 
/*0x00e*/   WORD    Instance; 
/*0x010*/   CHAR    ShortName[0x81]; 
/*0x091*/   CHAR    LongName[0x103]; 
/*0x194*/   DWORD   Unknown0x194; 
/*0x198*/   DWORD   Flags;              // (Flags & 0x100000) = HasMinLevel, 0x4000 no air, 0x2 newbie zone, 0x20 no bind, 0x400000 something 
/*0x19c*/   DWORD   Unknown0x19c; 
/*0x1a0*/   DWORD   Id2;                // This is Id+2242 
/*0x1a4*/   DWORD   PoPValue;           // This has something to do with PoP zones. 
/*0x1a8*/   DWORD   MinLevel;           // Minimum level to access 
/*0x1ac*/   WORD    Unknown0x1ac;          
/*0x1ae*/   BYTE    Unknown0x1ae[0x6];    
/*0x1b4*/   DWORD   Unknown0x1b4; 
/*0x1b8*/   DWORD   Unknown0x1b8; 
/*0x1bc*/   DWORD   Unknown0x1bc; 
/*0x1c0      next zone in list*/ 
} ZONELIST, *PZONELIST;

typedef struct _WORLDDATA {
/*0x000*/ PVOID lpvTable;
/*0x004*/ BYTE Hour;
/*0x005*/ BYTE Minute;
/*0x006*/ BYTE Day;
/*0x007*/ BYTE Month;
/*0x008*/ DWORD Year;
/*0x00C*/ BYTE Unknown0x00c[0x10];
/*0x01C*/ PZONELIST ZoneArray[MAX_ZONES];
} WORLDDATA, *PWORLDDATA;

// 5-15-2003    Amadeus (discovered by Lax)
// Actual Size 0x240, old
typedef struct _ZONEINFO {
/*0x000*/   CHAR    CharacterName[0x40];
/*0x040*/   CHAR    ShortName[0x20];
/*0x060*/   CHAR    Unknown0x060[0x60];
/*0x0c0*/   CHAR    LongName[0x80];
/*0x140*/   CHAR    Unknown0x140[0x96];  // <-- this isnt part of zone name, see CEverQuest__CEverQuest
/*0x1d6*/   BYTE    ZoneType; // (usually FF)
/*0x1d7*/	ARGBCOLOR FogRed;
/*0x1db*/	ARGBCOLOR FogGreen;
/*0x1df*/	ARGBCOLOR FogBlue;
/*0x1e3*/   BYTE    Unknown0x1e3;
/*0x1e4*/   BYTE	  Unknown0x1e4[0x10];
/*0x1f4*/   BYTE    Unknown0x1f4[0x10];
/*0x204*/   FLOAT   ZoneGravity;
/*0x208*/   BYTE    Unknown0x208;
/*0x209*/   BYTE    Unknown0x209[0x3];
/*0x20c*/   BYTE    Unknown0x20c[0x2e];
/*0x23a*/	BYTE	  SkyType;	
/*0x23b*/	BYTE	  Unknown0x23b[0xd];
/*0x248*/   FLOAT   ZoneExpModifier;    //This has been nerfed ..now reads 1.0 for all zones
/*0x24c*/   FLOAT   Unknown0x24c[0x3];
/*0x258*/   FLOAT   Ceiling;
/*0x25c*/   FLOAT   Floor; 
/*0x260*/   FLOAT   MinClip; 
/*0x264*/   FLOAT   MaxClip; 
/*0x268*/   BYTE    Unknown0x268[0x18];
/*0x280*/   BYTE    Unknown0x280[0x20];
/*0x2a0*/
} ZONEINFO, *PZONEINFO;

#define   TOTAL_SPELL_COUNT				0x2ee0      // # of spells allocated in memory (09/08/2006)
#define   TOTAL_ACTUAL_SPELLS			   0x1964      // # of ACTUAL spells in game      (9/14/2004)

// size: 0x17770 08-07-06          
typedef struct _SPELLMGR {
BYTE            unknown[0x68];
struct _SPELL*  Spells[TOTAL_SPELL_COUNT];
} SPELLMGR, *PSPELLMGR;

// actual size: 0x4dc 02-16-2007
typedef struct _SPELL {
/*0x000*/   DWORD   EnduranceCost;      //CA Endurance Cost
/*0x004*/   BYTE    SpellType;          //0=detrimental, 1=Beneficial, 2=Beneficial, Group Only
/*0x005*/   BYTE    Unknown0x5;
/*0x006*/   BYTE    Deletable;
/*0x007*/   BYTE    Unknown0x7;
/*0x008*/   DWORD   PvPResistBase;
/*0x00c*/   FLOAT   PushBack;
/*0x010*/   DWORD   ReagentCount[0x4];  //ReagentCount1-ReagentCount4
/*0x020*/   BYTE    Unknown0x20[0x8];
/*0x028*/   DWORD   CastTime;
/*0x02c*/   DWORD   Attrib[0x0c];       //Attrib1-Attrib12
/*0x05c*/   DWORD   DescriptionNumber;
/*0x060*/   DWORD   Unknown145;         //Unknown145 from lucy
/*0x064*/   DWORD   Unknown0x64;
/*0x068*/   BYTE    Resist;             //0=un 1=mr 2=fr 3=cr 4=pr 5=dr 6=chromatic 7=prismatic 8=physical(skills,etc) 9=corruption
/*0x069*/   BYTE    Unknown0x69[0x3];
/*0x06c*/   DWORD   BookIcon;
/*0x070*/   BYTE    Unknown0x70[0x8];
/*0x078*/   DWORD   RecastTime;
/*0x07c*/   DWORD   Unknown0x7c;
/*0x080*/   DWORD   DurationValue1;
/*0x084*/   BYTE    Unknown0x84[0xd];
/*0x091*/   BYTE    CastingAnim;
/*0x092*/   BYTE    Unknown0x92;
/*0x093*/   BYTE    Level[0x10];        //per class.
/*0x0a3*/   BYTE    Unknown0xa3[0x13];
/*0x0b6*/   BYTE    CanMGB;
/*0x0b7*/   BYTE    Unknown0xb7;
/*0x0b8*/   LONG    Base2[0x0c];        //Mostly unused, setting name to Base2 from Lucy for now
/*0x0e8*/   BYTE    Unknown0xe8[0x9];
/*0x0f1*/   BYTE    Skill;
/*0x0f2*/   BYTE    Unknown0xf2[0x2];
/*0x0f4*/   FLOAT   Range;
/*0x0f8*/   DWORD   Unknown0xf8;
/*0x0fc*/   DWORD   DurationType;       //DurationFormula on Lucy
/*0x100*/   DWORD   Unknown0x100;
/*0x104*/   DWORD   FizzleTime;
/*0x108*/   DWORD   Unknown0x108;
/*0x10c*/   BYTE    DurationWindow;     //0=Long, 1=Short
/*0x10d*/   BYTE    Unknown0x10d[0x3];
/*0x110*/   LONG    Base[0x0c];         //Base1-Base12
/*0x140*/   BYTE    Unknown0x140;
/*0x141*/   BYTE    FizzleAdj;
/*0x142*/   BYTE    Location;           //01=Outdoors, 02=dungeons, ff=Any
/*0x143*/   BYTE    Unknown0x143[0x5];
/*0x148*/   LONG    Max[0x0c];          //Max1-Max12
/*0x178*/   BYTE    Unknown0x178[0x14];
/*0x18c*/   DWORD   Autocast;           //SpellID of spell to instacast on caster when current spell lands on target
/*0x190*/   BYTE    Unknown0x190[0x8];
/*0x198*/   BYTE    TimeOfDay;          // 0=any, 1=day only, 2=night only
/*0x199*/   BYTE    Unknown0x199[0x3];
/*0x19c*/   FLOAT   AERange;
/*0x1a0*/   DWORD   Unknown0x1a0;       //added 02-13-07
/*0x1a4*/   DWORD   PvPResistCap;
/*0x1a8*/   DWORD   Unknown0x1a8;
/*0x1ac*/   DWORD   ReagentId[0x4];     //ReagentId1-ReagentId4
/*0x1bc*/   DWORD   Unknown0x1bc;       //added 02-13-07
/*0x1c0*/   DWORD   ID;
/*0x1c4*/   BYTE    Unknown0x1c4[0xc];
/*0x1d0*/   DWORD   CARecastTimerID;    //ID of combat timer, i think.
/*0x1d4*/   BYTE    TargetType;         //03=Group v1, 04=PB AE, 05=Single, 06=Self, 08=Targeted AE, 0e=Pet, 28=AE PC v2, 29=Group v2
/*0x1d5*/   BYTE    Unknown0x1d5;
/*0x1d6*/   BYTE    Environment;
/*0x1d7*/   BYTE    Unknown0x1d7;
/*0x1d8*/   DWORD   Mana;
/*0x1dc*/   DWORD   Unknown0x1dc;
/*0x1e0*/   DWORD   Unknown144;         //Unknown144 from lucy
/*0x1e4*/   BYTE    TargetAnim;
/*0x1e5*/   BYTE    Unknown0x1e5[0x7];
/*0x1ec*/   DWORD   Unknown183;         //Unknown183 from Lucy
/*0x1f0*/   BYTE    Unknown0x1f0;
/*0x1f1*/   BYTE    LightType;
/*0x1f2*/   BYTE    Unknown0x1f2[0x2];
/*0x1f4*/   DWORD   Calc[0x0c];         //Calc1-Calc12
/*0x224*/   BYTE    Unknown0x224[0xe];
/*0x232*/   CHAR    Name[0x40];	
/*0x272*/   CHAR    Target[0x20];
/*0x292*/   CHAR    Extra[0x20];        //This is 'Extra' from Lucy (portal shortnames etc)
/*0x2b2*/   CHAR    Unknown0x2b2[0x60];
/*0x312*/   CHAR    Unknown0x312[0x60];
/*0x372*/   CHAR    CastOnYou[0x60];
/*0x3d2*/   CHAR    CastOnAnother[0x60];
/*0x432*/   CHAR    WearOff[0x60];
/*0x492*/   BYTE    Unknonw0x492[0x6];
/*0x498*/   DWORD   spaindex;
/*0x49c*/   CHAR    *Unknown0x49c;      //spell effect name
/*0x4a0*/   DWORD   SpellAnim;
/*0x4a4*/   BYTE    Unknown0x4a4[0xc];
/*0x4b0*/   DWORD   SpellIcon;
/*0x4b4*/   DWORD   ResistAdj;
/*0x4b8*/   BYTE    Unknown0x4b8[0x1a];
/*0x4d2*/   BYTE    Uninterruptable;    //00=Interruptable, 01=Uninterruptable 
/*0x4d3*/   BYTE    Unknown0x4d3[0x9];
/*0x4dc*/
} SPELL, *PSPELL;

// actual size: 0x148 10-25-2006  ieatacid
typedef struct _SKILL {
/*0x000*/  PVOID  pUnknown0x0;       //_SKILL *pNext?
/*0x004*/  PVOID  pUnknown0x4;
/*0x008*/  DWORD  nName;
/*0x00c*/  DWORD  ReuseTimer;
/*0x010*/  DWORD  Unknown0x10;
/*0x014*/  CHAR   AltTimer;          //compare to 2 all over.. alternate timer?
/*0x015*/  BYTE   Unknown0x15[0x3];
/*0x018*/  DWORD  Unknown0x18;
/*0x01c*/  DWORD  Unknown0x1c;
/*0x020*/  CHAR   Activated;
/*0x021*/  CHAR   Unknown0x00B;
/*0x022*/  BYTE   Unknown0x22[0x2];
/*0x024*/  DWORD  MinLevel[0x24];
/*0x0b4*/  DWORD  Available[0x24];   //FF=not available for that class
/*0x144*/  DWORD  Unknown0x144;
/*0x148*/  
} SKILL, *PSKILL;

#define NUM_SKILLS 99
typedef struct _SKILLMGR {
/*0x000*/ struct _SKILL *pSkill[NUM_SKILLS];
/*0x004*/ //more data
} SKILLMGR, *PSKILLMGR;

//actual size 0x274  10-2-2006  ieatacid
typedef struct _GUILDMEMBER {
/*0x000*/ struct  _GUILDMEMBER *pNext;
/*0x004*/ BYTE    Online;
/*0x005*/ BYTE    Unknown0x5[0x3];
/*0x008*/ WORD    ZoneID;
/*0x00a*/ WORD    Instance;
/*0x00c*/ BYTE    Unknown0xc[0x4];
/*0x010*/ CHAR    Name[0x40];
/*0x050*/ DWORD   Level;
/*0x054*/ DWORD   Unknown0x54;
/*0x058*/ DWORD   Class;
/*0x05c*/ DWORD   Rank; //0=member 1=officer 2=leader
/*0x060*/ DWORD   LastSeen; //last seen timestamp
/*0x064*/ CHAR    PublicNote[0x100];
/*0x164*/ CHAR    PersonalNote[0x100];
/*0x264*/ DWORD   TributeStatus;
/*0x268*/ DWORD   TributeDonations;
/*0x26c*/ DWORD   LastDonation;//timestamp
/*0x270*/ DWORD   Unknown0x264;
/*0x274*/
} GUILDMEMBER, *PGUILDMEMBER;

#define MAX_GUILDS			0x5DC
typedef struct _GUILDS {
/*0x0000*/ PVOID		pOneEntryVTable;
/*0x0004*/ BYTE		UnknownByte0x0005;
/*0x0005*/ BYTE		Unknown0x0005[0x3f];
/*0x0044*/ DWORD		UnknownValue0x0044;
/*0x0048*/ struct    _GUILDMEMBER *pMember;
/*0x004c*/ CHAR		GuildName[MAX_GUILDS][0x40];
/*0x804c*/ BYTE		UnknownByteArray0x804c[0x200];
/*0x824c*/ BYTE		UnknownByteArray0x824c[0x40];
/*0x828c*/
} GUILDS, *PGUILDS;

typedef struct _INTERACTGROUNDITEM {
	DWORD DropID;
	DWORD SpawnID;
} INTERACTGROUNDITEM, *PINTERACTGROUNDITEM;

typedef struct _SPELLFAVORITE {
/*0x000*/   DWORD   SpellId[9];
/*0x024*/   CHAR    Name[25];
/*0x03d*/   BYTE    Byte_3d;
/*0x03e*/   BYTE    Byte_3e;
/*0x03f*/   BYTE    Byte_3f;
/*0x040*/
} SPELLFAVORITE, *PSPELLFAVORITE;

typedef struct _CMDLIST {
    DWORD LocalizedStringID;
    PCHAR szName;
    PCHAR szLocalized;
    VOID  (__cdecl *fAddress)(PSPAWNINFO, PCHAR);
    DWORD Restriction;
    DWORD Category;
    DWORD Unknown;
} CMDLIST, *PCMDLIST;

typedef struct _EQSOCIAL {
/*0x0000*/   CHAR   Name[0x10];
/*0x0010*/   CHAR   Line[0x5][0x100];
/*0x0510*/   BYTE   Color; 
} EQSOCIAL, *PEQSOCIAL;

typedef struct _EQFRIENDSLIST {
/*0x0000*/ CHAR Name[0x64][0x40];
/*0x1900*/
} EQFRIENDSLIST, *PEQFRIENDSLIST;

// Size 0x70 (8.11.2004)
typedef struct _ALTABILITY {
/*0x00*/ DWORD Index;
/*0x04*/ DWORD Flags;                    //?
/*0x08*/ DWORD nShortName;
/*0x0c*/ DWORD nShorterName;
/*0x10*/ DWORD nName;                    // now a database number
/*0x14*/ DWORD nDesc;                    // now a database number
/*0x18*/ DWORD MinLevel;
/*0x1c*/ DWORD Cost;                     //Initial Cost or cost the last time you bought a level of it
/*0x20*/ DWORD ID;                       // /alt activate id
/*0x24*/ DWORD AARankRequired;
union {  
/*0x28*/ LONG  RequiresAbility;          // If the value is positive then its the index number of the AA required.
/*0x28*/ DWORD RequiresPointsInCategory; // If the value is negative then abs(value) is the
};                                       // category, while (abs(value))*6 is the points required.
/*0x2c*/ DWORD RequiresAbilityPoints;
/*0x30*/ DWORD Type; 
/*0x34*/ LONG  SpellID;                  // -1 for no Spell
/*0x38*/ BYTE  Unknown0x34[0x8]; 
/*0x40*/ DWORD ReuseTimer;               // in seconds
/*0x44*/ DWORD Classes;                  // Classes/2 is the actual value we want.
/*0x48*/ DWORD MaxRank;					     //If you have not spent points in this 
union {						                 //If you have not spent points in this 
/*0x4c*/ DWORD PointsSpent;		        //ability, then its PointsToBeSpent (or 
/*0x4c*/ DWORD PointsToBeSpent;	        //'Cost', in other words).
}; 
/*0x50*/ DWORD AAIndex;                  // -1 if not available
/*0xxx*/ DWORD UseAAIndex;
/*0xxx*/ BYTE  Unknown0x54;
/*0xxx*/ BYTE  Unknown0x55;
/*0xxx*/ BYTE  Unknown0x56;
/*0xxx*/ BYTE  Unknown0x57;
/*0xxx*/ BYTE  Unknown0x58[0x18];
} ALTABILITY, *PALTABILITY;
#define zWarp				 0

typedef struct _ALTABILITIESLISTMGR {
/*0x00*/ struct _ALTABILITY* Ability;
/*0x04*/ DWORD Index;
} ALTABILITIESLISTMGR, *PALTABILITIESLISTMGR;

//NUM_ALT_ABILITIES is now defined before CHARINFO definition in this same header file.
typedef struct _ALTABILITIESLIST {
/*0x00*/ struct _ALTABILITIESLISTMGR* Abilities[NUM_ALT_ABILITIES_ARRAY];
} ALTABILITIESLIST, *PALTABILITIESLIST;

typedef struct _NEWALTADVMGR {
/*0x00*/ struct _ALTABILITIESLIST* AltAbilityList;
/*0x04*/ DWORD NumAltAbilities;  // NUM_ALT_ABILITIES
/*0x08*/ DWORD Unknown0x08; // data here
/*0x0c*/ DWORD Unknown0x0c; // data here
/*0x10*/ BYTE  Unknown0x10[0x8];
} NEWALTADVMGR, *PNEWALTADVMGR;

typedef struct _ALTADVMGR {
/*0x00*/ struct _NEWALTADVMGR* AltAbilities;
} ALTADVMGR, *PALTADVMGR;

// size 0x118 (8.11.2004)
typedef struct _EQRAIDMEMBER { 
/*0x00*/ CHAR Name[0x40]; 
/*0x40*/ CHAR RaidNote[0x40]; 
/*0x80*/ CHAR Level[0x08]; 
/*0x88*/ CHAR Class[0x20]; 
/*0xC8*/ BYTE Unknown0xC8[0x60]; 
/*0x108*/ DWORD nClass; 
/*0x10C*/ BYTE  RaidLeader; 
/*0x10D*/ BYTE  GroupLeader; 
/*0x10E*/ BYTE  Field_10E; 
/*0x10F*/ BYTE  Field_10F; 
/*0x110*/ BYTE  Field_110; 
/*0x111*/ BYTE  Padding0x111[0x3]; 
/*0x114*/ DWORD GroupNumber; 
/*0x118*/ 
} EQRAIDMEMBER, *PEQRAIDMEMBER;

// sizeof(_EQRAID) is 0x5ab8 (8-11-2004)
typedef struct _EQRAID { 
/*0x0000*/  BYTE  		Unknown0x0[0x154];
/*0x0154*/  CHAR  		RaidMemberUsed[0x48];
/*0x019c*/  struct		_EQRAIDMEMBER RaidMember[0x48];
/*0x505c*/  DWORD 		field_505c;
/*0x5060*/  DWORD 		RaidMemberCount;
/*0x5064*/  CHAR        RaidLeaderName[0x140];
/*0x51a4*/  CHAR        RaidMOTD[0x400];
/*0x55a4*/  BYTE        Unknown0x55a4[0x40];
/*0x55e4*/  BYTE        Invited;
/*0x55e5*/  BYTE        Unknown0x55a5[0x8];
/*0x55ed*/  BYTE        IsRaidLeader; 
/*0x55ee*/  BYTE        Unknown0x55ee[0x2];
/*0x55f0*/  DWORD       RaidTarget;
/*0x55f4*/  DWORD       LootType;
/*0x55f8*/  CHAR        RaidLooters[0x13][0x40];
/*0x5ab8*/  DWORD       TotalRaidMemberLevels; // TotalRaidMemberLevels/RaidMemberCount=RaidAvgLevel
/*0x5abc*/  BYTE        Locked;
/*0x5abd*/  BYTE        Padding0x5abd[0x3];
/*0x5ac0*/ 
} EQRAID, *PEQRAID;

// size 0x19C 3-23-2005
typedef struct _EQGROUP {
/*0x000*/ BYTE MemberExists[5];
/*0x005*/ CHAR MemberName[5][0x40];
/*0x145*/ BYTE Unused[3];
/*0x148*/ struct _SPAWNINFO* pMember[5];
/*0x15C*/ CHAR LeaderName[0x40];
/*0x19C*/
} EQGROUP, *PEQGROUP;

// size 0x08
typedef struct _EQSTRING {
/*0x00*/	DWORD ID;
/*0x04*/	PCHAR String;
} EQSTRING, *PEQSTRING;

// size 0x10 4-28-2004 lax
typedef struct _EQSTRINGTABLE {
/*0x00*/ struct _EQSTRING **StringItems;
/*0x04*/ DWORD Size;
/*0x08*/ DWORD Count;
/*0x0c*/ DWORD Unknown0x0c;
/*0x10*/
} EQSTRINGTABLE, *PEQSTRINGTABLE;

typedef struct connection_t {
/*0x000*/ void  *vtable;
/*0x004*/ BYTE  Unknown0x0[0x100];
/*0x104*/ DWORD Master;
/*0x108*/ DWORD Average;
/*0x10c*/ DWORD Low;
/*0x110*/ DWORD High;
/*0x114*/ DWORD Last;
/*0x118*/
} CONNECTION_T, *PCONNECTION_T;

//actual size 0x2d70 04-28-06 - ieatacid 
typedef struct _CDISPLAY { 
/*0x000*/ BYTE   Unknown0x000[0x150]; 
/*0x150*/ DWORD  TimeStamp; 
/*0x154*/ 
} CDISPLAY, *PCDISPLAY; 

//5-16-06 - ieatacid
typedef struct _DZTIMERINFO {
/*0x000*/ CHAR   ExpeditionName[0x80];
/*0x080*/ CHAR   EventName[0x100];
/*0x180*/ DWORD  TimeStamp;  // TimeStamp - Util__FastTime = time left
/*0x184*/ DWORD  TimerID;
/*0x188*/ struct _DZTIMERINFO *pNext;
/*0x18c*/
} DZTIMERINFO, *PDZTIMERINFO;

typedef struct _DZMEMBER {
/*0x000*/ CHAR   Name[0x40];
/*0x040*/ DWORD  Status;  // 0="unknown", 1="Online", 2="Offline", 3="In Dynamic Zone", 4="Link Dead"
/*0x044*/ struct _DZMEMBER *pNext;
/*0x048*/
} DZMEMBER, *PDZMEMBER;

typedef struct _TASKMEMBER {
/*0x000*/ CHAR   Name[0x40];
/*0x040*/ DWORD  Unknown0x40;
/*0x044*/ DWORD  IsLeader;
/*0x048*/ struct _TASKMEMBER *pNext;
/*0x04c*/
} TASKMEMBER, *PTASKMEMBER;

typedef struct _DYNAMICZONE {
/*0x000*/ void   *vftable;
/*0x004*/ BYTE   Unknown0x04[0x46];
/*0x04a*/ CHAR   Name[0x40]; // your name
/*0x08a*/ CHAR   ExpeditionName[0x80];
/*0x10a*/ BYTE   Unknown0x10a[0x2];
/*0x10c*/ WORD   MaxPlayers;
/*0x10e*/ BYTE   Unknown0x10e[0x2];
/*0x110*/ struct _DZMEMBER *pMemberList;
/*0x114*/ PCHAR  expeditionName;
/*0x118*/ // more?
} DYNAMICZONE, *PDYNAMICZONE;

typedef struct _CHATCHANNELS {
/*0x000*/ PCHAR  ChannelName[0xa];
/*0x004*/
} CHATCHANNELS, *PCHATCHANNELS;

typedef struct _CHATSERVICE {
/*0x000*/ BYTE   Unknown0x0[0xc];
/*0x00c*/ struct _CHATCHANNELS *ChannelList;
/*0x010*/ DWORD  ActiveChannels;   // number of channels joined
/*0x014*/ BYTE   Unknown0x14[0xc];
/*0x020*/ CHAR   ChatID[0x30];     // "ServerName.CharName" (0x60?)
/*0x050*/ BYTE   Unknown0x50[0x30];
/*0x080*/ CHAR   ServerName[0x30]; // "ServerName."
/*0x0b0*/ // more data
} CHATSERVICE, *PCHATSERVICE;

typedef struct _EVERQUEST {
/*0x000*/ BYTE   Unknown[0x2a4];
/*0x2a4*/ struct _CHATSERVICE *ChatService;
/*0x2a8*/ // more data
} EVERQUEST, *PEVERQUEST;

typedef struct _AURAINFO {
/*0x000*/ CHAR   Name[0x40];
/*0x040*/ BYTE   Unknown0x14[0xc];
/*0x04c*/
} AURAINFO, *PAURAINFO;

typedef struct _AURAMGR {
/*0x000*/ DWORD     NumAuras;
/*0x004*/ BYTE      Unknown0x4[0xc];
/*0x010*/ PAURAINFO *AuraArray;
/*0x014*/ BYTE      Unknown0x14[0x8];
/*0x01c*/
} AURAMGR, *PAURAMGR;

typedef struct _INTERACTSWITCH {
/*0x000*/ DWORD   switchID;
/*0x004*/ DWORD   dwzero;
/*0x008*/ DWORD   dwneg1;
/*0x00c*/ DWORD   spawnID;
} INTERACTSWITCH, *PINTERACTSWITCH;


#define EQ_INTERACTGROUNDITEM   0x76F0  // CEverQuest__LMouseUp 02/13
#define EQ_BAZAARSEARCHCREATE   0x5DC5  // CProgSelWnd__WndNotification 02/13
#define EQ_BAZAARSEARCHME       0x175b  // CBazaarSearchWnd__doQuery 02/13
#define EQ_EMOTE                0x40D0  // CEverQuest__Emote+8C
#define EQ_BEGIN_ZONE           0x0C9D  // CEverQuest__SavePCForce+433
#define EQ_END_ZONE             0x5E9C  // CEverQuest__DoMainLoop+A68
#define EQ_LoadingS__ArraySize  0x44    // EQ_LoadingS__SetProgressBar+7C
#define EQ_INTERACTSWITCH       0x36E2  // EQSwitch__UseSwitch
};
using namespace EQData;
