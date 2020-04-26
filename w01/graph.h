#ifndef _244_graph_H 
#define _244_graph_H 
#include <iostream>
using namespace std;
#define MAX_NO_OF_SAMPLES 20

namespace sict
{
	void getSamples(int samples[], int noOfSamples);
	int findMax(int samples[], int noOfSamples);
	void printBar(int val, int max);
	void printGraph(int samples[], int noOfSamples);
}
#endif 