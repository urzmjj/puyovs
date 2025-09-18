#pragma once

#include "global.h"
#include <vector>

namespace ppvs {

struct ControllerEvent {
	ControllerEvent()
		: time(0)
		, ev(0)
	{
	}
	ControllerEvent(const int t, const char ev)
		: time(t)
		, ev(ev)
	{
	}

	int time;
	char ev;
};

struct FeInput;

class Controller {
public:
	int m_down = 0;
	int m_up = 0;
	int m_left = 0;
	int m_right = 0;
	int m_a = 0;
	int m_b = 0;
	int m_start = 0;
	int m_select = 0;
	int m_x = 0;
	int m_y = 0;
	int m_l = 0;
	int m_r = 0;

	bool m_delayDown = false;
	bool m_delayUp = false;
	bool m_delayLeft = false;
	bool m_delayRight = false;
	bool m_delayA = false;
	bool m_delayB = false;
	bool m_delayStart = false;
	bool m_delaySelect = false;
	bool m_delayX = false;
	bool m_delayY = false;
	bool m_delayL = false;
	bool m_delayR = false;

	void init(int playerNumber, PlayerType type, RecordState s = RecordState::NOT_RECORDING);
	void setState(const FeInput& input, int t);
	void release();
	void record(int t);

	RecordState m_state = RecordState::NOT_RECORDING;
	std::vector<ControllerEvent> m_recordEvents;

private:
	// Delayed checking
	bool m_dUp = false;
	bool m_dDown = false;
	bool m_dLeft = false;
	bool m_dRight = false;
	bool m_dA = false;
	bool m_dB = false;
	bool m_dStart = false;
	bool m_dSelect = false;
	bool m_dX = false;
	bool m_dY = false;
	bool m_dL = false;
	bool m_dR = false;
	int m_playerNumber = 0;
	PlayerType m_type = CPU;
};
}
