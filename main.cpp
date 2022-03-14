#include "header.h"
#include "dll-lvl-1/header.h"
#include "dll-lvl-2/header.h"
#include <QTime>
#include <QDebug>

#include <QList>





int count_milliseconds(std::function<void()> func){
	QTime start = QTime::currentTime();
	func();
	return start.elapsed();
}


int ten_million_times(std::function<int()> func){

	int buff;
	return count_milliseconds([func, &buff]() -> void{
		for(long long i = 0; i < 10000000; ++i){
			buff = func();
		}
	});
}

struct Statistic{
	Statistic(QString name, std::function<int()> func): name_(name), func_(func){
		min_ = ten_million_times(func_);
		max_ = min_;

		count_ = 1;
		sum_ = min_;

		printInfo(min_);
	}

	void step(){
		int buff = ten_million_times(func_);
		if(min_ > buff)
			min_ = buff;
		if(max_ < buff)
			max_ = buff;
		count_ += 1;
		sum_ += buff;

		printInfo(buff);
	}

	void printInfo(int val){
		
		qInfo() << name_ << val << "(min:" << min_ << "max:" << max_ << "avg:" << (sum_ / count_) << ")";
	}

	QString name_;
	int min_;
	int max_;
	double sum_;
	int count_;
	std::function<int()> func_;
};





int main(){

	QList<Statistic> lst = { 
		Statistic("lvl0", lvl0::function), 
		Statistic("lvl1", lvl1::function), 
		Statistic("lvl2", lvl2::function)
		};



	for(int i = 0; i < 100; ++i){
		for(int j = 0; j < lst.length(); ++j)
			lst[j].step();
	}


	return 0;
}
