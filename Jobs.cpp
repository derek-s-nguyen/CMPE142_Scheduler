#include "Jobs.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#include <iostream>
Jobs::Jobs(){
	arrival = 0, completion = 0, ID = 0, duration = 0;
}

int Jobs::getArrival(){ return arrival; }

int Jobs::getCompletion(){ return completion; }

int Jobs::getID(){ return ID; }

int Jobs::getDuration(){ return duration; }

istream &operator >>(istream &in_stream, Jobs &job){
	in_stream >> job.ID;
	in_stream >> job.arrival;
	in_stream >> job.duration;
	return in_stream;
}
ostream &operator <<(ostream &out_stream, const Jobs &job){
	out_stream << job.ID << "\t" << job.arrival << "\t" << job.duration << "\n";
	return out_stream;
}
Jobs::~Jobs(){}
