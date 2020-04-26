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
// Name           Date          Reason
// Doyeon KIM 9/23/2018
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef SICT_Kingdom_H 
#define SICT_Kingdom_H 

// TODO: sict namespace
namespace sict {

  // TODO: define the structure Kingdom in the sict namespace
  struct Kingdom {
    char m_name[32];
    int m_population;
  };

  // TODO: declare the function display(...),
  //         also in the sict namespace
  void display(const Kingdom& pKingdom);
  void display(const Kingdom pKingdom[], size_t count);
}

#endif