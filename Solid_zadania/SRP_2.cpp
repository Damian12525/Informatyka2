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
    int _leavesTaken;	// Leaves taken this year.
    int _yearsInCompany;

    // How many leaves left in each past year the worker worked in the company.
    std::vector<int> _leavesLeftPreviously;

public:
    static const int LEAVES_ALLOWED = 10;

    Worker(int id, double wage, std::string manager, std::string name,
           int leavesTaken, const std::vector<int> &leavesLeftPreviously) {
        _id = id;
        _name = name;
        _weeklyWage = wage;
        _manager = manager;
        _leavesTaken = leavesTaken;
        _leavesLeftPreviously = leavesLeftPreviously;
        _yearsInCompany = leavesLeftPreviously.size();
    }


    int get_id()const{return _id;}
    std::string get_name (){ return _name;}
    double get_weeklyWage() const { return _weeklyWage;}
    std::string get_manager() const
    {
        if (_manager.empty())
        {
            return "None";
        }
        else
        {
            return _manager;
        }
    }
    int get_leavesTaken() const { return _leavesTaken;}
    int get_yearsInCompany()const { return _yearsInCompany;}
    std::vector<int> get_leavesLeftPreviously() const { return _leavesLeftPreviously;}

    int get_leavesLeft() const { return LEAVES_ALLOWED - _leavesTaken; }
    double get_yearlyWage() const { return round(_weeklyWage * 52); };
    int get_years() const
    {
        int years = 3;
        if (_yearsInCompany < 3)
        {
            years = _yearsInCompany;
        }
        return years;
    }
    int get_totalLeavesLeftPreviously() const
    {
        int totalLeavesLeftPreviously = 0;
        for (int i= 0; i < get_years(); i++) {
            totalLeavesLeftPreviously += _leavesLeftPreviously[_yearsInCompany - i - 1];
        }
        return totalLeavesLeftPreviously;
    }


};


class exportWorker{

public:
    std::string toHtml(Worker& worker) {
        std::stringstream ss;
        std::string str;

        ss << "<div>" << worker.get_id();

        ss << "<div>" << "<h1>Worker Info</h1>" << "<div id='emp" << worker.get_id() << "'>"
           << "<span>" << worker.get_name() << "</span>" << "<div class='left'>"
           << "<span>Leaves Left :</span>" << "<span>Annual salary:</span>"
           << "<span>Manager:</span>" << "<span>Reimbursable leaves:</span>"
           << "</div>";
        ss << "<div class='right'><span>" << (worker.get_leavesLeft())
           << "</span>";
        ss << "<span>" << round(worker.get_yearlyWage()) << "</span>";
        ss << "<span>" << worker.get_manager() << "</span>";


        ss << "<span>" + worker.get_totalLeavesLeftPreviously() << "</span>";

        ss << "</div> </div>";

        return ss.str();
    }

};



int main() {

    exportWorker _export;
    std::vector<int> v;
    v.push_back(5);
    v.push_back(2);

    Worker w = Worker(1, 2.5, "X", "Joe", 5, v);

    std::cout << _export.toHtml(w) << std::endl;

    return 0;
}

