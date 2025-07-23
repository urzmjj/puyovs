#pragma once

#include "Sprite.h"
#include "global.h"

namespace ppvs {

class Game;

class CharacterSelect final {
public:
	explicit CharacterSelect(Game*);
	~CharacterSelect();

	CharacterSelect(const CharacterSelect&) = delete;
	CharacterSelect& operator=(const CharacterSelect&) = delete;
	CharacterSelect(CharacterSelect&&) = delete;
	CharacterSelect& operator=(CharacterSelect&&) = delete;

	void draw();
	void prepare();
	void play();
	void end();

	void setCharacter(int playerNum, int selection, bool choice);

private:
	void setDropset(int x, int y, int pl);
	[[nodiscard]] int findCurrentCharacter(int i) const;

	int m_timer = 0;
	Game* m_currentGame = nullptr;
	GameData* m_data = nullptr;
	PuyoCharacter m_order[24*8] = {
		ARLE,
		SCHEZO,
		RULUE,
		DRACO,
		AMITIE,
		RAFFINE,
		SIG,
		RIDER,
		WITCH,
		SATAN,
		SUKETOUDARA,
		CARBUNCLE,
		ACCORD,
		KLUG,
		DONGURIGAERU,
		OCEAN_PRINCE,
		RINGO,
		MAGURO,
		RISUKUMA,
		ECOLO,
		FELI,
		LEMRES,
		OSHARE_BONES,
		YU_REI,
		ARLE1,
		SCHEZO1,
		RULUE1,
		DRACO1,
		AMITIE1,
		RAFFINE1,
		SIG1,
		RIDER1,
		WITCH1,
		SATAN1,
		SUKETOUDARA1,
		CARBUNCLE1,
		ACCORD1,
		KLUG1,
		DONGURIGAERU1,
		OCEAN_PRINCE1,
		RINGO1,
		MAGURO1,
		RISUKUMA1,
		ECOLO1,
		FELI1,
		LEMRES1,
		OSHARE_BONES1,
		YU_REI1,
		ARLE2,
		SCHEZO2,
		RULUE2,
		DRACO2,
		AMITIE2,
		RAFFINE2,
		SIG2,
		RIDER2,
		WITCH2,
		SATAN2,
		SUKETOUDARA2,
		CARBUNCLE2,
		ACCORD2,
		KLUG2,
		DONGURIGAERU2,
		OCEAN_PRINCE2,
		RINGO2,
		MAGURO2,
		RISUKUMA2,
		ECOLO2,
		FELI2,
		LEMRES2,
		OSHARE_BONES2,
		YU_REI2,
		ARLE3,
		SCHEZO3,
		RULUE3,
		DRACO3,
		AMITIE3,
		RAFFINE3,
		SIG3,
		RIDER3,
		WITCH3,
		SATAN3,
		SUKETOUDARA3,
		CARBUNCLE3,
		ACCORD3,
		KLUG3,
		DONGURIGAERU3,
		OCEAN_PRINCE3,
		RINGO3,
		MAGURO3,
		RISUKUMA3,
		ECOLO3,
		FELI3,
		LEMRES3,
		OSHARE_BONES3,
		YU_REI3,
		ARLE4,
		SCHEZO4,
		RULUE4,
		DRACO4,
		AMITIE4,
		RAFFINE4,
		SIG4,
		RIDER4,
		WITCH4,
		SATAN4,
		SUKETOUDARA4,
		CARBUNCLE4,
		ACCORD4,
		KLUG4,
		DONGURIGAERU4,
		OCEAN_PRINCE4,
		RINGO4,
		MAGURO4,
		RISUKUMA4,
		ECOLO4,
		FELI4,
		LEMRES4,
		OSHARE_BONES4,
		YU_REI4,
		ARLE5,
		SCHEZO5,
		RULUE5,
		DRACO5,
		AMITIE5,
		RAFFINE5,
		SIG5,
		RIDER5,
		WITCH5,
		SATAN5,
		SUKETOUDARA5,
		CARBUNCLE5,
		ACCORD5,
		KLUG5,
		DONGURIGAERU5,
		OCEAN_PRINCE5,
		RINGO5,
		MAGURO5,
		RISUKUMA5,
		ECOLO5,
		FELI5,
		LEMRES5,
		OSHARE_BONES5,
		YU_REI5,
		ARLE6,
		SCHEZO6,
		RULUE6,
		DRACO6,
		AMITIE6,
		RAFFINE6,
		SIG6,
		RIDER6,
		WITCH6,
		SATAN6,
		SUKETOUDARA6,
		CARBUNCLE6,
		ACCORD6,
		KLUG6,
		DONGURIGAERU6,
		OCEAN_PRINCE6,
		RINGO6,
		MAGURO6,
		RISUKUMA6,
		ECOLO6,
		FELI6,
		LEMRES6,
		OSHARE_BONES6,
		YU_REI6,
		ARLE7,
		SCHEZO7,
		RULUE7,
		DRACO7,
		AMITIE7,
		RAFFINE7,
		SIG7,
		RIDER7,
		WITCH7,
		SATAN7,
		SUKETOUDARA7,
		CARBUNCLE7,
		ACCORD7,
		KLUG7,
		DONGURIGAERU7,
		OCEAN_PRINCE7,
		RINGO7,
		MAGURO7,
		RISUKUMA7,
		ECOLO7,
		FELI7,
		LEMRES7,
		OSHARE_BONES7,
		YU_REI7,
	};
	Sprite m_background = {};
	Sprite m_holder[24*8] = {};
	Sprite m_charSprite[24*8] = {};

	// Player stuff
	Sprite* m_selectSprite = nullptr;
	Sprite* m_selectedCharacter = nullptr;
	Sprite* m_dropSet = nullptr;
	Sprite* m_name = nullptr;
	Sprite* m_nameHolder = nullptr;
	Sprite* m_nameHolderNumber = nullptr;
	Sprite* m_playerNumber = nullptr;
	int* m_sel = nullptr;
	bool* m_madeChoice = nullptr;
	float m_scale = 6.f;
	int m_numPlayers = 0;
	bool m_firstStart = true;
};

}
