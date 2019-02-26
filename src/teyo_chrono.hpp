
#include <chrono>
#include <memory>
namespace teyo{
namespace chrono{

// std::chronoの時間型をリネームする
using nanoseconds = std::chrono::nanoseconds;
using microseconds = std::chrono::microseconds;
using milliseconds = std::chrono::milliseconds;
using seconds = std::chrono::seconds;
using minutes = std::chrono::minutes;
using hours = std::chrono::hours;
	
template<class ResultType, class DefaultTUnit = nanoseconds>
class AutoClock{
	std::chrono::high_resolution_clock::time_point start, end;
	std::shared_ptr<ResultType> d;
	public:
	AutoClock(std::shared_ptr<ResultType> time_var){
		d = time_var;
		start = std::chrono::high_resolution_clock::now();
	}
	~AutoClock(){
		measure_arrange<DefaultTUnit>();
	}
	void reset(){
		start = std::chrono::high_resolution_clock::now();
	}
	template<class TUnit>
	void measure_arrange(){
		end = std::chrono::high_resolution_clock::now();
		*d = std::chrono::duration_cast<TUnit>(end - start).count();
	}
	template<class TUnit>
	ResultType measure(){
		auto tmp =  std::chrono::high_resolution_clock::now();
		return std::chrono::duration_cast<TUnit>(tmp - start).count();
	}
};

}
}
