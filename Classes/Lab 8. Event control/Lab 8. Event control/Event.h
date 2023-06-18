#pragma once
enum evtType {
	Nothing,
	Create,
	Add,
	Del,
	Get,
	Show,
	Info,
	Quit
};

struct TEvent
{
	evtType type;
	int param;
};