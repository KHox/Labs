#pragma once
#include "Vector.h"
#include "Event.h"

class Dialog
{
public:
	Dialog();
	virtual ~Dialog();
	virtual TEvent& GetEvent();
	virtual Object* CreateElement();
	virtual void HandleEvent (TEvent&);
	virtual void ClearEvent (TEvent&);
	virtual void PrintInfo();
	virtual void Execute();
	void EndExec();
	bool IsExecuting() { return executing; }

protected:
	bool executing = false;
	Vector* vec;
};
