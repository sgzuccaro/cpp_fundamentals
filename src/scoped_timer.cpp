#include <iostream>
#include <chrono>
#include <memory>

using namespace std::chrono;


class ScopedTimer{

public:

typedef std::chrono::_V2::system_clock::time_point timepoint;

typedef std::chrono::system_clock clock;

typedef std::chrono::duration<double> duration;

// 
ScopedTimer(std::string msg, double alert_threshold){
	m_message=msg;
	m_alert=alert_threshold;
	
	start_time = clock::now();
	}

~ScopedTimer(){
	end_time = clock::now();
	duration elapsed_time = end_time-start_time; 

	if(elapsed_time.count()>m_alert){

		std::cout << m_message + " elapsed time: " + std::to_string( elapsed_time.count() ) + "s" << std::endl; 
	}

	}

private:

timepoint start_time, end_time;
std::string m_message;
double m_alert;

};


int main(){

	// time using scopes
	{
		ScopedTimer scope_timer("For loop", 0.017);

		double d=0.001;
		
		for(int i=0; i<1000000; i++){
			d=d/1.001;
			
		}


	}


}

