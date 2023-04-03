/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */

/*********************************\
*                                 *
* HUNTER SERVER MOD               *
*                                 *
* By Bluelightzero                *
*                                 *
* http://github.com/bluelightzero *
*                                 *
\*********************************/

#include <engine/shared/config.h>
#include <game/server/player.h>

#include "mod.h"

CGameControllerMOD::CGameControllerMOD(class CGameContext *pGameServer)
: IGameController(pGameServer)
{
	// Exchange this to a string that identifies your game mode.
	// DM, TDM and CTF are reserved for teeworlds original modes.
	m_pGameType = "hunter";

	//m_GameFlags = GAMEFLAG_TEAMS; // GAMEFLAG_TEAMS makes it a two-team gamemode
}

void CGameControllerMOD::PostReset()
{
	m_Hunters = 0;
	m_HunterDeathes = 0;
	m_Civics = 0;
	m_CivicDeathes = 0;

	for(int i = 0; i < MAX_CLIENTS; i++)
		if(GameServer()->m_apPlayers[i])
		{
			GameServer()->m_apPlayers[i]->SetHunter(false);
			if(GameServer()->m_apPlayers[i]->GetTeam() == TEAM_SPECTATORS && GameServer()->m_apPlayers[i]->m_WantTeam != TEAM_SPECTATORS)
			{
				GameServer()->m_apPlayers[i]->SetTeamDirect(GameServer()->m_pController->ClampTeam(GameServer()->m_apPlayers[i]->m_WantTeam));
				GameServer()->m_apPlayers[i]->Respawn();
				//GameServer()->m_apPlayers[i]->m_Score = 0;
				//GameServer()->m_apPlayers[i]->m_ScoreStartTick = Server()->Tick();
				GameServer()->m_apPlayers[i]->m_RespawnTick = Server()->Tick()+Server()->TickSpeed()/2;
			}
			if(GameServer()->m_apPlayers[i]->GetTeam() != TEAM_SPECTATORS)
				m_Civics++;
		}
}

