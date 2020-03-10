#include"iostream"
#include"line.h"
#include"vector"
#include"map"
#include"fstream"
using namespace std;

vector<line> lines;
map<pair<double, double>,int> points;

//(y1-y2)x + (x2-x1)y + (x1y2-x2y1) = 0
line::line(long long x1, long long y1, long long x2, long long y2) {
	this->a = y1 - y2;
	this->b = x2 - x1;
	this->c = x1 * y2 - x2 * y1;
}

void line::calInteract(line l1, line l2) {
	long long a1 = l1.a;
	long long b1 = l1.b;
	long long c1 = l1.c;

	long long a2 = l2.a;
	long long b2 = l2.b;
	long long c2 = l2.c;
	
	double x;
	double y;

	long long temp = a1 * b2 - a2 * b1;

	pair<double,double> ans;

	if (temp != 0) {
		x = (1.0 * (c2 * b1 - c1 * b2)) / (1.0 * temp);
		y = (1.0 * (a2 * c1 - a1 * c2)) / (1.0 * temp);
		ans = pair<double, double>(double(x), double(y));
		points.insert(pair<pair<double, double>, int>(ans, 1));
	}
}

int main(int argc ,char* argv[]) {
	int n;

	int i = 0;
	long long x1 = 0;
	long long x2 = 0;
	long long y1 = 0;
	long long y2 = 0;
	char type;
	
	int lineNum = 0;


	string infile = "";
	string outfile = "";
	if (argc == 5) {
		infile = argv[2];
		outfile = argv[4];
	}
	else {
		cout << "ÊäÈë´íÎó";
	}


	ifstream in;
	ofstream out;
	in.open(infile, ios::in);
	out.open(outfile, ios::out);
	
	in >> n;



	for (; i < n; i++) {
		in >> type;
		if (type == 'L') {
			//Ö±Ïß
			in >> x1 >> y1 >> x2 >> y2;
			line templine(x1, y1, x2, y2);
			for (int j = 0; j < lineNum; j++) {
				line::calInteract(templine, lines[j]);
			}
			lines.push_back(templine);
			lineNum++;
		}
		else if (type == 'C') {
			//Ô²


		}
	}
	out << points.size();
	in.close();
	out.close();
	return 0;
}