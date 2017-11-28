#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

class Worker {

	private:
		int _id;
        std::string _name;
        double _weeklyWage;
        std::string _manager;
        int _leavesTakenThisYear;
        int _yearsInCompany;
        
        std::vector<int> _leavesLeftInEachPastYear;
		
	public:
		static const int LEAVES_ALLOWED = 10;
		
    	getId();
    	getName();
    	getWeeklyWage();
    	getManager();
    	getLeavesTakenThisYear();
    	getYearsInCompany();
    	
    	int leavesLeft() = { return LEAVES_ALLOWED - _leavesTakenThisYear; };
    	double roundYearWage() = { return round(_weeklyWage * 52); };
    	int getYears(){  int years = 3; if (_yearsInCompany < 3) {years = _yearsInCompany; return years;}
     
        Worker(int id, double wage, std::string manager, std::string name,
		int leavesTaken, std::vector<int> leavesLeftPreviously) {
			_id = id;
          	_name = name;
          	_wage = wage;
          	_manager = manager;
          	_leavesTaken = leavesTaken;
          	_leavesLeftPreviously = leavesLeftPreviously;
          	_yearsInCompany = leavesLeftPreviously.size();
        }
};
     
int main() {
     
	std::vector<int> v;
	
	v.push_back(5);
	v.push_back(2);
	
	Worker w = Worker(1, 2.5, "X", "Joe", 5, v);
	
	std::cout << w.toHtml() << std::endl;
	
	return 0;
    }
    
std::string workerToHtml(Worker temp) {
	std::stringstream ss;
	std::string str;
     
	ss << "<div>" << temp.getId();
     
	ss << "<div>" << "<h1>Worker Info</h1>" << "<div id='emp" << temp.getId() << "'>"
	<< "<span>" << temp.getName() << "</span>" << "<div class='left'>"
	<< "<span>Leaves Left :</span>" << "<span>Annual salary:</span>"
	<< "<span>Manager:</span>" << "<span>Reimbursable leaves:</span>"
	<< "</div>";
	ss << "<div class='right'><span>" << temp.leavesLeft();
	<< "</span>";
	ss << "<span>" << roundYearWage() << "</span>";
	
	if (_manager.empty()) {
		ss << "<span>None</span>";
	} else {
		ss << "<span>" << _manager << "</span>";
	}
	
	int leavesLeftPreviously = 0;
	for (int i = 0; i < temp.getYear(); i++) {
		leavesLeftPreviously += _leavesLeftPreviously[_yearsInCompany - i - 1];
	}
	
	ss << "<span>" + leavesLeftPreviously << "</span>";
     
	ss << "</div> </div>";
     
	return ss.str();
}
