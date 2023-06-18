#include "Dialog.h"
#include "Student.h"
#include <string>
#include <iostream>

using namespace std;


Dialog::Dialog()
{
    executing = false;
    vec = new Vector(0);
}

Dialog::~Dialog(void)
{
    delete[] vec;
}

TEvent& Dialog::GetEvent()
{
    TEvent evt;
    string s;

    getline(cin, s);

    if (s != "")
    {
        evt.type = static_cast<evtType>(s[0] - '0');
        evt.param = stof(s.substr(s.find(' ') + 1));
    }
    else
    {
        ClearEvent(evt);
    }

    return evt;
}

void Dialog::Execute()
{
    TEvent event;
    executing = true;
    PrintInfo();

    do {
        event = GetEvent();
        HandleEvent(event);
    } while (IsExecuting());
}

void Dialog::ClearEvent(TEvent& event)
{
    event.type = Nothing;
    event.param = 0;
}

void Dialog::EndExec()
{
    executing = false;
}

Object* Dialog::CreateElement()
{
    Object* p = NULL;
    cout << "Select type:\n";
    cout << "> 1. Person\n";
    cout << "> 2. Student\n";

    TEvent evt = GetEvent();
    switch (evt.type)
    {
    case Create:
        p = new Person();
        p->Input();
        break;
    case Add:
        p = new Student();
        p->Input();
        break;
    }

    ClearEvent(evt);
    return p;
}

void Dialog::HandleEvent(TEvent& event)
{
	Object* p;
	switch (event.type)
	{
	case Create:
		if (event.param == 0)
		{
			event.param = 5;
		}
		vec = new Vector(event.param);
        cout << "> Created Vector of length " << event.param << endl;
		break;
	case Add:
		vec->Add(CreateElement());
		break;
	case Del:
		vec->Del();
		break;
	case Get:
		bool tg;
		p = vec->TryGet(event.param, tg);
		if (tg)
		{
			p->Show();
		}
		break;
	case Show:
		vec->Show();
		break;
	case Info:
		PrintInfo();
		break;
	case Quit:
		EndExec();
		break;
	};

	ClearEvent(event);
}


void Dialog::PrintInfo()
{
	cout << "> 1. Create Empty Vector With Length (\"1 5\") - Vector[5]\n";
	cout << "> 2. Add\n";
	cout << "> 3. Delete\n";
	cout << "> 4. Get\n";
	cout << "> 5. Show\n";
	cout << "> 6. Info\n";
	cout << "> 7. Quit\n";
}