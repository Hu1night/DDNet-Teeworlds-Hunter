/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_GAMEMODES_MOD_H
#define GAME_SERVER_GAMEMODES_MOD_H
#include <game/server/gamecontroller.h>

/*********************************\
*                                 *
* HUNTER SERVER MOD               *
*                                 *
* By Bluelightzero                *
*                                 *
* http://github.com/bluelightzero *
*                                 *
\*********************************/

// you can subclass GAMECONTROLLER_CTF, GAMECONTROLLER_TDM etc if you want
// todo a modification with their base as well.
class CGameControllerMOD : public IGameController
{
public:
	CGameControllerMOD(class CGameContext *pGameServer);
	virtual void Tick();
	virtual int OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int Weapon);
	virtual void DoWincheck();
	virtual bool CanChangeTeam(CPlayer *pPlayer, int JoinTeam);
	virtual void OnCharacterSpawn(class CCharacter *pChr);
	virtual void PostReset();
	// add more virtual functions here if you wish

private:
	int m_Hunters = 0;
	int m_HunterDeathes = 0;
	int m_Civics = 0;
	int m_CivicDeathes = 0;

	char m_aHuntersMessage[512];
};
#endif
