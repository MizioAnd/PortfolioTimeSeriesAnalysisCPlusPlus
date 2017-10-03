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
// train_no_attrib.h5 is made using bash cmd
// h5copy -v -i "train.h5" -o "train_no_attrib.h5" -s "/train" -d "/train" -f noattr -p
// const H5std_string FILE_NAME( "train_no_attrib.h5" );
const H5std_string dataset_axis0_name( "/train/axis0" );
const H5std_string dataset_axis1_name( "/train/axis1" );
const H5std_string dataset_block0_items_name( "/train/block0_items" );
const H5std_string dataset_block0_values_name( "/train/block0_values" );
const H5std_string dataset_block1_items_name( "/train/block1_items" );
const H5std_string dataset_block1_values_name( "/train/block1_values" );
const H5std_string file_name_select( "Select.h5" );
const H5std_string dataset_name_select( "Matrix in file" );

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
    // H5File file_select( file_name_select, H5F_ACC_RDONLY );
    // H5File file( FILE_NAME, H5F_ACC_RDONLY );
    // DataSet dataset_axis0 = file.openDataSet( dataset_axis0_name );
    // DataSet dataset_axis1 = file.openDataSet( dataset_axis1_name );
    // DataSet dataset_block0_items = file.openDataSet( dataset_block0_items_name );
    // DataSet dataset_block0_values = file.openDataSet( dataset_block0_values_name );
    // DataSet dataset_block1_items = file.openDataSet( dataset_block1_items_name );
    // DataSet dataset_block1_values = file.openDataSet( dataset_block1_values_name );
    H5File * file = new H5File ( FILE_NAME, H5F_ACC_RDONLY );

    // Debugging dataset
    // DataSet dataset = file.openDataSet( dataset_axis0_name );
    // DataSet dataset = file.openDataSet( dataset_block0_items_name );
    // DataSet dataset = file.openDataSet( dataset_block0_values_name );
    // DataSet dataset = file_select.openDataSet( dataset_name_select );
    // DataSet * dataset = new DataSet (file->openDataSet( dataset_block0_items_name ));
    // DataSet * dataset = new DataSet (file->openDataSet( dataset_block0_values_name ));
    DataSet * dataset = new DataSet (file->openDataSet( dataset_block1_values_name ));

    // // Read an attribute using dynamic memory allocation on heap (new)
    // H5std_string test;
    // // Group * group = new Group (file->openGroup( "/" ));
    // Group * group = new Group (file->openGroup( "/train" ));
    // // Attribute * attr = new Attribute (group->openAttribute( "PYTABLES_FORMAT_VERSION" ));
    // // Attribute * attr = new Attribute (group->openAttribute( "pandas_type" ));
    // Attribute * attr = new Attribute (group->openAttribute( "pandas_type" ));
    // DataType * type = new DataType (attr->getDataType());
    // attr->read( *type, test );
    // cout << test << endl;
    // delete attr;
    // delete type;
    // delete group;
    // delete file;

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
    H5T_class_t * type_class = new H5T_class_t (dataset->getTypeClass());
    cout << *type_class << endl;

    /*
    * Get class of datatype and print message if it's a string.
    */
    if( *type_class == H5T_STRING )
    // if( *type_class == H5T_INTEGER )
    {
        cout << "Data set has STRING type" << endl;
        /*
        * Get the string datatype
        */
        StrType * strtype = new StrType (dataset->getStrType());
        /*
        * Get order of datatype and print message if it's a little endian.
        */
        H5std_string * order_string;
        H5T_cset_t * set_type = new H5T_cset_t (strtype->getCset());
        cout << *set_type << endl;
        /*
        * Get size of the data element stored in file and print it.
        */
        size_t * size = new size_t (strtype->getSize());
        cout << "Data size is " << *size << endl;
    }

    if( *type_class == H5T_INTEGER )
    {
        cout << "Data set has INTEGER type" << endl;
        /*
        * Get the integer datatype
        */
        IntType * intype = new IntType (dataset->getIntType());
        /*
        * Get order of datatype and print message if it's a little endian.
        */
        H5std_string * order_string;
        // H5T_order_t * order = new H5T_order_t (intype->getOrder( *order_string ));
        // cout << order_string << endl;

        /*
        * Get size of the data element stored in file and print it.
        */
        size_t * size = new size_t (intype->getSize());
        cout << "Data size is " << *size << endl;
    }

    delete type_class;

    /*
    * Get dataspace of the dataset.
    */
    DataSpace * dataspace = new DataSpace (dataset->getSpace());
    /*
     * Get the number of dimensions in the dataspace.
     */
    int * rank = new int (dataspace->getSimpleExtentNdims());
    /*
    * Get the dimension size of each dimension in the dataspace and
    * display them.
    */
    // hsize_t (*dims_out) [1];
    hsize_t * dims_out = new hsize_t [2];
    int * ndims = new int (dataspace->getSimpleExtentDims( dims_out, NULL));
    cout << "ndims " << *ndims << endl;
    cout << "rank " << *rank << ", dimensions " <<
        // (unsigned long)(dims_out[0]) << endl;
        (unsigned long)(dims_out[0]) << " x " <<
        (unsigned long)(dims_out[1]) << endl << endl;
    delete rank;
    delete ndims;
    delete dims_out;
    
    
    // hyperslab dimensions
    const int NX_SUB = 4;
    const int NY_SUB = 4;
    // const int NX = 1710756;        // output buffer dimensions
    const int NX = NX_SUB;
    const int NY = NY_SUB;
    // const int NX = 10;
    // const int NY = 2;
    // const int NX = 18000; 
    // const int NY = 111;
    const int RANK_OUT = 2;
    /* 
     * Define hyperslab in dataset. Implicitly with strike and 
     * block NULL.      
     */
    hsize_t offset[2];
    hsize_t count[2];
    offset[0] = 0;
    offset[1] = 0;
    count[0] = NX_SUB;
    count[1] = NY_SUB;
    dataspace->selectHyperslab( H5S_SELECT_SET, count , offset );
    /* 
     * Define memory dataspace.
     */
    hsize_t dimsm[2];
    dimsm[0] = NX;
    dimsm[1] = NY;
    DataSpace * memspace = new DataSpace ( RANK_OUT, dimsm );

    /* 
     * Define memory hyperslab.
     */
    hsize_t offset_out[2];
    hsize_t count_out[2];
    offset_out[0] = 0;
    offset_out[1] = 0;
    count_out[0] = NX_SUB;
    count_out[1] = NY_SUB;
    memspace->selectHyperslab( H5S_SELECT_SET, count_out, offset_out );

    /* 
     * Read data from file's hyperslab into the hyperslab of memory and display data.
     */
    int i, j;
    
    // int ** data_out = new int * [NX];  /* Output buffer */
    // for (i = 0; i < NX; i++)
    // {
    //     data_out[i] = new int [NY];
    // }

    // Define two dim array in static memory. Memory is cleared after leaving scope
    // int data_out[NX][NY];  /* Output buffer */    
    
    // H5T_IEEE_F32LE is of type float
    float data_out[NX][NY];  /* Output buffer */    
    
    // int data_out[NX];  /* Output buffer */
    // H5std_string * data_out = new H5std_string [NX];  /* Output buffer */
    // std::string * data_out = new std::string [NX];  /* Output buffer */
    // H5T_class_t * data_out = new H5T_class_t [NX];
    // H5T_STRING * data_out = new H5T_STRING [NX];  /* Output buffer */
    // string * data_out = new string [NX];  /* Output buffer */
    // int data_out[NX];  /* Output buffer */
    // H5T_STRING data_out[NX];  /* Output buffer */
    // PredType::C_S1 data_out[NX][NY];  /* Output buffer */

    if ( RANK_OUT == 2 )
    {
        // int two_dim_ar[NX][NY];  /* Output buffer */
        // int * data_out = two_dim_ar;
        for (i = 0; i < NX; i++)
        {
            for (j = 0; j < NY; j++)
            {
                // two_dim_ar[i][j] = 0;
                data_out[i][j] = 0;
                // (*data_out[i])[j] = 0;
                // data_out[i][j] = "0";
                // data_out[i][j] = '*';
            }
        }
    }
    else
    {
        int * data_out = new int [NX*NY];  /* Output buffer */
        for (i = 0; i < NX*NY; i++)
        {
            // data_out[i] = "0";
            data_out[i] = 0;
        }
    }

    // read for /train/block1_values dataset
    dataset->read( data_out, PredType::IEEE_F32LE, *memspace, *dataspace ); 
    // dataset->read( data_out, PredType::NATIVE_INT );

    // read for /train/block0_values dataset
    // dataset->read( data_out, PredType::NATIVE_INT, *memspace, *dataspace );
    // for (i = 0; i < NX; i++)
    // {
    //     dataset->read( data_out, PredType::NATIVE_INT, *memspace, *dataspace );
    // }
    // dataset->read( data_out, PredType::C_S1, *memspace, *dataspace );
    // dataset->read( data_out , PredType::C_S1 );
    if (RANK_OUT == 2)
    {
        for (i = 0; i < NX; i++)
        {
            for (j = 0; j < NY; j++)
            {
                cout << data_out[i][j] << " ";
            }
        cout << endl;
        }
        cout << endl;
    }
    else
    {
        for (i = 0; i < NX; i++)
        {
            cout << data_out[2*i] << " " << data_out[2*i + 1];
            cout << endl;
       }
    }
    delete dataset;
    delete memspace;
    delete dataspace;
    // delete [] data_out;
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