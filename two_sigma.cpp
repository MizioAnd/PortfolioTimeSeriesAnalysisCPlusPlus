// two_sigma.cpp -- Implementing the TwoSigmaFinModTools class
// Implements parts of TwoSigmaFinModTools python code in C++
// The code will be written in C++98 and not C++11
#include <iostream>
#include <fstream>
#include "two_sigma.h"
#include "H5Cpp.h"
#include <H5DataSet.h>
#include <H5CommonFG.h>
using namespace H5;
using namespace std;
const H5std_string FILE_NAME( "train.h5" );
const H5std_string DATASET_NAME( "/train/axis0" );
// const H5std_string FILE_NAME( "Select.h5" );
// const H5std_string DATASET_NAME( "Matrix in file" );

TwoSigmaFinModTools::TwoSigmaFinModTools(bool true_or_false = false, int n = 11)
{
    _input_file_name = "/pathToFile/train.h5";
    _save_path = "/pathToDir/";
    is_portfolio_predictions = true_or_false;
    number_of_assets_in_portfolio = n;
  
    /*
    * Open the specified file and the specified dataset in the file.
    */
    // The works for opening "Matrix in file" data set
    H5File file( FILE_NAME, H5F_ACC_RDONLY );
    DataSet dataset = file.openDataSet( DATASET_NAME );
    // DataSet* dataset = new DataSet( file->openDataSet( DATASET_NAME ));

    
    // hid_t file_id;
    // file_id = file.getLocId();
    // hid_t dataset_my;
    // dataset_my = H5Dopen( file_id, "Matrix in file", H5F_ACC_TRUNC );
    // dataset_my = H5Dopen( file_id, "train", H5F_ACC_TRUNC );
    // hid_t proplist = H5Dget_create_plist(file_id);

    // Explore data
    /*
    * Get the class of the datatype that is used by the dataset.
    */
    // H5T_class_t type_class = dataset.getTypeClass();
    /*
    * Get class of datatype and print message if it's an integer.
    */
    // if( type_class == H5T_INTEGER )
    // {
    //     cout << "Data set has INTEGER type" << endl;
    //     /*
    //     * Get the integer datatype
    //     */
    //     IntType intype = dataset.getIntType();
    //         /*
    //     * Get order of datatype and print message if it's a little endian.
    //     */
    //     H5std_string order_string;
    //     H5T_order_t order = intype.getOrder( order_string );
    //     cout << order_string << endl;
    //     /*
    //     * Get size of the data element stored in file and print it.
    //     */
    //     size_t size = intype.getSize();
    //     cout << "Data size is " << size << endl;
    // }
}

// destructor
TwoSigmaFinModTools::~TwoSigmaFinModTools()
{
    // std::cout << "Bye, " << name << "!\n";  
    std::cout << "Bye!\n";  
}

// Clean data handles the data munging of the training and test data
void TwoSigmaFinModTools::clean_data(int df)
{
    // Todo: return dataset without nulls
}

// Todo: implement the functions declared in the interface of the class
void TwoSigmaFinModTools::my_name(const std::string & your_name)
{
    std::cout << "Your name is: " << your_name << std::endl;
}