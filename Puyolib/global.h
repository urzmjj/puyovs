#pragma once
#include "Frontend.h"
#include "RNG/MersenneTwister.h"
#include "Sound.h"

#include <deque>
#include <map>
#include <sstream>
#include <vector>

#define CHANNEL_CHAT 0
#define CHANNEL_CHALLENGE 1
#define CHANNEL_CHALLENGERESPONSE 2
#define CHANNEL_GAME 3
#define CHANNEL_CHAT_PRIVATE 4

#define CHANNEL_MATCH 9

#ifdef _WIN32
#ifdef _MSC_VER
extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);
#endif
#else
#include <sys/time.h>
inline static unsigned long timeGetTime()
{
	timeval tv;
	gettimeofday(&tv, 0);

	return (tv.tv_usec / 1000) + tv.tv_sec * 1000;
}
#endif

namespace ppvs {

enum PlayerType : unsigned char {
	HUMAN,
	CPU,
	ONLINE,
};

enum PuyoCharacter : unsigned char {
	ACCORD,
	AMITIE,
	ARLE,
	DONGURIGAERU,
	DRACO,
	CARBUNCLE,
	ECOLO,
	FELI,
	KLUG,
	LEMRES,
	MAGURO,
	OCEAN_PRINCE,
	OSHARE_BONES,
	RAFFINE,
	RIDER,
	RISUKUMA,
	RINGO,
	RULUE,
	SATAN,
	SCHEZO,
	SIG,
	SUKETOUDARA,
	WITCH,
	YU_REI,
	ACCORD1,
	AMITIE1,
	ARLE1,
	DONGURIGAERU1,
	DRACO1,
	CARBUNCLE1,
	ECOLO1,
	FELI1,
	KLUG1,
	LEMRES1,
	MAGURO1,
	OCEAN_PRINCE1,
	OSHARE_BONES1,
	RAFFINE1,
	RIDER1,
	RISUKUMA1,
	RINGO1,
	RULUE1,
	SATAN1,
	SCHEZO1,
	SIG1,
	SUKETOUDARA1,
	WITCH1,
	YU_REI1,
	ACCORD2,
	AMITIE2,
	ARLE2,
	DONGURIGAERU2,
	DRACO2,
	CARBUNCLE2,
	ECOLO2,
	FELI2,
	KLUG2,
	LEMRES2,
	MAGURO2,
	OCEAN_PRINCE2,
	OSHARE_BONES2,
	RAFFINE2,
	RIDER2,
	RISUKUMA2,
	RINGO2,
	RULUE2,
	SATAN2,
	SCHEZO2,
	SIG2,
	SUKETOUDARA2,
	WITCH2,
	YU_REI2,
	ACCORD3,
	AMITIE3,
	ARLE3,
	DONGURIGAERU3,
	DRACO3,
	CARBUNCLE3,
	ECOLO3,
	FELI3,
	KLUG3,
	LEMRES3,
	MAGURO3,
	OCEAN_PRINCE3,
	OSHARE_BONES3,
	RAFFINE3,
	RIDER3,
	RISUKUMA3,
	RINGO3,
	RULUE3,
	SATAN3,
	SCHEZO3,
	SIG3,
	SUKETOUDARA3,
	WITCH3,
	YU_REI3,
	ACCORD4,
	AMITIE4,
	ARLE4,
	DONGURIGAERU4,
	DRACO4,
	CARBUNCLE4,
	ECOLO4,
	FELI4,
	KLUG4,
	LEMRES4,
	MAGURO4,
	OCEAN_PRINCE4,
	OSHARE_BONES4,
	RAFFINE4,
	RIDER4,
	RISUKUMA4,
	RINGO4,
	RULUE4,
	SATAN4,
	SCHEZO4,
	SIG4,
	SUKETOUDARA4,
	WITCH4,
	YU_REI4,
	ACCORD5,
	AMITIE5,
	ARLE5,
	DONGURIGAERU5,
	DRACO5,
	CARBUNCLE5,
	ECOLO5,
	FELI5,
	KLUG5,
	LEMRES5,
	MAGURO5,
	OCEAN_PRINCE5,
	OSHARE_BONES5,
	RAFFINE5,
	RIDER5,
	RISUKUMA5,
	RINGO5,
	RULUE5,
	SATAN5,
	SCHEZO5,
	SIG5,
	SUKETOUDARA5,
	WITCH5,
	YU_REI5,
	ACCORD6,
	AMITIE6,
	ARLE6,
	DONGURIGAERU6,
	DRACO6,
	CARBUNCLE6,
	ECOLO6,
	FELI6,
	KLUG6,
	LEMRES6,
	MAGURO6,
	OCEAN_PRINCE6,
	OSHARE_BONES6,
	RAFFINE6,
	RIDER6,
	RISUKUMA6,
	RINGO6,
	RULUE6,
	SATAN6,
	SCHEZO6,
	SIG6,
	SUKETOUDARA6,
	WITCH6,
	YU_REI6,
	ACCORD7,
	AMITIE7,
	ARLE7,
	DONGURIGAERU7,
	DRACO7,
	CARBUNCLE7,
	ECOLO7,
	FELI7,
	KLUG7,
	LEMRES7,
	MAGURO7,
	OCEAN_PRINCE7,
	OSHARE_BONES7,
	RAFFINE7,
	RIDER7,
	RISUKUMA7,
	RINGO7,
	RULUE7,
	SATAN7,
	SCHEZO7,
	SIG7,
	SUKETOUDARA7,
	WITCH7,
	YU_REI7,
};

constexpr int kNumCharacters = 24 * 8;

enum class RecordState : int {
	NOT_RECORDING,
	RECORDING,
	REPLAYING,
};

// Global sounds struct
struct Sounds {
	Sound allClearDrop, drop, feverLight, fever, feverTimeCount, feverTimeEnd, go, heavy, hit, lose, move,
		nuisanceHitL, nuisanceHitM, nuisanceHitS,
		nuisanceL, nuisanceS, ready, rotate, win,
		decide, cancel, cursor;
	Sound chain[7];
};

// Settings by the users for modding, are loaded at start of game
struct UserSettings {
	// Strings to user directories
	std::string puyoDirPath;
	std::string backgroundDirPath;
	std::string sfxDirPath;
};

// Variables through that are global in game
struct GameData {
	// Controllers
	Frontend* front {};
	FeImage *imgPuyo {}, *imgBackground {}, *imgField1 {}, *imgField2 {}, *imgBorder1 {}, *imgBorder2 {}, *imgPlayerBorder {}, *imgSpice {};
	FeImage *imgFieldFever {}, *imgScore {}, *imgChain {}, *imgCheckMark {};
	FeImage *imgAllClear {}, *imgLose {}, *imgWin {};
	FeImage *imgNextPuyoBackgroundR {}, *imgNextPuyoBackgroundL {};
	FeImage *imgFeverGauge {}, *imgSeconds {};
	FeImage *imgLight {}, *imgLightS {}, *imgLightHit {}, *imgFSparkle {}, *imgFLight {}, *imgFLightHit {}, *imgTime {};
	FeImage* imgMenu[3][2] {};
	FeImage* imgFeverBack[30] {};
	FeImage *imgCharHolder {}, *imgNameHolder {}, *imgPlayerNumber {}, *imgPlayerCharSelect {}, *imgBlack {};
	FeImage *imgCharField[kNumCharacters] {}, *imgCharSelect[kNumCharacters] {}, *imgSelect[kNumCharacters] {}, *imgCharName[kNumCharacters] {};
	FeImage* imgDropSet {};
	FeShader* glowShader {};
	FeShader* tunnelShader {};
	Sounds snd;
	UserSettings gUserSettings;
	int globalTimer {}; // Global timer in game
	int matchTimer {}; // Duration of a match
	int quadrupletCenter {}; // Center of rotation for quadruplets
	bool windowFocus {};
	bool playSounds {}, playMusic {};
};

struct TranslatableStrings {
	std::string waitingForPlayer;
	std::string disconnected;
	std::string rankedWaiting;
	std::string rankedSearching;
	TranslatableStrings()
		: waitingForPlayer("Waiting for player...")
		, disconnected("Player disconnected.")
		, rankedWaiting("Please press the Start button\n to find a new opponent. (default: Enter button)")
		, rankedSearching("Searching for opponent...")
	{
	}
};

typedef std::deque<std::string> StringList;

// Ini file is edited from launcher
extern std::map<std::string, int> controlsMap;

// Sound
extern std::vector<std::string> voicePattern;
extern std::vector<int> voicePatternClassic;

// Global constants throughout all games
constexpr float kPiF = 3.14159265f;
constexpr double kPiD = 3.141592653589793238463;
constexpr int kPuyoX = 32;
constexpr int kPuyoY = 32;
constexpr int kChainPopSpeed = 25;
constexpr float kGarbageSpeed = 4.8f;

// Global strings for local folders (to shorten expressions)
extern const std::string kFolderUserSounds;
extern const std::string kFolderUserMusic;
extern const std::string kFolderUserBackgrounds;
extern const std::string kFolderUserPuyo;
extern const std::string kFolderUserCharacter;

// Global RNG
extern MersenneTwister gRng;

// Shader
extern bool useShaders;
extern float tunnelShaderColor[6][3];

// Global functions
void initGlobal();
void initFeverChains();
std::string getFeverChain(int type, int colors, int chain, int offset = 0);
int getRandom(int);
std::string Lower(std::string str);
void setBuffer(Sound& s, FeSound* sb);
int sign(int i);
double interpolate(std::string type, double startVal, double endVal, double t, double alpha = 1, double beta = 1);
void splitString(std::string& in, char delimiter, StringList& v);
void createFolder(std::string folderName);


/* PUYOLIB DEBUGGING MODE
 * See Puyolib/global.cpp for more info. */
extern int debugMode;
extern std::string debugString;

// Convert int to string
template <class T>
std::string toString(const T& t)
{
	std::stringstream ss;
	ss << t;
	return ss.str();
}

int toInt(const std::string& s);

}
