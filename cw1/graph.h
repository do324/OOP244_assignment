// Workshop 1
// Name: Doyeon Kim
// Student #: 139766166
// Course: OOP244 Fall 2018
// File: graph.h
#pragma once
#include <iostream>
using namespace std;
#define MAX_NO_OF_SAMPLES 20

void getSamples(int samples[], int noOfSamples);
int findMax(int samples[], int noOfSamples);
void printBar(int val, int max);
void printGraph(int samples[], int noOfSamples);