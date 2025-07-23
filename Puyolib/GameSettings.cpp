#include "GameSettings.h"

namespace ppvs {

RuleSetInfo::RuleSetInfo()
{
	setRules(Rules::TSU);
}

RuleSetInfo::RuleSetInfo(const Rules type)
{
	setRules(type);
}

void RuleSetInfo::setRules(const Rules type)
{
	custom = true;
	quickDrop = false;
	marginTime = 192;
	requiredChain = 0;
	initialFeverCount = 0;
	feverPower = 100;
	puyoToClear = 4;
	numPlayers = 2;
	numHumans = 2;
	colors = 4; // Default: cannot choose colors
	ruleSetType = type;
	switch (type) {
	case Rules::TSU:
	case Rules::TSU_ONLINE:
	case Rules::ENDLESS:
	case Rules::ENDLESSFEVER:
	case Rules::ENDLESSFEVERVS:
	case Rules::EXCAVATION:
		targetPoint = 70;
		break;

	case Rules::FEVER:
	case Rules::FEVER_ONLINE:
	case Rules::FEVER15_ONLINE:
	case Rules::ENDLESSFEVERVS_ONLINE:
		targetPoint = 120;
	}
}

GameSettings::GameSettings(const RuleSetInfo& ruleSetInfo)
	: ruleSetInfo(ruleSetInfo)
{
	// Set default values
	numPlayers = 2;
	numHumans = 2;

	language = "EN";
	playSound = true;
	playMusic = true;
	background = "Forest";
	puyo = "Default";
	sfx = "Default";
	defaultPuyoCharacter = ARLE;
	useCharacterField = true;
	startWithCharacterSelect = true;
	for(int i = 0; i < 1000; i++)swapABConfirm[i] = false;
	pickColors = true;
	useCpuPlayers = false;
	spectating = false;
	recording = RecordState::NOT_RECORDING;
	showNames = 0;
	rankedMatch = false;
	maxWins = 2;

	// Default character folders
	characterSetup[ACCORD] = "Accord";
	characterSetup[AMITIE] = "Amitie";
	characterSetup[ARLE] = "Arle";
	characterSetup[DONGURIGAERU] = "Dongurigaeru";
	characterSetup[DRACO] = "Draco";
	characterSetup[CARBUNCLE] = "Carbuncle";
	characterSetup[ECOLO] = "Ecolo";
	characterSetup[FELI] = "Feli";
	characterSetup[KLUG] = "Klug";
	characterSetup[LEMRES] = "Lemres";
	characterSetup[MAGURO] = "Maguro";
	characterSetup[OCEAN_PRINCE] = "Ocean Prince";
	characterSetup[OSHARE_BONES] = "Oshare Bones";
	characterSetup[RAFFINE] = "Raffine";
	characterSetup[RIDER] = "Rider";
	characterSetup[RISUKUMA] = "Risukuma";
	characterSetup[RINGO] = "Ringo";
	characterSetup[RULUE] = "Rulue";
	characterSetup[SATAN] = "Satan";
	characterSetup[SCHEZO] = "Schezo";
	characterSetup[SIG] = "Sig";
	characterSetup[SUKETOUDARA] = "Suketoudara";
	characterSetup[WITCH] = "Witch";
	characterSetup[YU_REI] = "Yu";
	characterSetup[ACCORD1] = "Accord1";
	characterSetup[AMITIE1] = "Amitie1";
	characterSetup[ARLE1] = "Arle1";
	characterSetup[DONGURIGAERU1] = "Dongurigaeru1";
	characterSetup[DRACO1] = "Draco1";
	characterSetup[CARBUNCLE1] = "Carbuncle1";
	characterSetup[ECOLO1] = "Ecolo1";
	characterSetup[FELI1] = "Feli1";
	characterSetup[KLUG1] = "Klug1";
	characterSetup[LEMRES1] = "Lemres1";
	characterSetup[MAGURO1] = "Maguro1";
	characterSetup[OCEAN_PRINCE1] = "Ocean Prince1";
	characterSetup[OSHARE_BONES1] = "Oshare Bones1";
	characterSetup[RAFFINE1] = "Raffine1";
	characterSetup[RIDER1] = "Rider1";
	characterSetup[RISUKUMA1] = "Risukuma1";
	characterSetup[RINGO1] = "Ringo1";
	characterSetup[RULUE1] = "Rulue1";
	characterSetup[SATAN1] = "Satan1";
	characterSetup[SCHEZO1] = "Schezo1";
	characterSetup[SIG1] = "Sig1";
	characterSetup[SUKETOUDARA1] = "Suketoudara1";
	characterSetup[WITCH1] = "Witch1";
	characterSetup[YU_REI1] = "Yu1";
	characterSetup[ACCORD2] = "Accord2";
	characterSetup[AMITIE2] = "Amitie2";
	characterSetup[ARLE2] = "Arle2";
	characterSetup[DONGURIGAERU2] = "Dongurigaeru2";
	characterSetup[DRACO2] = "Draco2";
	characterSetup[CARBUNCLE2] = "Carbuncle2";
	characterSetup[ECOLO2] = "Ecolo2";
	characterSetup[FELI2] = "Feli2";
	characterSetup[KLUG2] = "Klug2";
	characterSetup[LEMRES2] = "Lemres2";
	characterSetup[MAGURO2] = "Maguro2";
	characterSetup[OCEAN_PRINCE2] = "Ocean Prince2";
	characterSetup[OSHARE_BONES2] = "Oshare Bones2";
	characterSetup[RAFFINE2] = "Raffine2";
	characterSetup[RIDER2] = "Rider2";
	characterSetup[RISUKUMA2] = "Risukuma2";
	characterSetup[RINGO2] = "Ringo2";
	characterSetup[RULUE2] = "Rulue2";
	characterSetup[SATAN2] = "Satan2";
	characterSetup[SCHEZO2] = "Schezo2";
	characterSetup[SIG2] = "Sig2";
	characterSetup[SUKETOUDARA2] = "Suketoudara2";
	characterSetup[WITCH2] = "Witch2";
	characterSetup[YU_REI2] = "Yu2";
	characterSetup[ACCORD3] = "Accord3";
	characterSetup[AMITIE3] = "Amitie3";
	characterSetup[ARLE3] = "Arle3";
	characterSetup[DONGURIGAERU3] = "Dongurigaeru3";
	characterSetup[DRACO3] = "Draco3";
	characterSetup[CARBUNCLE3] = "Carbuncle3";
	characterSetup[ECOLO3] = "Ecolo3";
	characterSetup[FELI3] = "Feli3";
	characterSetup[KLUG3] = "Klug3";
	characterSetup[LEMRES3] = "Lemres3";
	characterSetup[MAGURO3] = "Maguro3";
	characterSetup[OCEAN_PRINCE3] = "Ocean Prince3";
	characterSetup[OSHARE_BONES3] = "Oshare Bones3";
	characterSetup[RAFFINE3] = "Raffine3";
	characterSetup[RIDER3] = "Rider3";
	characterSetup[RISUKUMA3] = "Risukuma3";
	characterSetup[RINGO3] = "Ringo3";
	characterSetup[RULUE3] = "Rulue3";
	characterSetup[SATAN3] = "Satan3";
	characterSetup[SCHEZO3] = "Schezo3";
	characterSetup[SIG3] = "Sig3";
	characterSetup[SUKETOUDARA3] = "Suketoudara3";
	characterSetup[WITCH3] = "Witch3";
	characterSetup[YU_REI3] = "Yu3";
	characterSetup[ACCORD4] = "Accord4";
	characterSetup[AMITIE4] = "Amitie4";
	characterSetup[ARLE4] = "Arle4";
	characterSetup[DONGURIGAERU4] = "Dongurigaeru4";
	characterSetup[DRACO4] = "Draco4";
	characterSetup[CARBUNCLE4] = "Carbuncle4";
	characterSetup[ECOLO4] = "Ecolo4";
	characterSetup[FELI4] = "Feli4";
	characterSetup[KLUG4] = "Klug4";
	characterSetup[LEMRES4] = "Lemres4";
	characterSetup[MAGURO4] = "Maguro4";
	characterSetup[OCEAN_PRINCE4] = "Ocean Prince4";
	characterSetup[OSHARE_BONES4] = "Oshare Bones4";
	characterSetup[RAFFINE4] = "Raffine4";
	characterSetup[RIDER4] = "Rider4";
	characterSetup[RISUKUMA4] = "Risukuma4";
	characterSetup[RINGO4] = "Ringo4";
	characterSetup[RULUE4] = "Rulue4";
	characterSetup[SATAN4] = "Satan4";
	characterSetup[SCHEZO4] = "Schezo4";
	characterSetup[SIG4] = "Sig4";
	characterSetup[SUKETOUDARA4] = "Suketoudara4";
	characterSetup[WITCH4] = "Witch4";
	characterSetup[YU_REI4] = "Yu4";
	characterSetup[ACCORD5] = "Accord5";
	characterSetup[AMITIE5] = "Amitie5";
	characterSetup[ARLE5] = "Arle5";
	characterSetup[DONGURIGAERU5] = "Dongurigaeru5";
	characterSetup[DRACO5] = "Draco5";
	characterSetup[CARBUNCLE5] = "Carbuncle5";
	characterSetup[ECOLO5] = "Ecolo5";
	characterSetup[FELI5] = "Feli5";
	characterSetup[KLUG5] = "Klug5";
	characterSetup[LEMRES5] = "Lemres5";
	characterSetup[MAGURO5] = "Maguro5";
	characterSetup[OCEAN_PRINCE5] = "Ocean Prince5";
	characterSetup[OSHARE_BONES5] = "Oshare Bones5";
	characterSetup[RAFFINE5] = "Raffine5";
	characterSetup[RIDER5] = "Rider5";
	characterSetup[RISUKUMA5] = "Risukuma5";
	characterSetup[RINGO5] = "Ringo5";
	characterSetup[RULUE5] = "Rulue5";
	characterSetup[SATAN5] = "Satan5";
	characterSetup[SCHEZO5] = "Schezo5";
	characterSetup[SIG5] = "Sig5";
	characterSetup[SUKETOUDARA5] = "Suketoudara5";
	characterSetup[WITCH5] = "Witch5";
	characterSetup[YU_REI5] = "Yu5";
	characterSetup[ACCORD6] = "Accord6";
	characterSetup[AMITIE6] = "Amitie6";
	characterSetup[ARLE6] = "Arle6";
	characterSetup[DONGURIGAERU6] = "Dongurigaeru6";
	characterSetup[DRACO6] = "Draco6";
	characterSetup[CARBUNCLE6] = "Carbuncle6";
	characterSetup[ECOLO6] = "Ecolo6";
	characterSetup[FELI6] = "Feli6";
	characterSetup[KLUG6] = "Klug6";
	characterSetup[LEMRES6] = "Lemres6";
	characterSetup[MAGURO6] = "Maguro6";
	characterSetup[OCEAN_PRINCE6] = "Ocean Prince6";
	characterSetup[OSHARE_BONES6] = "Oshare Bones6";
	characterSetup[RAFFINE6] = "Raffine6";
	characterSetup[RIDER6] = "Rider6";
	characterSetup[RISUKUMA6] = "Risukuma6";
	characterSetup[RINGO6] = "Ringo6";
	characterSetup[RULUE6] = "Rulue6";
	characterSetup[SATAN6] = "Satan6";
	characterSetup[SCHEZO6] = "Schezo6";
	characterSetup[SIG6] = "Sig6";
	characterSetup[SUKETOUDARA6] = "Suketoudara6";
	characterSetup[WITCH6] = "Witch6";
	characterSetup[YU_REI6] = "Yu6";
	characterSetup[ACCORD7] = "Accord7";
	characterSetup[AMITIE7] = "Amitie7";
	characterSetup[ARLE7] = "Arle7";
	characterSetup[DONGURIGAERU7] = "Dongurigaeru7";
	characterSetup[DRACO7] = "Draco7";
	characterSetup[CARBUNCLE7] = "Carbuncle7";
	characterSetup[ECOLO7] = "Ecolo7";
	characterSetup[FELI7] = "Feli7";
	characterSetup[KLUG7] = "Klug7";
	characterSetup[LEMRES7] = "Lemres7";
	characterSetup[MAGURO7] = "Maguro7";
	characterSetup[OCEAN_PRINCE7] = "Ocean Prince7";
	characterSetup[OSHARE_BONES7] = "Oshare Bones7";
	characterSetup[RAFFINE7] = "Raffine7";
	characterSetup[RIDER7] = "Rider7";
	characterSetup[RISUKUMA7] = "Risukuma7";
	characterSetup[RINGO7] = "Ringo7";
	characterSetup[RULUE7] = "Rulue7";
	characterSetup[SATAN7] = "Satan7";
	characterSetup[SCHEZO7] = "Schezo7";
	characterSetup[SIG7] = "Sig7";
	characterSetup[SUKETOUDARA7] = "Suketoudara7";
	characterSetup[WITCH7] = "Witch7";
	characterSetup[YU_REI7] = "Yu7";

	// Default controls
	controls["1up"] = "up";
	controls["1down"] = "down";
	controls["1left"] = "left";
	controls["1right"] = "right";
	controls["1a"] = "x";
	controls["1b"] = "z";
	controls["1start"] = "enter";

	controls["2up"] = "i";
	controls["2down"] = "k";
	controls["2left"] = "j";
	controls["2right"] = "l";
	controls["2a"] = "m";
	controls["2b"] = "n";
	controls["2start"] = "space";
}

GameSettings::~GameSettings() = default;

}
