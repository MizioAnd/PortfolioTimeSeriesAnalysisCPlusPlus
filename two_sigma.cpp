// two_sigma.cpp -- Implementing the TwoSigmaFinModTools class
// Implements parts of TwoSigmaFinModTools python code in C++
// The code will be written in C++98 and not C++11
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "two_sigma.h"
#include "H5Cpp.h"
#include <H5DataSet.h>
#include <H5CommonFG.h>
using namespace H5;
using namespace std;
const H5std_string FILE_NAME( "train.h5" );
const H5std_string dataset_axis0_name( "/train/axis0" );
const H5std_string dataset_axis1_name( "/train/axis1" );
const H5std_string dataset_block0_items_name( "/train/block0_items" );
const H5std_string dataset_block0_values_name( "/train/block0_values" );
const H5std_string dataset_block1_items_name( "/train/block1_items" );
const H5std_string dataset_block1_values_name( "/train/block1_values" );
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
    DataSet dataset_axis0 = file.openDataSet( dataset_axis0_name );
    DataSet dataset_axis1 = file.openDataSet( dataset_axis1_name );
    DataSet dataset_block0_items = file.openDataSet( dataset_block0_items_name );
    DataSet dataset_block0_values = file.openDataSet( dataset_block0_values_name );
    DataSet dataset_block1_items = file.openDataSet( dataset_block1_items_name );
    DataSet dataset_block1_values = file.openDataSet( dataset_block1_values_name );
    
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
    H5T_class_t type_class = dataset_axis0.getTypeClass();
    cout << type_class  << endl;
    // std::ostringstream ss;
    // ss << type_class;
    // cout << ss.str()  << endl;

    /*
    * Get class of datatype and print message if it's a string.
    */
    if( type_class == H5T_STRING )
    {
        cout << "Data set has STRING type" << endl;
        /*
        * Get the string datatype
        */
        StrType strtype = dataset_axis0.getStrType();
        // IntType intype = dataset.getIntType();
        /*
        * Get order of datatype and print message if it's a little endian.
        */
        H5std_string order_string;
        H5T_order_t order = strtype.getOrder( order_string );
        // H5T_order_t order = intype.getOrder( order_string );
        cout << order_string << endl;
        /*
        * Get size of the data element stored in file and print it.
        */
        size_t size = strtype.getSize();
        // size_t size = intype.getSize();
        cout << "Data size is " << size << endl;
    }

    /*
    * Get dataspace of the dataset.
    */
    DataSpace dataspace_axis0 = dataset_axis0.getSpace();
    /*
     * Get the number of dimensions in the dataspace.
     */
    int rank = dataspace_axis0.getSimpleExtentNdims();
    /*
    * Get the dimension size of each dimension in the dataspace and
    * display them.
    */
    hsize_t dims_out[2];
    int ndims = dataspace_axis0.getSimpleExtentDims( dims_out, NULL);
    cout << "ndims" << ndims << endl;
    cout << "rank " << rank << ", dimensions " <<
        (unsigned long)(dims_out[0]) << " x " <<
        (unsigned long)(dims_out[1]) << endl;
    
    // hyperslab dimensions
    const int NX_SUB = 2;
    const int NY_SUB = 2;
    // const int NX = 1710756;        // output buffer dimensions
    const int NX = 18000; 
    const int NY = 111;
    const int RANK_OUT = 2;
    /* 
     * Define hyperslab in dataset. Implicitly with strike and 
     * block NULL.      
     */
    hsize_t offset[2];
    hsize_t count[2];
    offset[0] = 1;
    offset[0] = 2;
    count[0] = NX_SUB;
    count[1] = NY_SUB;
    dataspace_axis0.selectHyperslab( H5S_SELECT_SET, count, offset );
    /* 
     * Define memory dataspace.
     */
    hsize_t dimsm[2];
    dimsm[0] = NX;
    dimsm[1] = NY;
    DataSpace memspace( RANK_OUT, dimsm );

    /* 
     * Define memory hyperslab.
     */
    hsize_t offset_out[2];
    hsize_t count_out[2];
    offset_out[0] = 2;
    offset_out[1] = 0;
    count_out[0] = NX_SUB;
    count_out[1] = NY_SUB;
    memspace.selectHyperslab( H5S_SELECT_SET, count_out, offset_out );

    /* 
     * Read data from file's hyperslab into the hyperslab of memory and display data.
     */
    int i, j;
    int data_out[NX][NY];  /* Output buffer */
    for (i = 0; i < NX; i++)
    {
        for (j = 0; j < NY; j++)
        {
            data_out[i][j] = 0;
        }
    }
        
    // dataset_axis0.read( data_out, PredType::NATIVE_LDOUBLE, memspace, dataspace_axis0);
    // for (i = 0; i < NX; i++)
    // {
    //     for (j = 0; j < NY; j++)
    //     {
    //         cout << data_out[i][j] << " ";
    //     }
    //     cout << endl;
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
    // Todo: make it return the data set without nulls
}

// Todo: implement the functions declared in the interface of the class
void TwoSigmaFinModTools::my_name(const std::string & your_name)
{
    std::cout << "Your name is: " << your_name << std::endl;
}