#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <future>
#include <memory>
#include <thread>


class LOGGING{ 
    public:
        LOGGING(){ 
            std::cout << "[MESSAGE] " << "Logging class created" << std::endl;
        }

        ~LOGGING(){ 
            std::cout << "[MESSAGE] " << "Logging class destroyed" << std::endl;
        }

        void print_fault(std::string msg){ std::cout << "[FAULT] " << msg << std::endl; }

        void print_warning(std::string msg){ std::cout << "[WARNING] " << msg << std::endl; }

        void print(std::string msg){ std::cout << "[MESSAGE] " << msg << std::endl; }
 

};

class TIMER{

    public:

        TIMER(std::string message){
            *display_message = message;
            *start_time = std::chrono::system_clock::now();
        }

        ~TIMER(){
            *end_time = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds = *end_time-*start_time; 

            std::cout << *display_message + " elapsed time: " + std::to_string( elapsed_seconds.count() ) + "s" << std::endl; 

            delete start_time;
            delete end_time;
            delete display_message;
        }
 
    private:
        std::chrono::_V2::system_clock::time_point *start_time = new std::chrono::_V2::system_clock::time_point;
        std::chrono::_V2::system_clock::time_point *end_time  = new std::chrono::_V2::system_clock::time_point;
        std::string *display_message = new std::string;
};
 

void long_task(double scale){

        // create a large vector that is slow to move around
        //std::this_thread::sleep_for(std::chrono::seconds(3));

        { TIMER timer("task scaled: " + std::to_string(scale) );  
            double x=1.00000001;
            for(int i=0; i<1000000000*scale; i++){
                x = x*x;
            }

        }
 
}
 
 

int main(){
 
    // logging class
    LOGGING *log = new LOGGING(); 

    log->print("startup");

    std::vector<std::future<void>> futures;
    #define USE_ASYNC true

    std::vector<double> tasks={1,1.5,2,1.1,1.2,0.6};

    { TIMER timer("program total time");

        if(USE_ASYNC){

            for(auto &task : tasks){
                futures.push_back(std::async(std::launch::async, long_task, task) ); 
            }
            
                        
            for(auto &e : futures){
                e.get();
            }

            futures.clear();
 
        }else{

            for(auto &task : tasks){
                long_task(task);
            }
        

        }        




    }



    delete log;  

}