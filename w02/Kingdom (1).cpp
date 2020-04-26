/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
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
// File: <kingdom.cpp>


// TODO: include the necessary headers
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Kingdom.h"

// TODO: the sict namespace

// TODO:definition for display(...) 
using namespace std;
namespace sict {

	// TODO: the westeros namespace
	void display(const Kingdom k) {

		cout << k.m_name << ", population " << k.m_population << endl;
	}

}


