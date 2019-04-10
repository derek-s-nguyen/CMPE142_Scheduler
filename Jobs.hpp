#ifndef JOBS_H_
#define JOBS_H_
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
class Jobs
{
public:
	Jobs();
	int getArrival();
	int getCompletion();
	int getID();
	int getDuration();
	friend istream &operator >>(istream &in_stream, Jobs &job);
	friend ostream &operator <<(ostream &out_stream, const Jobs &job);
	~Jobs();
private:
	int arrival, completion, ID, duration;
};
//start time, finish time, total time elapsed, response time

#endif /* JOBS_H_ */
