#include <iostream>
#include <memory>

#define LOG(x) std::cout << x << std::endl;

class Entity{

	public:
	Entity(){
		LOG("Entity constructor")
	}

	~Entity(){
		LOG("Entity destructor")
	}

	template <class T>
	void set_speed(T v){
		m_speed=v;
	}

	template <class T>
	void speed_multiply(T x){
		m_speed=m_speed*x;
	}

	double get_speed(){
		return m_speed;
	}

	private:
		double m_speed=0;

};

class TestClass{

	public:

	TestClass(){
		LOG("TestClass constructor")
	}

	~TestClass(){
		LOG("TestClass destructor")
	}

	void entity_test(){
		entity->set_speed(12.7);
		entity->speed_multiply((int) 2);

		LOG("speed: " << 
		entity->get_speed())
		
	}

	

	private:

		std::unique_ptr<Entity> entity = std::make_unique<Entity>();



};




int main()
{

// unique pointer
	auto ptr=std::make_unique<double>(3.3);

	*ptr=6.5;

	LOG("T1: " << *ptr)

	std::unique_ptr<double> data;
	data= std::make_unique<double>();

	double temp=7.6;
	*data=temp;

	LOG("T2: " << data.get())
	

	
	LOG("T3")
	TestClass t;
	t.entity_test();
	


}