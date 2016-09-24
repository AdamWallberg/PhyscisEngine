#pragma once

class phIInputMapping
{
public:

	virtual ~phIInputMapping(){}

	virtual bool GetPressed() const = 0;
	virtual bool GetHeld() const = 0;
	virtual bool GetReleased() const = 0;
	virtual float GetValue() const = 0;

	virtual void Update() = 0;

};