void CGameControllerMOD::Tick()
{
	// this is the main part of the gamemode, this function is run every tick
 
	if(!GameServer()->m_World.m_Paused && !IsGameOver())
	{
		char aBuf[512];

		// when there are no hunters, try to elect one
		// sleep when no one play
		if(m_Hunters == 0 && (m_Civics || Server()->Tick() % (Server()->TickSpeed() * 3) == 0))
		{
			bool SoloPlayerBefore = m_Civics == 1;

			// release who wants to join the game first
			PostReset();

			// elect hunter
			int LeastPlayers = g_Config.m_HuntHunterFixed ? (g_Config.m_HuntHunterNumber + 1) : 2;
			if(m_Civics < LeastPlayers)
			{
				if(Server()->Tick() % (Server()->TickSpeed() * 2) == 0)
				{
					str_format(aBuf, sizeof(aBuf), "这里是猎人杀PVP\n分Civic和Hunter两个阵营\n消灭对立阵营胜利\n至少需要 %d 玩家才能开始", LeastPlayers);
					GameServer()->SendBroadcast(aBuf, -1);
					if(g_Config.m_SvTimelimit > 0)
						m_RoundStartTick = Server()->Tick();
				}
			}
			else if(SoloPlayerBefore)
			{
				// clear broadcast
				GameServer()->SendBroadcast("", -1);
				StartRound();
			}
			else
			{
				GameServer()->SendBroadcast("这局你是Civic! 噶了所有猎人胜利!                 ", -1);//平民提示往左靠以更好提示身份
				m_Hunters = g_Config.m_HuntHunterFixed ? g_Config.m_HuntHunterNumber : ((m_Civics + g_Config.m_HuntHunterRatio - 1) / g_Config.m_HuntHunterRatio);
					str_copy(aBuf, "Hunter是: ", sizeof(aBuf));
					str_copy(m_aHuntersMessage, "Hunter是: ", sizeof(m_aHuntersMessage));

				for(int iHunter = 0; iHunter < m_Hunters; iHunter++)
				{
					int nextHunter = rand() % m_Civics;
					for(int i = 0; i < MAX_CLIENTS; i++)
						// only players get elected
						if(GameServer()->m_apPlayers[i] && GameServer()->m_apPlayers[i]->GetTeam() != TEAM_SPECTATORS && !GameServer()->m_apPlayers[i]->GetHunter())
						{
							if(nextHunter == 0)
							{
								m_Civics--;
								GameServer()->m_apPlayers[i]->SetHunter(true);

								// give him hammer in case of infinite mode
								if(GameServer()->m_apPlayers[i]->GetCharacter())
									GameServer()->m_apPlayers[i]->GetCharacter()->GiveWeapon(WEAPON_HAMMER, -1);

								// generate info message
								const char* ClientName = Server()->ClientName(GameServer()->m_apPlayers[i]->GetCID());
								str_append(m_aHuntersMessage, ClientName, sizeof(m_aHuntersMessage));
								if(m_Hunters - iHunter > 1)
									str_append(m_aHuntersMessage, ", ", sizeof(m_aHuntersMessage));
								int aBufLen = str_length(aBuf);
								str_format(aBuf + aBufLen, sizeof(aBuf) - aBufLen, m_Hunters - iHunter == 1 ? "%d:%s" : "%d:%s, ", GameServer()->m_apPlayers[i]->GetCID(), ClientName);
								break;
							}
							nextHunter--;
						}
				}
				GameServer()->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "game", aBuf);

				// notify all
				GameServer()->SendChatTarget(-1, "————————————————————————————");
				str_format(aBuf, sizeof(aBuf), "本回合有 %d 个Hunter has been selected.", m_Hunters);
				GameServer()->SendChatTarget(-1, aBuf);
				GameServer()->SendChatTarget(-1, "秘密随机分配Civic和Hunter俩阵营 消灭对立阵营胜利 活人看不到死人消息 打字杀易被针对 猎人高伤榴弹有破片 有瞬杀锤子 其余武器双倍伤害");
				GameServer()->SendChatTarget(-1, "分辨出对立玩家并消灭他们来取得胜利");
				GameServer()->SendChatTarget(-1, "Be warned! Sudden Death.");
				GameServer()->CreateSoundGlobal(SOUND_CTF_GRAB_EN);

				for(int i = 0; i < MAX_CLIENTS; i++)
					if(GameServer()->m_apPlayers[i] && GameServer()->m_apPlayers[i]->GetTeam() == TEAM_SPECTATORS)
						GameServer()->SendChatTarget(GameServer()->m_apPlayers[i]->GetCID(), m_aHuntersMessage);
			}
		}
	}

	IGameController::Tick();
}

int CGameControllerMOD::OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int Weapon)
{
	// game not start
	if(m_Hunters + m_HunterDeathes == 0)
		return 0;

	char aBuf[128];

	if(pVictim->GetPlayer()->GetHunter())
	{
		m_Hunters--;
		m_HunterDeathes++;
		// send message notify
		str_format(aBuf, sizeof(aBuf), "Hunter '%s' was defeated!", Server()->ClientName(pVictim->GetPlayer()->GetCID()));
		if(g_Config.m_HuntBroadcastHunterDeath || m_Hunters == 0)
			GameServer()->SendChatTarget(-1, aBuf);
		else
			for(int i = 0; i < MAX_CLIENTS; i++)
				if(GameServer()->m_apPlayers[i] && (GameServer()->m_apPlayers[i]->GetTeam() == TEAM_SPECTATORS || GameServer()->m_apPlayers[i]->GetHunter()))
						GameServer()->SendChatTarget(GameServer()->m_apPlayers[i]->GetCID(), aBuf);
		// add score
		if(!pKiller->GetHunter())
			pKiller->m_HiddenScore += g_Config.m_HuntScoreCivicKillHunter;
		// if the last hunter, leave DoWincheck() to play the sound
		if(m_Hunters)
		{
			if(g_Config.m_HuntBroadcastHunterDeath)
				GameServer()->CreateSoundGlobal(SOUND_CTF_CAPTURE);
			else
				for(int i = 0; i < MAX_CLIENTS; i++)
					if(GameServer()->m_apPlayers[i])
					{
						if(GameServer()->m_apPlayers[i]->GetTeam() == TEAM_SPECTATORS || GameServer()->m_apPlayers[i]->GetHunter())
							GameServer()->CreateSoundGlobal(SOUND_CTF_CAPTURE, GameServer()->m_apPlayers[i]->GetCID());
						else
							GameServer()->CreateSoundGlobal(SOUND_CTF_DROP, GameServer()->m_apPlayers[i]->GetCID());
					}
		}
		else
			DoWincheck();
	}
	else
	{
		m_Civics--;
		m_CivicDeathes++;
		GameServer()->CreateSoundGlobal(SOUND_CTF_DROP);
	}

	// revel hunters (except for the only hunter or the last civic)
	if(!(pVictim->GetPlayer()->GetHunter() && m_Hunters + m_HunterDeathes == 1))
		GameServer()->SendChatTarget(pVictim->GetPlayer()->GetCID(), m_aHuntersMessage);
	pVictim->GetPlayer()->SetTeamDirect(TEAM_SPECTATORS);

	/*
	if(!pKiller || Weapon == WEAPON_GAME)
		return 0;

	if(Weapon == WEAPON_SELF)
		pVictim->GetPlayer()->m_RespawnTick = Server()->Tick()+Server()->TickSpeed()*3.0f;
		*/
	return 0;
}

