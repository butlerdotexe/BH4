# 1 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 2 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
.set LOCALID_RIVAL, 1
# 3 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 4 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_MapScripts::
# 5 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
# 6 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
# 7 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.byte 0
# 8 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 9 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnTransition:
# 10 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
# 11 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos
# 12 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 13 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 14 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 15 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 16 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 17 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos::
# 18 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 19 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 20 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 21 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 22 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos::
# 23 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 24 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 25 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	@ Odd that the MaysHouse equivalent was used below instead
# 26 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 27 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 0, 2
# 28 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
# 29 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 30 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 31 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Ret::
# 32 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 33 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 34 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan::
# 35 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 36 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
# 37 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 38 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 39 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan::
# 40 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 41 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 42 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 43 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnWarp:
# 44 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
# 45 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.2byte 0
# 46 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 47 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor::
# 48 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 49 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SecretBase_EventScript_InitDecorations
# 50 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 51 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 52 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall::
# 53 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 54 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan
# 55 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
# 56 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 57 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 58 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 59 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan::
# 60 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 61 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	addobject LOCALID_RIVAL
# 62 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters
# 63 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 64 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PIN
# 65 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 66 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 67 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 68 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 69 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 70 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 71 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth
# 72 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth
# 73 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest
# 74 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast
# 75 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 76 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 77 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 78 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 79 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	savebgm MUS_DUMMY
# 80 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	fadedefaultbgm
# 81 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 82 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 83 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 84 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth::
# 85 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth
# 86 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 87 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 88 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 89 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 90 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 91 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth
# 92 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth
# 93 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 94 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 95 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 96 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth::
# 97 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth
# 98 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 99 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 100 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 101 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 102 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 103 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth
# 104 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth
# 105 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 106 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 107 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 108 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest::
# 109 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest
# 110 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 111 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 112 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 113 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 114 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 115 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest
# 116 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest
# 117 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 118 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 119 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 120 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast::
# 121 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast
# 122 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 123 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 124 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 125 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 126 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 127 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast
# 128 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 129 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 130 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 131 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters:
# 132 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 133 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 134 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 135 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 136 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 137 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth:
# 138 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 139 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 140 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 141 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 142 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 143 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 144 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 145 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth:
# 146 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 147 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 148 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 149 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 150 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 151 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 152 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 153 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 154 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 155 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 156 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth:
# 157 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 158 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 159 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 160 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 161 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 162 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 163 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 164 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 165 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 166 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth:
# 167 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 168 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 169 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 170 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 171 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 172 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth:
# 173 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 174 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 175 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 176 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 177 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 178 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 179 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 180 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 181 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth:
# 182 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 183 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 184 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 185 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 186 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 187 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 188 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 189 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest:
# 190 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 191 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 192 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 193 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 194 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 195 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 196 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest:
# 197 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 198 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 199 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 200 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 201 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 202 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 203 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 204 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 205 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 206 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 207 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest:
# 208 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_8
# 209 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 210 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 211 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 212 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 213 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 214 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 215 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 216 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast:
# 217 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 218 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 219 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 220 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 221 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 222 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_down
# 223 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 224 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 225 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast:
# 226 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 227 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 228 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 229 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 230 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 231 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 232 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
@ Unused, the player is already facing this direction so its unneeded
# 233 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast:
# 234 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 235 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 236 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 237 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 238 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 239 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_PC::
# 240 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 241 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 242 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
# 243 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
# 244 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 245 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 246 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
# 247 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 248 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 249 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_ON
# 250 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 251 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special BedroomPC
# 252 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitstate
# 253 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 254 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 255 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 256 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
# 257 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 258 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 259 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 260 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 261 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 262 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 263 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC::
# 264 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 265 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 266 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 267 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 268 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_Notebook::
# 269 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
# 270 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 271 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 272 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_GameCube::
# 273 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
# 274 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 275 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 276 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ClockIsStopped:
# 277 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The clock is stopped…\p"
# 278 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Better set it and start it!$"
# 279 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 280 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_HowDoYouLikeYourRoom:
# 281 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "MOM: {PLAYER}, how do you like your\n"
# 282 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "new room?\p"
# 283 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Good! Everything's put away neatly!\p"
# 284 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "They finished moving everything in\n"
# 285 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "downstairs, too.\p"
# 286 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "POKéMON movers are so convenient!\p"
# 287 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Oh, you should make sure that\n"
# 288 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "everything's all there on your desk.$"
# 289 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 290 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_Notebook:
# 291 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} flipped open the notebook.\p"
# 292 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 1\n"
# 293 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Open the MENU with START.\p"
# 294 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 2\n"
# 295 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Record your progress with SAVE.\p"
# 296 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The remaining pages are blank…$"
# 297 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 298 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
Common_Text_LookCloserAtMap:
# 299 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
# 300 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "HOENN region map.$"
# 301 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 302 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ItsAGameCube:
# 303 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "It's a Nintendo GameCube.\p"
# 304 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "A Game Boy Advance is connected to\n"
# 305 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "serve as the Controller.$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball::
# 309 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_0, MSGBOX_DEFAULT
# 310 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	dynmultichoice 0, 0, TRUE, 9, 0, DYN_MULTICHOICE_CB_NONE, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_1, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_2, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_3, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_4, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_5, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_6, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_7, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_8, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_9
# 311 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_1
# 313 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_2
# 315 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_3
# 317 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_4
# 319 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_5
# 321 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_6
# 323 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_7
# 325 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_8
# 327 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_9
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_1:
# 312 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_2:
# 314 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_3:
# 316 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_4:
# 318 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_5:
# 320 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_6:
# 322 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_7:
# 324 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_8:
# 326 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_9:
# 328 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea
	return


LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto::
# 333 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_0, MSGBOX_DEFAULT
# 334 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_1, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_2, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_3
# 335 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_2
# 340 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_3
# 345 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_4
LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_1:
# 351 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknamePartyMon
# 352 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN, 8, 9
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_2:
# 336 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_BULBASAUR, 10, 3
# 337 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_BULBASAUR, 5, ITEM_ORAN_BERRY, hpIv = 0, atkIv = 0, defIv = 0, speedIv = 0, spAtkIv = 0, spDefIv = 0
# 338 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 339 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_4
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_3:
# 341 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_CHARMANDER, 10, 3
# 342 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_CHARMANDER, 5, ITEM_ORAN_BERRY, hpIv = 0, atkIv = 0, defIv = 0, speedIv = 0, spAtkIv = 0, spDefIv = 0
# 343 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 344 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_5
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_4:
# 346 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_SQUIRTLE, 10, 3
# 347 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_SQUIRTLE, 5, ITEM_ORAN_BERRY, hpIv = 0, atkIv = 0, defIv = 0, speedIv = 0, spAtkIv = 0, spDefIv = 0
# 348 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 349 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_6
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_1


LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto::
# 356 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_0, MSGBOX_DEFAULT
# 357 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_Text_0, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_Text_1, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_Text_2
# 358 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_2
# 363 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_3
# 368 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_4
LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_1:
# 374 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknamePartyMon
# 375 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN, 8, 9
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_2:
# 359 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 360 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_CHIKORITA, 5, ITEM_ORAN_BERRY, hpIv = 0, atkIv = 0, defIv = 0, speedIv = 0, spAtkIv = 0, spDefIv = 0
# 361 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 362 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_Text_3
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_3:
# 364 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 365 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 5, ITEM_ORAN_BERRY, hpIv = 0, atkIv = 0, defIv = 0, speedIv = 0, spAtkIv = 0, spDefIv = 0
# 366 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 367 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_Text_4
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_4:
# 369 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 370 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_TOTODILE, 5, ITEM_ORAN_BERRY, hpIv = 0, atkIv = 0, defIv = 0, speedIv = 0, spAtkIv = 0, spDefIv = 0
# 371 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 372 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_Text_5
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_1


LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn::
# 379 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_0, MSGBOX_DEFAULT
# 380 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_Text_0, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_Text_1, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_Text_2
# 381 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_2
# 386 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_3
# 391 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_4
LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_1:
# 397 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknamePartyMon
# 398 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN, 8, 9
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_2:
# 382 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_TREECKO, 10, 3
# 383 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_TREECKO, 5, ITEM_ORAN_BERRY, hpIv = 0, atkIv = 0, defIv = 0, speedIv = 0, spAtkIv = 0, spDefIv = 0
# 384 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 385 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_Text_3
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_3:
# 387 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_TORCHIC, 10, 3
# 388 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_TORCHIC, 5, ITEM_ORAN_BERRY, hpIv = 0, atkIv = 0, defIv = 0, speedIv = 0, spAtkIv = 0, spDefIv = 0
# 389 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 390 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_Text_4
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_4:
# 392 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_MUDKIP, 10, 3
# 393 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_MUDKIP, 5, ITEM_ORAN_BERRY, hpIv = 0, atkIv = 0, defIv = 0, speedIv = 0, spAtkIv = 0, spDefIv = 0
# 394 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 395 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_Text_5
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_1


LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh::
# 402 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_0, MSGBOX_DEFAULT
# 403 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_Text_0, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_Text_1, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_Text_2
# 404 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_2
# 409 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_3
# 414 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_4
LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_1:
# 420 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknamePartyMon
# 421 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN, 8, 9
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_2:
# 405 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_TURTWIG, 10, 3
# 406 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_TURTWIG, 5, ITEM_ORAN_BERRY
# 407 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 408 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_Text_3
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_3:
# 410 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_CHIMCHAR, 10, 3
# 411 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_CHIMCHAR, 5, ITEM_ORAN_BERRY
# 412 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 413 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_Text_4
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_4:
# 415 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_PIPLUP, 10, 3
# 416 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_PIPLUP, 5, ITEM_ORAN_BERRY
# 417 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 418 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_Text_5
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_1


LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova::
# 425 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_0, MSGBOX_DEFAULT
# 426 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_Text_0, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_Text_1, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_Text_2
# 427 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_2
# 432 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_3
# 437 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_4
LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_1:
# 443 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknamePartyMon
# 444 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN, 8, 9
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_2:
# 428 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_SNIVY, 10, 3
# 429 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_SNIVY, 5, ITEM_ORAN_BERRY
# 430 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 431 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_Text_3
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_3:
# 433 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_TEPIG, 10, 3
# 434 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_TEPIG, 5, ITEM_ORAN_BERRY
# 435 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 436 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_Text_4
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_4:
# 438 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_OSHAWOTT, 10, 3
# 439 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_OSHAWOTT, 5, ITEM_ORAN_BERRY
# 440 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 441 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_Text_5
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_1


LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos::
# 448 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_0, MSGBOX_DEFAULT
# 449 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_Text_0, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_Text_1, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_Text_2
# 450 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_2
# 455 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_3
# 460 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_4
LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_1:
# 466 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknamePartyMon
# 467 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN, 8, 9
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_2:
# 451 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_CHESPIN, 10, 3
# 452 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_CHESPIN, 5, ITEM_ORAN_BERRY
# 453 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 454 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_Text_3
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_3:
# 456 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_FENNEKIN, 10, 3
# 457 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_FENNEKIN, 5, ITEM_ORAN_BERRY
# 458 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 459 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_Text_4
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_4:
# 461 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_FROAKIE, 10, 3
# 462 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_FROAKIE, 5, ITEM_ORAN_BERRY
# 463 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 464 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_Text_5
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_1


LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola::
# 471 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_0, MSGBOX_DEFAULT
# 472 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_Text_0, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_Text_1, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_Text_2
# 473 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_2
# 478 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_3
# 483 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_4
LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_1:
# 489 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknamePartyMon
# 490 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN, 8, 9
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_2:
# 474 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_ROWLET, 10, 3
# 475 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_ROWLET, 5, ITEM_ORAN_BERRY
# 476 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 477 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_Text_3
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_3:
# 479 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_LITTEN, 10, 3
# 480 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_LITTEN, 5, ITEM_ORAN_BERRY
# 481 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 482 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_Text_4
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_4:
# 484 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_POPPLIO, 10, 3
# 485 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_POPPLIO, 5, ITEM_ORAN_BERRY
# 486 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 487 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_Text_5
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_1


LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar::
# 494 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_0, MSGBOX_DEFAULT
# 495 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_Text_0, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_Text_1, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_Text_2
# 496 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_2
# 501 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_3
# 506 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_4
LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_1:
# 512 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknamePartyMon
# 513 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN, 8, 9
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_2:
# 497 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_GROOKEY, 10, 3
# 498 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_GROOKEY, 5, ITEM_ORAN_BERRY
# 499 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 500 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_Text_3
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_3:
# 502 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_SCORBUNNY, 10, 3
# 503 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_SCORBUNNY, 5, ITEM_ORAN_BERRY
# 504 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 505 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_Text_4
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_4:
# 507 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_SOBBLE, 10, 3
# 508 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_SOBBLE, 5, ITEM_ORAN_BERRY
# 509 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 510 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_Text_5
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_1


LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea::
# 517 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_0, MSGBOX_DEFAULT
# 518 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_Text_0, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_Text_1, LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_Text_2
# 519 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_2
# 524 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_3
# 529 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_4
LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_1:
# 535 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknamePartyMon
# 536 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN, 8, 9
	return

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_2:
# 520 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_SPRIGATITO, 10, 3
# 521 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_SPRIGATITO, 5, ITEM_ORAN_BERRY
# 522 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 523 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_Text_3
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_3:
# 525 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_FUECOCO, 10, 3
# 526 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_FUECOCO, 5, ITEM_ORAN_BERRY
# 527 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 528 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_Text_4
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_1

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_4:
# 530 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_QUAXLY, 10, 3
# 531 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_QUAXLY, 5, ITEM_ORAN_BERRY
# 532 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 533 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_Text_5
	goto LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_1


NicknamePartyMon::
# 540 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 541 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	hidemonpic
# 542 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 543 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 544 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_0:
# 309 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Choose a region!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_1:
# 310 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Kanto$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_2:
# 310 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Johto$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_3:
# 310 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Hoenn$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_4:
# 310 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Sinnoh$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_5:
# 310 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Unova$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_6:
# 310 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Kalos$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_7:
# 310 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Alola$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_8:
# 310 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Galar$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Text_9:
# 310 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Paldea$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_0:
# 333 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Choose your starter!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_1:
# 334 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Bulbasaur$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_2:
# 334 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Charmander$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_3:
# 334 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Squirtle$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_4:
# 339 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Bulbasaur!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_5:
# 344 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Charmander!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kanto_Text_6:
# 349 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Squirtle!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_Text_0:
# 357 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Chikorita$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_Text_1:
# 357 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Cyndaquil$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_Text_2:
# 357 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Totodile$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_Text_3:
# 362 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Chikorita!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_Text_4:
# 367 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Cyndaquil!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Johto_Text_5:
# 372 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Totodile!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_Text_0:
# 380 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Treecko$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_Text_1:
# 380 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Torchic$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_Text_2:
# 380 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Mudkip$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_Text_3:
# 385 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Treecko!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_Text_4:
# 390 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Torchic!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Hoenn_Text_5:
# 395 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Mudkip!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_Text_0:
# 403 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Turtwig$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_Text_1:
# 403 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Chimchar$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_Text_2:
# 403 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Piplup$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_Text_3:
# 408 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Turtwig!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_Text_4:
# 413 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Chimchar!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Sinnoh_Text_5:
# 418 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Piplup!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_Text_0:
# 426 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Snivy$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_Text_1:
# 426 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Tepig$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_Text_2:
# 426 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Oshawott$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_Text_3:
# 431 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Snivy!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_Text_4:
# 436 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Tepig!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Unova_Text_5:
# 441 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Oshawott!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_Text_0:
# 449 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Chespin$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_Text_1:
# 449 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Fennekin$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_Text_2:
# 449 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Froakie$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_Text_3:
# 454 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Chespin!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_Text_4:
# 459 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Fennekin!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Kalos_Text_5:
# 464 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Froakie!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_Text_0:
# 472 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Rowlet$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_Text_1:
# 472 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Litten$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_Text_2:
# 472 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Popplio$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_Text_3:
# 477 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Rowlet!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_Text_4:
# 482 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Litten!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Alola_Text_5:
# 487 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Popplio!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_Text_0:
# 495 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Grookey$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_Text_1:
# 495 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Scorbunny$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_Text_2:
# 495 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Sobble$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_Text_3:
# 500 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Grookey!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_Text_4:
# 505 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Scorbunny!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Galar_Text_5:
# 510 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Sobble!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_Text_0:
# 518 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Sprigatito$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_Text_1:
# 518 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Fuecoco$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_Text_2:
# 518 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Quaxly$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_Text_3:
# 523 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Sprigatito!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_Text_4:
# 528 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Fuecoco!$"

LittlerootTown_BrendansHouse_2F_EventScript_Pokeball_Paldea_Text_5:
# 533 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Quaxly!$"

NicknamePartyMon_Text_0:
# 540 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Give it a nickname?$"

NewProfessor_NotChosen::
# 548 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "You did not choose the Pokémon.$"
