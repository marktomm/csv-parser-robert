#include <iostream>

#include "../include/csv.h"
#include <boost/date_time/posix_time/posix_time.hpp>

int main(int argc, char *argv[])
{  
	io::CSVReader<13, io::trim_chars<' ', '\t'>, io::double_quote_escape<',', '"'> > in("run.csv");
  	// in.read_header(io::ignore_extra_column, "s1","s2","s3","s4","s5","s6");
  	std::string s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13;

	try{
		boost::posix_time::time_duration total_dur = boost::posix_time::seconds(0);
		while(in.read_row(s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13)){
			// do stuff with the data
			boost::posix_time::ptime s2time = boost::posix_time::time_from_string(s2);
			boost::posix_time::ptime s3time = boost::posix_time::time_from_string(s3);

			boost::posix_time::time_duration tdur = s3time - s2time;

			if(tdur < boost::posix_time::hours(24)) {
				total_dur += tdur;
			}
		}
		std::cout << total_dur << std::endl;
	} catch (io::error::too_many_columns& e) {
		std::cout << e.what() << std::endl;
	}
}