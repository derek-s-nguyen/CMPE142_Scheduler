#include "Jobs.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#include <iostream>
Jobs::Jobs(){ arrival = 0, completion = 0, ID = 0, duration = 0, startTime = 0, finishTime = 0, totalTimeElapsed = 0, responseTime = 0; }
int Jobs::getArrival(){ return arrival; }
int Jobs::getID(){ return ID; }
int Jobs::getDuration(){ return duration; }
void Jobs::operator =(const Jobs &job)
{
	ID = job.ID;
	arrival = job.arrival;
	duration = job.duration;
}
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
int Jobs::getStartTime(){ return startTime; }
int Jobs::getFinishTime(){ return finishTime; }
int Jobs::getTotalTimeElapsed(){ return totalTimeElapsed; }
int Jobs::getResponseTime(){ return responseTime; }
void Jobs::setStartTime(int start){ startTime = start; }
void Jobs::setFinishTime(int finish){ finishTime = finish; }
void Jobs::setTotalTimeElapsed(int total){ totalTimeElapsed = total; }
void Jobs::setResponseTime(int response){ responseTime = response; }
void Jobs::outputForJobs(){
	 for(k = 0; k < numberOfJobs; k++){
    	if(jobsArry[k].getArrival() > currentTimeStamp)//if there are no jobs to schedule
    	{
    		currentTimeStamp = jobsArry[k].getArrival();//adjust the current time stamp to skip to the next job's arrival time
    	}
    	jobsArry[k].setStartTime(currentTimeStamp);//start time is the current time stamp because FIFO (array is sorted)
    	jobsArry[k].setFinishTime((jobsArry[k].getDuration() + currentTimeStamp));
    	currentTimeStamp = jobsArry[k].getFinishTime();
    }
	 for(a = 0; a < numberOfJobs; a++){
    	cout << "Job ID " << jobsArry[a].getID() << ":\n"
    			<< "\tStart Time: " << jobsArry[a].getStartTime() << endl
				<< "\tFinish Time: " << jobsArry[a].getFinishTime() << endl
				<< "\tTotal Time Elapsed: " << (jobsArry[a].getFinishTime() - jobsArry[a].getArrival()) << endl
				<< "\tResponse Time: " << (jobsArry[a].getStartTime() - jobsArry[a].getArrival()) << endl;
    }
}