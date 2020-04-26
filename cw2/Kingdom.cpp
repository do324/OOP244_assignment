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
// Doyeon KIM 9/23/2018
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers

#include <iostream>
#include "Kingdom.h"
using namespace std;

// TODO: the sict namespace

    // TODO:definition for display(...) 

namespace sict {
  void display(const Kingdom& pKingdom) {
    cout << pKingdom.m_name << ", " << "population " << pKingdom.m_population << endl;
  }

  void display(const Kingdom pKingdom[], size_t count) {
    cout << "------------------------------" << endl;
    cout << "Kingdoms of SICT" << endl;
    cout << "------------------------------" << endl;
    int total = 0;
    for (size_t i = 0; i < count; i++) {
      cout << i + 1 << ". ";
      display(pKingdom[i]);
      total += pKingdom[i].m_population;
    }
    cout << "------------------------------" << endl;
    cout << "Total population of SICT: " << total << endl;
    cout << "------------------------------" << endl;
  }
}