void CGameControllerMOD::DoWincheck()
{
	const char *pWinMessage;

	char aBuf[128];

	if(m_GameOverTick == -1 && !m_Warmup && !GameServer()->m_World.m_ResetRequested)
	{
		if(m_Hunters < 0 || m_Civics < 0 || m_CivicDeathes < 0 || m_HunterDeathes < 0 || (m_Hunters && m_Civics == 0 && m_CivicDeathes <= 0))
		{
			str_format(aBuf, sizeof(aBuf), "BUG! m_Hunters %d m_Civics %d m_CivicDeathes %d m_HunterDeathes %d", m_Hunters, m_Civics, m_CivicDeathes, m_HunterDeathes);
			pWinMessage = aBuf;
		}
		// only hunters left
		else if(m_Hunters && m_Civics == 0)
		{
			pWinMessage = "Hunters胜利!";
		}
		// timeout or hunters died out
		else if((g_Config.m_SvTimelimit > 0 && (Server()->Tick()-m_RoundStartTick) >= g_Config.m_SvTimelimit*Server()->TickSpeed()*60) || (m_Hunters == 0 && m_Civics && m_HunterDeathes))
			pWinMessage = "Civics胜利!";
		// no one left
		else if(m_Hunters == 0 && m_Civics == 0 && m_HunterDeathes)
			pWinMessage = "两人幸终!";
		else
			goto no_win;

		GameServer()->SendChatTarget(-1, pWinMessage);
		// add score for live hunters
		for(int i = 0; i < MAX_CLIENTS; i++)
			if(GameServer()->m_apPlayers[i] && GameServer()->m_apPlayers[i]->GetTeam() != TEAM_SPECTATORS)
				GameServer()->m_apPlayers[i]->m_HiddenScore += GameServer()->m_apPlayers[i]->GetHunter() ? g_Config.m_HuntScoreHunterWin : g_Config.m_HuntScoreCivicWin;
		// round end sound
		GameServer()->CreateSoundGlobal(SOUND_CTF_CAPTURE);
		// add hidden scores back to players
		for(int i = 0; i < MAX_CLIENTS; i++)
			if(GameServer()->m_apPlayers[i])
			{
				// add players back to team to show the score
				if(GameServer()->m_apPlayers[i]->m_WantTeam != TEAM_SPECTATORS)
					GameServer()->m_apPlayers[i]->SetTeamDirect(GameServer()->m_pController->ClampTeam(1));
				GameServer()->m_apPlayers[i]->m_Score += GameServer()->m_apPlayers[i]->m_HiddenScore;
				GameServer()->m_apPlayers[i]->m_HiddenScore = 0;
			}
		EndRound();

		no_win:;
	}
}

bool CGameControllerMOD::CanChangeTeam(CPlayer *pPlayer, int JoinTeam)
{
	if(JoinTeam == TEAM_SPECTATORS)
		return true;

	if(m_Hunters == 0)
		return true;

	return pPlayer->GetCharacter() && pPlayer->GetCharacter()->IsAlive();
}

void CGameControllerMOD::OnCharacterSpawn(class CCharacter *pChr)
{
	// default health
	pChr->IncreaseHealth(10);

	// give default weapons
	if(pChr->GetPlayer()->GetHunter())
		pChr->GiveWeapon(WEAPON_HAMMER, -1);
	pChr->GiveWeapon(WEAPON_GUN, 10);
}
