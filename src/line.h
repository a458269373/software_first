#pragma once

#include"map"

using namespace std;

class line {
public:
	//ax+by+c=0
	long long a = 0;
	long long b = 0;
	long long c = 0;
	static void calInteract(line l1, line l2);
	line(long long x1, long long y1, long long x2, long long y2);
};

