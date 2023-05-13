#include <iostream>
#include <vector>
#include <memory>

#define LOG(x) std::cout << x << std::endl;

class MotionBase{

public:

MotionBase(){}

~MotionBase(){}

// note that virtual functions run slower
virtual bool initialize(){
	LOG("MotionBase startup")
	return false;
	}

virtual bool uninitialize(){
	return false;
	}

double create_cmd(){
	return m_prev=m_prev+0.1;

	}

virtual bool send_cmd(){
	return false;
	}


private:
double m_prev=0;

};

class TcpMotion : public MotionBase{

public:
TcpMotion(){}

~TcpMotion(){}

bool initialize() override {
	LOG("tcpMotion startup")
	return false;
	} 


private:


};


int main(){

	TcpMotion tcp;

	tcp.initialize();



	}


