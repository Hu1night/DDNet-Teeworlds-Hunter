/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_VARIABLES_H
#define GAME_VARIABLES_H
#undef GAME_VARIABLES_H // this file will be included several times


// client
MACRO_CONFIG_INT(ClPredict, cl_predict, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Predict client movements")
MACRO_CONFIG_INT(ClNameplates, cl_nameplates, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Show name plates")
MACRO_CONFIG_INT(ClNameplatesAlways, cl_nameplates_always, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Always show name plates disregarding of distance")
MACRO_CONFIG_INT(ClNameplatesTeamcolors, cl_nameplates_teamcolors, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Use team colors for name plates")
MACRO_CONFIG_INT(ClNameplatesSize, cl_nameplates_size, 50, 0, 100, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Size of the name plates from 0 to 100%")
MACRO_CONFIG_INT(ClAutoswitchWeapons, cl_autoswitch_weapons, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Auto switch weapon on pickup")

MACRO_CONFIG_INT(ClShowhud, cl_showhud, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Show ingame HUD")
MACRO_CONFIG_INT(ClShowChatFriends, cl_show_chat_friends, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Show only chat messages from friends")
MACRO_CONFIG_INT(ClShowfps, cl_showfps, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Show ingame FPS counter")

MACRO_CONFIG_INT(ClAirjumpindicator, cl_airjumpindicator, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")
MACRO_CONFIG_INT(ClThreadsoundloading, cl_threadsoundloading, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Load sound files threaded")

MACRO_CONFIG_INT(ClWarningTeambalance, cl_warning_teambalance, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Warn about team balance")

MACRO_CONFIG_INT(ClMouseDeadzone, cl_mouse_deadzone, 300, 0, 0, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")
MACRO_CONFIG_INT(ClMouseFollowfactor, cl_mouse_followfactor, 60, 0, 200, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")
MACRO_CONFIG_INT(ClMouseMaxDistance, cl_mouse_max_distance, 800, 0, 0, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")

MACRO_CONFIG_INT(EdShowkeys, ed_showkeys, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")

//MACRO_CONFIG_INT(ClFlow, cl_flow, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")

MACRO_CONFIG_INT(ClShowWelcome, cl_show_welcome, 1, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "")
MACRO_CONFIG_INT(ClMotdTime, cl_motd_time, 10, 0, 100, CFGFLAG_CLIENT|CFGFLAG_SAVE, "How long to show the server message of the day")

MACRO_CONFIG_STR(ClVersionServer, cl_version_server, 100, "version.teeworlds.com", CFGFLAG_CLIENT|CFGFLAG_SAVE, "Server to use to check for new versions")

MACRO_CONFIG_STR(ClLanguagefile, cl_languagefile, 255, "", CFGFLAG_CLIENT|CFGFLAG_SAVE, "What language file to use")

MACRO_CONFIG_INT(PlayerUseCustomColor, player_use_custom_color, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Toggles usage of custom colors")
MACRO_CONFIG_INT(PlayerColorBody, player_color_body, 65408, 0, 0xFFFFFF, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Player body color")
MACRO_CONFIG_INT(PlayerColorFeet, player_color_feet, 65408, 0, 0xFFFFFF, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Player feet color")
MACRO_CONFIG_STR(PlayerSkin, player_skin, 24, "default", CFGFLAG_CLIENT|CFGFLAG_SAVE, "Player skin")

MACRO_CONFIG_INT(UiPage, ui_page, 6, 0, 10, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface page")
MACRO_CONFIG_INT(UiToolboxPage, ui_toolbox_page, 0, 0, 2, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Toolbox page")
MACRO_CONFIG_STR(UiServerAddress, ui_server_address, 64, "localhost:8303", CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface server address")
MACRO_CONFIG_INT(UiScale, ui_scale, 100, 50, 150, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface scale")
MACRO_CONFIG_INT(UiMousesens, ui_mousesens, 100, 5, 100000, CFGFLAG_SAVE|CFGFLAG_CLIENT, "Mouse sensitivity for menus/editor")

MACRO_CONFIG_INT(UiColorHue, ui_color_hue, 160, 0, 255, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface color hue")
MACRO_CONFIG_INT(UiColorSat, ui_color_sat, 70, 0, 255, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface color saturation")
MACRO_CONFIG_INT(UiColorLht, ui_color_lht, 175, 0, 255, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface color lightness")
MACRO_CONFIG_INT(UiColorAlpha, ui_color_alpha, 228, 0, 255, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Interface alpha")

MACRO_CONFIG_INT(GfxNoclip, gfx_noclip, 0, 0, 1, CFGFLAG_CLIENT|CFGFLAG_SAVE, "Disable clipping")

// server
MACRO_CONFIG_INT(SvWarmup, sv_warmup, 0, 0, 0, CFGFLAG_SERVER, "Number of seconds to do warmup before round starts")
MACRO_CONFIG_INT(SvUnpauseTimer, sv_unpause_timer, 0, 0, 0, CFGFLAG_SERVER, "Number of seconds till the game continues")
MACRO_CONFIG_STR(SvMotd, sv_motd, 900, "", CFGFLAG_SERVER, "Message of the day to display for the clients")
MACRO_CONFIG_INT(SvTeamdamage, sv_teamdamage, 0, 0, 1, CFGFLAG_SERVER, "Team damage")
MACRO_CONFIG_STR(SvMaprotation, sv_maprotation, 768, "", CFGFLAG_SERVER, "Maps to rotate between")
MACRO_CONFIG_INT(SvRoundsPerMap, sv_rounds_per_map, 1, 1, 114514, CFGFLAG_SERVER, "Number of rounds on each map before rotating")
MACRO_CONFIG_INT(SvRoundSwap, sv_round_swap, 1, 0, 1, CFGFLAG_SERVER, "Swap teams between rounds")
MACRO_CONFIG_INT(SvPowerups, sv_powerups, 1, 0, 1, CFGFLAG_SERVER, "Allow powerups like ninja")
MACRO_CONFIG_INT(SvScorelimit, sv_scorelimit, 20, 0, 1000, CFGFLAG_SERVER, "Score limit (0 disables)")
MACRO_CONFIG_INT(SvTimelimit, sv_timelimit, 0, 0, 1000, CFGFLAG_SERVER, "Time limit in minutes (0 disables)")
MACRO_CONFIG_STR(SvGametype, sv_gametype, 32, "dm", CFGFLAG_SERVER, "Game type (dm, tdm, ctf)")
MACRO_CONFIG_INT(SvTournamentMode, sv_tournament_mode, 0, 0, 1, CFGFLAG_SERVER, "Tournament mode. When enabled, players joins the server as spectator")
MACRO_CONFIG_INT(SvSpamprotection, sv_spamprotection, 1, 0, 1, CFGFLAG_SERVER, "Spam protection")

MACRO_CONFIG_INT(SvRespawnDelayTDM, sv_respawn_delay_tdm, 3, 0, 10, CFGFLAG_SERVER, "Time needed to respawn after death in tdm gametype")

MACRO_CONFIG_INT(SvSpectatorSlots, sv_spectator_slots, 0, 0, MAX_CLIENTS, CFGFLAG_SERVER, "Number of slots to reserve for spectators")
MACRO_CONFIG_INT(SvTeambalanceTime, sv_teambalance_time, 1, 0, 1000, CFGFLAG_SERVER, "How many minutes to wait before autobalancing teams")
MACRO_CONFIG_INT(SvInactiveKickTime, sv_inactivekick_time, 3, 0, 1000, CFGFLAG_SERVER, "How many minutes to wait before taking care of inactive players")
MACRO_CONFIG_INT(SvInactiveKick, sv_inactivekick, 1, 0, 2, CFGFLAG_SERVER, "How to deal with inactive players (0=move to spectator, 1=move to free spectator slot/kick, 2=kick)")

MACRO_CONFIG_INT(SvStrictSpectateMode, sv_strict_spectate_mode, 0, 0, 1, CFGFLAG_SERVER, "Restricts information in spectator mode")
MACRO_CONFIG_INT(SvVoteSpectate, sv_vote_spectate, 1, 0, 1, CFGFLAG_SERVER, "Allow voting to move players to spectators")
MACRO_CONFIG_INT(SvVoteSpectateRejoindelay, sv_vote_spectate_rejoindelay, 3, 0, 1000, CFGFLAG_SERVER, "How many minutes to wait before a player can rejoin after being moved to spectators by vote")
MACRO_CONFIG_INT(SvVoteKick, sv_vote_kick, 1, 0, 1, CFGFLAG_SERVER, "Allow voting to kick players")
MACRO_CONFIG_INT(SvVoteKickMin, sv_vote_kick_min, 0, 0, MAX_CLIENTS, CFGFLAG_SERVER, "Minimum number of players required to start a kick vote")
MACRO_CONFIG_INT(SvVoteKickBantime, sv_vote_kick_bantime, 5, 0, 1440, CFGFLAG_SERVER, "The time to ban a player if kicked by vote. 0 makes it just use kick")

//以下是Hunter设置

MACRO_CONFIG_INT(SvGameOverTime, svmod_gameovertime, 6, 1, 20, CFGFLAG_SERVER, "结算画面显示时间（默认6,最小1,最大20）")

MACRO_CONFIG_INT(HuntHunterFixed, hunt_hunter_fixed, 0, 0, 1, CFGFLAG_SERVER, "Whether to fix the number hunters (1 to fix)")
MACRO_CONFIG_INT(HuntHunterNumber, hunt_hunter_number, 1, 1, 0xFFFFFF, CFGFLAG_SERVER, "When fixing hunter number, the number of hunters")
MACRO_CONFIG_INT(HuntHunterRatio, hunt_hunter_ratio, 5, 2, 0xFFFFFF, CFGFLAG_SERVER, "几个玩家里选取一个猎人（默认5,最小2,最大inf）")

MACRO_CONFIG_INT(AnyWpNinjaAllow, any_wpninja_allow, 1, 0, 1, CFGFLAG_SERVER, "是否允许Ninja（默认1,最小0,最大1）")

MACRO_CONFIG_INT(HuntWpHammerDmg, hunt_wphammer_dmg, 20, 0, 0xFFFFFF, CFGFLAG_SERVER, "猎人锤子伤害（默认20,最小0,最大inf）")
MACRO_CONFIG_INT(HuntWpNinjaDmg, hunt_wpninja_dmg, 20, 0, 0xFFFFFF, CFGFLAG_SERVER, "猎人Ninja伤害（默认20,最小0,最大inf）")
MACRO_CONFIG_INT(HuntWpPowerup, hunt_wppowerup, 2, 1, 0xFFFFFF, CFGFLAG_SERVER, "猎人武器增强比例（默认2,最小1,最大inf）")
MACRO_CONFIG_INT(HuntWpGrenadeFwAllow, hunt_wpgrenade_fwallow, 1, 0, 1, CFGFLAG_SERVER, "猎人是否允许榴弹破片（默认1,最小0,最大1）")
MACRO_CONFIG_INT(HuntWpGrenadeFw, hunt_wpgrenade_fw, 14, 0, 0xFFFFFF, CFGFLAG_SERVER, "榴弹破片数量（默认14,最小0,最大inf）")

MACRO_CONFIG_INT(HuntWpHammerGive, hunt_wphammer_give, 1, 0, 1, CFGFLAG_SERVER, "猎人是否允许锤子（默认0,最小0,最大1）")
MACRO_CONFIG_INT(HuntWpShotgunGive, hunt_wpshotgun_give, 0, 0, 1, CFGFLAG_SERVER, "猎人是否给予霰弹（默认0,最小0,最大1）")
MACRO_CONFIG_INT(HuntWpGrenadeGive, hunt_wpgrenade_give, 0, 0, 1, CFGFLAG_SERVER, "猎人是否给予榴弹（默认0,最小0,最大1）")
MACRO_CONFIG_INT(HuntWpRifleGive, hunt_wprifle_give, 0, 0, 1, CFGFLAG_SERVER, "猎人是否给予激光（默认0,最小0,最大1）")

MACRO_CONFIG_INT(HuntBroadcastHunterDeath, hunt_broadcast_hunter_death, 0, 0, 1, CFGFLAG_SERVER, "是否向全体广播猎人死亡（默认0,最小0,最大1）")
MACRO_CONFIG_INT(ShowHunterList, hunt_show_hunterlist, 0, 0, 1, CFGFLAG_SERVER, "是否开局向全体广播猎人列表（默认0,最小0,最大1）")

MACRO_CONFIG_INT(CivWpHammerDmg, civ_wphammer_dmg, 3, 0, 0xFFFFFF, CFGFLAG_SERVER, "平民锤子伤害（默认3,最小0,最大inf）")
MACRO_CONFIG_INT(CivWpNinjaDmg, civ_wpninja_dmg, 20, 0, 0xFFFFFF, CFGFLAG_SERVER, "平民Ninja伤害（默认13,最小0,最大inf）")

MACRO_CONFIG_INT(CivWpHammerGive, civ_wphammer_give, 0, 0, 1, CFGFLAG_SERVER, "平民是否给予锤子（默认0,最小0,最大1）")
MACRO_CONFIG_INT(CivWpShotgunGive, civ_wpshotgun_give, 0, 0, 1, CFGFLAG_SERVER, "平民是否给予霰弹（默认0,最小0,最大1）")
MACRO_CONFIG_INT(CivWpGrenadeGive, civ_wpgrenade_give, 0, 0, 1, CFGFLAG_SERVER, "平民是否给予榴弹（默认0,最小0,最大1）")
MACRO_CONFIG_INT(CivWpRifleGive, civ_wprifle_give, 0, 0, 1, CFGFLAG_SERVER, "平民是否给予激光（默认0,最小0,最大1）")

MACRO_CONFIG_INT(HuntRoundStartHealth, hunt_round_start_health, 10, 1, 0xFFFFFF, CFGFLAG_SERVER, "猎人开局给的血量（默认10,最小1,最大inf）")
MACRO_CONFIG_INT(HuntRoundStartArmor, hunt_round_start_armor, 0, 0, 0xFFFFFF, CFGFLAG_SERVER, "猎人开局给的盾（默认0,最小0,最大inf）")
MACRO_CONFIG_INT(CivRoundStartHealth, civ_round_start_health, 10, 1, 0xFFFFFF, CFGFLAG_SERVER, "平民开局给的血量（默认10,最小1,最大inf）")
MACRO_CONFIG_INT(CivRoundStartArmor, civ_round_start_armor, 0, 0, 0xFFFFFF, CFGFLAG_SERVER, "平民开局给的盾（默认0,最小0,最大inf）")

MACRO_CONFIG_INT(AnyWpAmmoRegen, any_wpammo_regan, 1, 0, 1, CFGFLAG_SERVER, "子弹回复样式（默认1,最小0,最大1）")
MACRO_CONFIG_INT(AnyWpNinjaRespawnTime, any_wpninja_respawntime, 90, 0, 0xFFFFFF, CFGFLAG_SERVER, "Ninja重刷新时间（默认90,最小0,最大inf）")

MACRO_CONFIG_INT(AnyForceTeamTalk, any_force_team_talk, 1, 0, 1, CFGFLAG_SERVER, "强制馆茶者在一个频道里（默认1,最小0,最大1）")
MACRO_CONFIG_INT(WhisperDtL, svmod_whisper_dead_to_alive, 0, 0, 1, CFGFLAG_SERVER, "允许死人对活人whisper（默认0,最小0,最大1）")
MACRO_CONFIG_INT(WhisperLtL, svmod_whisper_alive_to_alive, 1, 0, 1, CFGFLAG_SERVER, "允许活人对活人whisper（默认1,最小0,最大1）")

MACRO_CONFIG_INT(HuntScoreHunterWin, hunt_score_hunter_win, 2, 0, 0xFFFFFF, CFGFLAG_SERVER, "猎人胜利给的分数（默认2,最小0,最大inf）")
MACRO_CONFIG_INT(HuntScoreCivicWin, hunt_score_civic_win, 1, 0, 0xFFFFFF, CFGFLAG_SERVER, "平民胜利给的分数（默认1,最小0,最大inf）")
MACRO_CONFIG_INT(HuntScoreCivicKillHunter, hunt_score_civic_kill_hunter, 2, 0, 0xFFFFFF, CFGFLAG_SERVER, "平民杀个猎给的分数（默认2,最小0,最大inf）")

MACRO_CONFIG_INT(HuntRoundtype, hunt_roundtype, 1, 0, 1, CFGFLAG_SERVER, "回合类型 0不会显示开局chat（默认1,最小0,最大1）")

// debug
#ifdef CONF_DEBUG // this one can crash the server if not used correctly
	MACRO_CONFIG_INT(DbgDummies, dbg_dummies, 0, 0, 15, CFGFLAG_SERVER, "")
#endif

MACRO_CONFIG_INT(DbgFocus, dbg_focus, 0, 0, 1, CFGFLAG_CLIENT, "")
MACRO_CONFIG_INT(DbgTuning, dbg_tuning, 0, 0, 1, CFGFLAG_CLIENT, "")
#endif
