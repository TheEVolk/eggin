#pragma once

class IScene {
public:
	virtual void precache() = 0;
	virtual void load() = 0;
	virtual void clear() = 0;
};