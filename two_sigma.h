// two_sigma.h -- TwoSigmaFinModTools class interface

#include <string>

class TwoSigmaFinModTools // class declaration
{
private:
    // define private variables and methods here
    std::string _input_file_name;
    std::string _save_path;

public:
    // define public variables and methods here
    bool is_portfolio_predictions;
    int number_of_assets_in_portfolio;

    void my_name(const std::string & your_name);

    // Todo: clean_data() returns object similar to DataFrame and input is DataFrame
    void clean_data(int df);

    // Constructors
    TwoSigmaFinModTools(bool true_or_false, int n);
    ~TwoSigmaFinModTools(); // noisy destructor
};