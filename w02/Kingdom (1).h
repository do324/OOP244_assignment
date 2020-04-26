/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/
// Workshop <Workshop 2>
// Name: <Doyeon Kim>
// Student #: <139766166>
// Course: OOP244 Fall 2018
// File: <kingdom.h>
// TODO: header safeguards
#ifndef KINGDOM_H_
#define KINGDOM_H_
#include "Kingdom.h"
#include <iostream>
#include <string>
// TODO: sict namespace
namespace sict {
	struct Kingdom {
	public:
		char m_name[32];
		int m_population;
	};
	void display(struct Kingdom k);


}
#endif
